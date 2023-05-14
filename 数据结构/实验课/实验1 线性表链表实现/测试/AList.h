//
// Created by david on 2019/10/06.
//

#ifndef TREE_ALIST_H
#define TREE_ALIST_H

#include "List.h"

const int defaultSize = 5000;

template<typename E>
class AList : public List<E> {
private:
    int maxSize; // ���Ա���󳤶�
    int listSize; // ��ǰ˳�����
    int curr; // ��ǰλ��
    E *listArray; // ˳��������ַ
public:
    AList(int size = defaultSize) {
        maxSize = size;
        listSize = curr = 0;
        listArray = new E[maxSize];
    }

    ~AList() {// ��������
        delete[] listArray;
    } 
    void clear() {// ������Ա�
        delete[] listArray;
        listSize = curr = 0;
        listArray = new E[maxSize];
    } 
    void insert(const E &item) {// ��curr����в������
        try {
            if (listSize == maxSize) {
                throw "�Ѵﵽ�����Ŀ���޷��������";
            }
            for (int i = listSize; i > curr; --i) {
                listArray[i] = listArray[i - 1];
            }
            listArray[curr] = item;
            listSize++;
        } catch (char const *str) {
            std::cerr << str;
            system("pause");
        }
    } 
    void append(const E &item) {// ��ĩβ����׷��
        try {
            if (listSize == maxSize) {
                throw "�Ѵﵽ�����Ŀ���޷��������";
            }
            listArray[listSize++] = item;
        } catch (char const *str) {
            std::cerr << str;
            system("pause");
        }
    } 
    E remove() {// ���curr�ڵ㣬������ֵ
        try {
            if (curr < 0 || curr >= listSize) {
                throw "�޷�ɾ������������";
            }
            E it = listArray[curr];
            for (int i = curr; i < listSize - 1; ++i) {
                listArray[i] = listArray[i + 1];
            }
            listSize--;
            return it;
        } catch (char const *str) {
            std::cerr << str;
            system("pause");
        }
    } 
    void moveToStart() {// �ƶ�curr����ʼ
        curr = 0;
    } 
    void moveToEnd() {// �ƶ�curr������
        curr = listSize - 1;
    } 
    void prev() {// �ƶ�curr��ǰһ�ڵ�
        if (curr != 0) {
            curr--;
        }
    } 
    void next() {// �ƶ�curr����һ�ڵ�
        if (curr < listSize - 1) {
            curr++;
        }
    } 
    int length() const {// �������Ա���
        return listSize;
    } 
    int currPos() const {// ��������currλ��
        return curr;
    } 
    void moveToPos(int pos) {// �ƶ�curr��ĳһ�ڵ�
        try {
            if (pos < 0 || pos > listSize) {
                throw "�������鷶Χ";
            }
            curr = pos;
        } catch (char const *str) {
            std::cerr << str;
            system("pause");
        }
    } 
    const E &getValue() const {// ��ȡcurrԪ��ֵ
        try {
            if (curr < 0 || curr > listSize) {
                throw "û��Ԫ�أ��������鷶Χ";
            }
            return listArray[curr];
        } catch (char const *str) {
            std::cerr << str;
            system("pause");
        }
    } 
};


#endif //TREE_ALIST_H
