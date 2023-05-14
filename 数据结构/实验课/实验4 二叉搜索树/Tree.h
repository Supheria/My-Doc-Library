/*
created by David on 2019.10.29
*/
#ifndef _TREE_H
#define _TREE_H

#include <cmath>
#include <queue>
#include <algorithm>
#include <iostream>
#include "BSTNode.h"
using namespace std;

template<typename E>
void CreatTree(BSTNode<E> *T, E que[], int len) {
	if(len <= 0) return;
	E n;
	int k = ceil(log(len+1) / log(2));

	int le = pow(2,k) - 1 - len;
	if(le > pow(2,k-2)){//左边不为满完全二叉树 
		le =  len - pow(2,k-2); 
		n = que[le]; 
	} else {
		le = pow(2,k-1) - 1;
		n = que[le];
	}
	
	T->setelem(n);
	//cout << T->getelem() << ' ';
	T->setleft(new BSTNode<E>);
	CreatTree(T->left(),que,le);
	T->setright(new BSTNode<E>);
	CreatTree(T->right(),que+le+1,len-le-1);
}

template<typename E>
void floororder(BSTNode<E> *T) {
	queue< BSTNode<E>* > q;
	BSTNode<E> *it = new BSTNode<E>;
	q.push(T);
	while(q.size() != 0){
		it = q.front();
		
		
		if(it->left() != NULL) q.push(it->left());
		if(it->right()!= NULL) q.push(it->right());
		if(!it->isLeaf()){
			cout << it->getelem() << ' ';
		}
		q.pop();
	}
}

template<typename E>
void preorder(BSTNode<E> *T) {
	if(T->isLeaf()) return;
	cout << T->getelem() << ' ';
	preorder(T->left());
	preorder(T->right());
}

template<typename E>
int count(BSTNode<E> *T, int sum) {
	if(T == NULL) return sum;
	sum++;
	sum += count(T->left(),0);
	sum += count(T->right(),0);
	return sum;
}

template<typename E>
int deep(BSTNode<E> *T, int sum) {
	if(T == NULL) return sum;
	return max(deep(T->left(), sum), deep(T->right(), sum)) + 1;
}

#endif
