// ReaderQry.cpp : implementation file
//

#include "stdafx.h"
#include "Library.h"
#include "ReaderQry.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CReaderQry dialog


CReaderQry::CReaderQry(CWnd* pParent /*=NULL*/)
	: CDialog(CReaderQry::IDD, pParent)
{
	//{{AFX_DATA_INIT(CReaderQry)
	m_ReaderID = _T("");
	m_Name = _T("");
	m_ID_Card = _T("");
	//}}AFX_DATA_INIT
}


void CReaderQry::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CReaderQry)
	DDX_Text(pDX, IDC_EDITReaderID, m_ReaderID);
	DDX_Text(pDX, IDC_EDITName, m_Name);
	DDX_Text(pDX, IDC_EDITID_CARD, m_ID_Card);
	DDX_Control(pDX, IDC_REMOTEDATACTLReaderQry, m_RemoteDataCTL);
	DDX_Control(pDX, IDC_DBGRIDReaderInfo, m_DbgridCTL);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CReaderQry, CDialog)
	//{{AFX_MSG_MAP(CReaderQry)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CReaderQry message handlers

void CReaderQry::OnOK() 
{

	// TODO: Add extra validation here
	UpdateData(TRUE);
	if (m_ReaderID=="")
	{
		::AfxMessageBox("«Î ‰»Î∂¡’ﬂID");
		return;
	}
	
	m_ReaderSet.Open();
	m_ReaderSet.m_strFilter="READER_ID='"+m_ReaderID+"'";
	m_ReaderSet.Requery();

	UpdateData(FALSE);
	m_Name=m_ReaderSet.m_NAME;
	m_ID_Card=m_ReaderSet.m_READER_ID;
	
	m_RemoteDataCTL.SetSql("select bookname,borrow_date from book,borrow,reader where book.book_id=borrow.book_id and borrow.reader_id=reader.reader_id "); 
	
//	m_RemoteDataCTL.Query();
	m_RemoteDataCTL.Refresh( );

	

	CDialog::OnOK();
}

void CReaderQry::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}
