#if !defined(AFX_FINEHISTORYDATASET_H__94E0FB6C_864C_4527_866D_B9281CE682F2__INCLUDED_)
#define AFX_FINEHISTORYDATASET_H__94E0FB6C_864C_4527_866D_B9281CE682F2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FineHistoryDataSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFineHistoryDataSet recordset

class CFineHistoryDataSet : public CRecordset
{
public:
	CFineHistoryDataSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CFineHistoryDataSet)

// Field/Param Data
	//{{AFX_FIELD(CFineHistoryDataSet, CRecordset)
	CString	m_READER_ID;
	long	m_AMOUNT;
	int		m_DAYS;
	CTime	m_FINE_DATE;
	CTime	m_OK_DATE;
	long	m_ID;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFineHistoryDataSet)
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

#endif // !defined(AFX_FINEHISTORYDATASET_H__94E0FB6C_864C_4527_866D_B9281CE682F2__INCLUDED_)
