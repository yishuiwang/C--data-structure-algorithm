//
// Created by Acher on 2022/4/16.
//

#include "iostream"
#include "string"
#include "math.h"

using namespace std;

class Samples {
public:
    void input();

    void output(int i);

    float GetDistance(float *a, float *b);

    int Adjust();

private:
    int m;
    int n;
    int s;
    int k;
    float **pattern;
    float *unknow;
    int *labels;
    string *name;
    string *type;
};

void Samples::input() {

    //m（样本数）, n（特征维数）, s（类别数，K-Means算法该项为0）
    cin >> m >> n >> s;
    pattern = new float *[m];
    for (int i = 0; i < m; ++i) {
        pattern[i] = new float[n];
    }
    name = new string[n];
    labels = new int[m];

    //m行（每行n列）输入样本；
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> pattern[i][j];
        }
        cin >> labels[i];
    }

    //输入n项特征的名称；
    for (int i = 0; i < n; ++i) {
        cin >> name[i];
    }

    //当s>0，输入一行s项类别的名称；
    if (s > 0) {
        type = new string[s];
        for (int i = 0; i < s; ++i) {
            cin >> type[i];
        }
    }
    //输入K值
    cin >> k;

    //输入未知样本
    unknow = new float[n];
    for (int i = 0; i < n; ++i) {
        cin >> unknow[i];
    }
}

void Samples::output(int i) {
    cout << type[labels[i]];
}

float Samples::GetDistance(float *a, float *b) {
    int len = sizeof(a) / sizeof(float);
    float distance = 0;
    for (int i = 0; i < len; ++i) {
        distance += pow(a[i] - b[i], 2);
    }
    return sqrt(distance);
}

int Samples::Adjust() {
    float *distances;
    distances = new float[m];
    float minDistance = 0x11111;
    for (int i = 0; i < m; ++i) {
        distances[i] = GetDistance(unknow, pattern[i]);
        if (distances[i] < minDistance) {
            minDistance = distances[i];
        }
    }

    for (int i = 0; i < m; ++i) {
        if (distances[i] == minDistance) {
            return i;
        }
    }

}


int main() {
    Samples sz;
    sz.input();
    int i = sz.Adjust();
    sz.output(i);
}
/*
12 4 2
228 134 20 11 0
245 134 10 40 0
200 167 12 27 0
170 150 7 8 0
100 167 20 14 0
150 117 7 6 1
120 133 10 26 1
160 100 5 10 1
185 115 5 19 1
170 125 6 4 1
165 142 5 3 1
185 108 2 12 1
铜蓝蛋白 蓝色反应 吲哚乙酸 中性硫化物
阳性 阴性
1
100 117 7 2

 */
