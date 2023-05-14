#pragma once
#include "stdafx.h"
#include <queue>
#include <vector>
#include <set>

using namespace std;

#ifdef _HEHE

//该宏定义用于判断T类型
template<class T>
struct TypeParseTraits;
#define REGISTER_PARSE_TYPE(X) template <> struct TypeParseTraits<X> \
    { static const char* name; } ; const char* TypeParseTraits<X>::name = #X
REGISTER_PARSE_TYPE(int);
REGISTER_PARSE_TYPE(float);
REGISTER_PARSE_TYPE(double);
REGISTER_PARSE_TYPE(char);
REGISTER_PARSE_TYPE(TCHAR);

#endif

//二叉树结点
template <class T>
struct Btnode
{
    Btnode() {

    }

    T d;
    Btnode* lchild;
    Btnode* rchild;
};

struct DrawNode {
    DrawNode() : deep(0), left(0), right(0), lchild(false), rchild(false), selected(false) {

    }

    TCHAR ch;
    int deep;
    int left;
    int right;
    bool lchild;
    bool rchild;
    bool selected;
};

//二叉树类
template <class T>
class Binary_Tree
{
private:
    Btnode<T>* BT;    //根
    CString Sequence; //遍历序列
    int width;
    std::vector<std::vector<DrawNode>> snapshoot; //动画快照

public:
    Btnode<T>* selected; //当前选定节点
    int count;
    int depth;
    int leaf;
    int breadth;

public:
    Binary_Tree()     //构造函数，初始化
    {
        BT = NULL;
        selected = NULL;
        width = 0;
        count = 0;
        depth = 0;
        leaf = 0;
        breadth = 0;
        return;
    }

    ~Binary_Tree() {
        reset();
    }

    void creat_Binary_Tree(T*, T);   //生成树
    CString pretrav_Binary_Tree();   //先序遍历
    CString intrav_Binary_Tree();    //中序遍历
    CString postrav_Binary_Tree();   //后序遍历
    CString broacast_Binary_Tree();  //按层遍历
    void draw_Binary_Tree(std::vector<DrawNode>& list, int width);  //绘制二叉树
    void mirror_Binary_Tree();      //镜像

    void reset() {
        clear(BT);
        BT = NULL;
        snapshoot.clear();
    }

    void clear(Btnode<T>*& node, bool snap = false) {
        if (node) {
            if (snap) {
                selected = node;
                makeSnapshoot();
                makeSnapshoot();
            }
            clear(node->lchild, snap);
            clear(node->rchild, snap);
            delete node;
            node = NULL;
            if (snap) {
                makeSnapshoot();
            }
        }
    }

    void setWidth(int width) {
        this->width = width;
    }

    std::vector<DrawNode> getSnapshoot() {
        if (snapshoot.empty()) {
            return std::vector<DrawNode>();
        }
        if (snapshoot.size() == 1) {
            return snapshoot[0];
        } else {
            std::vector<DrawNode> result = snapshoot[0];
            snapshoot.erase(snapshoot.begin());
            return result;
        }
    }

    void makeSnapshoot() {
        std::vector<DrawNode> list;
        draw_Binary_Tree(list, width);
        snapshoot.push_back(list);
    }

    void refresh() {
        count = countNode(BT);
        depth = countDepth(BT);
        leaf = countleaf(BT);
        breadth = countBreadth();
    }

    int countNode(Btnode<T>* node) {
        if (node) {
            return countNode(node->lchild) + countNode(node->rchild) + 1;
        }
        return 0;
    }

    int countleaf(Btnode<T>* node) {
        if (node) {
            if (node->lchild == NULL && node->rchild == NULL) {
                return 1;
            }
            return countleaf(node->lchild) + countleaf(node->rchild);
        }
        return 0;
    }

    int countBreadth() {
        std::queue<Btnode<T>*> q;
        Btnode<T>* p;

        std::set<Btnode<T>*> ends;
        p = BT;
        while (p) {
            ends.insert(p);
            if (p->rchild) {
                p = p->rchild;
                continue;
            }
            if (p->lchild) {
                p = p->lchild;
                continue;
            }
            break;
        }

        int max = 0;
        int count = 0;
        p = BT;
        if (p) {
            q.push(p);
            while (!q.empty()) {
                Btnode<T>* n = q.front();
                q.pop();
                ++count;
                if (ends.find(n) != ends.end()) {
                    if (count > max) {
                        max = count;
                    }
                    count = 0;
                }

                if (n->lchild) {
                    q.push(n->lchild);
                }
                if (n->rchild) {
                    q.push(n->rchild);
                }
            }
        }

        return max;
    }

    int countDepth(Btnode<T>* node) {
        if (node) {
            int l = countDepth(node->lchild);
            int r = countDepth(node->rchild);
            return (1 + (l > r ? l : r));
        }
        return 0;
    }

