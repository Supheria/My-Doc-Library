#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;

int search(int *tempA, int len, int x) {//顺序查找，返回查找次数 
	int j = 0;
	for(int i = 0; i < len; i++) if(tempA[i] != x) j++;
	else return j;
}

int find(int a[], int len, int b){
	int left = 0,right = len - 1;
	int c = 0, p = 0;
	while(left < right){
		p++;
		c = (left + right)/2;
		if(b == a[c]) return p;
		else if(b > a[c]) left = c + 1;
		else right = c - 1;
	}
	return p;
}

double aver(double a[], int n) {
	double sum = 0.0;
	for(int i = 0; i < n; i++) sum += a[i];
	return sum/n*1.0;
}
int main() {
	int n = 0;
	cout << "请输入数据规模：" << endl;
	cin >> n;
	int *tempA = new int[n];//原始数据
	int *tempB = new int[n];//对应的成功查找数据 
	int *tempC = new int[n];//对应的失败查找数据 
	
	ifstream input;
	ifstream input1;
	ifstream input2;
	switch (n) {
		case 100 :
			input.open("..\\dataset\\100.txt");
			input1.open("..\\100\\vectory\\100.txt");
			input2.open("..\\100\\defeat\\100.txt");
			break;
		case 1000 :
			input.open("..\\dataset\\1000.txt");
			input1.open("..\\100\\vectory\\1000.txt");
			input2.open("..\\100\\defeat\\1000.txt");
			break;
		case 10000 :
			input.open("..\\dataset\\10000.txt");
			input1.open("..\\100\\vectory\\10000.txt");
			input2.open("..\\100\\defeat\\10000.txt");
			break;
		case 100000 :
			input.open("..\\dataset\\100000.txt");
			input1.open("..\\100\\vectory\\100000.txt");
			input2.open("..\\100\\defeat\\100000.txt");
			break;
		case 1000000 :
			input.open("..\\dataset\\1000000.txt");
			input1.open("..\\100\\vectory\\1000000.txt");
			input2.open("..\\100\\defeat\\1000000.txt");
			break;
	}
	for (int i = 0; i < n; ++i) input >> tempA[i];
	for (int i = 0; i < 100; ++i) input1 >> tempB[i];
	for (int i = 0; i < 100; ++i) input2 >> tempC[i];
	input.close();
	input1.close();
	input2.close();
	
	ofstream output1;
	ofstream output2;
	switch (n) {
		case 100 :
			output1.open("..\\dataout\\find\\100.txt", ios::trunc);
			output2.open("..\\dataout\\search\\100.txt", ios::trunc);
			break;
		case 1000 :
			output1.open("..\\dataout\\find\\1000.txt", ios::trunc);
			output2.open("..\\dataout\\search\\1000.txt", ios::trunc);
			break;
		case 10000 :
			output1.open("..\\dataout\\find\\10000.txt", ios::trunc);
			output2.open("..\\dataout\\search\\10000.txt", ios::trunc);
			break;
		case 100000 :
			output1.open("..\\dataout\\find\\100000.txt", ios::trunc);
			output2.open("..\\dataout\\search\\100000.txt", ios::trunc);
			break;
		case 1000000 :
			output1.open("..\\dataout\\find\\1000000.txt", ios::trunc);
			output2.open("..\\dataout\\search\\1000000.txt", ios::trunc);
			break;
	}
	
	cout << "--------------------------------" << endl;
	int p = 0;
	int j = 0;
	double time[100];
	double mintime = 99999999.9;
	double maxtime = 0.0;
	double ret = 0.0;
	double average = 0.0;
	int sum = 0;
	for(int i = 0; i < 100; i++) {
		clock_t start = clock();
		j += search(tempA, n, tempB[i]);
		clock_t end = clock();
		ret = ((double)(end - start) / CLOCKS_PER_SEC) * 1000;
		time[i] = ret;
		if(mintime > ret) mintime = ret;
		if(maxtime < ret) maxtime = ret;
	}
	average = aver(time, 100);
	sum = ceil(j / 100);
	output1 << "以顺序法执行100次成功查找的数据如下：\n";
	output1 << "最小查找时间：" << mintime << "ms\n";
	output1 << "最大查找时间：" << maxtime << "ms\n";
	output1 << "平均查找时间：" << average << "ms\n";
	output1 << "平均查找次数：" << sum << "次\n\n";
	cout << "以顺序法执行100次成功查找的数据如下：" << endl;
	cout << "最小查找时间：" << mintime << "ms" << endl;
	cout << "最大查找时间：" << maxtime << "ms" << endl;
	cout << "平均查找时间：" << average << "ms" << endl;
	cout << "平均查找次数：" << sum << "次" << endl;
	cout << "--------------------------------" << endl;
	
	p = 0;
	j = 0;
	mintime = 99999999.9;
	maxtime = 0.0;
	ret = 0.0;
	for(int i = 0; i < 100; i++) {
		clock_t start = clock();
		j += find(tempA, n, tempB[i]);
		clock_t end = clock();
		ret = ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;
		time[i] = ret;
		if(mintime > ret) mintime = ret;
		if(maxtime < ret) maxtime = ret;
	}
	average = aver(time, 100);
	sum = ceil(j / 100);
	output2 << "以二分法执行100次成功查找的数据如下：\n";
	output2 << "最小查找时间：" << mintime << "ms\n";
	output2 << "最大查找时间：" << maxtime << "ms\n";
	output2 << "平均查找时间：" << average << "ms\n";
	output2 << "平均查找次数：" << sum << "次\n\n";
	cout << "以二分法执行100次成功查找的数据如下：" << endl;
	cout << "最小查找时间：" << mintime << "ms" << endl;
	cout << "最大查找时间：" << maxtime << "ms" << endl;
	cout << "平均查找时间：" << average << "ms" << endl;
	cout << "平均查找次数：" << sum << "次" << endl;
	cout << "--------------------------------" << endl;
	
	p = 0;
	j = 0;
	mintime = 99999999.9;
	maxtime = 0.0;
	ret = 0.0;
	for(int i = 0; i < 100; i++) {
		clock_t start = clock();
		j += search(tempA, n, tempC[i]);
		clock_t end = clock();
		ret = ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;
		time[i] = ret;
		if(mintime > ret) mintime = ret;
		if(maxtime < ret) maxtime = ret;
	}
	average = aver(time, 100);
	sum = ceil(j / 100);
	output1 << "以顺序法执行100次失败查找的数据如下：\n";
	output1 << "最小查找时间：" << mintime << "ms\n";
	output1 << "最大查找时间：" << maxtime << "ms\n";
	output1 << "平均查找时间：" << average << "ms\n";
	output1 << "平均查找次数：" << sum << "次\n\n";
	cout << "以顺序法执行100次失败查找的数据如下：" << endl;
	cout << "最小查找时间：" << mintime << "ms" << endl;
	cout << "最大查找时间：" << maxtime << "ms" << endl;
	cout << "平均查找时间：" << average << "ms" << endl;
	cout << "平均查找次数：" << sum << "次" << endl;
	cout << "--------------------------------" << endl;
	
	p = 0;
	j = 0;
	mintime = 99999999.9;
	maxtime = 0.0;
	ret = 0.0;
	for(int i = 0; i < 100; i++) {
		clock_t start = clock();
		j += find(tempA, n, tempC[i]);
		clock_t end = clock();
		ret = ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;
		time[i] = ret;
		if(mintime > ret) mintime = ret;
		if(maxtime < ret) maxtime = ret;
	}
	average = aver(time, 100);
	sum = ceil(j / 100);
	output2 << "以二分法执行100次失败查找的数据如下：\n";
	output2 << "最小查找时间：" << mintime << "ms\n";
	output2 << "最大查找时间：" << maxtime << "ms\n";
	output2 << "平均查找时间：" << average << "ms\n";
	output2 << "平均查找次数：" << sum << "次\n\n";
	cout << "以二分法执行100次失败查找的数据如下：" << endl;
	cout << "最小查找时间：" << mintime << "ms" << endl;
	cout << "最大查找时间：" << maxtime << "ms" << endl;
	cout << "平均查找时间：" << average << "ms" << endl;
	cout << "平均查找次数：" << sum << "次" << endl;
	cout << "--------------------------------" << endl;
	
	output1.close();
	output2.close();
	return 0;
}
