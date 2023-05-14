#include <iostream>
#include <queue>
using namespace std;
int cir(int n,int k){
    queue<int> q;
    int a = 1,cur = 0;
    for(int i = 1;i <= n;i++){
    	q.push(i);
	}
	while(q.size()!=1){
		cur = q.front();
		if(a%k==0||a%10==k){
			q.pop();
		} else {
			q.pop();
			q.push(cur);
		}
		a++;
	}
	return q.front();
}
int main(){
	int a = 0,b = 0;
	cin >> a >> b;
	cout << cir(a,b);
	return 0;
} 
