//
// Created by david on 2019/10/06.
//

#ifndef TREE_LLIST_H
#define TREE_LLIST_H


#include "List.h"

template<typename E>
class Link {
public:
    E element; // 数据域
    Link *next; // 指针域

    // 两个不同型的构造函数
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
    Link<E> *head; // 头指针
    Link<E> *tail; // 尾指针
    Link<E> *curr; // 现在指向的元素
    int count; // 元素个数

    void init() {// init初始化 
        curr = tail = head = new Link<E>;
        count = 0;
    } 
    void removeAll() {// 解除空间
        while (head != NULL) {
            curr = head;
            head = head->next;
            delete curr;
        }
    } 

public:
    LList() {// 构造函数
        init();
    }  
    ~LList() {// 析构函数
        removeAll();
    } 
    void clear() {// 清空线性表
        removeAll();
        init();
    } 
    void insert(const E &item) {// 在curr后进行插入操作
        curr->next = new Link<E>(item, curr->next);
        if (tail == curr) {
            tail = curr->next;
        }
        count++;
    } 
    void append(const E &item) {// 在末尾进行追加
        tail = tail->next = new Link<E>(item, NULL);
        count++;
    } 
    E remove() {// 清除curr节点，并返回值
        try {
            if (curr->next == NULL) {
                throw "没有数据无法删除";
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
    void moveToStart() {// 移动curr到开始
        curr = head;
    } 
    void moveToEnd() {// 移动curr到结束
        curr = tail;
    } 
    void prev() {// 移动curr到前一节点
        if (curr == head) {
            return;
        }
        Link<E> *temp = head;
        while (temp->next != curr) {
            temp = temp->next;
        }
        curr = temp;
    } 
    void next() {// 移动curr到后一节点
        if (curr != tail) {
            curr = curr->next;
        }
    } 
    int length() const {// 返回线性表长度
        return count;
    } 
    int currPos() const {// 返回现在curr位置
        Link<E> *temp = head;
        int i;
        for (i = 0; curr != temp; ++i) {
            temp = temp->next;
        }
        return i;
    } 
    void moveToPos(int pos) {// 移动curr到某一节点
        try {
            if (pos < 0 || pos > count) {
                throw "不存在这样的位置";
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
    const E &getValue() const {// 获取curr元素值
        try {
            if (curr->next == NULL) {
                throw "不存在这样的值";
            }
            return curr->next->element;
        } catch (char const *str) {
            std::cerr << str;
            system("pause");
        }
    } 
};


#endif //TREE_LLIST_H
