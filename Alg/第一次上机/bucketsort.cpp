#include <iostream>
#include <vector>
#include <time.h>
#include <Windows.h>
using namespace std;
 
void Bucket_sort(double a[],size_t n)
{
	double **p = new double *[10];//p数组存放十个double指针，分为10个桶
	for (int i=0; i < 10; ++i)
	{
		p[i] = new double[100];//每个指针都指向一块10个double的数组，每个桶都可以包含100个元素
	}
 
	int count[10] = {0};//元素全为0的数组
	for (int i = 0; i < n; ++i)
	{
		double temp = a[i];
		int flag = (int)(temp*10);//判断每个元素属于哪个桶
		p[flag][count[flag]] = temp;//将每个元素放入到对应的桶中，从0开始
		int j = count[flag]++;//将对应桶的计数加1
 
		//在本桶之中与之前的元素做比较，比较替换（插入排序）
		for (;j > 0 && temp < p[flag][j-1];--j)
		{
			p[flag][j] = p[flag][j-1];
		}
		p[flag][j] = temp;
	}
 
	//元素全部放完之后，需要进行重新链接的过程
	int k = 0;
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < count[i]; ++j)//桶中元素的个数count[i]
		{
			a[k++] = p[i][j];
		}
	}
 
	//申请内存的释放
	for (int i = 0 ; i<10 ;i++)  
	{  
		delete p[i];  
		p[i] =NULL;  
	}  
	delete []p;  
	p = NULL;  
}  
 
void Bucket_sort(vector<double>::iterator begin,vector<double>::iterator end)
{
	double **p = new double*[10];//分10个桶
	for (int i = 0; i < 10; ++i)
	{
		p[i] = new double[end-begin];//每个桶至多存放end-begin个元素
	}
	auto iter1 = begin;
 
	int count[10] = {0};//桶内元素计数
	for (iter1; iter1 != end; ++iter1)
	{
		double temp = *iter1;//保存当前值
		int flag = (int)(temp*10);//确定桶序号
	
		p[flag][count[flag]] = temp;
		int j = count[flag]++;//桶内元素计数加一
 
		for (j;j >0 && temp < p[flag][j-1]; --j)
		{
			p[flag][j] = p[flag][j-1];
		}
		p[flag][j] = temp;//将本值插入桶中的适当位置
	}
 
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < count[i]; ++j)
		{
			*begin++ = p[i][j];
		}
	}
 
	for (int i = 0; i < 10; ++i)
	{
		delete p[i];
		p[i] = NULL;
	}
	delete []p;
	p = NULL;
}
 
 
//随机初始化数组[0,1)
void Initial_array(double a[],size_t n)
{
	for (size_t i = 0; i < n; ++i)
	{
		//rand()的返回值应该是[0, RAND_MAX]，最小可能为0，最大可能为RAND_MAX。
		//rand()/(RAND_MAX+0.0)和rand()/(RAND_MAX+1.0)
		//当rand()返回0，前者为0，后者为0
		//当rand()返回RAND_MAX，前者为1，后者为非常接近1的一个小数。
		a[i] = rand()/double(RAND_MAX+1);
	}
}
 
int main(int argc, char **argv)
{
	double a[50];
	Initial_array(a,50);
	vector<double> vec(a,a+50);
 
	Bucket_sort(a,50);
	for (int i = 0; i < 50; ++i)
	{
		cout<<a[i]<<" ";
	}
 
	cout<<endl;
	Bucket_sort(vec.begin(),vec.end());
	for (int i = 0; i < 50; ++i)
	{
		cout<<vec[i]<<" ";
	}
	cin.get();
	return 0;
}
