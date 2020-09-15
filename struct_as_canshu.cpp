#include <iostream>
#include <string>
using namespace std;


struct student{
    /* data */
    string name;
    int age;
    int score;
};


void printStudent1(student stu){
    //值传递
    stu.age = 999;
    cout << "值传递里面打印" << stu.age << endl;
}


void printStudent2(student *stu){
    //地址传递
    stu->score = 99;
    cout << "地址传递里面打印" << stu->score << endl;
}


int main(){
    student s;
    s.name = "David";
    s.age = 19;
    s.score = 100;
    printStudent1(s);
    printStudent2(&s);
    cout << "main里面打印,name  " << s.name << "    age  " << s.age << "   score  " << s.score;
    return 0;
}