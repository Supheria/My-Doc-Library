/*
created by David on 2019.10.20
*/
#include "Tree.h"
#include "BSTNode.h"
#include "BinNode.h"
#include <iostream>

int main(){
	int a=0;
	//cout << "请输入二叉树的节点数：" << endl;
	cin >> a;
	int pos[a];
	int mid[a];
	//cout << "请输入后序遍历结果：" << endl;
	for(int i=0;i<a;i++) cin >> pos[i];
	//cout << "请输入中序遍历结果：" << endl;
	for(int i=0;i<a;i++) cin >> mid[i];
	
	BSTNode<int> *T = new BSTNode<int>;
	CreatTree(T,mid,pos,a);
//	preorder(T);
//	cout << endl;
	floororder(T);
	return 0;
}
//7
//2 3 1 5 7 6 4
//1 2 3 4 5 6 7
