
// TreeTestDlg.h : ͷ�ļ�
//

#pragma once
#include "BinaryTree.h"


// CTreeTestDlg �Ի���
class CTreeTestDlg : public CDialogEx
{
// ����
public:
	CTreeTestDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_TREETEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
    // ���ƻ�����
    void paintBuffer();
    // ����ȫ��ͼ��
    void paintGraph(Graphics& graphics);

private:
    virtual void OnOK();

private:
    Binary_Tree<TCHAR> m_tree;
    std::vector<DrawNode> m_snapshoot;
};
