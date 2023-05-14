#if !defined(AFX_LENDOUTDLG_H__BD766AC9_5106_41C1_B1FD_AC5D4917A287__INCLUDED_)
#define AFX_LENDOUTDLG_H__BD766AC9_5106_41C1_B1FD_AC5D4917A287__INCLUDED_

#include "BorrowDataSet.h"	// Added by ClassView
#include "ReaderDataSet.h"	// Added by ClassView
#include "BookDataSet.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LendOutDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLendOutDlg dialog

class CLendOutDlg : public CDialog
{
// Construction
public:
	CBookDataSet m_rsBookDataSet;
	CReaderDataSet m_rsReaderDataSet;
	CBorrowDataSet m_rsDataSet;
	CLendOutDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLendOutDlg)
	enum { IDD = IDD_LENDOUT };
	CString	m_strBookID;
	CString	m_strReaderID;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLendOutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLendOutDlg)
	afx_msg void OnConfirm();
	afx_msg void OnCancel();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LENDOUTDLG_H__BD766AC9_5106_41C1_B1FD_AC5D4917A287__INCLUDED_)
