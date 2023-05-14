//
// Created by David on 2019/11/26.
//

#ifndef COMMIT_GRAPHL_H
#define COMMIT_GRAPHL_H

#include <algorithm>
#include <iostream>
#include <string.h>
#include<cstring>
#include <vector>
#include <map>
#include "Graph.h"

using namespace std;

const int MAX_SIZE = 100;
const int UNVISITED = 0;
const int VISIT = 1;

class Edge {
public:
    int vert;
	int wt;

    Edge() {
        vert = -1;
        wt = -1;
    }

    Edge(int v, int w) {
        vert = v;
        wt = w;
    }

    int vertex() {
        return vert;
    }

    int weight() {
        return wt;
    }
};

template<class T>
class Graphm : public Graph {
    // 节点和边的数目
    int numVertex;
	int numEdge;
    // 存储节点内容
    map<T, int> vertex1;
    map<int, T> vertex2;
    // 存储边
    vector< vector<Edge> > vertex;
    // 对节点进行标记
    int *mark;
public:
	int *sum;
    Graphm(int numVert = MAX_SIZE) {
        Init(numVert);
    }

    ~Graphm() {
        delete[]mark;
        delete[]sum;
    }

    void Init(int n) {
        numVertex = n;
        numEdge = 0;
        sum = new int[n];
        mark = new int[n];
        for (int i = 0; i < numVertex; ++i) {
            mark[i] = UNVISITED;
            sum[i] = UNVISITED;
        }
        numVertex = 0;
    }

    void setPoint(T v) {
        vertex.push_back(vector<Edge>());
        pair<T, int> temp = make_pair(v, numVertex);
        vertex1.insert(temp);
        vertex2.insert(make_pair(numVertex, v));
        numVertex++;
    }

    int n() {
        return numVertex;
    }

    int e() {
        return numEdge;
    }

    int first(int v) {
        if (vertex[v].size() == 0) {
            return numVertex;
        }
        Edge it = vertex[v][0];
        return it.vertex();
    }

    int next(int v, int w) {
        Edge it;
        for (int i = 0; i < vertex[v].size(); ++i) {
            if (i < vertex[v].size() - 1 && mark[vertex[v][i + 1].vertex()] == UNVISITED) {
                return vertex[v][i + 1].vertex();
            }
        }
        return numVertex;
    }

    pair<T, int> val(T v = NULL, int x = -1) {
        if (vertex1.find(v) != vertex1.end() && x == -1) {
            return make_pair(v, vertex1[v]);
        } else {
            return make_pair(vertex2[x], x);
        }
    }

    void setEdge(int v1, int v2, int wght) {
        try {
            if (wght <= 0) {
                throw "Illegal weight value";
            }
            int it1 = isEdge(v1, v2);
            //int it2 = isEdge(v2, v1);
            if (it1 != numVertex) {
                vertex[v1][it1].vert = wght;
                //vertex[v2][it2].vert = wght;
            } else {
                Edge temp1(v2, wght);
                //Edge temp2(v1, wght);
                vertex[v1].push_back(temp1);
                //vertex[v2].push_back(temp2);
                numEdge++;
            }
        } catch (const char *str) {
            std::cerr << str << std::endl;
        }
    }

    void delEdge(int v1, int v2) {
        int it = isEdge(v1, v2);
        if (it != numEdge) {
            vertex[v1].erase(vertex[v1].begin() + it);
            numEdge--;
        }
    }

    int isEdge(int v1, int v2) {
        for (int i = 0; i < vertex[v1].size(); ++i) {
            if (vertex[v1][i].vertex() == v2) {
                return i;
            }
        }
        return numVertex;
    }

    int weight(int v1, int v2) {
        int it = isEdge(v1, v2);
        if (it == numVertex) {
            return -1;
        } else {
            return vertex[v1][it].vertex();
        }
    }

    int getMark(int v) {
        return mark[v];
    }

    void setMark(int v, int val) {
        mark[v] = val;
    }

    void print() {
    	map<int, int> vertex3;
    	int s[numVertex];
    	int sum = 0;
    	memset(s,0,sizeof(s));
        for (int i = 0; i < vertex.size(); ++i) {
            for (int j = 0; j < vertex.size(); ++j) {
                if(isEdge(i, j) != numVertex) {
                	s[i] ++;
                	cout << "1 ";
				} else {
					cout << "0 ";
				}
            }
            cout << endl;
            if(vertex3.find(s[i]) == vertex3.end()){
            	vertex3.insert(make_pair(s[i], vertex2[i]));
			} else {
				vertex3.erase(s[i]);
				vertex3.insert(make_pair(s[i], vertex2[i]));
			}
            
        }
        map<int, int>::iterator it = vertex3.begin();
        while(it != vertex3.end()){
        	it ++;
        	sum ++;
		}
		it --;
		cout << it->second << " " << it->first << endl; 
    }
    
	void DFS(Graphm<T> *graphm, int v) {
	    graphm->setMark(v, VISIT);
	    sum[v] = VISIT;
	    for (int i = graphm->first(v); i < graphm->n(); i = graphm->next(v, i)) {
	        if (graphm->getMark(i) == UNVISITED) {
	        	//sum[v] = VISIT;
	            //cout << graphm->val(NULL, v).first << " " << graphm->val(NULL, i).first << endl;
	            DFS(graphm, i);
	        }
	    }
	}
	
	void graphTraverse(Graphm<T> *graphm) {
	    for (int i = 0; i < graphm->n(); ++i) {
	        graphm->setMark(i, UNVISITED);
	    }
	    for (int i = 0; i < graphm->n(); ++i) {
	        if (graphm->getMark(i) == UNVISITED) {
	            DFS(graphm, i);
	        }
	    }
	}
	
	void resetsum() {
		memset(sum,UNVISITED,sizeof(sum));
	}
};
#endif //COMMIT_GRAPHM_H

