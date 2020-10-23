#include <iostream>
#include<cstring>
using namespace std;

struct ListNode
{
    int id;
    int a;
};

int main()
{
    int number,a1,search,n=0;
    char s[10];
    ListNode x[1000000];
    cin >> s;
    while (s != "EXIT")
    {
        if(s == "INSERT"){
            cin >> number >> a1;
            n++;
        }else
        {
            cin >> search;
            int i =0;
            while (x[i].a != search){
                i++;
            }
            if(i>n){
                cout << -1 << endl;
            }else
            cout << x[i].id << endl; // Process node
        }
    }
}