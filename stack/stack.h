//
// Created by Acher on 2022/4/3.
//

#ifndef DATA_STRUCT____ALGORITHM_STACK_H
#define DATA_STRUCT____ALGORITHM_STACK_H


const int maxSize = 50;
template<class T>
class Stack {
public:
    Stack() {};
    virtual void Push(const T& x) = 0;
    virtual bool Pop(T& x) = 0;
    virtual bool getTop(T& x) = 0;
    virtual bool IsEmpty()  = 0;
    virtual bool IsFull()  = 0;
    virtual int getSize()  = 0;

};


#endif //DATA_STRUCT____ALGORITHM_STACK_H
