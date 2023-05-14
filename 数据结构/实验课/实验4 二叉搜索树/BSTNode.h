/*
created by David on 2019.10.29
*/
#ifndef _BSTNODE_H
#define _BSTNODE_H

#include "BinNode.h"
#include <iostream>

template<typename E>
class BSTNode : public BinNode<E> {
	private:
		E element;
		BSTNode *lc;
		BSTNode *rc;
		void clear(BSTNode *root){
			if(root == NULL) return;
			clear(root->lc);
			lc = NULL;
			clear(root->rc);
			rc = NULL;
			delete root;
		}
	public:
		BSTNode() {lc = rc = NULL;}
		
		~BSTNode() {clear(this);}
		
		BSTNode(E elem, BSTNode *l = NULL, BSTNode *r = NULL) {
			element = elem;
			lc = l;rc = r;
		}
		
		E &getelem() {return element;}
		
		void setelem(const E &elem) {element = elem;}
		
		inline BSTNode *left() const {return lc;}
		
		inline BSTNode *right() const {return rc;}
		
		void setleft(BSTNode<E> *b) {lc = (BSTNode *) b;}
		
		void setright(BSTNode<E> *b) {rc = (BSTNode *) b;}
		
		bool isLeaf() {return (lc == NULL && rc == NULL);}	
};
#endif
