#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
using namespace std;

string trans(int a) {
	stringstream ss;
	string str;
	ss << a;
	ss >> str;
	return str;
}

int main() {
	ofstream output;
	int x = 1000000;//数据规模 
	srand((unsigned)time(NULL));
	output.open("..\\dataset\\1000000.txt", ios::trunc);
	
	for(int i = 0; i < x; i++) {
		output << i << " ";
	}
	return 0;
}
