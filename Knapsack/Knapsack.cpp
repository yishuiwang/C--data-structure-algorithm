//
// Created by Acher on 2022/3/29.
//
#include "iostream"
#include "iomanip"

using namespace std;

class knapsack {
public:
    //~knapsack();

    void input();

    void output();

    void Adjust();

private:
    int capacity;            //物品数量
    int num_of_object;       //物品个数
    int *weight;             //物品重量
    int *value;              //物品价值
    int **f;                 //优化函数
    int **note;              //标记函数
    int *Container;          //背包所含物品
};

void knapsack::Adjust() {
    for (int i = 0; i < num_of_object; i++) {
        for (int j = 1; j <= capacity; j++) {
            //默认不做调整
            if (i >= 1) {
                note[i][j] = note[i - 1][j];
                f[i][j] = f[i - 1][j];
            }
            //当背包容量大于物品容量时开始调整
            if (j >= weight[i]) {
                int temp = f[i][j];
                //取其中较大值作为f[i][j]的值
                f[i][j] = max(f[i][j], f[i][j - weight[i]] + value[i]);
                if (temp != f[i][j]) {
                    //更新标记函数
                    note[i][j] = i + 1;
                }
            }
        }
    }
    int w = capacity, n = num_of_object - 1;
    while (note[n][w] != 0 && w > 0 && n >= 0) {
        //找出标记函数所标记的物品
        n = note[n][w] - 1;
        //标记为已选
        Container[n] = Container[n] + 1;
        //从背包容量中减去
        w -= weight[n];
    }
}


//knapsack::~knapsack() {
//    delete[] weight;
//    delete[] value;
//    delete[] Container;
//    for (int i = 0; i <= num_of_object; ++i) {
//        delete[] note[i];
//        delete[] f[i];
//    }
//    delete[] f;
//    delete[] note;
//}

void knapsack::input() {
    cin >> num_of_object;
    weight = new int[num_of_object + 1];
    value = new int[num_of_object + 1];
    Container=new int [num_of_object+1];
    for (int i = 0; i < num_of_object; ++i) {
        cin >> weight[i] >> value[i];
    }
    cin >> capacity;
    f = new int *[capacity + 1];
    note = new int *[num_of_object + 1];
    for (int i = 0; i <= num_of_object; ++i) {
        note[i] = new int[capacity];
        f[i] = new int[capacity];
    }
    //初始化
    for (int i = 0; i <= num_of_object; ++i) {
        for (int j = 0; j <= capacity; ++j) {
            note[i][j] = 0;
            f[i][j] = 0;
            Container[i]=0;
        }
    }
}

void knapsack::output() {
    for (int i = 0; i < num_of_object; ++i) {
        cout << "F[ " << i + 1 << " ]: ";
        for (int j = 1; j <= capacity; ++j) {
            cout << setw(5) << f[i][j];
        }
        cout << endl;
    }
    for (int i = 0; i < num_of_object; ++i) {
        cout << "i[ " << i + 1 << " ]: ";
        for (int j = 1; j <= capacity; ++j) {
            cout << setw(5) << note[i][j];
        }
        cout << endl;
    }
    cout<<"[";
    for (int i = 0; i < num_of_object-1; ++i) {
        cout<<Container[i]<<", ";
    }
    cout<<Container[num_of_object-1]<<"]"<<endl;
}

int main() {
    knapsack sz;
    sz.input();
    sz.Adjust();
    sz.output();
    return 0;
}

//F[ 1 ]:     0    0    0    0    0    0    0    0    0
//[0, 0, 0]
/*
4
2 1
3 3
4 5
7 9
10
 */
