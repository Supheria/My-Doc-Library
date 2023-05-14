#if !defined(AFX_CONFIGDATASET_H__2A4BEB50_C81C_4D40_9F48_84F475F0E3F2__INCLUDED_)
#define AFX_CONFIGDATASET_H__2A4BEB50_C81C_4D40_9F48_84F475F0E3F2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ConfigDataSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CConfigDataSet recordset

class CConfigDataSet : public CRecordset
{
public:
	CConfigDataSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CConfigDataSet)

// Field/Param Data
	//{{AFX_FIELD(CConfigDataSet, CRecordset)
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CConfigDataSet)
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

#endif // !defined(AFX_CONFIGDATASET_H__2A4BEB50_C81C_4D40_9F48_84F475F0E3F2__INCLUDED_)
