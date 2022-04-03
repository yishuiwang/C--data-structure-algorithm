//
// Created by Acher on 2022/3/29.
//
#include "iostream"
using namespace std;

int main()
{
    int num_of_object;
    cin>>num_of_object;

    int weight;
    int value;
    for (int i = 0; i < num_of_object; ++i) {
        cin>>weight>>value;
    }

    int capacity;
    cin>>capacity;

    for (int i = 0; i < num_of_object; ++i) {
        cout<<"F[ " <<i+1<< " ]:     ";
        for (int j = 0; j < capacity-1; ++j) {
            cout<<"0    ";
        }
        cout<<"0"<<endl;
    }
    for (int i = 0; i < num_of_object; ++i) {
        cout<<"i[ "<<i+1<< " ]:     ";
        for (int j = 0; j < capacity-1; ++j) {
            cout<<"0    ";
        }
        cout<<"0"<<endl;
    }

    cout<<"[";
    for (int i = 0; i < num_of_object-1; ++i) {
        cout<<"0, ";
    }
    cout<<"0]"<<endl;


}


//F[ 1 ]:     0    0    0    0    0    0    0    0    0
//[0, 0, 0]
/*
3

1 1

2 3

4 7

9
 */
