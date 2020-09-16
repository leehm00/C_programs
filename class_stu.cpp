#include <iostream>
using namespace std;

class student
{
private:
    /* data */
public:
    string m_name;
    int m_id;
public:
    void setname(string name){
        m_name = name;
    }

    void setid(int id){
        m_id = id;
    }

    void show(){
        cout << "name:" << m_name << "\t" << "id:" << m_id << endl;
    }
};

int main(){
    student stu;
    stu.setname("leehm");
    stu.setid(1495);
    stu.show();
    system("pause");
    return 0;
}
