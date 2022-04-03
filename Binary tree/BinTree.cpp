//
// Created by Acher on 2022/4/3.
//
#include "iostream"
using namespace std;

template<class T>
struct BinTreeNode {
    T data;
    BinTreeNode<T> *left,*right;
};


template<class T>
class BinTree{
public:

private:
    BinTreeNode<T> *root;
};


