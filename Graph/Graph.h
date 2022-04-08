//
// Created by Acher on 2022/4/7.
//

#ifndef DATA_STRUCT____ALGORITHM_GRAPH_H
#define DATA_STRUCT____ALGORITHM_GRAPH_H

template <class T,class E>
class Graph{
public:
    Graph();
private:
    int maxVertices;    //图中最大顶点数
    int numEdge;        //当前边数
    int numVertices;    //当前顶点数
    int getVertexPos;
};

#endif //DATA_STRUCT____ALGORITHM_GRAPH_H
