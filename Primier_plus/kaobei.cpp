#include <iostream>
using namespace std;

class person
{
private:
    /* data */
public:
    int age;
public:
    //无参(默认)构造函数
    person(/* args */){
        cout << "无参构造函数" << endl;
        age = 0;
    };
    //有参
    person(int a){
        cout << "有参构造函数!" << endl;
        age = a;
    };
    //拷贝函数,也可以对值做相应的更改其实
    person(const person & p){
        cout << "拷贝构造函数!" << endl;
		age = p.age + 1;
    };
    //析构函数在释放内存之前调用,不可以有参数
    ~person(){
        cout << "析构函数!" << endl;
    };
};

void test1(){
    person p1(18);
    //如果不写拷贝构造，编译器会自动添加拷贝构造，并且做浅拷贝操作
	person p2(p1);
	cout << "p2的年龄为： " << p2.age << endl;
}

void test02()
{
	//如果用户提供有参构造，编译器不会提供默认构造，会提供拷贝构造
	person p1; //此时如果用户自己没有提供默认构造，会出错
	person p2(10); //用户提供的有参
	person p3(p2); //此时如果用户没有提供拷贝构造，编译器会提供

	//如果用户提供拷贝构造，编译器不会提供其他构造函数
	person p4; //此时如果用户自己没有提供默认构造，会出错
	person p5(10); //此时如果用户自己没有提供有参，会出错
	person p6(p5); //用户自己提供拷贝构造
}

int main(){
    test1();
    system("pause");
    return 0;
}