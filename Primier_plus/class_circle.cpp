#include <iostream>
using namespace std;
const double PI = 3.14159;


class Circle
{
private:
    /* data */
public:
    int m_r;
    double calculateZC(){
        return 2*PI*m_r;
    }
};

int main(){
    Circle c1;
    c1.m_r = 10;
    cout << "圆的周长" << c1.calculateZC() << endl;
    system("pause");
    return 0;
}