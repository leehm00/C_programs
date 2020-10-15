#include<iostream>
using namespace std;

void shellSort(int *arr, int n) {
    int gap, j, k;
    for(gap = n/2; gap > 0; gap = gap / 2) {        //initially gap = n/2,decreasing by gap /2
        for(j = gap; j<n; j++) {
            for(k = j-gap; k>=0; k -= gap) {
                if(arr[k+gap] >= arr[k])
                    break;
                else
                std:swap(arr[k+gap], arr[k]);
            }
        }
    }
}