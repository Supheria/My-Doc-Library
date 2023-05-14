/*
created by David on 2019.10.20
*/
#ifndef _TREE_H
#define _TREE_H

#include <queue>
#include <algorithm>
#include <iostream>
#include "BSTNode.h"
using namespace std;

template<typename E>
void CreatTree(BSTNode<E> *T, E mid[], E pos[], int len) {
	if(len == 0) return;
	E n = pos[len-1];
	int index = 0;
	for(;index<len;index++){
		if(mid[index] == n) break;
	}
	T->setelem(n);
	//cout << T->getelem() << ' ';
	T->setleft(new BSTNode<E>);
	CreatTree(T->left(),mid,pos,index);
	T->setright(new BSTNode<E>);
	CreatTree(T->right(),mid+index+1,pos+index,len-index-1);
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
