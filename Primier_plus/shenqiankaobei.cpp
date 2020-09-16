#include <iostream>
using namespace std;

//浅拷贝：简单的赋值拷贝操作(之前的都是浅拷贝)
//深拷贝：在堆区重新申请空间，进行拷贝操作
class person
{
private:
    /* data */
public:
    int m_age;
    int * m_height;
public:
    //无参（默认）构造函数
    person(/* args */){
        cout << "无参构造函数!" << endl;
    };
    //有参构造函数
    person(int age, int height){
        cout << "有参构造函数!" << endl;
        m_age = age;
        m_height = new int(height);

    };
    person(const person&p){
        cout << "拷贝构造函数!" << endl;
		//如果不利用深拷贝在堆区创建新内存，会导致浅拷贝带来的重复释放堆区问题
        m_age = p.m_age;
        m_height = new int(*p.m_height);
    };
    //析构函数,一定要记得释放空间
	~person() {
		cout << "析构函数!" << endl;
		if (m_height != NULL)
		{
			delete m_height;
		}
	}
};

void test01()
{
	person p1(18, 180);

	person p2(p1);

	cout << "p1的年龄： " << p1.m_age << " 身高： " << *p1.m_height << endl;

	cout << "p2的年龄： " << p2.m_age << " 身高： " << *p2.m_height << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}
//如果属性有在堆区开辟的，一定要自己提供拷贝构造函数，防止浅拷贝带来的问题