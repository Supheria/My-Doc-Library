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
    // �ڵ�ͱߵ���Ŀ
    int numVertex;
	int numEdge;
	int vis[maxn];
	int dis[maxn];
    // �洢�ڵ�����
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
	            if(i == j) mp[i][j] = 0;//��ʼ����
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

    void getmap(int m){//��ͼ 
	    int t,u,v,val;
	    for(int i = 0;i<m;i++){
	        cin >>t>>u>>v>>val ;
	        u--,v--;//��0��ʼ�� 
	        if(t==1)mp[u][v] = val*val,mp[v][u] = val*val;//����ͼ
	        else mp[u][v] = val,mp[v][u] = val;//����ͼ
	    } 
	}
    
    int djk(int st, int en){
	    memset(vis,0,sizeof(vis));
	    vis[st] = 1;
	    for(int i = 0;i < n(); i++) dis[i] = mp[st][i];
	    for(int i = 1;i < n(); i++){//ÿһ�ζ���һ�θ��� 
	        int mn = INF,id = -1;
	        for(int j = 0;j < n();j++){//�ҵ���st����ĵ� 
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

