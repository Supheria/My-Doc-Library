//
// Created by david on 2019/10/06.
//

#include "AList.h"
#include "LList.h"
#include "testTemp.h"
#include <fstream>
#include <sstream>
#include <string>
using namespace std; 
template<typename E>
void print(E &list) {
    list.moveToStart();
    for (int i = 0; i < list.length(); ++i) {
        cout << list.getValue() << " ";
        list.next();
    }
    std::cout << std::endl;
}

template<typename E>
void second(E &list, int it) {
    while (true) {
        secondScreen(it);
        int option;
        cin >> option;
        if (option == 0) return;
        
        try {
            if (option > 5 || option < 0) {
                throw "输入错误";
            }
            string str;
//            cin >> str;
//            for(int i=0;i<str.length();i++){
//            	list.append(str[i]);
//			}
            stringstream stream;
            stream << option;
            stream >> str;
            str = "..\\test\\" + str + ".txt";
            ifstream read;
            read.open(str);
            while (true) {
                read >> str;
                list.append(str);
                if (read.eof()) {
                    break;
                }
            }
            read.close();
            break;
        } catch (char const *str) {
            cerr << str;
            system("pause");
        }
    }

}

template<typename E>
void third(E &list) {
    while (true) {
        thirdScerrn();
        int option;
        cin >> option;
        if (option == 0) return;
        
        try {
            if (option < 0 || option > 6) {
                throw "指令错误";
            }
            switch (option) {
                case 1: {
                    cout << "请输入要追加的数值:\n";
                    string str;
                    cin >> str;
                    list.append(str);
                    print(list);
                    system("pause");
                }
                    break;
                case 2: {
                    cout << "请输入要添加的索引:\n"
                                 "（链表在索引后添加，顺序表在索引处添加）\n";
                    int index;
                    cin >> index;
                    cout << "请输入要插入的值\n";
                    string str;
                    cin >> str;
                    list.moveToPos(index);
                    list.insert(str);
                    print(list);
                    system("pause");
                }
                    break;
                case 3: {
                    list.clear();
                    cout << "清空成功\n";
                    system("pause");
                    return;
                }
                    break;
                case 4: {
                    cout << "请输入要删除的索引:\n"
                                 "（链表删除索引后的值，顺序表在索引处删除）\n";
                    int index;
                    cin >> index;
                    list.moveToPos(index);
                    cout << "删除的元素是：" << list.remove() << endl;
                    print(list);
                    system("pause");
                }
                    break;
                case 5: {
                    cout << "请输入要修改的索引:\n"
                                 "（链表修改索引后的值，顺序表在索引处修改）\n";
                    int index;
                    cin >> index;
                    cout << "请输入要插入的值\n";
                    string str;
                    cin >> str;
                    list.moveToPos(index);
                    list.remove();
                    list.insert(str);
                    print(list);
                    system("pause");
                }
                    break;
            }
        } catch (char const *str) {
            cerr << str;
            system("pause");
        }
    }
}

int main() {
    int option;
    while (true) {
        // 第一屏
        firstScreen();
        cin >> option;
        switch (option) {
            case 0:
                return 0;
            case 1: {
                AList<string> list;
                // 第二屏
                second(list, option);
                // 第三屏
                third(list);
            }
                break;
            case 2: {
                LList<string> list;
                // 第二屏
                second(list, option);
                // 第三屏
                third(list);
            }
                break;
            default:
                continue;
        }
    }
}
