#ifndef LIST
#define LIST
template<typename E> class List {// List ADT �����������Ͷ��壨�������飩 
private:
	void operator =(const List&){}
	List(const List&){}
public:
	List(){}
	~List(){}
	void clear();//����б�
	void append(const E& item);//�ڱ�β���Ԫ��item 
	void remove();//ɾ������Ԫ��
	void reset();//���ø��ַ�����
	E current();//���ص�ǰԪ�� 
	int E_word();//�����б�ǰ��Ӣ��Ԫ�ظ���
	int N_word();//�����б�ǰ������Ԫ�ظ���
	int O_word();//�����б�ǰ������Ԫ�ظ���
	int size();//�����б��С 
	int cha();//������С��ֵ 
};
#endif
