//
// Created by Acher on 2022/4/3.
//

#include<iostream>
using namespace std;
template<class T>
struct LinkNode {
    T data;
    LinkNode<T>* link;
    LinkNode(LinkNode<T>* ptr = NULL) { link = ptr; }
    LinkNode(T& x, LinkNode<T>* ptr = NULL) {
        data = x;
        link = ptr;
    }
};

template<class T>
class List {
public:
    List();
    List(T& x);
    ~List();
    void makeEmpty();
    int Length();
    bool getData(int i, T& x);
    bool setData(int i, const T& x);
    bool Insert(int i, T& x);
    bool Remove(int i, T& x);
    bool IsEmpty();
    bool IsFull();
    void Input();
    void Output();
    LinkNode<T>* Locate(int i);
private:
    LinkNode<T>* first;
};

template<class T>
List<T>::List(){
    first = new LinkNode<T>;
}

template<class T>
List<T>::List(T &x) {
    first = new LinkNode<T>(x);
}

template<class T>
List<T>::~List() {
    makeEmpty();
}

template<class T>
void List<T>::makeEmpty() {
    LinkNode<T>* p;
    while (first-> link != NULL) {
        p = first->link;
        first->link = p->link;
        delete p;
    }
}

template<class T>
int List<T>::Length() {
    int count = 0;
    LinkNode<T>* p = first->link;
    while (p != NULL) {
        p = p->link;
        count++;
    }
    return count;
}

template<class T>
LinkNode<T>* List<T>::Locate(int i) {
    if (i < 0&&i>Length()) {
        cout << "input error" << endl;
        return NULL;
    }
    LinkNode<T>* current = first;
    int k = 0;
    while (current!=NULL&&k<i){
        current = current->link;
        k++;
    }
    return current;
}

template<class T>
bool List<T>::Insert(int i,T&x) {
    LinkNode<T>* p = Locate(i);
    if (p == NULL) {
        return false;
    }
    LinkNode<T>* q = new LinkNode<T>(x);
    q->link = p->link;
    p->link = q;
    return true;
}


template<class T>
bool List<T>::setData(int i, const T& x) {
    LinkNode<T>* p = Locate(i);
    if (p == NULL) {
        return false;
    }
    p->data = x;
    return true;
}

template<class T>
bool List<T>::getData(int i,T&x) {
    LinkNode<T>* p = Locate(i);
    if (p == NULL) {
        return false;
    }
    x = p->data;
    return true;
}

template<class T>
bool List<T>::Remove(int i, T& x) {
    LinkNode<T>* p = Locate(i-1);
    if (p == NULL&&p->link==NULL) {
        return false;
    }
    x = p->data;
    LinkNode<T>* q;
    q = p->link;
    p->link = q->link;
    delete q;
    return true;
}

template<class T>
bool List<T>::IsEmpty() {
    if (first == NULL) {
        return true;
    }
    return false;
}

template<class T>
bool List<T>::IsFull() {
    return false;
}


template<class T>
void List<T>::Input() {
    for (int i = 0; i < 10; i++) {
        Insert(i, i);
    }
}

template<class T>
void List<T>::Output() {
    LinkNode<T>* p = first->link;
    while(p != NULL) {
        cout << p->data << "<=";
        p = p->link;
    }
    cout << endl;
}

