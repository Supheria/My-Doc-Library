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
    	virtual void Init(int) = 0;
    	
    	// 返回节点数
	    virtual int n() = 0;
	
	    // 返回边数
	    virtual int e() = 0;
	    
	    // 返回第一个相邻节点
	    virtual int first(int) = 0;
	
	    // 返回下一个节点
	    virtual int next(int, int) = 0;
	
	    // 设置边
	    virtual void setEdge(int, int, int) = 0;
	
	    // 删除边
	    virtual void delEdge(int, int) = 0;
	
	    // 返回两点之间是否有边
	    virtual int isEdge(int, int) = 0;
	
	    // 返回边的权重
	    virtual int weight(int, int) = 0;
	
	    // 获取是否标记
	    virtual int getMark(int) = 0;
	
	    // 设置标记
	    virtual void setMark(int, int) = 0;
};

#endif
