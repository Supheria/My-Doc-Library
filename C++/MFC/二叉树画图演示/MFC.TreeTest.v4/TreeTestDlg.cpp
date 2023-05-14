
// TreeTestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"

#define _HEHE

#include "TreeTest.h"
#include "TreeTestDlg.h"
#include "afxdialogex.h"
#include "resource.h"

//#include "BinaryTree.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTreeTestDlg �Ի���




CTreeTestDlg::CTreeTestDlg(CWnd* pParent /*=NULL*/)
    : CDialogEx(CTreeTestDlg::IDD, pParent) {
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTreeTestDlg::DoDataExchange(CDataExchange* pDX) {
    CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTreeTestDlg, CDialogEx)
    ON_WM_PAINT()
    ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_BUILD, &CTreeTestDlg::OnBnClickedBuild)
    ON_BN_CLICKED(IDC_PRETRAV, &CTreeTestDlg::OnBnClickedPretrav)
    ON_BN_CLICKED(IDC_INTRAV, &CTreeTestDlg::OnBnClickedIntrav)
    ON_BN_CLICKED(IDC_POSTRAV, &CTreeTestDlg::OnBnClickedPostrav)
    ON_BN_CLICKED(IDC_LEVELTRAV, &CTreeTestDlg::OnBnClickedLeveltrav)
    ON_COMMAND(IDM_MIRROR, &CTreeTestDlg::OnMirror)
    ON_COMMAND(IDM_QUIT, &CTreeTestDlg::OnQuit)
    ON_WM_TIMER()
    ON_BN_CLICKED(IDC_SEARCH, &CTreeTestDlg::OnBnClickedSearch)
    ON_BN_CLICKED(IDC_ADD, &CTreeTestDlg::OnBnClickedAdd)
    ON_BN_CLICKED(IDC_REMOVE, &CTreeTestDlg::OnBnClickedRemove)
END_MESSAGE_MAP()


// CTreeTestDlg ��Ϣ�������

