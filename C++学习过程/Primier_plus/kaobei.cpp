#include <iostream>
using namespace std;

class person
{
private:
    /* data */
public:
    int age;
public:
    //�޲�(Ĭ��)���캯��
    person(/* args */){
        cout << "�޲ι��캯��" << endl;
        age = 0;
    };
    //�в�
    person(int a){
        cout << "�вι��캯��!" << endl;
        age = a;
    };
    //��������,Ҳ���Զ�ֵ����Ӧ�ĸ�����ʵ
    person(const person & p){
        cout << "�������캯��!" << endl;
		age = p.age + 1;
    };
    //�����������ͷ��ڴ�֮ǰ����,�������в���
    ~person(){
        cout << "��������!" << endl;
    };
};

void test1(){
    person p1(18);
    //�����д�������죬���������Զ���ӿ������죬������ǳ��������
	person p2(p1);
	cout << "p2������Ϊ�� " << p2.age << endl;
}

void test02()
{
	//����û��ṩ�вι��죬�����������ṩĬ�Ϲ��죬���ṩ��������
	person p1; //��ʱ����û��Լ�û���ṩĬ�Ϲ��죬�����
	person p2(10); //�û��ṩ���в�
	person p3(p2); //��ʱ����û�û���ṩ�������죬���������ṩ

	//����û��ṩ�������죬�����������ṩ�������캯��
	person p4; //��ʱ����û��Լ�û���ṩĬ�Ϲ��죬�����
	person p5(10); //��ʱ����û��Լ�û���ṩ�вΣ������
	person p6(p5); //�û��Լ��ṩ��������
}

int main(){
    test1();
    system("pause");
    return 0;
}