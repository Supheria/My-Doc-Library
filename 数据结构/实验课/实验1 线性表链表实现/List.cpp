#include "List.h"
#include "AList.h"
#include <iostream>
#include <string>
using namespace std;
int main(){
	Alist<char> L(1000);
	string a;
	int E=0,N=0,O=0;
	cin >> a;
	int len=a.length();
	for(int i=0;i<len;i++){
		L.append(a[i]);
	}
	E = L.E_word();
	N = L.N_word();
	O = L.O_word();
	cout << E << ' ' << N << ' ' << O << endl;
	L.remove();
	for(int i=0;i<L.size();i++){
		cout << L.current(i);
	}
	return 0;
}
