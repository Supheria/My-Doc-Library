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
	list<int>::iterator it;//������
	list<int> l;//���������������ɵ������
	int begin = 0, end = 999999;//���ַ�Χ
	int sum = 100;//���������
	ofstream output;
	output.open(".\\1000000.txt", ios::trunc);
	while (l.size() < sum) {
		l.push_back(rand() % (end - begin + 1) + begin);
		//l.sort();//����
		l.unique();//ȥ�����ڵ��ظ�������еĵ�һ��
	}
	for (it = l.begin(); it != l.end(); it++){
		output << *it << " ";
	}
	return 0;
}
