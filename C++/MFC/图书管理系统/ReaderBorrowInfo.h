#if !defined(AFX_READERBORROWINFO_H__C3ED1313_8A60_4F65_82DB_12529C41305D__INCLUDED_)
#define AFX_READERBORROWINFO_H__C3ED1313_8A60_4F65_82DB_12529C41305D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ReaderBorrowInfo.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CReaderBorrowInfo recordset

class CReaderBorrowInfo : public CRecordset
{
public:
	CReaderBorrowInfo(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CReaderBorrowInfo)

// Field/Param Data
	//{{AFX_FIELD(CReaderBorrowInfo, CRecordset)
	CString	m_strBookName;
	CString	m_strReaderID;
	CTime	m_dtBorrowDate;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReaderBorrowInfo)
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

#endif // !defined(AFX_READERBORROWINFO_H__C3ED1313_8A60_4F65_82DB_12529C41305D__INCLUDED_)
