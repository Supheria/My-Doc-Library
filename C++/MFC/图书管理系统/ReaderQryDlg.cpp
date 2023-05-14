// ReaderQryDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Library.h"
#include "ReaderQryDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CReaderQryDlg dialog


CReaderQryDlg::CReaderQryDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CReaderQryDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CReaderQryDlg)
	m_strReaderID = _T("");
	m_strReaderName = _T("");
	m_strReaderIDCard = _T("");
	//}}AFX_DATA_INIT
}


void CReaderQryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CReaderQryDlg)
	DDX_Control(pDX, IDC_LISTBOOK, m_lstBook);
	DDX_Text(pDX, IDC_READERID, m_strReaderID);
	DDV_MaxChars(pDX, m_strReaderID, 8);
	DDX_Text(pDX, IDC_READERNAME, m_strReaderName);
	DDX_Text(pDX, IDC_READERIDCARD, m_strReaderIDCard);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CReaderQryDlg, CDialog)
	//{{AFX_MSG_MAP(CReaderQryDlg)
	ON_BN_CLICKED(IDC_QUERY, OnQuery)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CReaderQryDlg message handlers

void CReaderQryDlg::OnQuery() 
{
	// TODO: Add your control notification handler code here
	m_lstBook.DeleteAllItems();
	UpdateData(TRUE);
	m_strReaderName = "";
	m_strReaderIDCard = "";
	UpdateData(FALSE);
	if (m_strReaderID == "")
	{
		::AfxMessageBox("请输入读者ID");
		return;
	}
	
	m_ReaderSet.m_strFilter="READER_ID='"+m_strReaderID+"'";
	m_ReaderSet.Open();
	if (m_ReaderSet.IsEOF())
	{
		AfxMessageBox("此读者ID号码不存在！");
		m_ReaderSet.Close();
		return;
	}
	m_strReaderName = m_ReaderSet.m_NAME ;
	m_strReaderIDCard = m_ReaderSet.m_IDCARD ;
	m_BorrowInfo.m_strFilter = "BOOK.BOOK_ID = BORROW.BOOK_ID AND READER_ID='" + m_strReaderID + "'";
	m_BorrowInfo.Open();
	LVITEM			lvi;
	int				nNumofCount;
	CString			m_strTime;
	while (!m_BorrowInfo.IsEOF())
	{

		lvi.mask = LVIF_TEXT | LVIF_IMAGE | LVIF_PARAM;
		nNumofCount = m_lstBook.GetItemCount();
		lvi.iItem = nNumofCount;
		lvi.iSubItem = 0;
		lvi.pszText = m_BorrowInfo.m_strBookName.GetBuffer(0) ;
		m_lstBook.InsertItem(&lvi);
		m_strTime = m_BorrowInfo.m_dtBorrowDate.Format("%D");

		m_lstBook.SetItemText(nNumofCount,1, m_strTime);

		m_BorrowInfo.MoveNext();
	}
	UpdateData(FALSE);
	m_BorrowInfo.Close();
	m_ReaderSet.Close();


}

BOOL CReaderQryDlg::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CDialog::Create(IDD, pParentWnd);
}

int CReaderQryDlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	
	return 0;
}

void CReaderQryDlg::AddExStyle(DWORD dwNewStyle)
{
	DWORD dwStyle = ::SendMessage (m_lstBook.m_hWnd, LVM_GETEXTENDEDLISTVIEWSTYLE, 0, 0);
	dwStyle |= dwNewStyle;

	::SendMessage (m_lstBook.m_hWnd, LVM_SETEXTENDEDLISTVIEWSTYLE, 0, dwStyle);

}

BOOL CReaderQryDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_lstBook.ModifyStyleEx(0, WS_EX_CLIENTEDGE);
	AddExStyle(LVS_EX_FULLROWSELECT | LVS_OWNERDRAWFIXED);
	
	LV_COLUMN	lvc;
	int			i;

	lvc.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
	CString	strTemp[2] = {"书名", "借书日期"};
	int size[2] = {200,150};
	for(i = 0; i < 2; i++)
	{
		lvc.iSubItem = i;
		lvc.pszText = (char*)(LPCTSTR)strTemp[i];
		lvc.cx = size[i];
		lvc.fmt = LVCFMT_LEFT;
		m_lstBook.InsertColumn(i, &lvc);
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
