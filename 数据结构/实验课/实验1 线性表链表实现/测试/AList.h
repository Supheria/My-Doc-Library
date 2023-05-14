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
    int maxSize; // 线性表最大长度
    int listSize; // 当前顺序表长度
    int curr; // 当前位置
    E *listArray; // 顺序表物理地址
public:
    AList(int size = defaultSize) {
        maxSize = size;
        listSize = curr = 0;
        listArray = new E[maxSize];
    }

    ~AList() {// 析构函数
        delete[] listArray;
    } 
    void clear() {// 清空线性表
        delete[] listArray;
        listSize = curr = 0;
        listArray = new E[maxSize];
    } 
    void insert(const E &item) {// 在curr后进行插入操作
        try {
            if (listSize == maxSize) {
                throw "已达到最大数目，无法继续添加";
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
    void append(const E &item) {// 在末尾进行追加
        try {
            if (listSize == maxSize) {
                throw "已达到最大数目，无法继续添加";
            }
            listArray[listSize++] = item;
        } catch (char const *str) {
            std::cerr << str;
            system("pause");
        }
    } 
    E remove() {// 清楚curr节点，并返回值
        try {
            if (curr < 0 || curr >= listSize) {
                throw "无法删除不满足条件";
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
    void moveToStart() {// 移动curr到开始
        curr = 0;
    } 
    void moveToEnd() {// 移动curr到结束
        curr = listSize - 1;
    } 
    void prev() {// 移动curr到前一节点
        if (curr != 0) {
            curr--;
        }
    } 
    void next() {// 移动curr到后一节点
        if (curr < listSize - 1) {
            curr++;
        }
    } 
    int length() const {// 返回线性表长度
        return listSize;
    } 
    int currPos() const {// 返回现在curr位置
        return curr;
    } 
    void moveToPos(int pos) {// 移动curr到某一节点
        try {
            if (pos < 0 || pos > listSize) {
                throw "超出数组范围";
            }
            curr = pos;
        } catch (char const *str) {
            std::cerr << str;
            system("pause");
        }
    } 
    const E &getValue() const {// 获取curr元素值
        try {
            if (curr < 0 || curr > listSize) {
                throw "没有元素，超出数组范围";
            }
            return listArray[curr];
        } catch (char const *str) {
            std::cerr << str;
            system("pause");
        }
    } 
};


#endif //TREE_ALIST_H
