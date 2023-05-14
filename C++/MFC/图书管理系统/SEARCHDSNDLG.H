#if !defined(AFX_SEARCHDSNDLG_H__3FA1902B_BAF4_11D4_A7B0_0010B54D545E__INCLUDED_)
#define AFX_SEARCHDSNDLG_H__3FA1902B_BAF4_11D4_A7B0_0010B54D545E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SearchDSNDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSearchDSNDlg dialog
#include "resource.h"
class CSearchDSNDlg : public CDialog
{
// Construction
public:
	BOOL InitDSNListBox();
	CSearchDSNDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSearchDSNDlg)
	enum { IDD = IDD_DSN_DLG };
	CListBox	m_DSNList;
	BOOL	m_bSys;
	BOOL	m_bUser;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSearchDSNDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSearchDSNDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SEARCHDSNDLG_H__3FA1902B_BAF4_11D4_A7B0_0010B54D545E__INCLUDED_)
