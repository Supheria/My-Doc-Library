// CreateDSN.cpp : implementation file
//

#include "stdafx.h"
#include "Library.h"
#include "CreateDSN.h"

#include "odbcinst.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCreateDSN dialog


CCreateDSN::CCreateDSN(CWnd* pParent /*=NULL*/)
	: CDialog(CCreateDSN::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCreateDSN)
	m_szDSNName = _T("Library");
	m_szPassword = _T("");
	m_szUserName = _T("");
	m_szFileName = _T("");
	//}}AFX_DATA_INIT
}


void CCreateDSN::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCreateDSN)
	DDX_Text(pDX, IDC_ODBCDSN, m_szDSNName);
	DDV_MaxChars(pDX, m_szDSNName, 10);
	DDX_Text(pDX, IDC_PASSWORD, m_szPassword);
	DDV_MaxChars(pDX, m_szPassword, 10);
	DDX_Text(pDX, IDC_USERNAME, m_szUserName);
	DDV_MaxChars(pDX, m_szUserName, 10);
	DDX_Text(pDX, IDC_FILENAME, m_szFileName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCreateDSN, CDialog)
	//{{AFX_MSG_MAP(CCreateDSN)
	ON_BN_CLICKED(IDC_CANCEL, OnCancel)
	ON_BN_CLICKED(IDC_CREATE, OnCreate)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCreateDSN message handlers

void CCreateDSN::OnCancel() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();	
}

void CCreateDSN::OnCreate() 
{
	// TODO: Add your control notification handler code here
	CString m_szDriver = _T("Microsoft Access Driver (*.mdb)\0");
//	SQLConfigDataSource(NULL, ODBC_ADD_DSN, m_szDriver, strattr);
}
