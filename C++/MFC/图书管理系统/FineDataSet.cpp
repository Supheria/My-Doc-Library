// FineDataSet.cpp : implementation file
//

#include "stdafx.h"
#include "Library.h"
#include "FineDataSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFineDataSet

IMPLEMENT_DYNAMIC(CFineDataSet, CRecordset)

CFineDataSet::CFineDataSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CFineDataSet)
	m_READER_ID = _T("");
	m_AMOUNT = 0;
	m_DAYS = 0;
	m_CLERK_ID = _T("");
	m_ID = 0;
	m_nFields = 6;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CFineDataSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=Library");
}

CString CFineDataSet::GetDefaultSQL()
{
	return _T("[FINE]");
}

void CFineDataSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CFineDataSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[READER_ID]"), m_READER_ID);
	RFX_Long(pFX, _T("[AMOUNT]"), m_AMOUNT);
	RFX_Int(pFX, _T("[DAYS]"), m_DAYS);
	RFX_Date(pFX, _T("[FINE_DATE]"), m_FINE_DATE);
	RFX_Text(pFX, _T("[CLERK_ID]"), m_CLERK_ID);
	RFX_Long(pFX, _T("[ID]"), m_ID);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CFineDataSet diagnostics

#ifdef _DEBUG
void CFineDataSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CFineDataSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
