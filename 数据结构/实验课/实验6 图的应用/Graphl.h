//
// Created by David on 2019/11/26.
//

#ifndef COMMIT_GRAPHL_H
#define COMMIT_GRAPHL_H

#include <algorithm>
#include <iostream>
#include<cstring>
#include <vector>
#include "Graph.h"
using namespace std;

const int N = 1000 + 10;
template<class T>
class Graphm : public Graph {
	public:
		int Max;
		vector<int> sx[N];
		vector<int> nx[N];
		bool v_sx[N];
		bool v_nx[N];
		
		Graphm() {}
		
		~Graphm() {
			delete[]v_sx;
			delete[]v_nx;
		}
		
		void Init() {
			memset(v_sx, false, sizeof(v_sx));
			memset(v_nx, false, sizeof(v_nx));
		}
		
		int n() {
			return Max;
		}
		
		void setsxmark(int a = 0, bool b = true) {
			v_sx[a] = b;
		}
		
		void setnxmark(int a = 0, bool b = true) {
			v_nx[a] = b;
		}
		
		void runsx(Graphm<T> *grap, queue<int> &q) {
			while(!q.empty()) {
				int u = q.front();
				q.pop();
				int l = grap->sx[u].size();
				for(int j = 0; j < l; j ++) {
					if(!grap->v_sx[grap->sx[u][j]]) {
						grap->v_sx[grap->sx[u][j]] = true;
						q.push(grap->sx[u][j]);
					}
				}
			}
		}
		
		void runnx(Graphm<T> *grap, queue<int> &q) {
			while(!q.empty()) {
				int u = q.front();
				q.pop();
				int l = grap->nx[u].size();
				for(int j = 0; j < l; j ++) {
					if(!grap->v_nx[grap->nx[u][j]]) {
						grap->v_nx[grap->nx[u][j]] = true;
						q.push(grap->nx[u][j]);
					}
				}
			}
		}
};
#endif //COMMIT_GRAPHM_H

