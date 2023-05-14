#include <iostream>
#include"BinTree.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
template<typename E>
void printNode(BinNode<E>*tmp)//��ӡ����ֵ�ĺ���
{
	cout << tmp->getValue() << " ";
}
template<typename E>
BinNode<E>* creatBinaryTree(string post[],int postStart,int postEnd,string in[],int inStart,int inEnd) //���ݺ��б��������������� 
{
	if(postStart>postEnd||inStart>inEnd)
	return NULL;
	
	BinNode<E>*node=new BinNode<E>(post[postEnd]); 
	for(int i=inStart;i<=inEnd;i++)
	{
		if(in[i]==post[postEnd])
		{
			node->setLeft(creatBinaryTree<E>(post,postStart,postEnd-inEnd+i-1,in,inStart,i-1)); //���Ĳ��裬�ݹ鴴�����Ĺؼ������� 
			node->setRight(creatBinaryTree<E>(post,postEnd+i-inEnd,postEnd-1,in,i+1,inEnd));
			break;
		}
	}
	return node;
}


void creatBinaryTree(BinTree<string>*BT)//�����������ĺ���������������Ĺ������������������������������������м��һЩ������
{

	int n=0;

	cin>>n;
	string *pre=new string[n];
	string *in=new string[n];
	for(int i=0;i<n;i++)
	cin>>pre[i];
	for(int i=0;i<n;i++)
	cin>>in[i];
	BT->setRoot(creatBinaryTree<string>(pre,0,n-1,in,0,n-1));
}


int main() {
	BinTree<string>*BT = new BinTree<string>;
	creatBinaryTree(BT);
	BT->LevelOrderTranverse(BT->getRoot(),printNode);
	return 0;
}
