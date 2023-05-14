
// TreeTestDlg.h : 头文件
//

#pragma once
#include "BinaryTree.h"


// CTreeTestDlg 对话框
class CTreeTestDlg : public CDialogEx
{
// 构造
public:
	CTreeTestDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_TREETEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
    afx_msg void OnTimer(UINT_PTR nIDEvent);
    afx_msg void OnBnClickedBuild();
    afx_msg void OnBnClickedPretrav();
    afx_msg void OnBnClickedIntrav();
    afx_msg void OnBnClickedPostrav();
    afx_msg void OnBnClickedLeveltrav();
    afx_msg void OnBnClickedSearch();
    afx_msg void OnBnClickedAdd();
    afx_msg void OnBnClickedRemove();
    afx_msg void OnMirror();
    afx_msg void OnQuit();
	DECLARE_MESSAGE_MAP()

private:
    // 绘制缓冲区
    void paintBuffer();
    // 绘制全部图形
    void paintGraph(Graphics& graphics);

private:
    virtual void OnOK();

private:
    Binary_Tree<TCHAR> m_tree;
    std::vector<DrawNode> m_snapshoot;
};