    Btnode<T>* search(TCHAR ch) {
        snapshoot.clear();
        if (BT) {
            if (BT->d == ch) {
                selected = BT;
                makeSnapshoot();
                return BT;
            }
            return searchTraverse(BT, ch);
        }
        return NULL;
    }

    Btnode<T>* searchTraverse(Btnode<T>* node, TCHAR ch) {
        if (node) {
            selected = node;
            makeSnapshoot();
            makeSnapshoot();
            if (node->lchild) {
                if (node->lchild->d == ch) {
                    selected = node->lchild;
                    makeSnapshoot();
                    return node;
                }
                Btnode<T>* target = searchTraverse(node->lchild, ch);
                if (target) {
                    return target;
                }
            }
            if (node->rchild) {
                if (node->rchild->d == ch) {
                    selected = node->rchild;
                    makeSnapshoot();
                    return node;
                }
                Btnode<T>* target = searchTraverse(node->rchild, ch);
                if (target) {
                    return target;
                }
            }
        }
        return NULL;
    }

    bool remove(TCHAR ch) {
        std::vector<std::vector<DrawNode>> temp;
        temp.swap(snapshoot);
        bool succeed = false;
        if (BT) {
            if (BT->d == ch) {
                selected = BT;
                makeSnapshoot();
                clear(BT, true);
                makeSnapshoot();
                succeed = true;
            }
            if (!succeed) {
                succeed = removeTraverse(BT, ch);
            }
        }
        if (!succeed) {
            snapshoot.swap(temp);
        }
        if (succeed) {
            refresh();
        }
        return succeed;
    }

    bool removeTraverse(Btnode<T>*& node, TCHAR ch) {
        if (node) {
            if (node->lchild) {
                if (node->lchild->d == ch) {
                    selected = node->lchild;
                    makeSnapshoot();
                    clear(node->lchild, true);
                    makeSnapshoot();
                    return true;
                }
                if (removeTraverse(node->lchild, ch)) return true;
            }
            if (node->rchild) {
                if (node->rchild->d == ch) {
                    selected = node->rchild;
                    makeSnapshoot();
                    clear(node->rchild, true);
                    makeSnapshoot();
                    return true;
                }
                if (removeTraverse(node->rchild, ch)) return true;
            }
        }
        return false;
    }

    bool add(TCHAR ch, TCHAR parent, int mode) {
        std::vector<std::vector<DrawNode>> temp;
        temp.swap(snapshoot);
        bool succeed = false;
        Btnode<T>* node = new Btnode<T>();
        node->d = ch;
        node->lchild = NULL;
        node->rchild = NULL;
        succeed = addTraverse(BT, node, parent, mode);
        if (!succeed) {
            snapshoot.swap(temp);
            delete node;
        }
        if (succeed) {
            refresh();
        }
        return succeed;
    }

    bool addTraverse(Btnode<T>*& tree, Btnode<T>* node, TCHAR parent, int mode) {
        if (tree) {
            if (tree->d == parent) {
                selected = tree;
                makeSnapshoot();

                if (mode == 1 && tree->lchild == NULL) {
                    tree->lchild = node;
                    selected = node;
                    makeSnapshoot();
                    makeSnapshoot();
                    return true;
                }

                if (mode == 2 && tree->rchild == NULL) {
                    tree->rchild = node;

                    selected = node;
                    makeSnapshoot();
                    makeSnapshoot();
                    return true;
                }
            }
            if (addTraverse(tree->lchild, node, parent, mode)) return true;
            if (addTraverse(tree->rchild, node, parent, mode)) return true;
        }
        return false;
    }
};

//输出结点内容
template <class T>
static CString output(T a) {
    CString s;
    char* name = (char*)TypeParseTraits<T>::name;
    if (strcmp(name, "int") == 0) {
        s.Format(L"%d", a);
    } else if (strcmp(name, "double") == 0 || strcmp(name, "float") == 0) {
        s.Format(L"%f", a);
    } else if (strcmp(name, "char") == 0 || strcmp(name, "TCHAR") == 0) {
        s.Format(L"%c", a);
    }
    return s;
}

//生成树
template <class T>
void Binary_Tree<T>::creat_Binary_Tree(T* nodes, T end) {
    reset();
    if (nodes == NULL) return;

    Btnode<T>* p;
    T* tmpnodes = nodes;
    T x = tmpnodes[0];
    if (x == end) return;

    p = new Btnode<T>;
    p->d = x;
    p->lchild = NULL;
    p->rchild = NULL;
    BT = p;
    selected = p;
    makeSnapshoot();
    makeSnapshoot();
    creat(this, p, tmpnodes, 1, end);
    creat(this, p, tmpnodes, 2, end);
    selected = p;
    makeSnapshoot();
    makeSnapshoot();
    refresh();
}
template <class T>
static void creat(Binary_Tree<T>* tree, Btnode<T>* p, T*& nodes, int k, T end) {
    if (nodes[1] == '\0') return;
    nodes++;
    Btnode<T>* q;
    T x = nodes[0];
    if (x != end) {
        q = new Btnode<T>;
        q->d = x;
        q->lchild = NULL;
        q->rchild = NULL;
        if (k == 1) p->lchild = q;
        if (k == 2) p->rchild = q;
        tree->selected = q;
        tree->makeSnapshoot();
        tree->makeSnapshoot();

        creat(tree, q, nodes, 1, end);
        tree->selected = q;
        tree->makeSnapshoot();
        tree->makeSnapshoot();

        creat(tree, q, nodes, 2, end);
        tree->selected = q;
        tree->makeSnapshoot();
        tree->makeSnapshoot();
    }
}

