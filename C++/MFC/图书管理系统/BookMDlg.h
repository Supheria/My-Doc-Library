#if !defined(AFX_BOOKMDLG_H__52817D2F_D260_4393_9F7C_143466DE662D__INCLUDED_)
#define AFX_BOOKMDLG_H__52817D2F_D260_4393_9F7C_143466DE662D__INCLUDED_

#include "BookDataSet.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BookMDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBookMDlg dialog

class CBookMDlg : public CDialog
{
// Construction
public:
	BOOL SetButtonState();
	BOOL SetTextState();
	BOOL DisplayRecord();
	BOOL m_bEdit;
	BOOL m_bAdd;
	CBookDataSet m_rsDataSet;
	CBookMDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CBookMDlg)
	enum { IDD = IDD_BOOK_MAINTAIN };
	CString	m_strAuthor;
	CString	m_strBookID;
	CString	m_strBookIDQ;
	CString	m_strBookName;
	CString	m_strBookNameQ;
	CString	m_strFlag;
	CString	m_strPress;
	CString	m_strPressDate;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBookMDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBookMDlg)
	afx_msg void OnCancelRec();
	afx_msg void OnDelete();
	afx_msg void OnEdit();
	afx_msg void OnEnquery();
	afx_msg void OnExit();
	afx_msg void OnFirst();
	afx_msg void OnLast();
	afx_msg void OnNew();
	afx_msg void OnNext();
	afx_msg void OnPrior();
	afx_msg void OnSave();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BOOKMDLG_H__52817D2F_D260_4393_9F7C_143466DE662D__INCLUDED_)
