#include <iostream>
using namespace std;

void quickSort(int s[], int l, int r)
{
	if (l< r)
	{
		int i = l, j = r, x = s[l];
		while (i < j)
		{
			while(i < j && s[j]>= x) // 从右向左找第一个小于x的数
				j--;
			if(i < j)
				s[i++] = s[j];
			while(i < j && s[i]< x) // 从左向右找第一个大于等于x的数
				i++;
			if(i < j)
				s[j--] = s[i];
		}
		s[i] = x;
		quickSort(s, l, i - 1); // 递归调用
		quickSort(s, i + 1, r);
	}
}

int main(){
    int n;
	int i,j,temp,count;
	cin >> n;
	int A[n];
	int result[n][2];
    for(i = 0;i < n;i++){
        cin >> A[i];
    }
    quickSort(A,0,n - 1);
    result[0][0]=A[0];
	result[0][1]=1;
	count=0;
	for(i=1;i<n;i++){
		if(A[i]==result[count][0]){
			result[count][1]++;
		}else{
			count++;
			result[count][0]=A[i];
			result[count][1]=1;
		}
	}
    for(i=1;i<=count;i++){
		for(j=i;j>0&&result[j][1]>result[j-1][1];j--){
			temp=result[j][0];
			result[j][0]=result[j-1][0];
			result[j-1][0]=temp;
			temp=result[j][1];
			result[j][1]=result[j-1][1];
			result[j-1][1]=temp;
		}
	}
    for(i = 0;i <= count;i++){
        cout << result[i][0] << "\t" << result[i][1] << endl;
    }
}