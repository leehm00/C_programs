#include <iostream>
using namespace std;

//ǳ�������򵥵ĸ�ֵ��������(֮ǰ�Ķ���ǳ����)
//������ڶ�����������ռ䣬���п�������
class person
{
private:
    /* data */
public:
    int m_age;
    int * m_height;
public:
    //�޲Σ�Ĭ�ϣ����캯��
    person(/* args */){
        cout << "�޲ι��캯��!" << endl;
    };
    //�вι��캯��
    person(int age, int height){
        cout << "�вι��캯��!" << endl;
        m_age = age;
        m_height = new int(height);

    };
    person(const person&p){
        cout << "�������캯��!" << endl;
		//�������������ڶ����������ڴ棬�ᵼ��ǳ�����������ظ��ͷŶ�������
        m_age = p.m_age;
        m_height = new int(*p.m_height);
    };
    //��������,һ��Ҫ�ǵ��ͷſռ�
	~person() {
		cout << "��������!" << endl;
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

	cout << "p1�����䣺 " << p1.m_age << " ��ߣ� " << *p1.m_height << endl;

	cout << "p2�����䣺 " << p2.m_age << " ��ߣ� " << *p2.m_height << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}
//����������ڶ������ٵģ�һ��Ҫ�Լ��ṩ�������캯������ֹǳ��������������