//
//created by David on 2019/12/10
//

#ifndef GRAPH_H
#define GRAPH_H

class Graph{
	private :
		// 拷贝函数
		void operator = (const Graph &) {}
		
		Graph(const Graph &) {}
		
	public :
		// 构造函数
		Graph() {}
		
		//析构函数
    	virtual ~Graph() {}
    	
    	// 初始化函数
    	virtual void init(int) = 0;
    	
    	// 返回节点数
	    virtual int n() = 0;
	
	    // 返回边数
	    virtual int e() = 0;
	
};

#endif
