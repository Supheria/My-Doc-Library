#if !defined(AFX_READERQRYDLG_H__07FBBD90_0C66_4F2A_ADC0_529630B11D16__INCLUDED_)
#define AFX_READERQRYDLG_H__07FBBD90_0C66_4F2A_ADC0_529630B11D16__INCLUDED_

#include "ReaderDataSet.h"	// Added by ClassView
#include "ReaderBorrowInfo.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ReaderQryDlg.h : header file
//


/////////////////////////////////////////////////////////////////////////////
// CReaderQryDlg dialog

class CReaderQryDlg : public CDialog
{
// Construction
public:
	CReaderDataSet m_ReaderSet;
	CReaderBorrowInfo m_BorrowInfo;
	void AddExStyle(DWORD dwNewStyle);
	CReaderQryDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CReaderQryDlg)
	enum { IDD = IDD_DLGREADERQRY };
	CListCtrl	m_lstBook;
	CString	m_strReaderID;
	CString	m_strReaderName;
	CString	m_strReaderIDCard;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReaderQryDlg)
	public:
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CReaderQryDlg)
	afx_msg void OnQuery();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_READERQRYDLG_H__07FBBD90_0C66_4F2A_ADC0_529630B11D16__INCLUDED_)
