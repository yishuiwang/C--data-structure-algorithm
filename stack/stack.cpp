//
// Created by Acher on 2022/4/3.
//

#include<iostream>
#include"stack.h"
using namespace std;
template<class T>
class SeqStack :public Stack<T> {
public:
    SeqStack();
    SeqStack(int sz);
    ~SeqStack();
    void Push(const T& x);
    bool Pop(T& x);
    bool getTop(T& x);
    bool IsEmpty();
    bool IsFull();
    int getSize();
private:
    T* elements;
    int top;
    int maxSize;
};


template<class T>
SeqStack<T>::SeqStack(int sz) {
    elements = new T[sz];
    top = -1;
    maxSize = sz;
}

template<class T>
SeqStack<T>::~SeqStack() {
    delete[] elements;
}

template<class T>
void SeqStack<T>::Push(const T& x) {
    if (IsFull()) {
        cout << "栈满溢出，overflowProcess";
        return;
    }
    elements[++top] = x;
}

template<class T>
bool SeqStack<T>::Pop(T& x) {
    if (IsEmpty()) {
        return false;
    }
    x = elements[top--];
    return true;
}

template<class T>
bool SeqStack<T>::getTop(T& x) {
    if (IsEmpty()) {
        return false;
    }
    x = elements[top];
    return true;
}

template<class T>
bool SeqStack<T>::IsEmpty() {
    if (top == -1) {
        return true;
    }
    return false;
}

template<class T>
bool SeqStack<T>::IsFull() {
    if (top == maxSize) {
        return true;
    }
    return false;
}

template<class T>
int SeqStack<T>::getSize() {
    return top;
}