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
    	virtual void Init(int) = 0;
    	
    	// ���ؽڵ���
	    virtual int n() = 0;
	
	    // ���ر���
	    virtual int e() = 0;
	    
	    // ���ص�һ�����ڽڵ�
	    virtual int first(int) = 0;
	
	    // ������һ���ڵ�
	    virtual int next(int, int) = 0;
	
	    // ���ñ�
	    virtual void setEdge(int, int, int) = 0;
	
	    // ɾ����
	    virtual void delEdge(int, int) = 0;
	
	    // ��������֮���Ƿ��б�
	    virtual int isEdge(int, int) = 0;
	
	    // ���رߵ�Ȩ��
	    virtual int weight(int, int) = 0;
	
	    // ��ȡ�Ƿ���
	    virtual int getMark(int) = 0;
	
	    // ���ñ��
	    virtual void setMark(int, int) = 0;
};

#endif
