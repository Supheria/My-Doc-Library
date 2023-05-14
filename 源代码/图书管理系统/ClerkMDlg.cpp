// ClerkMDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Library.h"
#include "ClerkMDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClerkMDlg dialog


CClerkMDlg::CClerkMDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CClerkMDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CClerkMDlg)
	m_strUserNameQ = _T("");
	m_strUserName = _T("");
	m_strUserIDQ = _T("");
	m_strUserID = _T("");
	m_strPassword = _T("");
	m_strIDCard = _T("");
	//}}AFX_DATA_INIT
}


void CClerkMDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CClerkMDlg)
	DDX_Control(pDX, IDC_POSITION, m_cntrPosition);
	DDX_Text(pDX, IDC_USERNAME_Q, m_strUserNameQ);
	DDV_MaxChars(pDX, m_strUserNameQ, 8);
	DDX_Text(pDX, IDC_USERNAME, m_strUserName);
	DDV_MaxChars(pDX, m_strUserName, 8);
	DDX_Text(pDX, IDC_USERID_Q, m_strUserIDQ);
	DDV_MaxChars(pDX, m_strUserIDQ, 8);
	DDX_Text(pDX, IDC_USERID, m_strUserID);
	DDV_MaxChars(pDX, m_strUserID, 8);
	DDX_Text(pDX, IDC_PASSWORD, m_strPassword);
	DDV_MaxChars(pDX, m_strPassword, 8);
	DDX_Text(pDX, IDC_IDCARD, m_strIDCard);
	DDV_MaxChars(pDX, m_strIDCard, 18);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CClerkMDlg, CDialog)
	//{{AFX_MSG_MAP(CClerkMDlg)
	ON_BN_CLICKED(IDC_CANCEL_REC, OnCancelRec)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	ON_BN_CLICKED(IDC_EDIT, OnEdit)
	ON_BN_CLICKED(IDC_ENQUERY, OnEnquery)
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	ON_BN_CLICKED(IDC_FIRST, OnFirst)
	ON_BN_CLICKED(IDC_LAST, OnLast)
	ON_BN_CLICKED(IDC_NEW, OnNew)
	ON_BN_CLICKED(IDC_NEXT, OnNext)
	ON_BN_CLICKED(IDC_PRIOR, OnPrior)
	ON_BN_CLICKED(IDC_SAVE, OnSave)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClerkMDlg message handlers

void CClerkMDlg::OnCancelRec() 
{
	// TODO: Add your control notification handler code here
	m_bAdd = FALSE;
	m_bEdit = FALSE;
	DisplayRecord();
	SetButtonState();

	SetTextState();
	
}

void CClerkMDlg::OnDelete() 
{
	// TODO: Add your control notification handler code here
	m_rsDataSet.Delete();
	DisplayRecord();
	SetButtonState();
	
}

void CClerkMDlg::OnEdit() 
{
	// TODO: Add your control notification handler code here
	m_bEdit = TRUE;
	SetButtonState();
	SetTextState();
	CWnd *pWnd;
	pWnd = GetDlgItem(IDC_USERNAME);
	pWnd->SetFocus();
	
}

void CClerkMDlg::OnEnquery() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (m_strUserIDQ.IsEmpty() && m_strUserNameQ.IsEmpty())
	{
		m_rsDataSet.m_strFilter = "";
		m_rsDataSet.Requery();
		DisplayRecord();
		SetButtonState();
		return;
	}
	BOOL mAll = FALSE;
	if (!m_strUserIDQ.IsEmpty())
	{
		m_rsDataSet.m_strFilter = "CLERK_ID='" + m_strUserIDQ ;
		m_rsDataSet.m_strFilter = m_rsDataSet.m_strFilter + "'";
		mAll = TRUE;
	}
	if (!m_strUserNameQ.IsEmpty())
	{
		if (mAll)
		{
			m_rsDataSet.m_strFilter = m_rsDataSet.m_strFilter + " AND NAME='";
			m_rsDataSet.m_strFilter = m_rsDataSet.m_strFilter + m_strUserNameQ;
			m_rsDataSet.m_strFilter = m_rsDataSet.m_strFilter + "'";
		}
		else
		{
			m_rsDataSet.m_strFilter = "NAME='"  + m_strUserNameQ;
			m_rsDataSet.m_strFilter = m_rsDataSet.m_strFilter + "'";
		}
			
	}
	m_rsDataSet.Requery();
	DisplayRecord();
	SetButtonState();

	
}

void CClerkMDlg::OnExit() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
	
}

void CClerkMDlg::OnFirst() 
{
	// TODO: Add your control notification handler code here
	if(!m_rsDataSet.IsBOF())
	{
		m_rsDataSet.MoveFirst();
		DisplayRecord();
		SetButtonState();
	}
	
}

