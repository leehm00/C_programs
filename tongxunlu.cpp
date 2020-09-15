#include <iostream>
#include <string>
#define MAX 1000
using namespace std;


struct  person//通讯录成员
{
    /* data */
    string m_name;
    int m_age;
    int m_sex;
    string m_phone;
    string m_addr;
};


struct addressbook
{
    person personarray[MAX];
    int m_size;
};


void showmenu(){
    cout << "**********************" << endl;
    cout << "***** 1添加联系人 *****" << endl;
    cout << "***** 2显示联系人 *****" << endl;
    cout << "***** 3删除联系人 *****" << endl;
    cout << "***** 4查找联系人 *****" << endl;
    cout << "***** 5修改联系人 *****" << endl;
    cout << "***** 6清空联系人 *****" << endl;
    cout << "***** 0退出通讯录 *****" << endl;
    cout << "**********************" << endl;
}


void addperson(addressbook *ads)
{
    if(ads->m_size == MAX){
        cout << "通讯录已满" <<endl;
        return;
    }else{
        cout << "输入姓名" << endl;
        cin >> ads->personarray[ads->m_size].m_name;
        cout << "输入年龄" << endl;
        cin >> ads->personarray[ads->m_size].m_age;
        cout << "输入性别 0-女 1-男" << endl;
        cin >> ads->personarray[ads->m_size].m_sex;
        cout << "输入电话号码" << endl;
        cin >> ads->personarray[ads->m_size].m_phone;
        cout << "输入住址" << endl;
        cin >> ads->personarray[ads->m_size].m_addr;
        ads->m_size ++;
        cout << "添加成功" << endl;
        system("pause");//请按任意键继续
        system("cls");//清屏操作
    }
}


void showperson(addressbook *ads){
    if(ads->m_size == 0){
        cout << "空记录" << endl;
        return;
    }else{
        for(int i = 0;i < ads->m_size;i++){
            cout << "姓名：" << ads->personarray[i].m_name << "\t";
			cout << "性别：" << (ads->personarray[i].m_sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << ads->personarray[i].m_age << "\t";
			cout << "电话：" << ads->personarray[i].m_phone << "\t";
			cout << "住址：" << ads->personarray[i].m_addr << endl;
        }
    }
    system("pause");
    system("cls");
}


int isexist(addressbook *ads,string name){
    for(int i = 0;i < ads->m_size;i++){
        if(ads->personarray[i].m_name == name){
            return i;
        }
    }
    return -1;
}


void deleteperson(addressbook *abs){
	cout << "请输入您要删除的联系人" << endl;
	string name;
	cin >> name;

	int ret = isexist(abs, name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->m_size; i++)
		{
			abs->personarray[i] = abs->personarray[i + 1];
		}
        abs->m_size--;
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");
}


void findperson(addressbook * abs)
{
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;

	int ret = isexist(abs, name);
	if (ret != -1)
	{
		cout << "姓名：" << abs->personarray[ret].m_name << "\t";
		cout << "性别：" << abs->personarray[ret].m_sex << "\t";
		cout << "年龄：" << abs->personarray[ret].m_age << "\t";
		cout << "电话：" << abs->personarray[ret].m_phone << "\t";
		cout << "住址：" << abs->personarray[ret].m_addr << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");

}


void modifyperson(addressbook * abs)
{
	cout << "请输入您要修改的联系人" << endl;
	string name;
	cin >> name;

	int ret = isexist(abs, name);
	if (ret != -1)
	{
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personarray[ret].m_name = name;

		cout << "请输入性别：" << endl;
		cout << "1 -- 男" << endl;
		cout << "2 -- 女" << endl;

		//性别
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personarray[ret].m_sex = sex;
				break;
			}
			cout << "输入有误，请重新输入";
		}

		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personarray[ret].m_age = age;

		//联系电话
		cout << "请输入联系电话：" << endl;
		string phone = "";
		cin >> phone;
		abs->personarray[ret].m_phone = phone;

		//家庭住址
		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		abs->personarray[ret].m_addr = address;

		cout << "修改成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");

}


void cleanperson(addressbook * abs)
{
	abs->m_size = 0;
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");
}


int main(){
    addressbook ads;
    ads.m_size = 0;
    int select;
    while(true){
        showmenu();
        cin >> select;
        switch(select){
            case 1:
                addperson(&ads);
                break;
            case 2:
                showperson(&ads);
                break;
            case 3:
                deleteperson(&ads);
                break;
            case 4:
                findperson(&ads);
                break;
            case 5:
                modifyperson(&ads);
                break;
            case 6:
                cleanperson(&ads);
                break;
            case 0:
                cout << "欢迎下次使用" << endl;
                return 0;
            default:
                break;
        }
    }
    system("pause");
    return 0;
}