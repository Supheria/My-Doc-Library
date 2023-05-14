#if !defined(AFX_READERDATASET_H__EBE1088E_B8B2_4138_B26B_F1B4EB445F8D__INCLUDED_)
#define AFX_READERDATASET_H__EBE1088E_B8B2_4138_B26B_F1B4EB445F8D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ReaderDataSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CReaderDataSet recordset

class CReaderDataSet : public CRecordset
{
public:
	CReaderDataSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CReaderDataSet)

// Field/Param Data
	//{{AFX_FIELD(CReaderDataSet, CRecordset)
	CString	m_NAME;
	CString	m_IDCARD;
	int		m_MAXNUM_CAN_BORROW;
	CString	m_READER_ID;
	CString	m_FLAG_BORROW;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReaderDataSet)
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

#endif // !defined(AFX_READERDATASET_H__EBE1088E_B8B2_4138_B26B_F1B4EB445F8D__INCLUDED_)
