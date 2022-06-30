//
// Created by Acher on 2022/5/5.
//
#include<iostream>
using namespace std;

//用第一个元素将待排序序列划分成左右两个部分
int partition(int a[], int low, int high) {
    //第一个元素作为枢纽
    int pivot = a[low];
    while (low < high) {

        //比枢纽小的元素移动到左端
        while (low < high && a[high] >= pivot) {
            high--;
        }
        a[low] = a[high];
        //比枢纽大的元素移动到右端
        while (low < high && a[low] <= pivot) {
            low++;
        }
        a[high] = a[low];
    }
    //每次划分完后枢纽元素回到最终位置,此时low==high
    a[low] = pivot;
    //返回存放枢纽的最终位置
    return low;

}

// 快速排序

void quickSort(int a[], int low, int high) {
    if (low < high) { //递归跳出条件
        int pivotPosition = partition(a, low, high);
        quickSort(a, low, pivotPosition - 1);
        quickSort(a, pivotPosition + 1, high);
    }
}

void printArr(int a[], int len) {

    for (int i = 0; i < len; i++) {
        printf("%d  ", a[i]);
    }
    printf("\n");
}


int main() {
    int arr[6] = {23, 54, 12, 4, 5,6};
    int len = sizeof(arr) / sizeof(int);
    printArr(arr, len);
    quickSort(arr,0,5);
    printArr(arr, len);
    system("pause");
}