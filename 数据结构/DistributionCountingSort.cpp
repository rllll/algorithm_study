#include<iostream>
using namespace std;

void DistributionCountingSort(int *a, int size, int l, int r){
    int range = r-l+1;
    int D[range]={0};
    for(int i=0; i < size; i++){
        D[a[i]-l]++;
    }
    for(int i=1; i < range; i++){
        D[i] = D[i-1] + D[i];
    }
    int Sort[size];
    for(int i = size-1; i >= 0; i--){
        int j = a[i]-l;
        Sort[D[j]-1]=a[i];
        D[j]--;
    }
    for(int i = 0; i < size; i++){
        cout << Sort[i] << " ";
    }
}
void test(){
    int a[10] = {4,12,78,23,56,23,67,19,45,17};
    int size = sizeof(a)/sizeof(int);
    int l=a[0],r=a[0];
    for(int i = 0; i < size; i++){
        if(a[i] < l){
            l = a[i];
        }
        if(a[i] > r){
            r = a[i];
        }
    }
    DistributionCountingSort(a,size,l,r);
}
int main(){
    test();
    return 0;
}