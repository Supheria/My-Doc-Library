// LendOutDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Library.h"
#include "LendOutDlg.h"

#include "BorrowDataSet.h"
#include "ReaderDataSet.h"
#include "BookDataSet.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLendOutDlg dialog


CLendOutDlg::CLendOutDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLendOutDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLendOutDlg)
	m_strBookID = _T("");
	m_strReaderID = _T("");
	//}}AFX_DATA_INIT
}


void CLendOutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLendOutDlg)
	DDX_Text(pDX, IDC_BOOK_ID, m_strBookID);
	DDV_MaxChars(pDX, m_strBookID, 8);
	DDX_Text(pDX, IDC_READER_ID, m_strReaderID);
	DDV_MaxChars(pDX, m_strReaderID, 8);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLendOutDlg, CDialog)
	//{{AFX_MSG_MAP(CLendOutDlg)
	ON_BN_CLICKED(IDC_CONFIRM, OnConfirm)
	ON_BN_CLICKED(IDC_CANCEL, OnCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLendOutDlg message handlers

void CLendOutDlg::OnConfirm() 
{
	// TODO: Add your control notification handler code here
	//int m_nMaxNum;
	BOOL m_bCanBorrow;
	BOOL m_bCanLendOut;
	m_bCanBorrow = FALSE;
	m_bCanLendOut = FALSE;
	CString mSqlStr;

	UpdateData(TRUE);

//	mSqlStr = "SELECT * FROM READER WHERE READER_ID='" + m_strReaderID;
//	mSqlStr = "SELECT FLAG_BORROW,READER_ID FROM READER";
//	mSqlStr = mSqlStr + "'";

//	if (!m_rsReaderDataSet.Open(AFX_DB_USE_DEFAULT_TYPE, mSqlStr))
	if (!m_rsReaderDataSet.Open(AFX_DB_USE_DEFAULT_TYPE))
	{
		AfxMessageBox("数据表打开错误!");
		return;
	}
	
	m_rsReaderDataSet.m_strFilter = "READER_ID='" + m_strReaderID;
	m_rsReaderDataSet.m_strFilter = m_rsReaderDataSet.m_strFilter + "'";
	m_rsReaderDataSet.Requery();

	if (!m_rsReaderDataSet.IsEOF())
	{
		if (m_rsReaderDataSet.m_FLAG_BORROW == "Y")
		{
			mSqlStr = "SELECT * FROM BORROW WHERE READER_ID= '" + m_strReaderID;
			mSqlStr = mSqlStr + "'";

			if (!m_rsDataSet.Open(AFX_DB_USE_DEFAULT_TYPE,mSqlStr))
			{
				m_rsReaderDataSet.Close();
				AfxMessageBox("数据表打开错误!");
				return;

			}

			// Add some code to determine the num of book which this reader borrowed.
			m_bCanBorrow = TRUE;
			m_rsDataSet.Close();
		}
	}
	m_rsReaderDataSet.Close();

	if (!m_bCanBorrow)
	{
		AfxMessageBox("读者不能借书！");
		return;
	}

	mSqlStr = "SELECT * FROM BOOK WHERE BOOK_ID='" + m_strBookID;
	mSqlStr = mSqlStr + "'";

	if(!m_rsBookDataSet.Open(AFX_DB_USE_DEFAULT_TYPE, mSqlStr))
	{
		AfxMessageBox("数据表打开错误！");
		return ;
	}
	if (!m_rsBookDataSet.IsEOF())
	{
		if (m_rsBookDataSet.m_FLAG_BORROW == "Y")
		{
			m_bCanLendOut = TRUE;
		}
		else
		{
			AfxMessageBox("此书不外借！ ");
			m_rsBookDataSet.Close();
			return;
		}
	}
	else
	{
		AfxMessageBox("无此书！");
		m_rsBookDataSet.Close();
		return;
	}
	
	m_rsBookDataSet.Close();

	CMainFrame *pWnd;
	pWnd = (CMainFrame *)this->GetParent();
	CString m_strUserID;
	m_strUserID = pWnd->m_strUserID ;

//	mSqlStr = "INSERT INTO BORROW (READER_ID, BOOK_ID, BORROW_DATE, B_CLERK_ID) VALUES('";
	mSqlStr = "INSERT INTO BORROW (READER_ID, BOOK_ID, B_CLERK_ID) VALUES('";
	mSqlStr = mSqlStr + m_strReaderID;
	mSqlStr = mSqlStr + "','";
	mSqlStr = mSqlStr + m_strBookID;
	mSqlStr = mSqlStr + "','";
//	mSqlStr = mSqlStr + "', SYSDATE,'";
	mSqlStr = mSqlStr + m_strUserID;
	mSqlStr = mSqlStr + "')";
	
	CDatabase mDB;
	if (!mDB.Open(_T("Library")))
	{
		AfxMessageBox("无法打开数据库！");
		return;
	}
	

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
	AfxMessageBox("操作成功！");

}

void CLendOutDlg::OnCancel() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
}

BOOL CLendOutDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
