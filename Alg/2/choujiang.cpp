
#include <iostream>
using namespace std;
int median3(int nums[], int left, int right){
	int center = (left + right) / 2;
	if(nums[left] > nums[center])
		swap(nums[left], nums[center]);
	if(nums[left] > nums[right])
		swap(nums[left], nums[right]);
	if(nums[center] > nums[right])
		swap(nums[center], nums[right]);//此时nums[left] <= nums[center] <= nums[right]
	swap(nums[center], nums[right-1]);//交换中枢和a[right-1]，此时上面三个值的居中的数在下标right-1处，然后返回中枢，由于a[right]必定比中枢大，故只需对区间[left, right-1]以中枢a[right-1]进行一次快速排序即可。
	return nums[right-1];
}

int QuickSelect(int nums[], int k, int left, int right){
	int pivot = median3(nums, left, right), i = left, j = right-1;
	while(i < j){
		while(nums[i] < pivot && i < j) ++i;
		nums[j] = nums[i];
		while(nums[j] >= pivot && i < j) --j;
		nums[i] = nums[j];
	}
	nums[i] = pivot;
	if(k < i)
		QuickSelect(nums, k, 0, i-1);
	else if(k > i)
		QuickSelect(nums, k, i+1, right);
	else
		return nums[i];
}


int main(){
    int n,k;
    cin >> n >> k;
    int a[n];
    for(int i = 0;i < n; i++){
        cin >> a[i];
    }
    cout << QuickSelect(a, k-1, 0, n-1);
}