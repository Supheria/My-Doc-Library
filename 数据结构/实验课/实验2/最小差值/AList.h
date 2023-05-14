#include "List.h"
#include <iostream>
#include <algorithm>
using namespace std;
template<typename E>
class Alist:public List<E>{
	private:
		int maxlen;
		int curlen;
		int curr;
		int E_words;
		int N_words;
		int O_words;
		E* listArray; 
	public:
		Alist(int size=100) {// Constructor 构造函数
			maxlen = size;
    		curlen = curr = 0;
    		E_words = N_words = O_words = 0;
	    	listArray = new E[maxlen];
		}
		
		~Alist(){delete[] listArray;}// Destructor 析构函数
		
		void reset(){
			E_words = 0;
			N_words = 0;
			O_words = 0;
			curr = 0;
		} 
		
		void clear(){//初始化顺序表
			delete [] listArray;
   			curlen = curr = 0;
    		listArray = new E[maxlen];
		}
		
		void append(const E& it){// Append "it" 在顺序表的末尾追加it
    		if(curlen<maxlen) listArray[curlen++] = it;
    		curr++;
		}
		
		int remove(){
			for(int i=0;i<curlen;i++){
				if(listArray[i]>=48&&listArray[i]<=57){
					for(int j=i; j<curlen-1; j++) listArray[j] = listArray[j+1];//左移元素
					i--;
	    			curlen--;
				}
			}
			reset();
			return curlen;
		}
		
		int E_word(){
			for(int i=0;i<curlen;i++){
				if((listArray[i]<=122&&listArray[i]>=97)||(listArray[i]<=90&&listArray[i]>=65)) E_words++;
			}
			return E_words;
		}
		
		int N_word(){
			for(int i=0;i<curlen;i++){
				if(listArray[i]<=57&&listArray[i]>=48) N_words++;
			}
			return N_words;
		}
		
		int O_word(){
			for(int i=0;i<curlen;i++){
				if(!(listArray[i]<=57&&listArray[i]>=48)
				&&!(listArray[i]<=122&&listArray[i]>=97)
				&&!(listArray[i]<=90&&listArray[i]>=65)) O_words++;;
			}
			return O_words;
		}
		
		E current(int a){
			return listArray[a];
		}
		
		int size(){
			return curlen;
		}
		
		int cha(){
			try {
	            if (curlen == 1) {
	                throw "只有一个元素，无法计算最小差值";
	            }
	            int a[curlen];
				int b[curlen-1];
				for(int i=0;i<curlen;i++){
					a[i]=listArray[i];
				}
				sort(a,a+curlen);
				for(int i=0;i<curlen-1;i++){
					b[i]=a[i+1]-a[i];
				}
				sort(b,b+curlen-1);
				return b[0];
	        } catch (char const *str) {
	            std::cerr << str;
	            system("pause");
	        }
		} 
};

