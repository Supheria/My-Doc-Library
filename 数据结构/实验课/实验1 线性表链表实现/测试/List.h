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
    void operator=(const List &) {} // 重载运算符 
    List(const List &) {} // 构造函数 

public:
    List() {} // 构造函数 
    virtual ~List() {} // 析构函数 
    virtual void clear() = 0; // 清空表 
    virtual void insert(const E &item) = 0; // 定点插入 
    virtual void append(const E &item) = 0; // 底部插入 
    virtual E remove() = 0; // 移除
    virtual void moveToStart() = 0; // 将curr指针移动到头部 
    virtual void moveToEnd() = 0; // 将curr指针移动到底部 
    virtual void prev() = 0; // 移动curr至前一节点 
    virtual void next() = 0; // 移动curr至后一节点 
    virtual int length() const = 0; // 获取长度 
    virtual int currPos() const = 0; // 获取curr当前位置 
    virtual void moveToPos(int pos) = 0; // 移动curr到某一节点
    virtual const E &getValue() const = 0; // 获取当前值 
};

#endif //TREE_LIST_H
