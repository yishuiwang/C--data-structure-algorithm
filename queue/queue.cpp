//
// Created by Acher on 2022/4/3.
//

#include<iostream>
using namespace std;
template<class T>
class Queue {
public:
    Queue(int sz);	//构造函数
    ~Queue();//析构函数
    bool Enqueue(const T& x);//进队
    bool Dequeue(T& x);//出队
    bool getFront(T& x);//返回头元素的值
    bool IsEmpty();//空
    bool IsFull();//非空
    int getSize();//大小
private:
    T* elements;
    int rear;
    int front;
    int maxSize;
};

template<class T>
Queue<T>::Queue(int sz) {
    elements = new T[sz];
    maxSize = sz;
    rear = 0;
    front = 0;
}

template<class T>
Queue<T>::~Queue() {
    delete[] elements;
}

template<class T>
bool Queue<T>::IsEmpty() {
    if (rear==front){
        return true;
    }
    return false;
}

template<class T>
bool Queue<T>::IsFull() {
    if ((rear + 1) % maxSize == front) {
        return true;
    }
    return false;
}

template<class T>
bool Queue<T>::Enqueue(const T& x) {
    if (IsFull()) {
        cout << "队列已满，进队失败" << endl;
        return false;
    }
    elements[rear] = x;
    rear = (rear + 1) % maxSize;
    return true;
}

template<class T>
bool Queue<T>::Dequeue(T& x) {
    if (IsEmpty()) {
        cout << "队列已空，出队失败" << endl;
        return false;
    }
    x = elements[front];
    front = (front + 1) % maxSize;
    return true;
}

template<class T>
bool Queue<T>::getFront(T& x) {
    if (IsEmpty()) {
        cout << "队列已空" << endl;
        return false;
    }
    x = elements[front];
    return true;
}
template<class T>
int Queue <T>::getSize() {
    return rear-front;
}