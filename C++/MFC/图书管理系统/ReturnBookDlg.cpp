// ReturnBookDlg.cpp : implementation file
//

#include "stdafx.h"
#include "time.h"
#include "Library.h"
#include "ReturnBookDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CReturnBookDlg dialog


CReturnBookDlg::CReturnBookDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CReturnBookDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CReturnBookDlg)
	m_Book_ID = _T("");
	m_BorrowDate = _T("");
	m_Days = 0;
	m_ReaderName = _T("");
	m_ReturnDate = _T("");
	//}}AFX_DATA_INIT

}


void CReturnBookDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CReturnBookDlg)
	DDX_Text(pDX, IDC_EDITBook_ID, m_Book_ID);
	DDX_Text(pDX, IDC_EDITBorrowDate, m_BorrowDate);
	DDX_Text(pDX, IDC_EDITDays, m_Days);
	DDX_Text(pDX, IDC_EDITReaderName, m_ReaderName);
	DDX_Text(pDX, IDC_EDITReturnDate, m_ReturnDate);
	//}}AFX_DATA_MAP
	
}


BEGIN_MESSAGE_MAP(CReturnBookDlg, CDialog)
	//{{AFX_MSG_MAP(CReturnBookDlg)
	ON_EN_KILLFOCUS(IDC_EDITBook_ID, OnKillfocusEDITBookID)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CReturnBookDlg message handlers

int CReturnBookDlg::QryBorrow()
{
	int result;
	CTime  m_ReturnDate_tmp;
	CString m_strtmp;
	CTime  m_Current_Time=CTime::GetCurrentTime();
	CTimeSpan m_TimeSpan_tmp(30,24,59,59);
	UpdateData(true);
	if (strcmp(m_Book_ID,"")==0) 
		return 0;
	m_rsDataSet.m_strFilter ="reader.reader_ID=borrow.reader_ID and BOOK_ID='"+m_Book_ID+"'";
	if (!m_rsDataSet.Open())
	{
		AfxMessageBox("数据打开失败！");
		return -1;
	}
	
	m_rsDataSet.Requery();
	if (m_rsDataSet.GetRecordCount()!=0) 
	{
		m_ReaderName=m_rsDataSet.m_ReaderName ;
		m_BorrowDate=m_rsDataSet.m_BORROW_DATE.Format("%Y, %B %d") ;
		m_ReturnDate_tmp=m_rsDataSet.m_BORROW_DATE+m_TimeSpan_tmp;
		m_ReturnDate=m_ReturnDate_tmp.Format("%Y,%B %d");
		if (m_ReturnDate_tmp<m_Current_Time)
		{
			m_TimeSpan_tmp=CTime::GetCurrentTime()-m_ReturnDate_tmp;
			m_Days=m_TimeSpan_tmp.GetDays();
			UpdateData(false);
			Insert_Fine();

			result=1;
			
			
		}
		else
		{
			UpdateData(false);
			Insert_History();//正常还书
			result=2;
			
		}
		
		m_rsDataSet.Close();
		return result;
	}
	else
	{
		
		return 0;
	}
}

void CReturnBookDlg::OnKillfocusEDITBookID() 
{
	int rs;
	CWnd *pWnd;
	CString m_strtmp;

	rs=QryBorrow();
	if(rs==1)
	{
		m_strtmp.Format("超期%d天，还书处理正常完成。是否继续处理还书流程？",m_Days);
		if(::MessageBox(this->m_hWnd,m_strtmp,"提示",MB_YESNO)==IDYES)
		
			SetTxtNull();
		else
			CDialog::OnClose();
		
	}
	else if(rs==2)
	{
		if(::MessageBox(this->m_hWnd,"还书处理正常完成","提示",MB_YESNO)==IDYES)
			SetTxtNull();
		else
			CDialog::OnClose();

	}
	else if(rs==0)
	{
		if (m_Book_ID == "")
			return;
		::MessageBox(this->m_hWnd,"该书号信息不存在！","警告",MB_OK);
	}  
	
	// TODO: Add your control notification handler code here
	pWnd=GetDlgItem(IDC_EDITBook_ID);
	pWnd->SetFocus();
}

void CReturnBookDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

int CReturnBookDlg::Insert_Fine()
{
	CDatabase mdb;
	CString   m_strsql;
	CTime     m_CurrentTime;
	m_CurrentTime=CTime::GetCurrentTime();
	m_strsql.Format("insert into fine(Reader_ID,amount,days,fine_date) values( \'%s\',%f,%d",m_rsDataSet.m_READER_ID,(m_Days*0.2),m_Days);
	m_strsql=m_strsql+",'"+m_CurrentTime.Format("%Y,%B %d")+"')";
	if(!mdb.Open(_T("Library")))
	{
		AfxMessageBox("数据库打开出错");
		return 0;
	}
	try
	{
		mdb.BeginTrans();
		mdb.ExecuteSQL(m_strsql);
		m_strsql = "UPDATE READER SET FLAG_BORROW='N' WHERE READER_ID='" +m_rsDataSet.m_READER_ID;
		m_strsql = m_strsql + "'";
		mdb.ExecuteSQL(m_strsql);
		mdb.CommitTrans();
		return 1;
	}
	catch(CDBException e)
	{
		AfxMessageBox("数据库执行出错");
		return 0;
	}
}

int CReturnBookDlg::Insert_History()
{
	CDatabase mdb;
	CString   m_strsql;

	if(!mdb.Open(_T("library")))
	{
		AfxMessageBox("数据库执行出错");
		return 0;
	}

	m_strsql="INSERT INTO HISTORY (READER_ID,BOOK_ID,BORROW_DATE,RETURN_DATE) VALUES ('"+m_rsDataSet.m_READER_ID+"'";
	m_strsql=m_strsql+",'"+m_rsDataSet.m_BOOK_ID+"'";
	m_strsql=m_strsql+",'"+m_BorrowDate+"'";
	m_strsql=m_strsql+",'"+(CTime::GetCurrentTime()).Format("%Y,%B %d")+"')";
	try
	{
		mdb.BeginTrans();
		mdb.ExecuteSQL(m_strsql);
		mdb.CommitTrans();
	}
	catch(CDBException e)
	{
		AfxMessageBox("数据库执行出错");
		return 0;
	}
	return 1;
}

int CReturnBookDlg::SetTxtNull()
{	
	CWnd *pWnd;
	m_Book_ID="";
	m_BorrowDate="";
	m_Days=0;
	m_ReaderName="";
	m_ReturnDate="";
	UpdateData(false);
	pWnd=GetDlgItem(IDC_EDITBook_ID);
//	pWnd->SetFocus();
	return 1;
}

int CReturnBookDlg::setTxtDisable()
{
	CWnd *pWnd;
	pWnd=GetDlgItem(IDC_EDITReaderName);
	pWnd->EnableWindow(false);
	pWnd=GetDlgItem(IDC_EDITBorrowDate);
	pWnd->EnableWindow(false);
	pWnd=GetDlgItem(IDC_EDITReturnDate);
	pWnd->EnableWindow(false);
	pWnd=GetDlgItem(IDC_EDITDays);
	pWnd->EnableWindow(false);
	return 1;

}

BOOL CReturnBookDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
//	setTxtDisable();
	return true;
}