void CClerkMDlg::OnLast() 
{
	// TODO: Add your control notification handler code here
	if(!m_rsDataSet.IsEOF())
	{
		m_rsDataSet.MoveLast();
		DisplayRecord();
		SetButtonState();
	}
	
}

void CClerkMDlg::OnNew() 
{
	// TODO: Add your control notification handler code here
	m_strUserID = "";
	m_strUserName = "";
	m_strIDCard = "";
	m_strPassword = "";
//	m_cntrPosition.
	UpdateData(FALSE);
	m_bEdit = TRUE;
	m_bAdd = TRUE;
	SetButtonState();
	SetTextState();
	CWnd *pWnd;
	pWnd = GetDlgItem(IDC_USERID);
	pWnd->SetFocus();
	
}

void CClerkMDlg::OnNext() 
{
	// TODO: Add your control notification handler code here
	if(!m_rsDataSet.IsEOF())
	{
		m_rsDataSet.MoveNext();
		DisplayRecord();
		SetButtonState();
	}
	
}

void CClerkMDlg::OnPrior() 
{
	// TODO: Add your control notification handler code here
	if(!m_rsDataSet.IsBOF())
	{
		m_rsDataSet.MovePrev();
		DisplayRecord();
		SetButtonState();
	}
	
}

void CClerkMDlg::OnSave() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (m_strIDCard.IsEmpty() || m_strUserName.IsEmpty() || m_strUserID.IsEmpty())
	{
		AfxMessageBox("请输入相应数据！");
		return;
	}
	if (m_bAdd)
	{
		m_rsDataSet.AddNew();

	}
	else
	{
		m_rsDataSet.Edit();
	}
	m_rsDataSet.m_ID_CARD = m_strIDCard;
	m_rsDataSet.m_NAME = m_strUserName;
	m_rsDataSet.m_CLERK_ID = m_strUserID;
	m_rsDataSet.m_PASSWORD = m_strPassword;

//	m_rsDataSet.m_FLAG_BORROW  = "Y";
	m_rsDataSet.Update();
	m_rsDataSet.Requery();
	m_bAdd = FALSE;
	m_bEdit = FALSE;
	DisplayRecord();
	SetButtonState();
	SetTextState();
	
}

BOOL CClerkMDlg::DisplayRecord()
{
	if (m_rsDataSet.IsEOF() && m_rsDataSet.IsBOF())	
	{
		m_strUserID = "";
		m_strUserName = "";
		m_strIDCard = "";
		m_strPassword = "";
		m_cntrPosition.SelectString(1,"");
	}
	else
	{
		if (m_rsDataSet.IsBOF())
		{
			m_rsDataSet.MoveNext();
		}
		else
		{	
			if (m_rsDataSet.IsEOF())
			{		
				m_rsDataSet.MovePrev();
			}
		}
		m_strUserID = m_rsDataSet.m_CLERK_ID;
		m_strUserName = m_rsDataSet.m_NAME;
		m_strIDCard = m_rsDataSet.m_ID_CARD;
		m_strPassword = m_rsDataSet.m_PASSWORD ;
		m_cntrPosition.SelectString(1,m_rsDataSet.m_OFFICIER);
	}
	UpdateData(FALSE);
	return TRUE;

}

BOOL CClerkMDlg::SetTextState()
{
	CWnd *pWnd;

	if (m_bEdit)
	{
		pWnd = GetDlgItem(IDC_USERNAME);
		pWnd->EnableWindow(TRUE);
		pWnd = GetDlgItem(IDC_USERID);
		if (m_bAdd)
			pWnd->EnableWindow(TRUE);
		else
			pWnd->EnableWindow(FALSE);
		pWnd = GetDlgItem(IDC_IDCARD);
		pWnd->EnableWindow(TRUE);
		pWnd = GetDlgItem(IDC_PASSWORD);
		pWnd->EnableWindow(TRUE);
		pWnd = GetDlgItem(IDC_POSITION);
		pWnd->EnableWindow(TRUE);

	}
	else
	{
		pWnd = GetDlgItem(IDC_USERNAME);
		pWnd->EnableWindow(FALSE);
		pWnd = GetDlgItem(IDC_USERID);
		pWnd->EnableWindow(FALSE);
		pWnd = GetDlgItem(IDC_IDCARD);
		pWnd->EnableWindow(FALSE);
		pWnd = GetDlgItem(IDC_PASSWORD);
		pWnd->EnableWindow(FALSE);
		pWnd = GetDlgItem(IDC_POSITION);
		pWnd->EnableWindow(FALSE);
	}
	pWnd = GetDlgItem(IDC_USERNAME_Q);
	pWnd->EnableWindow(TRUE);
	pWnd = GetDlgItem(IDC_USERID_Q);
	pWnd->EnableWindow(TRUE);
	return TRUE;

}

