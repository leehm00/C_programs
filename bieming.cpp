#include <iostream>
using namespace std;


int main(){
    int a = 10;
    int &b = a;
    cout << "before" << a << b <<endl;
    b = 100;
    cout << "after" << a << b <<endl;
    system("pause");
    return 0;
}