//先序遍历
template <class T>
CString Binary_Tree<T>::pretrav_Binary_Tree() {
    Btnode<T>* p;
    p = BT;
    Sequence = "";
    snapshoot.clear();
    pretrav(this, p, Sequence);
    return Sequence;
}
template <class T>
static void pretrav(Binary_Tree<T>* tree, Btnode<T>* p, CString& s0) {
    if (p != NULL) {
        s0 += output(p->d);
        tree->selected = p;
        tree->makeSnapshoot();
        tree->makeSnapshoot();
        pretrav(tree, p->lchild, s0);
        pretrav(tree, p->rchild, s0);
    }
}

//中序遍历
template <class T>
CString Binary_Tree<T>::intrav_Binary_Tree() {
    Btnode<T>* p;
    p = BT;
    Sequence = "";
    snapshoot.clear();
    intrav(this, p, Sequence);
    return Sequence;
}
template <class T>
static void intrav(Binary_Tree<T>* tree, Btnode<T>* p, CString& s0) {
    if (p != NULL) {
        intrav(tree, p->lchild, s0);
        tree->selected = p;
        tree->makeSnapshoot();
        tree->makeSnapshoot();
        s0 += output(p->d);
        intrav(tree, p->rchild, s0);
    }
}

//后序遍历
template <class T>
CString Binary_Tree<T>::postrav_Binary_Tree() {
    Btnode<T>* p;
    p = BT;
    Sequence = "";
    snapshoot.clear();
    postrav(this, p, Sequence);
    return Sequence;
}

template<class T>
CString Binary_Tree<T>::broacast_Binary_Tree() {
    std::queue<Btnode<T>*> q;
    Btnode<T>* p;
    p = BT;
    Sequence = "";
    snapshoot.clear();
    if (p) {
        q.push(p);
        while (!q.empty()) {
            Btnode<T>* n = q.front();
            selected = n;
            makeSnapshoot();
            makeSnapshoot();
            Sequence += output(n->d);
            q.pop();
            if (n->lchild) {
                q.push(n->lchild);
            }
            if (n->rchild) {
                q.push(n->rchild);
            }
        }
    }
    return Sequence;
}

template<class T>
void Binary_Tree<T>::draw_Binary_Tree(std::vector<DrawNode>& list, int width) {
    Btnode<T>* p;
    p = BT;
    DrawNode dr;
    dr.left = 0;
    dr.right = width;
    dr.deep = 0;
    draw_tree(this, p, dr, list);
}

template<class T>
void Binary_Tree<T>::mirror_Binary_Tree() {
    Btnode<T>* p;
    p = BT;
    mirror_tree(this, p);
}

template <class T>
static void postrav(Binary_Tree<T>* tree, Btnode<T>* p, CString& s0) {
    if (p != NULL) {
        postrav(tree, p->lchild, s0);
        postrav(tree, p->rchild, s0);
        tree->selected = p;
        tree->makeSnapshoot();
        tree->makeSnapshoot();
        s0 += output(p->d);
    }
}

template <class T>
static void draw_tree(Binary_Tree<T>* tree, Btnode<T>* p, DrawNode dr, std::vector<DrawNode>& list) {
    if (p != NULL) {
        dr.ch = p->d;
        if (p->lchild) dr.lchild = true;
        if (p->rchild) dr.rchild = true;
        if (p == tree->selected) {
            dr.selected = true;
            tree->selected = NULL;
        }
        list.push_back(dr);
        dr.selected = false;
        ++dr.deep;
        dr.lchild = false;
        dr.rchild = false;

        DrawNode ldr = dr;
        ldr.right = (dr.left + dr.right) / 2;
        draw_tree(tree, p->lchild, ldr, list);
        DrawNode rdr = dr;
        rdr.left = (dr.left + dr.right) / 2;
        draw_tree(tree, p->rchild, rdr, list);
    }
}

template <class T>
static void mirror_tree(Binary_Tree<T>* tree, Btnode<T>* p) {
    if (p != NULL) {
        Btnode<T>* t = p->lchild;
        p->lchild = p->rchild;
        p->rchild = t;

        tree->selected = p;
        tree->makeSnapshoot();
        tree->makeSnapshoot();

        mirror_tree(tree, p->lchild);
        mirror_tree(tree, p->rchild);
    }
}