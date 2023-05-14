#include<iostream>
using namespace std;

#ifndef BINNODE_H
#define BINNODE_H 
template <typename E>
class BinNode      //��������� 
{
private:
		BinNode *Left;
		BinNode *Right;
		E elem;
public:
	   
	    BinNode()//Ĭ�Ϲ��캯�� 
		{
			Left=NULL;
			Right=NULL;
			}
		BinNode(E x,BinNode *l=NULL,BinNode *r=NULL) //���캯�� ,=NULL������ 
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
		
		E getValue()  //����ֵ 
		{
			return elem;
		}
		
		bool isLeaf() //�ж��Ƿ�ΪҶ�ڵ� 
		{
			if(Right==Left)
			return true;
			
			else return false;
			
		}
};
#endif

