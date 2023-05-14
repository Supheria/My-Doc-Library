#include"BinNode.h"
#include<iostream>
#include<queue> 

template <typename E>
class BinTree
{
private:
	BinNode<E>* root;
public:
	BinTree()//默认构造函数
	{
		root=new BinNode<E>;
	}
	void setRoot(BinNode<E>*r)//设置根节点
	{
		root = r;
	}
	BinNode<E>* getRoot()
	{
		return root;
	}
	void clear(BinNode<E>*r)//清除 
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
	
void preOrder(BinNode<E>*tmp,void(*visit)(BinNode<E>*node))//先序遍历，void(*visit)(BinNode<E>*node)为一个函数指针参数，用visit代替传进来的函数，在遍历函数中使用传进来的函数功能
	{
		if (tmp == NULL)
			return;
		visit(tmp);
		preOrder(tmp->left(),visit);
		preOrder(tmp->right(),visit);
	}

	void inOrder( BinNode<E>*tmp,void(*visit)(BinNode<E>*node))
	//中序遍历，void(*visit)(BinNode<E>*node)为一个函数指针参数，
	//用visit代替传进来的函数，在遍历函数中使用传进来的函数功能
	{
		if (tmp == NULL)
			return;
		inOrder(tmp->left(),visit);
		visit(tmp);
		inOrder(tmp->right(),visit);
	}
	void postOrder(BinNode<E>*tmp,void(*visit)(BinNode<E>*node))
	//后序遍历，void(*visit)(BinNode<E>*node)为一个函数指针参数，
	//用visit代替传进来的函数，在遍历函数中使用传进来的函数功能
	{
		if (tmp == NULL)
			return;
		postOrder(tmp->left(),visit);
		postOrder(tmp->right(),visit);
		visit(tmp);
	}
	
	void LevelOrderTranverse( BinNode<E>*tmp,void(*visit)(BinNode<E>*node))
	//层次遍历，void(*visit)(BinNode<E>*node)为一个函数指针参数，
	//用visit代替传进来的函数，在遍历函数中使用传进来的函数功能
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
