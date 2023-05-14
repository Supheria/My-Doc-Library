#include<iostream>
#include<queue>
#include<vector>
#include "Graph.h"
#include "Graphl.h"
using namespace std;
int main(){
	Graphm<int> *mmp = new Graphm<int>;
	int N = 0, M = 0, sum = 0;
	int va = 0, vb = 0;
	cin >> N >> M;
	for(int i = 0; i < M; i++) {
		cin >> va >> vb;
		mmp->sx[va].push_back(vb);
		mmp->nx[vb].push_back(va);
	}
	
	for(int i = 1; i <= N; i ++) {
		queue<int> q;
		mmp->Init();
		q.push(i);
		mmp->setsxmark(i, true);
		mmp->runsx(mmp, q);
		q.push(i);
		mmp->setnxmark(i, true);
		mmp->runnx(mmp, q);
		
		int cnt = 0;
		for(int j = 1; j <= N; j ++) {
			if(mmp->v_sx[j] || mmp->v_nx[j]) cnt ++;
		}
		if(cnt == N) sum ++;
	}
	cout << sum;
	return 0;
}
//4 4
//1 2
//1 3
//2 4
//3 4