BOOL CTreeTestDlg::OnInitDialog() {
    CDialogEx::OnInitDialog();

    CMenu* pSysMenu = GetSystemMenu(FALSE);
    if (pSysMenu != nullptr) {
        CString strAboutMenu;
        if (!strAboutMenu.IsEmpty()) {
            pSysMenu->AppendMenu(MF_SEPARATOR);
        }
    }

    // ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
    //  ִ�д˲���
    SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
    SetIcon(m_hIcon, FALSE);		// ����Сͼ��

    // TODO: �ڴ���Ӷ���ĳ�ʼ������
    CString s0 = L"ABD##EF###C#GH##I##";
    GetDlgItem(IDC_EDIT_TREE)->SetWindowTextW(s0);

    RECT rect;
    GetDlgItem(IDC_STATIC_PIC)->GetWindowRect(&rect);
    m_tree.setWidth(rect.right - rect.left);

    ((CButton*)GetDlgItem(IDC_RADIO_LEFT))->SetCheck(TRUE);

    SetTimer(1, 200, NULL);
    return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CTreeTestDlg::OnPaint() {
    if (IsIconic()) {
        CPaintDC dc(this); // ���ڻ��Ƶ��豸������

        SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

        // ʹͼ���ڹ����������о���
        int cxIcon = GetSystemMetrics(SM_CXICON);
        int cyIcon = GetSystemMetrics(SM_CYICON);
        CRect rect;
        GetClientRect(&rect);
        int x = (rect.Width() - cxIcon + 1) / 2;
        int y = (rect.Height() - cyIcon + 1) / 2;

        // ����ͼ��
        dc.DrawIcon(x, y, m_hIcon);
    } else {
        paintBuffer();
        CDialogEx::OnPaint();
    }
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CTreeTestDlg::OnQueryDragIcon() {
    return static_cast<HCURSOR>(m_hIcon);
}

void CTreeTestDlg::OnTimer(UINT_PTR nIDEvent) {
    m_snapshoot = m_tree.getSnapshoot();
    paintBuffer();
    CDialogEx::OnTimer(nIDEvent);
}

void CTreeTestDlg::OnBnClickedBuild() {
    //��ȡ������Ϣ
    CString s0;
    GetDlgItem(IDC_EDIT_TREE)->GetWindowTextW(s0);
    TCHAR* p = (TCHAR*)s0.GetBuffer(0);

    m_tree.creat_Binary_Tree(p, '#');
}

void CTreeTestDlg::OnMirror() {
    //��ȡ������Ϣ
    CString s0;
    GetDlgItem(IDC_EDIT_TREE)->GetWindowTextW(s0);
    TCHAR* p = (TCHAR*)s0.GetBuffer(0);

    m_tree.creat_Binary_Tree(p, '#');
    m_tree.mirror_Binary_Tree();
}

void CTreeTestDlg::OnQuit() {
    CDialogEx::OnCancel();
}

void CTreeTestDlg::OnBnClickedPretrav() {
    //�������
    CString s1 = m_tree.pretrav_Binary_Tree();
    GetDlgItem(IDC_EDIT_PRETRAV)->SetWindowTextW(s1);
}

void CTreeTestDlg::OnBnClickedIntrav() {
    //�������
    CString s2 = m_tree.intrav_Binary_Tree();
    GetDlgItem(IDC_EDIT_INTRAV)->SetWindowTextW(s2);
}

void CTreeTestDlg::OnBnClickedPostrav() {
    //�������
    CString s3 = m_tree.postrav_Binary_Tree();
    GetDlgItem(IDC_EDIT_POSTRAV)->SetWindowTextW(s3);
}

void CTreeTestDlg::OnBnClickedLeveltrav() {
    //�������
    CString s4 = m_tree.broacast_Binary_Tree();
    GetDlgItem(IDC_EDIT_LEVELTRAV)->SetWindowTextW(s4);
}

void CTreeTestDlg::OnBnClickedSearch() {
    CString name;
    GetDlgItemText(IDC_EDIT_SEARCH, name);
    name.Trim();
    if (name.IsEmpty()) {
        AfxMessageBox(L"������Ҫ���ҵĽڵ�����");
        return;
    }

    Btnode<TCHAR>* target = m_tree.search(name.GetBuffer()[0]);
    if (target) {
        if (name.GetBuffer()[0] == target->d) {
            CString left = L"NULL";
            CString right = L"NULL";

            if (target->lchild) {
                left = target->lchild->d;
            }

            if (target->rchild) {
                right = target->rchild->d;
            }

            CString str;
            str.Format(L"[ROOT] : %c [Left] : %s [Right] : %s", target->d, left, right);
            SetDlgItemText(IDC_EDIT_SEARCH_RESULT, str);
        }
        else if (target->lchild && name.GetBuffer()[0] == target->lchild->d) {
            CString parent = L"NULL";
            CString left = L"NULL";
            CString right = L"NULL";

            parent = target->d;

            target = target->lchild;
            if (target->lchild) {
                left = target->lchild->d;
            }

            if (target->rchild) {
                right = target->rchild->d;
            }

            CString str;
            str.Format(L"[Parent] : %s [Left] : %s [Right] : %s", parent, left, right);
            SetDlgItemText(IDC_EDIT_SEARCH_RESULT, str);
        }
        else if (target->rchild && name.GetBuffer()[0] == target->rchild->d) {
            CString parent = L"NULL";
            CString left = L"NULL";
            CString right = L"NULL";

            parent = target->d;

            target = target->rchild;
            if (target->lchild) {
                left = target->lchild->d;
            }

            if (target->rchild) {
                right = target->rchild->d;
            }

            CString str;
            str.Format(L"[Parent] : %s [Left] : %s [Right] : %s", parent, left, right);
            SetDlgItemText(IDC_EDIT_SEARCH_RESULT, str);
        }
    } else {
        SetDlgItemText(IDC_EDIT_SEARCH_RESULT, L"NOT FOUND!");
    }
}


void CTreeTestDlg::OnBnClickedAdd() {
    CString name;
    GetDlgItemText(IDC_EDIT_ADD_NODE, name);
    name.Trim();
    if (name.IsEmpty()) {
        AfxMessageBox(L"������Ҫ��ӵĽڵ�����");
        return;
    }

    CString parent;
    GetDlgItemText(IDC_EDIT_ADD_PARENT, parent);
    parent.Trim();
    if (parent.IsEmpty()) {
        AfxMessageBox(L"������Ҫ��ӵ��������ڵ�����");
        return;
    }

    int mode = 1;
    if (((CButton*)GetDlgItem(IDC_RADIO_RIGHT))->GetCheck()) {
        mode = 2;
    }

    if (!m_tree.add(name.GetBuffer()[0], parent.GetBuffer()[0], mode)) {
        AfxMessageBox(L"���ʧ��");
    }
}


void CTreeTestDlg::OnBnClickedRemove() {
    CString name;
    GetDlgItemText(IDC_EDIT_REMOVE, name);
    name.Trim();
    if (name.IsEmpty()) {
        AfxMessageBox(L"������Ҫɾ���Ľڵ�����");
        return;
    }
    if (!m_tree.remove(name.GetBuffer()[0])) {
        AfxMessageBox(L"ɾ��ʧ�ܣ�û���ҵ�Ҫɾ���Ľڵ�");
    }
}

void CTreeTestDlg::paintBuffer() {
    //��ȡ��Ҫ��ͼ�Ŀؼ�����
    CWnd* wnd = GetDlgItem(IDC_STATIC_PIC);
    //��ȡ�ؼ����ڵ�DC
    CDC* dc = wnd->GetDC();

    CRect rect;
    //�õ��ؼ��Ŀͻ�����С
    wnd->GetClientRect(&rect);

    //����һ������DC��˫������ٻ�ͼЧ����
    CDC memdc;
    //������DC���ó��봰��DC����ģʽ
    memdc.CreateCompatibleDC(dc);

    //����һ������λͼ
    CBitmap bitmap;
    bitmap.CreateCompatibleBitmap(dc, rect.Width(), rect.Height());
    memdc.SelectObject(&bitmap);

    //ʹ��GDI+��ͼ
    Graphics graphics(memdc.GetSafeHdc());
    //��߻�������
    graphics.SetSmoothingMode(SmoothingModeAntiAlias);
    graphics.SetCompositingQuality(CompositingQualityHighQuality);
    graphics.SetTextRenderingHint(TextRenderingHintAntiAliasGridFit);

    SolidBrush bgcolor(Color(0xf0, 0xf8, 0xff));
    //���Ʊ���ɫ
    graphics.FillRectangle(&bgcolor, rect.left, rect.top, rect.Width(), rect.Height());
    paintGraph(graphics);
    graphics.ReleaseHDC(memdc.GetSafeHdc());

    //������DC����д�봰��DC
    dc->BitBlt(0, 0, rect.Width(), rect.Height(), &memdc, 0, 0, SRCCOPY);
    //ʹ�ؼ�ʧЧ�ػ�
    wnd->Invalidate();
    wnd->UpdateWindow();
}

void CTreeTestDlg::paintGraph(Graphics& graphics) {
    Gdiplus::Pen pen(Color::Red, 2);
    Gdiplus::SolidBrush brush(Color::Orange);
    Gdiplus::SolidBrush shadowbrush(Color::Gray);
    Gdiplus::SolidBrush selectedbrush(Color::Red);
    Gdiplus::SolidBrush stringbrush(Color::White);
    Gdiplus::SolidBrush infobrush(Color::Black);
    Gdiplus::PointF point(10, 10);

    Gdiplus::Font font(L"Arial", 16, FontStyleRegular);
    Gdiplus::Font infofont(L"Arial", 14, FontStyleRegular);
    StringFormat stringformat;
    stringformat.SetLineAlignment(StringAlignment::StringAlignmentCenter);
    stringformat.SetAlignment(StringAlignment::StringAlignmentCenter);

    CString info;
    info.Format(L"[TREE INFO]\n"
                L"Node Count: %d\n"
                L"Leaf Count: %d\n"
                L"Max Breadth: %d\n"
                L"Depth: %d\n"
                , m_tree.count
                , m_tree.leaf
                , m_tree.breadth
                , m_tree.depth);
    graphics.DrawString(info, info.GetLength(), &infofont, point, &infobrush);

    int scale = 35;
    int offset = 160;
    for (std::vector<DrawNode>::iterator iter = m_snapshoot.begin(); iter != m_snapshoot.end(); ++iter) {
        int x = (iter->left + iter->right) / 2;
        int y = iter->deep * scale + offset;
        int half = scale / 2;

        if (iter->lchild) {
            int l = iter->left;
            int r = (iter->left + iter->right) / 2;
            int cx = (l + r) / 2;
            int cy = (iter->deep + 1) * scale + offset;
            graphics.DrawLine(&pen, x, y, cx, cy);
        }
        if (iter->rchild) {
            int l = (iter->left + iter->right) / 2;
            int r = iter->right;
            int cx = (l + r) / 2;
            int cy = (iter->deep + 1) * scale + offset;
            graphics.DrawLine(&pen, x, y, cx, cy);
        }

        CString txt;
        txt.Format(TEXT("%c"), iter->ch);

        if (iter->selected) {
            graphics.FillEllipse(&selectedbrush, x - half + 4, y - half + 4, scale, scale);
            Gdiplus::RectF rect(x - half + 4, y - half + 4, scale, scale);
            graphics.DrawString(txt, txt.GetLength(), &font, rect, &stringformat, &stringbrush);
        } else {
            graphics.FillEllipse(&shadowbrush, x - half + 4, y - half + 4, scale, scale);
            graphics.FillEllipse(&brush, x - half, y - half, scale, scale);
            Gdiplus::RectF rect(x - half, y - half, scale, scale);
            graphics.DrawString(txt, txt.GetLength(), &font, rect, &stringformat, &stringbrush);
        }
    }
}

void CTreeTestDlg::OnOK() {

}
