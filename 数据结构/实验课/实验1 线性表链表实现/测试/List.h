//
// Created by david on 2019/10/06.
//

#ifndef TREE_LIST_H
#define TREE_LIST_H

#include <iostream>
#include <windows.h>

template<typename E>
class List {
private:
    void operator=(const List &) {} // ��������� 
    List(const List &) {} // ���캯�� 

public:
    List() {} // ���캯�� 
    virtual ~List() {} // �������� 
    virtual void clear() = 0; // ��ձ� 
    virtual void insert(const E &item) = 0; // ������� 
    virtual void append(const E &item) = 0; // �ײ����� 
    virtual E remove() = 0; // �Ƴ�
    virtual void moveToStart() = 0; // ��currָ���ƶ���ͷ�� 
    virtual void moveToEnd() = 0; // ��currָ���ƶ����ײ� 
    virtual void prev() = 0; // �ƶ�curr��ǰһ�ڵ� 
    virtual void next() = 0; // �ƶ�curr����һ�ڵ� 
    virtual int length() const = 0; // ��ȡ���� 
    virtual int currPos() const = 0; // ��ȡcurr��ǰλ�� 
    virtual void moveToPos(int pos) = 0; // �ƶ�curr��ĳһ�ڵ�
    virtual const E &getValue() const = 0; // ��ȡ��ǰֵ 
};

#endif //TREE_LIST_H
