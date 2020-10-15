#include <iostream>
using namespace std;
struct stu
{
    int id;
    int math;
    int en;
    int total;
};

void shellSorttotal(stu *arr, int n) {
    int gap, j, k;
    for(gap = n/2; gap > 0; gap = gap / 2) {        //initially gap = n/2,decreasing by gap /2
        for(j = gap; j<n; j++) {
            for(k = j-gap; k>=0; k -= gap) {
                if(arr[k+gap].total > arr[k].total)
                    break;
                else if(arr[k+gap].total == arr[k].total){
                    if(arr[k+gap].math > arr[k].math)
                            break;
                        else if(arr[k+gap].math == arr[k].math){
                            if(arr[k+gap].en > arr[k].en)
                                    break;
                                else if(arr[k+gap].en == arr[k].en){
                                    if(arr[k+gap].id >= arr[k].id)
                                            break;
                                        else
                                            swap(arr[k+gap], arr[k]);
                                }else swap(arr[k+gap], arr[k]);
                        }else swap(arr[k+gap], arr[k]);
                }else swap(arr[k+gap], arr[k]);
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    stu students[n];
    for(int i = 0;i < n;i++){
        cin >> students[i].id >> students[i].math >> students[i].en;
        students[i].total = students[i].math + students[i].en;
    }
    shellSorttotal(students,n);
    for (int i = n-1; i >=0; i--)
    {
        cout << students[i].id << " " << students[i].total << endl;
    }
}