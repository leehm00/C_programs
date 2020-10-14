#include <iostream>
using namespace std;
struct stu
{
    int id;
    int math;
    int en;
    int total;
};

void quickSorttotal(stu students[], int l, int r)
{
	if (l< r)
	{
		int i = l, j = r;
        stu x = students[l];
		while (i < j)
		{
			while(i < j && students[j].total>= x.total) // 从右向左找第一个小于x的数
				j--;
			if(i < j)
				students[i++] = students[j];
			while(i < j && students[i].total< x.total) // 从左向右找第一个大于等于x的数
				i++;
			if(i < j)
				students[j--] = students[i];
		}
		students[i] = x;
		quickSorttotal(students, l, i - 1); // 递归调用
		quickSorttotal(students, i + 1, r);
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
    quickSorttotal(students,0,n);
    for (int i = 0; i < n; i++)
    {
        cout << students[i].id << "\t";
    }
    

}