/*
created by David on 2019.10.29
*/
#include "Tree.h"
#include "BSTNode.h"
#include "BinNode.h"
#include <iostream>
#include <algorithm>

int main(){
	int a=0;
	cin >> a;
	int que[a];
	for(int i=0;i<a;i++) cin >> que[i];
	sort(que,que+a);
	
	BSTNode<int> *T = new BSTNode<int>;
	CreatTree(T,que,a);
	floororder(T);
	return 0;
}
//10
//1 2 3 4 5 6 7 8 9 0

//6 3 8 1 5 7 9 0 2 4
