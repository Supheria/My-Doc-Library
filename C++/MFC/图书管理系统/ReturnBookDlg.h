#if !defined(AFX_RETURNBOOKDLG_H__365AA4F2_3956_4710_A5B4_192BC5F5B316__INCLUDED_)
#define AFX_RETURNBOOKDLG_H__365AA4F2_3956_4710_A5B4_192BC5F5B316__INCLUDED_

#include "BorrowSet.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ReturnBookDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CReturnBookDlg dialog

class CReturnBookDlg : public CDialog
{
// Construction
public:
	BOOL OnInitDialog();

	int Insert_Fine();
	CBorrowSet m_rsDataSet;
	CReturnBookDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CReturnBookDlg)
	enum { IDD = IDD_ReturnBook };
	CString	m_Book_ID;
	CString	m_BorrowDate;
	int		m_Days;
	CString	m_ReaderName;
	CString	m_ReturnDate;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReturnBookDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CReturnBookDlg)
	afx_msg void OnKillfocusEDITBookID();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	int setTxtDisable( );
	int SetTxtNull();
	int Insert_History();
	int QryBorrow( );
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RETURNBOOKDLG_H__365AA4F2_3956_4710_A5B4_192BC5F5B316__INCLUDED_)
