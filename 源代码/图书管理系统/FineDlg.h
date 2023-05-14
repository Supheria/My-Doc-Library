#if !defined(AFX_FINEDLG_H__07D38E99_27BD_43E6_9703_B0E16422EDC9__INCLUDED_)
#define AFX_FINEDLG_H__07D38E99_27BD_43E6_9703_B0E16422EDC9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FineDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFineDlg dialog

class CFineDlg : public CDialog
{
// Construction
public:
	CString m_szReaderID;
	CFineDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFineDlg)
	enum { IDD = IDD_FINE };
	long	m_nAmount;
	int		m_nDays;
	COleDateTime	m_dFineDate;
	CString	m_strReaderName;
	CString	m_strReaderID;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFineDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFineDlg)
	afx_msg void OnConfirm();
	afx_msg void OnExit();
	afx_msg void OnKillfocusReaderId();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FINEDLG_H__07D38E99_27BD_43E6_9703_B0E16422EDC9__INCLUDED_)
