#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
	ofstream output;
	int x = 1000000;
	srand((unsigned)time(NULL));
	output.open("..\\dataset\\1000000.txt", ios::trunc);
	
	for(int i = 0; i < x; ++i) {
		output << rand() << " ";
	}
	
	return 0;
}
