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
                throw "�������";
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
                throw "ָ�����";
            }
            switch (option) {
                case 1: {
                    cout << "������Ҫ׷�ӵ���ֵ:\n";
                    string str;
                    cin >> str;
                    list.append(str);
                    print(list);
                    system("pause");
                }
                    break;
                case 2: {
                    cout << "������Ҫ��ӵ�����:\n"
                                 "����������������ӣ�˳�������������ӣ�\n";
                    int index;
                    cin >> index;
                    cout << "������Ҫ�����ֵ\n";
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
                    cout << "��ճɹ�\n";
                    system("pause");
                    return;
                }
                    break;
                case 4: {
                    cout << "������Ҫɾ��������:\n"
                                 "������ɾ���������ֵ��˳�����������ɾ����\n";
                    int index;
                    cin >> index;
                    list.moveToPos(index);
                    cout << "ɾ����Ԫ���ǣ�" << list.remove() << endl;
                    print(list);
                    system("pause");
                }
                    break;
                case 5: {
                    cout << "������Ҫ�޸ĵ�����:\n"
                                 "�������޸��������ֵ��˳������������޸ģ�\n";
                    int index;
                    cin >> index;
                    cout << "������Ҫ�����ֵ\n";
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
        // ��һ��
        firstScreen();
        cin >> option;
        switch (option) {
            case 0:
                return 0;
            case 1: {
                AList<string> list;
                // �ڶ���
                second(list, option);
                // ������
                third(list);
            }
                break;
            case 2: {
                LList<string> list;
                // �ڶ���
                second(list, option);
                // ������
                third(list);
            }
                break;
            default:
                continue;
        }
    }
}
