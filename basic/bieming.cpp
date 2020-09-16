#include <iostream>
using namespace std;


int main(){
    int a = 10;
    int &b = a;//不可以直接写作int &b = 10;
    int * const c = &a;//这里c和b等价
    cout << "before" << a << b <<endl;
    b = 100;
    cout << "after" << a << b <<endl;
    system("pause");
    return 0;
}