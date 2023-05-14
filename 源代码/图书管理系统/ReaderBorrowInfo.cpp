// ReaderBorrowInfo.cpp : implementation file
//

#include "stdafx.h"
#include "Library.h"
#include "ReaderBorrowInfo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CReaderBorrowInfo

IMPLEMENT_DYNAMIC(CReaderBorrowInfo, CRecordset)

CReaderBorrowInfo::CReaderBorrowInfo(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CReaderBorrowInfo)
	m_strBookName = _T("");
	m_strReaderID = _T("");
	m_nFields = 3;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CReaderBorrowInfo::GetDefaultConnect()
{
	return _T("ODBC;DSN=library");
}

CString CReaderBorrowInfo::GetDefaultSQL()
{
	return _T("[BOOK],[BORROW]");
	//return _T("SELECT BOOK_NAME, BORROW_DATE, READER_ID FROM BOOK, BORROW WHERE BOOK.BOOK_ID = BORROW.BOOK_ID");
}

void CReaderBorrowInfo::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CReaderBorrowInfo)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[BOOK_NAME]"), m_strBookName);
	RFX_Text(pFX, _T("[READER_ID]"), m_strReaderID);
	RFX_Date(pFX, _T("[BORROW_DATE]"), m_dtBorrowDate);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CReaderBorrowInfo diagnostics

#ifdef _DEBUG
void CReaderBorrowInfo::AssertValid() const
{
	CRecordset::AssertValid();
}

void CReaderBorrowInfo::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
