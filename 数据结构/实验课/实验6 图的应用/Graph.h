//
//created by David on 2019/11/26
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
    	virtual void Init() = 0;
    	
    	// ���ؽڵ���
	    virtual int n() = 0;
	    
	    //���ñ�� 
	    virtual void setsxmark(int, bool) = 0;
	    virtual void setnxmark(int, bool) = 0;
};

#endif
