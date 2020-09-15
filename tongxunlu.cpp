#include <iostream>
using namespace std;


void showmenu(){
    cout << "**********************" << endl;
    cout << "***** 1添加联系人 *****" << endl;
    cout << "***** 2显示联系人 *****" << endl;
    cout << "***** 3删除联系人 *****" << endl;
    cout << "***** 4查找联系人 *****" << endl;
    cout << "***** 5修改联系人 *****" << endl;
    cout << "***** 6清空联系人 *****" << endl;
    cout << "***** 0退出通讯录 *****" << endl;
}


int main(){
    int select;
    while(true){
        showmenu();
        cin >> select;
        switch(select){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 0:
                cout << "欢迎下次使用" << endl;
                return 0;
            default:
                break;
        }
    }
    return 0;
}