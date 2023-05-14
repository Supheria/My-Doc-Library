#if !defined(AFX_FINEDATASET_H__CBC6A6BD_FE43_4804_BB06_39B3A48CAFC5__INCLUDED_)
#define AFX_FINEDATASET_H__CBC6A6BD_FE43_4804_BB06_39B3A48CAFC5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FineDataSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFineDataSet recordset

class CFineDataSet : public CRecordset
{
public:
	CFineDataSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CFineDataSet)

// Field/Param Data
	//{{AFX_FIELD(CFineDataSet, CRecordset)
	CString	m_READER_ID;
	long	m_AMOUNT;
	int		m_DAYS;
	CTime	m_FINE_DATE;
	CString	m_CLERK_ID;
	long	m_ID;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFineDataSet)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FINEDATASET_H__CBC6A6BD_FE43_4804_BB06_39B3A48CAFC5__INCLUDED_)
