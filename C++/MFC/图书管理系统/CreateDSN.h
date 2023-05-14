#if !defined(AFX_CREATEDSN_H__2398DD64_D722_484B_8825_49D88F601BE9__INCLUDED_)
#define AFX_CREATEDSN_H__2398DD64_D722_484B_8825_49D88F601BE9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CreateDSN.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCreateDSN dialog

class CCreateDSN : public CDialog
{
// Construction
public:
	CCreateDSN(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCreateDSN)
	enum { IDD = IDD_SETODBC };
	CString	m_szDSNName;
	CString	m_szPassword;
	CString	m_szUserName;
	CString	m_szFileName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCreateDSN)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCreateDSN)
	afx_msg void OnCancel();
	afx_msg void OnCreate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CREATEDSN_H__2398DD64_D722_484B_8825_49D88F601BE9__INCLUDED_)
