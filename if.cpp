#include <iostream>
using namespace std;
int main(){
    int score;
    cin >> score;
    if (score > 600){
        cout << "Congradulations!" << endl;
    }else{
        cout << "Failed" << endl;
    }
    return 0;
}