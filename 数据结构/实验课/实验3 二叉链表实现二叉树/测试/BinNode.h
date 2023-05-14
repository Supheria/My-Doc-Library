#include<iostream>
using namespace std;

#ifndef BINNODE_H
#define BINNODE_H 
template <typename E>
class BinNode      //构建结点类 
{
private:
		BinNode *Left;
		BinNode *Right;
		E elem;
public:
	   
	    BinNode()//默认构造函数 
		{
			Left=NULL;
			Right=NULL;
			}
		BinNode(E x,BinNode *l=NULL,BinNode *r=NULL) //构造函数 ,=NULL不可少 
		{
			elem=x;
			Left=l;
			Right=r;
			}		
		BinNode*left()
		{
			return Left;
		}
		BinNode*right()
		{
			return Right;
		}
		
		void setLeft(BinNode*l)
		{
			Left=l;
		}
		void setRight(BinNode*r)
		{
			Right=r;
		}
		void setValue(E x)
		{
			elem=x;
		}
		
		E getValue()  //返回值 
		{
			return elem;
		}
		
		bool isLeaf() //判断是否为叶节点 
		{
			if(Right==Left)
			return true;
			
			else return false;
			
		}
};
#endif

