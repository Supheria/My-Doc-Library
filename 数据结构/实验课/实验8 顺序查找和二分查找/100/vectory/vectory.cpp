#include <iostream> 
#include <stdlib.h> 
#include <time.h>
#include <list>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
	srand((unsigned)time(NULL));
	list<int>::iterator it;//迭代器
	list<int> l;//定义链表，保存生成的随机数
	int begin = 0, end = 999999;//数字范围
	int sum = 100;//随机数个数
	ofstream output;
	output.open(".\\1000000.txt", ios::trunc);
	while (l.size() < sum) {
		l.push_back(rand() % (end - begin + 1) + begin);
		//l.sort();//排序
		l.unique();//去除相邻的重复随机数中的第一个
	}
	for (it = l.begin(); it != l.end(); it++){
		output << *it << " ";
	}
	return 0;
}
