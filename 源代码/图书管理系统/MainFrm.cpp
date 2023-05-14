// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Library.h"

#include "MainFrm.h"

#include "LoginDlg.h"
#include "ReaderMDlg.h"
#include "ClerkMDlg.h"
#include "BookMDlg.h"

#include "LendOutDlg.h"
#include "FineDlg.h"
#include "ReturnBookDlg.h"

#include "ReaderQryDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_WM_SETFOCUS()
	ON_COMMAND(ID_LOGIN_IN, OnLoginIn)
	ON_UPDATE_COMMAND_UI(ID_FINE, OnUpdateFine)
	ON_UPDATE_COMMAND_UI(ID_BOOK_MAINTAIN, OnUpdateBookMaintain)
	ON_UPDATE_COMMAND_UI(ID_CONFIG_MAINTAIN, OnUpdateConfigMaintain)
	ON_UPDATE_COMMAND_UI(ID_LEND_OUT, OnUpdateLendOut)
	ON_UPDATE_COMMAND_UI(ID_LOGIN_OUT, OnUpdateLoginOut)
	ON_UPDATE_COMMAND_UI(ID_READER_MAINTAIN, OnUpdateReaderMaintain)
	ON_UPDATE_COMMAND_UI(ID_RETURN_BACK, OnUpdateReturnBack)
	ON_UPDATE_COMMAND_UI(ID_USER_MAINTAIN, OnUpdateUserMaintain)
	ON_COMMAND(ID_LOGIN_OUT, OnLoginOut)
	ON_COMMAND(ID_READER_MAINTAIN, OnReaderMaintain)
	ON_COMMAND(ID_USER_MAINTAIN, OnUserMaintain)
	ON_COMMAND(ID_BOOK_MAINTAIN, OnBookMaintain)
	ON_COMMAND(ID_LEND_OUT, OnLendOut)
	ON_COMMAND(ID_FINE, OnFine)
	ON_COMMAND(ID_RETURN_BACK, OnReturnBack)
	ON_COMMAND(ID_ReaderQry, OnReaderQry)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	m_bLogin = FALSE;
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	// create a view to occupy the client area of the frame
	if (!m_wndView.Create(NULL, NULL, AFX_WS_DEFAULT_VIEW,
		CRect(0, 0, 0, 0), this, AFX_IDW_PANE_FIRST, NULL))
	{
		TRACE0("Failed to create view window\n");
		return -1;
	}
	
	if (!m_wndToolBar.CreateEx(this) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}
	if (!m_wndDlgBar.Create(this, IDR_MAINFRAME, 
		CBRS_ALIGN_TOP, AFX_IDW_DIALOGBAR))
	{
		TRACE0("Failed to create dialogbar\n");
		return -1;		// fail to create
	}

	if (!m_wndReBar.Create(this) ||
		!m_wndReBar.AddBar(&m_wndToolBar) ||
		!m_wndReBar.AddBar(&m_wndDlgBar))
	{
		TRACE0("Failed to create rebar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Remove this if you don't want tool tips
	m_wndToolBar.SetBarStyle(m_wndToolBar.GetBarStyle() |
		CBRS_TOOLTIPS | CBRS_FLYBY);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	cs.style = WS_OVERLAPPED | WS_CAPTION | FWS_ADDTOTITLE
		| WS_THICKFRAME | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_MAXIMIZE;

	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	cs.lpszClass = AfxRegisterWndClass(0);
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers
void CMainFrame::OnSetFocus(CWnd* pOldWnd)
{
	// forward focus to the view window
	m_wndView.SetFocus();
}

BOOL CMainFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
	// let the view have first crack at the command
	if (m_wndView.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
		return TRUE;

	// otherwise, do default handling
	return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}


void CMainFrame::OnLoginIn() 
{
	// TODO: Add your command handler code here
	CLoginDlg mDlg;
	if (mDlg.DoModal() == IDOK)
	{
		m_bLogin = TRUE;
		m_strUserName = mDlg.m_strName ;
		m_strUserID = mDlg.m_strUSERID;
	}
	else
	{
		m_bLogin = FALSE;
		m_strUserName = _T("");
		m_strUserID = _T("");
	}
	CString Name;
	Name = "当前用户：" + m_strUserName;
	m_wndStatusBar.SetPaneText(0,Name);
}

void CMainFrame::OnUpdateFine(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_bLogin);
}

void CMainFrame::OnUpdateBookMaintain(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_bLogin);
	
}

void CMainFrame::OnUpdateConfigMaintain(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_bLogin);
	
}

void CMainFrame::OnUpdateLendOut(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_bLogin);
	
}

void CMainFrame::OnUpdateLoginOut(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_bLogin);
	
}

void CMainFrame::OnUpdateReaderMaintain(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_bLogin);
	
}

void CMainFrame::OnUpdateReturnBack(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_bLogin);
	
}

void CMainFrame::OnUpdateUserMaintain(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_bLogin);
	
}

void CMainFrame::OnLoginOut() 
{
	// TODO: Add your command handler code here
	m_bLogin = FALSE;
	m_strUserName = _T("");	
	m_strUserID = _T("");

	CString Name;
	Name = "当前用户：" + m_strUserName;
	m_wndStatusBar.SetPaneText(0,Name);
}

void CMainFrame::OnReaderMaintain() 
{
	// TODO: Add your command handler code here
	CReaderMDlg mDlg;
	mDlg.DoModal();
}

void CMainFrame::OnUserMaintain() 
{
	// TODO: Add your command handler code here
	CClerkMDlg mDlg;
	mDlg.DoModal();
}

void CMainFrame::OnBookMaintain() 
{
	// TODO: Add your command handler code here
	CBookMDlg mDlg;
	mDlg.DoModal();
}

void CMainFrame::OnLendOut() 
{
	// TODO: Add your command handler code here
	CLendOutDlg mDlg;
	mDlg.DoModal();
}

void CMainFrame::OnFine() 
{
	// TODO: Add your command handler code here
	CFineDlg mDlg;
	mDlg.DoModal();
}

void CMainFrame::OnReturnBack() 
{
	CReturnBookDlg  mDlg;
	mDlg.DoModal();
	// TODO: Add your command handler code here
	
}

void CMainFrame::OnReaderQry() 
{
	// TODO: Add your command handler code here
	//CReaderQry mDlg;
	CReaderQryDlg mDlg;
	mDlg.DoModal();
	
}
