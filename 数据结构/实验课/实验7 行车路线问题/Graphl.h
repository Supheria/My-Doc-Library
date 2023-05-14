//
// Created by David on 2019/12/10.
//

#ifndef COMMIT_GRAPHL_H
#define COMMIT_GRAPHL_H

#include <iostream>
#include <string.h>
#include <vector>
#include <map>
#include "Graph.h"

using namespace std;

const int MAX_SIZE = 100;
const int UNVISITED = 0;
const int VISIT = 1;
const int INF = 0x3f3f3f3f;
const int maxn = (int)1000 + 10;


template<class T>
class Graphm : public Graph {
    // 节点和边的数目
    int numVertex;
	int numEdge;
	int vis[maxn];
	int dis[maxn];
    // 存储节点内容
    int mp[10][10];
public:
    Graphm() {}

    ~Graphm() {
        delete[]mp;
    }

    void init(int n){
    	numVertex = n;
	    for(int i = 0;i<n;i++){
	        for(int j =0;j<n;j++){
	            if(i == j) mp[i][j] = 0;//初始化环
	            else mp[i][j] = INF; 
	        }
	    }
	}

    int n() {
        return numVertex;
    }

    int e() {
        return numEdge;
    }

    void getmap(int m){//建图 
	    int t,u,v,val;
	    for(int i = 0;i<m;i++){
	        cin >>t>>u>>v>>val ;
	        u--,v--;//从0开始的 
	        if(t==1)mp[u][v] = val*val,mp[v][u] = val*val;//无向图
	        else mp[u][v] = val,mp[v][u] = val;//无向图
	    } 
	}
    
    int djk(int st, int en){
	    memset(vis,0,sizeof(vis));
	    vis[st] = 1;
	    for(int i = 0;i < n(); i++) dis[i] = mp[st][i];
	    for(int i = 1;i < n(); i++){//每一次都有一次更新 
	        int mn = INF,id = -1;
	        for(int j = 0;j < n();j++){//找到离st最近的点 
	            if(dis[j] < mn && !vis[j]){
	                mn = dis[j],id = j;
	            }
	        }
	            if(id == -1) break;     
	            vis[id] = 1;
	            for(int j = 0;j < n();j++){
	                if(!vis[j] && mp[id][j] != INF){
	                    if(dis[j] > dis[id] + mp[id][j])
	                        dis[j] = dis[id] + mp[id][j];
	                }
	            }
	    }
	    return dis[en];
	}

};
#endif //COMMIT_GRAPHM_H

