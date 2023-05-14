// ConfigDataSet.cpp : implementation file
//

#include "stdafx.h"
#include "Library.h"
#include "ConfigDataSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CConfigDataSet

IMPLEMENT_DYNAMIC(CConfigDataSet, CRecordset)

CConfigDataSet::CConfigDataSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CConfigDataSet)
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CConfigDataSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=Library");
}

CString CConfigDataSet::GetDefaultSQL()
{
	return _T("");
}

void CConfigDataSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CConfigDataSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CConfigDataSet diagnostics

#ifdef _DEBUG
void CConfigDataSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CConfigDataSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
