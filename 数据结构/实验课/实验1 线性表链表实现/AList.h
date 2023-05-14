#include "List.h"
#include <iostream>
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
		Alist(int size=100) {// Constructor ���캯��
			maxlen = size;
    		curlen = curr = 0;
    		E_words = N_words = O_words = 0;
	    	listArray = new E[maxlen];
		}
		
		~Alist(){delete[] listArray;}// Destructor ��������
		
		void reset(){
			E_words = 0;
			N_words = 0;
			O_words = 0;
			curr = 0;
		} 
		
		void clear(){//��ʼ��˳���
			delete [] listArray;
   			curlen = curr = 0;
    		listArray = new E[maxlen];
		}
		
		void append(const E& it){// Append "it" ��˳����ĩβ׷��it
    		if(curlen<maxlen) listArray[curlen++] = it;
    		curr++;
		}
		
		int remove(){
			for(int i=0;i<curlen;i++){
				if(listArray[i]>=48&&listArray[i]<=57){
					for(int j=i; j<curlen-1; j++) listArray[j] = listArray[j+1];//����Ԫ��
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
};

