// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__4333C38E_6066_4779_AE0B_906E3847A4A4__INCLUDED_)
#define AFX_MAINFRM_H__4333C38E_6066_4779_AE0B_906E3847A4A4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ChildView.h"

class CMainFrame : public CFrameWnd
{
	
public:
	CMainFrame();
protected: 
	DECLARE_DYNAMIC(CMainFrame)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	CString m_strUserID;
	CString m_strUserName;
	BOOL m_bLogin;
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;
	CReBar      m_wndReBar;
	CDialogBar      m_wndDlgBar;
	CChildView    m_wndView;

// Generated message map functions
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSetFocus(CWnd *pOldWnd);
	afx_msg void OnLoginIn();
	afx_msg void OnUpdateFine(CCmdUI* pCmdUI);
	afx_msg void OnUpdateBookMaintain(CCmdUI* pCmdUI);
	afx_msg void OnUpdateConfigMaintain(CCmdUI* pCmdUI);
	afx_msg void OnUpdateLendOut(CCmdUI* pCmdUI);
	afx_msg void OnUpdateLoginOut(CCmdUI* pCmdUI);
	afx_msg void OnUpdateReaderMaintain(CCmdUI* pCmdUI);
	afx_msg void OnUpdateReturnBack(CCmdUI* pCmdUI);
	afx_msg void OnUpdateUserMaintain(CCmdUI* pCmdUI);
	afx_msg void OnLoginOut();
	afx_msg void OnReaderMaintain();
	afx_msg void OnUserMaintain();
	afx_msg void OnBookMaintain();
	afx_msg void OnLendOut();
	afx_msg void OnFine();
	afx_msg void OnReturnBack();
	afx_msg void OnReaderQry();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__4333C38E_6066_4779_AE0B_906E3847A4A4__INCLUDED_)
