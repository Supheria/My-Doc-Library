#include "Graph.h"
#include "Graphl.h"
using namespace std;
int main(){
	Graphm<int> *mmp = new Graphm<int>;
	int m = 0, n = 0, wt = 0;
	int va, vb, tp;
	cin >> n >> m;
	mmp->init(n);
	mmp->getmap(m);
	cout << mmp->djk(0, n-1);
	return 0;
}
//6 7
//1 1 2 3
//0 2 3 2
//0 1 3 30
//0 3 4 20
//0 4 5 30
//1 3 5 6
//0 5 6 1
