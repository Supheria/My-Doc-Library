#if !defined(AFX_CLERKMDLG_H__E21F5C3F_121C_4A40_AF51_248C6F325C84__INCLUDED_)
#define AFX_CLERKMDLG_H__E21F5C3F_121C_4A40_AF51_248C6F325C84__INCLUDED_

#include "ClerkDataSet.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ClerkMDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CClerkMDlg dialog

class CClerkMDlg : public CDialog
{
// Construction
public:
	CClerkDataSet m_rsDataSet;
	BOOL m_bEdit;
	BOOL m_bAdd;
	BOOL SetButtonState();
	BOOL SetTextState();
	BOOL DisplayRecord();
	CClerkMDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CClerkMDlg)
	enum { IDD = IDD_CLERK_MAINTAIN };
	CComboBox	m_cntrPosition;
	CString	m_strUserNameQ;
	CString	m_strUserName;
	CString	m_strUserIDQ;
	CString	m_strUserID;
	CString	m_strPassword;
	CString	m_strIDCard;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClerkMDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CClerkMDlg)
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

#endif // !defined(AFX_CLERKMDLG_H__E21F5C3F_121C_4A40_AF51_248C6F325C84__INCLUDED_)
