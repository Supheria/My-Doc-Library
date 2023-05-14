#include <iostream>
#include <ctime>
#include <fstream>
#include <sstream>

using namespace std;

string trans(int);

void inssort(int*, int);

void Swap(int, int, int *);

void outIt(int, int, int *);

void quickSort(int, int, int *);

int main() {
	int n;
	cout << "请输入数据规模：" << endl;
	cin >> n;
	int *tempA = new int[n];
	int *tempB = new int[n];
	ifstream input;
	
	switch(n) {
		case 100:
			input.open("..\\dataset\\100.txt");
			break;
		case 1000:
			input.open("..\\dataset\\1000.txt");
			break;
		case 10000:
			input.open("..\\dataset\\10000.txt");
			break;
		case 100000:
			input.open("..\\dataset\\100000.txt");
			break;
		case 1000000:
			input.open("..\\dataset\\1000000.txt");
			break;
		default :
			cout << "输入规模错误，请重新输入：" << endl;
			return main();
	}
	

	for (int i = 0; i < n; ++i) {
		input >> tempA[i];
		tempB[i] = tempA[i];
	}
	
	input.close();

	clock_t start_time1 = clock();
	inssort(tempA, n);
	clock_t end_time1 = clock();
	cout << "插入排序运行时间："
	     << static_cast<double>(end_time1 - start_time1) / CLOCKS_PER_SEC * 1000
	     << "ms" << endl;
	outIt(1, n, tempA);
	
	clock_t start_time2 = clock();
	quickSort(0, n, tempB);
	clock_t end_time2 = clock();
	cout << "快速排序运行时间："
	     << static_cast<double>(end_time2 - start_time2) / CLOCKS_PER_SEC * 1000
	     << "ms" << endl;
	outIt(0, n, tempB);
}

string trans(int x) {
	stringstream ss;
	string str;
	ss << x;
	ss >> str;

	return str;
}

void inssort(int *tempA, int n) {
	for (int i = 1; i < n; ++i) {
		for (int j = i; j > 0 && tempA[j] < tempA[j - 1]; --j) {
			int temp = tempA[j];
			tempA[j] = tempA[j - 1];
			tempA[j - 1] = temp;
		}
	}
}

void Swap(int x, int y, int *tempA) {
	int temp = tempA[x];
	tempA[x] = tempA[y];
	tempA[y] = temp;
}

void outIt(int x, int n, int *tempA) {
	string path;
	ofstream output;
	if (x == 1) {
		switch(n) {
			case 100:
				output.open("..\\dataout\\insert\\100.txt");
				break;
			case 1000:
				output.open("..\\dataout\\insert\\1000.txt");
				break;
			case 10000:
				output.open("..\\dataout\\insert\\10000.txt");
				break;
			case 100000:
				output.open("..\\dataout\\insert\\100000.txt");
				break;
			case 1000000:
				output.open("..\\dataout\\insert\\1000000.txt");
				break;
		}
	} else {
		switch(n) {
			case 100:
				output.open("..\\dataout\\quick\\100.txt");
				break;
			case 1000:
				output.open("..\\dataout\\quick\\1000.txt");
				break;
			case 10000:
				output.open("..\\dataout\\quick\\10000.txt");
				break;
			case 100000:
				output.open("..\\dataout\\quick\\100000.txt");
				break;
			case 1000000:
				output.open("..\\dataout\\quick\\1000000.txt");
				break;
		}
	}

	for (int i = 0; i < n; ++i) {
		output << tempA[i] << " ";
	}

	output.close();
}

void quickSort(int left, int right, int *tempA) {
	if (left >= right) {
		return;
	}
	int l = left, r = right;
	int dex = (left + right) / 2;
	int axle = tempA[dex];
	Swap(dex, right, tempA);

	while (l != r) {
		while (tempA[l] <= axle && l < r) {
			l++;
		}
		while (tempA[r] >= axle && l < r) {
			r--;
		}
		Swap(l, r, tempA);
	}
	Swap(l, right, tempA);
	quickSort(left, l - 1, tempA);
	quickSort(l + 1, right, tempA);
}