BOOL CClerkMDlg::SetButtonState()
{
	CWnd *pWnd;

	if(!m_rsDataSet.IsOpen())
	{
		pWnd = GetDlgItem(IDC_FIRST);
		pWnd->EnableWindow(FALSE);
		pWnd = GetDlgItem(IDC_NEXT);
		pWnd->EnableWindow(FALSE);
		pWnd = GetDlgItem(IDC_PRIOR);
		pWnd->EnableWindow(FALSE);
		pWnd = GetDlgItem(IDC_LAST);
		pWnd->EnableWindow(FALSE);
		
		pWnd = GetDlgItem(IDC_NEW);
		pWnd->EnableWindow(FALSE);
		pWnd = GetDlgItem(IDC_EDIT);
		pWnd->EnableWindow(FALSE);
		pWnd = GetDlgItem(IDC_ENQUERY);
		pWnd->EnableWindow(FALSE);
		pWnd = GetDlgItem(IDC_DELETE);
		pWnd->EnableWindow(FALSE);
		pWnd = GetDlgItem(IDC_SAVE);
		pWnd->EnableWindow(FALSE);
		pWnd = GetDlgItem(IDC_CANCEL_REC);
		pWnd->EnableWindow(FALSE);
		

		return TRUE;
	}


	if (m_bEdit)
	{
		pWnd = GetDlgItem(IDC_FIRST);
		pWnd->EnableWindow(FALSE);
		pWnd = GetDlgItem(IDC_NEXT);
		pWnd->EnableWindow(FALSE);
		pWnd = GetDlgItem(IDC_PRIOR);
		pWnd->EnableWindow(FALSE);
		pWnd = GetDlgItem(IDC_LAST);
		pWnd->EnableWindow(FALSE);

		pWnd = GetDlgItem(IDC_NEW);
		pWnd->EnableWindow(FALSE);
		pWnd = GetDlgItem(IDC_EDIT);
		pWnd->EnableWindow(FALSE);
		pWnd = GetDlgItem(IDC_ENQUERY);
		pWnd->EnableWindow(FALSE);
		pWnd = GetDlgItem(IDC_DELETE);
		pWnd->EnableWindow(FALSE);
		pWnd = GetDlgItem(IDC_SAVE);
		pWnd->EnableWindow(TRUE);
		pWnd = GetDlgItem(IDC_CANCEL_REC);
		pWnd->EnableWindow(TRUE);

		return TRUE;

	}


	if (m_rsDataSet.IsBOF())
	{
		pWnd = GetDlgItem(IDC_FIRST);
		pWnd->EnableWindow(FALSE);
		pWnd = GetDlgItem(IDC_PRIOR);
		pWnd->EnableWindow(FALSE);
	}
	else
	{
		pWnd = GetDlgItem(IDC_FIRST);
		pWnd->EnableWindow(TRUE);
		pWnd = GetDlgItem(IDC_PRIOR);
		pWnd->EnableWindow(TRUE);
	}

	if (m_rsDataSet.IsEOF())
	{
		pWnd = GetDlgItem(IDC_NEXT);
		pWnd->EnableWindow(FALSE);
		pWnd = GetDlgItem(IDC_LAST);
		pWnd->EnableWindow(FALSE);
	}
	else
	{
		pWnd = GetDlgItem(IDC_NEXT);
		pWnd->EnableWindow(TRUE);
		pWnd = GetDlgItem(IDC_LAST);
		pWnd->EnableWindow(TRUE);

	}
	if (m_rsDataSet.IsBOF() && m_rsDataSet.IsEOF())
	{
		pWnd = GetDlgItem(IDC_EDIT);
		pWnd->EnableWindow(FALSE);
		pWnd = GetDlgItem(IDC_DELETE);
		pWnd->EnableWindow(FALSE);

	}
	else
	{
		pWnd = GetDlgItem(IDC_EDIT);
		pWnd->EnableWindow(TRUE);
		pWnd = GetDlgItem(IDC_DELETE);
		pWnd->EnableWindow(TRUE);

	}

	pWnd = GetDlgItem(IDC_NEW);
	pWnd->EnableWindow(TRUE);
	pWnd = GetDlgItem(IDC_ENQUERY);
	pWnd->EnableWindow(TRUE);
	pWnd = GetDlgItem(IDC_SAVE);
	pWnd->EnableWindow(FALSE);
	pWnd = GetDlgItem(IDC_CANCEL_REC);
	pWnd->EnableWindow(FALSE);

	return TRUE;

}

BOOL CClerkMDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_bAdd = FALSE;
	m_bEdit = FALSE;
	CWnd *pWnd;
	pWnd = GetDlgItem(IDC_POSITION);
	((CComboBox *)pWnd)->AddString("主席");
	((CComboBox *)pWnd)->AddString("经理");
	((CComboBox *)pWnd)->AddString("主任");
	((CComboBox *)pWnd)->AddString("员工");

	if (!m_rsDataSet.Open(AFX_DB_USE_DEFAULT_TYPE))
		AfxMessageBox("数据打开失败！");

	DisplayRecord();
	SetButtonState();
	SetTextState();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
