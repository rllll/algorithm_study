#include<iostream>
using namespace std;

void CountingSort(int *a, int size){
    int max = a[0];
    for(int i = 1; i < size; i++){
        if(a[i] > max){
            max = a[i];
        }
    }
    max++;
    int num[max]={0};
    for(int i = 0; i < size; i++){
        num[a[i]]++;
    }
    for(int i = 0; i < max; i++){
        if(num[i]){
            cout << i << " ";
            num[i]--;
            i--;
        }
    }
}

void test(){
    int a[10] = {4,12,78,23,56,23,67,19,45,17};
    int size = sizeof(a)/sizeof(int);
    CountingSort(a,size);
}

int main(){
    test();
    return 0;
}