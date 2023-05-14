#include "Graph.h"
#include "Graphl.h"
using namespace std;
int main(){
	Graphm<char> *mmp = new Graphm<char>;
	int m = 0, n = 0, wt = 0;
	char va, vb;
	cin >> n >> m;
	char a[n];//n¸ö¶¥µã
	for(int i = 0;i < n;i ++) {
		cin >> a[i];
		mmp->setPoint(a[i]);
	}
	for(int i = 0;i < m;i ++) {
		cin >> va >> vb >> wt;
		mmp->setEdge(mmp->val(va).second, mmp->val(vb).second, wt);
	}
	mmp->print();
	return 0;
}
//4 3 
//A B C D
//A B 1  
//B C 1
//B D 1
//3 5
//A B C
//A B 1
//B A 1
//B C 1
//C A 1
//C B 1 
