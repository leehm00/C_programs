#include <iostream>
using namespace std;
int main(){
    int a = 10;
    const int *p = &a;//常量指针:指针的指向可以修改,不可以通过指针修改指向的值
    cout << p;
    int * const p_converse = &a;//指针常量:指针的指向不可以改变,可以通过指针修改指向的值
    const int * const p_restricted = &a;//都不可以改
}