//
//created by David on 2019/12/10
//

#ifndef GRAPH_H
#define GRAPH_H

class Graph{
	private :
		// ��������
		void operator = (const Graph &) {}
		
		Graph(const Graph &) {}
		
	public :
		// ���캯��
		Graph() {}
		
		//��������
    	virtual ~Graph() {}
    	
    	// ��ʼ������
    	virtual void init(int) = 0;
    	
    	// ���ؽڵ���
	    virtual int n() = 0;
	
	    // ���ر���
	    virtual int e() = 0;
	
};

#endif
