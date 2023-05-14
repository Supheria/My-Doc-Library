// FineDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Library.h"
#include "FineDlg.h"

#include "ReaderDataSet.h"
#include "FineDataSet.h"

#include "stdlib.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFineDlg dialog


CFineDlg::CFineDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFineDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFineDlg)
	m_nAmount = 0;
	m_nDays = 0;
	m_dFineDate = COleDateTime::GetCurrentTime();
	m_strReaderName = _T("");
	m_strReaderID = _T("");
	//}}AFX_DATA_INIT
}


void CFineDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFineDlg)
	DDX_Text(pDX, IDC_AMOUNT, m_nAmount);
	DDX_Text(pDX, IDC_DAYS, m_nDays);
	DDX_Text(pDX, IDC_FINE_DATE, m_dFineDate);
	DDX_Text(pDX, IDC_READER_NAME, m_strReaderName);
	DDX_Text(pDX, IDC_READER_ID, m_strReaderID);
	DDV_MaxChars(pDX, m_strReaderID, 8);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFineDlg, CDialog)
	//{{AFX_MSG_MAP(CFineDlg)
	ON_BN_CLICKED(IDC_CONFIRM, OnConfirm)
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	ON_EN_KILLFOCUS(IDC_READER_ID, OnKillfocusReaderId)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFineDlg message handlers

void CFineDlg::OnConfirm() 
{
	// TODO: Add your control notification handler code here
	
//	UpdateData(TRUE);
//	CWnd *pWnd;
//	pWnd = GetDlgItem(IDC_READER_ID);

//	pWnd->GetWindowText(m_strReaderId);

	if (m_szReaderID.IsEmpty())
	{
		AfxMessageBox("请输入读者编码！");
		return;
	}


	CString mSqlStr;
	CDatabase mDB;
	if(!mDB.Open(_T("library")))
		AfxMessageBox("数据库打开出错");

	mSqlStr = "UPDATE READER SET FLAG_BORROW='Y' WHERE READER_ID='" + m_szReaderID;
	mSqlStr = mSqlStr + "'";

	try
	{
		mDB.ExecuteSQL(mSqlStr);
	}
	catch(CDBException e)
	{
		AfxMessageBox("执行错！");
		return;
	}

	mSqlStr = "DELETE FROM FINE WHERE READER_ID='" + m_szReaderID;
	mSqlStr = mSqlStr + "'";
	try
	{
		mDB.ExecuteSQL(mSqlStr);
	}
	catch(CDBException e)
	{
		AfxMessageBox("执行错！");
		return;
	}
	
	char mTemp[10];
	_itoa(m_nAmount,mTemp,10);

	mSqlStr = "INSERT INTO FINE_HISTORY(READER_ID,AMOUNT) VALUES ('" + m_szReaderID;
	mSqlStr = mSqlStr + "',";
	mSqlStr = mSqlStr + mTemp;
	mSqlStr = mSqlStr + ")";

	try
	{
		mDB.ExecuteSQL(mSqlStr);
	}
	catch(CDBException e)
	{
		AfxMessageBox("执行错！");
		return;
	}

	mDB.Close();
	AfxMessageBox("执行成功！");

}

void CFineDlg::OnExit() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
}

void CFineDlg::OnKillfocusReaderId() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (m_strReaderID.IsEmpty())
	{
		AfxMessageBox("请输入读者编码！");
		return;
	}

	m_szReaderID = m_strReaderID;

	CReaderDataSet m_rsReaderDataset;
	if(!m_rsReaderDataset.Open(AFX_DB_USE_DEFAULT_TYPE))
	{
		AfxMessageBox("数据表打开失败！");
		return;
	}

	m_rsReaderDataset.m_strFilter = "READER_ID='" + m_strReaderID;
	m_rsReaderDataset.m_strFilter = m_rsReaderDataset.m_strFilter + "'";
	m_rsReaderDataset.Requery();
	if (m_rsReaderDataset.IsEOF())
	{
		AfxMessageBox("没有此读者！");
		m_rsReaderDataset.Close();
		return;
	}

	m_strReaderName = m_rsReaderDataset.m_NAME ;

	m_rsReaderDataset.Close();

	CString mSqlStr;
	mSqlStr = "SELECT * FROM FINE WHERE READER_ID='" + m_strReaderID;
	mSqlStr = mSqlStr + "'";

	CFineDataSet m_rsFineDataSet;
	if (!m_rsFineDataSet.Open(AFX_DB_USE_DEFAULT_TYPE,mSqlStr))
	{
		AfxMessageBox("数据表打开失败！");
		return;
	}
	
	if (m_rsFineDataSet.IsEOF())
	{
		AfxMessageBox("读者没有罚款记录！");
		m_rsFineDataSet.Close();
		return;
	}

	m_nAmount = m_rsFineDataSet.m_AMOUNT ;
	m_nDays = m_rsFineDataSet.m_DAYS ;
//	m_dFineDate = m_rsFineDataSet.m_FINE_DATE ;

	m_rsFineDataSet.Close();

	UpdateData(FALSE);	
}
