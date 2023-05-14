#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include "Graph.h"
#include "Graphl.h"
using namespace std;
const int N=1000+10;
vector<int> g[N],g0[N];
bool vis[N],vis0[N];
int n,m;
int main(){
	Graphm<int> *mmp = new Graphm<int>;
	Graphm<int> *emm = new Graphm<int>;
	int N = 0, M = 0, sum = 0;
	int va = 0, vb = 0, wt = 1;
	//cin >> N >> M;
	for(int i = 1;i <= N;i ++) {
		mmp->setPoint(i);
		emm->setPoint(i);
	}
	for(int i = 0;i < M;i ++) {
		cin >> va >> vb;
		mmp->setEdge(mmp->val(va).second, mmp->val(vb).second, wt);
		emm->setEdge(emm->val(vb).second, emm->val(va).second, wt);
	}
	int cns = 0, ant = 0;
	
	while(cns < N) {
		mmp->DFS(mmp,cns);
		emm->DFS(emm,cns);
		
		for(int i = 0;i <= N;i ++) {
			if(mmp->sum[i] == 1 || emm->sum[i] == 1) cns++;
		}
		if(cns == N) ant++;
		
		mmp->resetsum();
		emm->resetsum();
		for (int i = 0; i < mmp->n(); ++i) {
		    mmp->setMark(i, 0);
		    emm->setMark(i, 0);
		}
		cns++;
	}
	////
	int a = 0, b = 0, ans = 0;
	cin >> n >> m;
	for(int i=0;i<m;i++) {
		cin >> a >> b;
		g[a].push_back(b);
		g0[b].push_back(a);
	}
	for(int k = 1;k <= n;k ++) {
		memset(vis,false,sizeof(vis));
		memset(vis0,false,sizeof(vis0));
		queue<int> q;
		q.push(k);
		vis[k] = true;
		while(!q.empty())
		{
			int u = q.front();
			q.pop();
			int l = g[u].size();
			for(int i = 0;i < l;i ++)
			{
				if(!vis[g[u][i]])
				{
					vis[g[u][i]] = true;
					q.push(g[u][i]);
				}
			}
		}
		q.push(k);
		vis0[k] = true;
		while(!q.empty())
		{
			int u = q.front();
			q.pop();
			int l = g0[u].size();
			for(int i = 0;i < l;i ++)
			{
				if(!vis0[g0[u][i]])
				{
					vis0[g0[u][i]] = true;
					q.push(g0[u][i]);
				}
			}
		}
		int cnt = 0;
		for(int i = 1;i <= n;i ++)
		if(vis[i] || vis0[i]) cnt++;
		if(cnt == n) ans++;
	}
	cout << ans;
	return 0;
}
//4 4
//1 2
//1 3
//2 4
//3 4
























//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include<cmath>
//#include<queue>
//#include<vector>
//using namespace std;
//const int N=1000+10;
//vector<int> g[N],g0[N];
//bool vis[N],vis0[N];
//int n,m;
//int main()
//{
//	int a = 0, b = 0, ans = 0;
//	cin >> n >> m;
//	for(int i=0;i<m;i++) {
//		cin >> a >> b;
//		g[a].push_back(b);
//		g0[b].push_back(a);
//	}
//	for(int k = 1;k <= n;k ++) {
//		memset(vis,false,sizeof(vis));
//		memset(vis0,false,sizeof(vis0));
//		queue<int> q;
//		q.push(k);
//		vis[k] = true;
//		while(!q.empty())
//		{
//			int u = q.front();
//			q.pop();
//			int l = g[u].size();
//			for(int i = 0;i < l;i ++)
//			{
//				if(!vis[g[u][i]])
//				{
//					vis[g[u][i]] = true;
//					q.push(g[u][i]);
//				}
//			}
//		}
//		q.push(k);
//		vis0[k] = true;
//		while(!q.empty())
//		{
//			int u = q.front();
//			q.pop();
//			int l = g0[u].size();
//			for(int i = 0;i < l;i ++)
//			{
//				if(!vis0[g0[u][i]])
//				{
//					vis0[g0[u][i]] = true;
//					q.push(g0[u][i]);
//				}
//			}
//		}
//		int cnt = 0;
//		for(int i = 1;i <= n;i ++)
//		if(vis[i] || vis0[i]) cnt++;
//		if(cnt == n) ans++;
//	}
//	cout << ans;
//	return 0;
//}











