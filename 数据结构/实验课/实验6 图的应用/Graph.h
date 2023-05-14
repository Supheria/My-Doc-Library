//
//created by David on 2019/11/26
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
    	virtual void Init() = 0;
    	
    	// 返回节点数
	    virtual int n() = 0;
	    
	    //设置标记 
	    virtual void setsxmark(int, bool) = 0;
	    virtual void setnxmark(int, bool) = 0;
};

#endif
