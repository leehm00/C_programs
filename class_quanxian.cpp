#include <iostream>
using namespace std;

class person
{
private:
    /* data */
    int m_password;
public:
    string m_name;
public:
    void func(){
        m_name = "zhangsan";
        m_car = "car";
        m_password = 123456;
    }
protected:
    string m_car;
};

int main(){
    person p,p1;
    p1.func();
    p.m_name = "lisi";
    //p.m_car = "奔驰";  //保护权限类外访问不到
	//p.m_password = 123; //私有权限类外访问不到
    //cout << p1.m_car << p1.m_password;//保护,私有权限类外访问不到
	system("pause");

	return 0;
}
//在C++中struct和class唯一的区别就在于默认的访问权限不同
//struct 默认权限为公共
//class  默认权限为私有(就是在前面public,private,protected都不加,直接声明)