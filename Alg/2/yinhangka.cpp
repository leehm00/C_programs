#include <iostream>
using namespace std;

int FindSecMax(int arr[], int len)
{
    int sec_Max = -32767;
    int Max = arr[0];
    for (int i = 1; i < len; i++)
    {
        if (arr[i] > Max)
        {
            sec_Max = Max;
            Max = arr[i];
        }
        else
        {
            if (arr[i] > sec_Max)
                sec_Max = arr[i];
        }
    }

    return sec_Max;
}

int main(){
    int n,k,i,j,max,smax=0;
    cin >> n >> k;
    int a[n];
    for(i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
    max = a[0];
    for(i=0;i<k;i++){
        if(a[i]>max){
            max = a[i];
        }
    }
    smax = FindSecMax(a,k);
    cout << max;
    for(i=1;i<=n-k;i++){
        if(a[i+k-1]>max)
            max = a[i+k];
        cout << " " << max;
    }
}