//
// Created by Acher on 2022/4/7.
// 没写完
//

#include "iostream"
#include "Graph.h"
using namespace std;

template<class T,class E>
class Graph_Matrix:public Graph<T,E>{
public:
    const E maxWeight = 100000;
    Graph_Matrix(int sz);
    Graph_Matrix();
    ~Graph_Matrix();
    void input();
    void output();
    void Default();
private:
    T *VerticesList;    //顶点
    E **Edge;           //边
};
template<class T,class E>
Graph_Matrix<T,E>::Graph_Matrix(){

}

template<class T,class E>
Graph_Matrix<T,E>::Graph_Matrix(int sz) {
    VerticesList=new T[sz];
    Edge=new E*[sz];
    for (int i = 0; i < sz; ++i) {
        Edge[i]=new E[sz];
    }
    for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < sz; ++j) {
            if (i == j)
                Edge[i][j] = 0;
            else
                Edge[i][j] = maxWeight;
        }
    }
}
template<class T,class E>
Graph_Matrix<T,E>::~Graph_Matrix() {

}

template<class T,class E>
void Graph_Matrix<T,E>::input() {

}

template<class T,class E>
void Graph_Matrix<T,E>::output() {

}

template<class T,class E>
void Graph_Matrix<T,E>::Default() {
    Edge=new E*[5];
    for (int i = 0; i < 5; ++i) {
        Edge[i]=new E(5);
    }
    Edge[0][0]=1;
    Edge[1][1]=1;
    Edge[2][2]=1;
    Edge[3][3]=1;
    Edge[4][4]=1;

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout<<Edge[i][j]<<" ";
        }
        cout<<"\n";
    }
    
}

int main(){
    Graph_Matrix<int,int> sz;
    sz.Default();
}

