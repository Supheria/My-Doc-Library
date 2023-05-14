
// TreeTestDlg.cpp : 实现文件
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


// CTreeTestDlg 对话框




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


// CTreeTestDlg 消息处理程序

BOOL CTreeTestDlg::OnInitDialog() {
    CDialogEx::OnInitDialog();

    CMenu* pSysMenu = GetSystemMenu(FALSE);
    if (pSysMenu != nullptr) {
        CString strAboutMenu;
        if (!strAboutMenu.IsEmpty()) {
            pSysMenu->AppendMenu(MF_SEPARATOR);
        }
    }

    // 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
    //  执行此操作
    SetIcon(m_hIcon, TRUE);			// 设置大图标
    SetIcon(m_hIcon, FALSE);		// 设置小图标

    // TODO: 在此添加额外的初始化代码
    CString s0 = L"ABD##EF###C#GH##I##";
    GetDlgItem(IDC_EDIT_TREE)->SetWindowTextW(s0);

    RECT rect;
    GetDlgItem(IDC_STATIC_PIC)->GetWindowRect(&rect);
    m_tree.setWidth(rect.right - rect.left);

    ((CButton*)GetDlgItem(IDC_RADIO_LEFT))->SetCheck(TRUE);

    SetTimer(1, 200, NULL);
    return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CTreeTestDlg::OnPaint() {
    if (IsIconic()) {
        CPaintDC dc(this); // 用于绘制的设备上下文

        SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

        // 使图标在工作区矩形中居中
        int cxIcon = GetSystemMetrics(SM_CXICON);
        int cyIcon = GetSystemMetrics(SM_CYICON);
        CRect rect;
        GetClientRect(&rect);
        int x = (rect.Width() - cxIcon + 1) / 2;
        int y = (rect.Height() - cyIcon + 1) / 2;

        // 绘制图标
        dc.DrawIcon(x, y, m_hIcon);
    } else {
        paintBuffer();
        CDialogEx::OnPaint();
    }
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CTreeTestDlg::OnQueryDragIcon() {
    return static_cast<HCURSOR>(m_hIcon);
}

void CTreeTestDlg::OnTimer(UINT_PTR nIDEvent) {
    m_snapshoot = m_tree.getSnapshoot();
    paintBuffer();
    CDialogEx::OnTimer(nIDEvent);
}

void CTreeTestDlg::OnBnClickedBuild() {
    //获取输入信息
    CString s0;
    GetDlgItem(IDC_EDIT_TREE)->GetWindowTextW(s0);
    TCHAR* p = (TCHAR*)s0.GetBuffer(0);

    m_tree.creat_Binary_Tree(p, '#');
}

void CTreeTestDlg::OnMirror() {
    //获取输入信息
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
    //先序遍历
    CString s1 = m_tree.pretrav_Binary_Tree();
    GetDlgItem(IDC_EDIT_PRETRAV)->SetWindowTextW(s1);
}

void CTreeTestDlg::OnBnClickedIntrav() {
    //中序遍历
    CString s2 = m_tree.intrav_Binary_Tree();
    GetDlgItem(IDC_EDIT_INTRAV)->SetWindowTextW(s2);
}

void CTreeTestDlg::OnBnClickedPostrav() {
    //后序遍历
    CString s3 = m_tree.postrav_Binary_Tree();
    GetDlgItem(IDC_EDIT_POSTRAV)->SetWindowTextW(s3);
}

void CTreeTestDlg::OnBnClickedLeveltrav() {
    //按层遍历
    CString s4 = m_tree.broacast_Binary_Tree();
    GetDlgItem(IDC_EDIT_LEVELTRAV)->SetWindowTextW(s4);
}

void CTreeTestDlg::OnBnClickedSearch() {
    CString name;
    GetDlgItemText(IDC_EDIT_SEARCH, name);
    name.Trim();
    if (name.IsEmpty()) {
        AfxMessageBox(L"请输入要查找的节点名称");
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
        AfxMessageBox(L"请输入要添加的节点名称");
        return;
    }

    CString parent;
    GetDlgItemText(IDC_EDIT_ADD_PARENT, parent);
    parent.Trim();
    if (parent.IsEmpty()) {
        AfxMessageBox(L"请输入要添加的所属父节点名称");
        return;
    }

    int mode = 1;
    if (((CButton*)GetDlgItem(IDC_RADIO_RIGHT))->GetCheck()) {
        mode = 2;
    }

    if (!m_tree.add(name.GetBuffer()[0], parent.GetBuffer()[0], mode)) {
        AfxMessageBox(L"添加失败");
    }
}


void CTreeTestDlg::OnBnClickedRemove() {
    CString name;
    GetDlgItemText(IDC_EDIT_REMOVE, name);
    name.Trim();
    if (name.IsEmpty()) {
        AfxMessageBox(L"请输入要删除的节点名称");
        return;
    }
    if (!m_tree.remove(name.GetBuffer()[0])) {
        AfxMessageBox(L"删除失败，没有找到要删除的节点");
    }
}

void CTreeTestDlg::paintBuffer() {
    //获取需要绘图的控件窗口
    CWnd* wnd = GetDlgItem(IDC_STATIC_PIC);
    //获取控件窗口的DC
    CDC* dc = wnd->GetDC();

    CRect rect;
    //得到控件的客户区大小
    wnd->GetClientRect(&rect);

    //创建一个缓冲DC（双缓冲加速绘图效果）
    CDC memdc;
    //将缓冲DC设置成与窗口DC兼容模式
    memdc.CreateCompatibleDC(dc);

    //设置一个缓存位图
    CBitmap bitmap;
    bitmap.CreateCompatibleBitmap(dc, rect.Width(), rect.Height());
    memdc.SelectObject(&bitmap);

    //使用GDI+绘图
    Graphics graphics(memdc.GetSafeHdc());
    //提高绘制质量
    graphics.SetSmoothingMode(SmoothingModeAntiAlias);
    graphics.SetCompositingQuality(CompositingQualityHighQuality);
    graphics.SetTextRenderingHint(TextRenderingHintAntiAliasGridFit);

    SolidBrush bgcolor(Color(0xf0, 0xf8, 0xff));
    //绘制背景色
    graphics.FillRectangle(&bgcolor, rect.left, rect.top, rect.Width(), rect.Height());
    paintGraph(graphics);
    graphics.ReleaseHDC(memdc.GetSafeHdc());

    //将缓冲DC数据写入窗口DC
    dc->BitBlt(0, 0, rect.Width(), rect.Height(), &memdc, 0, 0, SRCCOPY);
    //使控件失效重绘
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
