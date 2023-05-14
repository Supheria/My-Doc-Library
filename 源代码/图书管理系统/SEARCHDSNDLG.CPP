// SearchDSNDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DSNCollection.h"
#include "SearchDSNDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSearchDSNDlg dialog

CSearchDSNDlg::CSearchDSNDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSearchDSNDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSearchDSNDlg)
	m_bSys = TRUE;//缺省状况下显示系统DSN
	m_bUser = FALSE;
	//}}AFX_DATA_INIT
}


void CSearchDSNDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSearchDSNDlg)
	DDX_Control(pDX, IDC_DSN_LIST, m_DSNList);
	DDX_Check(pDX, IDC_SYSTEM, m_bSys);
	DDX_Check(pDX, IDC_USER, m_bUser);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSearchDSNDlg, CDialog)
	//{{AFX_MSG_MAP(CSearchDSNDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSearchDSNDlg message handlers

BOOL CSearchDSNDlg::InitDSNListBox()
{
	UpdateData(TRUE);
	//清楚上一次的搜索结果
	m_DSNList.ResetContent();

	CDSNCollection dsn;
	for (bool bFirst = true; dsn.GetLastSQLResult() == SQL_SUCCESS; bFirst = false)
	{
		CString s;
		if (bFirst)//得到第一个DSN
			s = dsn.GetFirstDSNName((m_bSys?CDSNCollection::s_SYSTEM:0) |
									(m_bUser?CDSNCollection::s_USER:0));
		else//得到下一个DSN
			s = dsn.GetNextDSNName();

		if (dsn.GetLastSQLResult() == SQL_SUCCESS)
			m_DSNList.AddString(s);
	}

	if (dsn.GetLastSQLResult() != SQL_NO_DATA)
		MessageBox(dsn.GetErrorMessage());
	return TRUE;
}

BOOL CSearchDSNDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	ASSERT(InitDSNListBox());

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSearchDSNDlg::OnOK() 
{
	//刷新搜索结果
	if(MessageBox("需要刷新数据源列表吗?","刷新数据源",MB_YESNO|MB_ICONQUESTION) == IDYES)
	{
		InitDSNListBox();
		return;
	}	
	CDialog::OnOK();
}
