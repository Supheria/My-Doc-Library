//{{AFX_INCLUDES()
#include "rdc.h"
#include "ReaderDataSet.h"
#include "msdgridctrl.h"
//}}AFX_INCLUDES
#if !defined(AFX_READERQRY_H__B83CA228_A73B_437F_9797_9E14DA65D26E__INCLUDED_)
#define AFX_READERQRY_H__B83CA228_A73B_437F_9797_9E14DA65D26E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ReaderQry.h : header file
//

#include "ReaderDataSet.h"

/////////////////////////////////////////////////////////////////////////////
// CReaderQry dialog

class CReaderQry : public CDialog
{
// Construction
public:
	CReaderDataSet m_ReaderSet;
	CReaderQry(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CReaderQry)
	enum { IDD = IDD_DIALOGQRY };
	CString	m_ReaderID;
	CString	m_Name;
	CString	m_ID_Card;
	CRdc	m_RemoteDataCTL;
	CMsDgridCtrl	m_DbgridCTL;
	//}}AFX_DATA
  

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReaderQry)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CReaderQry)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_READERQRY_H__B83CA228_A73B_437F_9797_9E14DA65D26E__INCLUDED_)
