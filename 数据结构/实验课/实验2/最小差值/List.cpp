#include "List.h"
#include "AList.h"
#include <iostream>
#include <string>
using namespace std;
int main(){
	Alist<int> L(1000);
	int a;
	cin >> a;
	int b=0;
	for(int i=0;i<a;i++){
		cin >> b;
		L.append(b);
	}
	cout << L.cha();
	return 0;
}
