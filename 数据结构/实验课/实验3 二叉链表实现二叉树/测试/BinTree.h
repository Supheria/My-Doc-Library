#include"BinNode.h"
#include<iostream>
#include<queue> 

template <typename E>
class BinTree
{
private:
	BinNode<E>* root;
public:
	BinTree()//Ĭ�Ϲ��캯��
	{
		root=new BinNode<E>;
	}
	void setRoot(BinNode<E>*r)//���ø��ڵ�
	{
		root = r;
	}
	BinNode<E>* getRoot()
	{
		return root;
	}
	void clear(BinNode<E>*r)//��� 
	{
		if(r==NULL)
		return;
		if(r->left()!=NULL)
		clear(r->left());
		if(r->right()!=NULL)
		clear(r->right());
		
		delete r;
		r=NULL;	
	}
	~BinTree()
	{
		clear(root);
	 } 
	
void preOrder(BinNode<E>*tmp,void(*visit)(BinNode<E>*node))//���������void(*visit)(BinNode<E>*node)Ϊһ������ָ���������visit���洫�����ĺ������ڱ���������ʹ�ô������ĺ�������
	{
		if (tmp == NULL)
			return;
		visit(tmp);
		preOrder(tmp->left(),visit);
		preOrder(tmp->right(),visit);
	}

	void inOrder( BinNode<E>*tmp,void(*visit)(BinNode<E>*node))
	//���������void(*visit)(BinNode<E>*node)Ϊһ������ָ�������
	//��visit���洫�����ĺ������ڱ���������ʹ�ô������ĺ�������
	{
		if (tmp == NULL)
			return;
		inOrder(tmp->left(),visit);
		visit(tmp);
		inOrder(tmp->right(),visit);
	}
	void postOrder(BinNode<E>*tmp,void(*visit)(BinNode<E>*node))
	//���������void(*visit)(BinNode<E>*node)Ϊһ������ָ�������
	//��visit���洫�����ĺ������ڱ���������ʹ�ô������ĺ�������
	{
		if (tmp == NULL)
			return;
		postOrder(tmp->left(),visit);
		postOrder(tmp->right(),visit);
		visit(tmp);
	}
	
	void LevelOrderTranverse( BinNode<E>*tmp,void(*visit)(BinNode<E>*node))
	//��α�����void(*visit)(BinNode<E>*node)Ϊһ������ָ�������
	//��visit���洫�����ĺ������ڱ���������ʹ�ô������ĺ�������
	{
		if (tmp == NULL)
			return;
		queue<BinNode<E>*>que;
		que.push(tmp);
		BinNode<E>* curr;
		while (que.empty() != true)
		{
			curr = que.front();
			if (curr->left() != NULL)
			{
				que.push(curr->left());
			}
			if (curr->right() != NULL)
			{
				que.push(curr->right());
			}
			que.pop();
			visit(curr);
		}
	}


	
};
