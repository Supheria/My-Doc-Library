//
// Created by david on 2019/10/06.
//

#ifndef TREE_LLIST_H
#define TREE_LLIST_H


#include "List.h"

template<typename E>
class Link {
public:
    E element; // ������
    Link *next; // ָ����

    // ������ͬ�͵Ĺ��캯��
    Link(const E &value, Link *nextVal = NULL) {
        element = value;
        next = nextVal;
    }

    Link(Link *nextVal = NULL) {
        next = nextVal;
    }
};

template<typename E>
class LList : public List<E> {
private:
    Link<E> *head; // ͷָ��
    Link<E> *tail; // βָ��
    Link<E> *curr; // ����ָ���Ԫ��
    int count; // Ԫ�ظ���

    void init() {// init��ʼ�� 
        curr = tail = head = new Link<E>;
        count = 0;
    } 
    void removeAll() {// ����ռ�
        while (head != NULL) {
            curr = head;
            head = head->next;
            delete curr;
        }
    } 

public:
    LList() {// ���캯��
        init();
    }  
    ~LList() {// ��������
        removeAll();
    } 
    void clear() {// ������Ա�
        removeAll();
        init();
    } 
    void insert(const E &item) {// ��curr����в������
        curr->next = new Link<E>(item, curr->next);
        if (tail == curr) {
            tail = curr->next;
        }
        count++;
    } 
    void append(const E &item) {// ��ĩβ����׷��
        tail = tail->next = new Link<E>(item, NULL);
        count++;
    } 
    E remove() {// ���curr�ڵ㣬������ֵ
        try {
            if (curr->next == NULL) {
                throw "û�������޷�ɾ��";
            }
            E it = curr->next->element;
            Link<E> *itTemp = curr->next;
            if (tail == curr->next) {
                tail = curr;
            }
            curr->next = curr->next->next;
            delete itTemp;
            count--;
            return it;
        } catch (char const *str) {
            std::cerr << str;
            system("pause");
        }
    } 
    void moveToStart() {// �ƶ�curr����ʼ
        curr = head;
    } 
    void moveToEnd() {// �ƶ�curr������
        curr = tail;
    } 
    void prev() {// �ƶ�curr��ǰһ�ڵ�
        if (curr == head) {
            return;
        }
        Link<E> *temp = head;
        while (temp->next != curr) {
            temp = temp->next;
        }
        curr = temp;
    } 
    void next() {// �ƶ�curr����һ�ڵ�
        if (curr != tail) {
            curr = curr->next;
        }
    } 
    int length() const {// �������Ա���
        return count;
    } 
    int currPos() const {// ��������currλ��
        Link<E> *temp = head;
        int i;
        for (i = 0; curr != temp; ++i) {
            temp = temp->next;
        }
        return i;
    } 
    void moveToPos(int pos) {// �ƶ�curr��ĳһ�ڵ�
        try {
            if (pos < 0 || pos > count) {
                throw "������������λ��";
            }
            curr = head;
            for (int i = 0; i < pos; ++i) {
                curr = curr->next;
            }
        } catch (char const *str) {
            std::cerr << str;
            system("pause");
        }
    } 
    const E &getValue() const {// ��ȡcurrԪ��ֵ
        try {
            if (curr->next == NULL) {
                throw "������������ֵ";
            }
            return curr->next->element;
        } catch (char const *str) {
            std::cerr << str;
            system("pause");
        }
    } 
};


#endif //TREE_LLIST_H
