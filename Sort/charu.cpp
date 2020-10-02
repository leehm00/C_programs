#include<iostream>
using namespace std;

int length(int *a){
    return sizeof(a)/sizeof(int);
}

int INSERT(int *a){
    for(int j = 0;j < length(a);j++){
        int key = a[j];
        int i = j - 1;
        while(i > 0 && a[i] > key){
            a[i + 1] = a[i];
            i = i-1;
        }
        a[i + 1] = key;
    }
}