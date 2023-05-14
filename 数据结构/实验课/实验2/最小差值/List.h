#ifndef LIST
#define LIST
template<typename E> class List {// List ADT 抽象数据类型定义（基于数组） 
private:
	void operator =(const List&){}
	List(const List&){}
public:
	List(){}
	~List(){}
	void clear();//清空列表
	void append(const E& item);//在表尾添加元素item 
	void remove();//删除数字元素
	void reset();//重置各字符数量
	E current();//返回当前元素 
	int E_word();//返回列表当前的英文元素个数
	int N_word();//返回列表当前的数字元素个数
	int O_word();//返回列表当前的其他元素个数
	int size();//返回列表大小 
	int cha();//计算最小差值 
};
#endif
