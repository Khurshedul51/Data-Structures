#include <bits/stdc++.h>
using namespace std;

template<class T>
void insertionSort(T A[], int size){
    for(int i = 1; i<size; i++){
        T key = A[i];
        int j = i-1;
        while(key <= A[j] && j>=0){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
}
int main(){

    return 0;
}