//阴阳猜数字4.0
#include<iostream>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include<conio.h>

#define CLS system("cls")

using namespace std;

void mainTable();//主界面
void game();//游戏
void about();//关于界面

void mainTable() {
    CLS;
    int ch;
    cout << "                                        " << endl;
    cout << "                                        " << endl;
    cout << "             阴阳怪气系列               " << endl;
    cout << "                猜数字                  " << endl;
    cout << "                                        " << endl;
    cout << "             按1键开始游戏              " << endl;
    cout << "             按2键查看关于              " << endl;
    cout << "                                        " << endl;
    cout << "              按esc键退出               " << endl;
    cout << "                                        " << endl;
    while (1) {
        if (_kbhit()) {//如果有按键按下，则_kbhit()函数返回真
            ch = _getch();//使用_getch()函数获取按下的键值
            switch (ch) {
            case 49:game(); break;
            case 50:about(); break;
            case 27:exit(0);
            default:cout << "输入错误！按任意键重新输入"; ch = _getch(); mainTable();
            }

        }
    }
}

void game() {
    CLS;
    int a, b,ch;
    int min = 1, max = 100;
    int times = 0;
    srand((unsigned)time(NULL));
    a = (rand() % 100) + 1;
    while (true) {
        cout << "请猜一个1-100的数,";
        cout << "当前范围(" << min << "—" << max << "):";
        cin >> b;
        if (b > a) {
            times++;
            max = b;
            CLS;
            cout << "你输入的数字太大了鸭！重新输一个吧！" << endl;
        }
        else if (b < a) {
            times++;
            min = b;
            CLS;
            cout << "你输入的数字太小了鸭！重新输入一个吧！" << endl;
        }
        else {
            times++;
            CLS;
            cout << "猜对啦！这个数字就是" << a << ".你一共猜了" << times << "次！" << endl;
            if (times >= 1 && times <= 3)
                cout << "你可真是个猜数字大神哦！我好崇拜你啊！" << endl;
            else if (times > 3 && times <= 5)
                cout << "你可真的是厉害！" << endl;
            else if (times > 5 && times <= 10)
                cout << "你这猜数字还得好好练练哦！" << endl;
            else
                cout << "你可别玩猜数字了，看看脑子吧！" << endl;
            cout << "按1键重新玩，按任意键退出游戏。";
            while (1) {
                if (_kbhit()) {//如果有按键按下，则_kbhit()函数返回真
                    ch = _getch();//使用_getch()函数获取按下的键值
                    switch (ch) {
                    case 49:game(); break;
                    default:exit(0);
                    }

                }
            }
            break;
        }

    }
}

void about() {
    CLS;
    cout << "                                        " << endl;
    cout << "                                        " << endl;
    cout << "             阴阳怪气猜数字             " << endl;
    cout << "                 v4.0                   " << endl;
    cout << "               github链接：             " << endl;
    cout << "   https://github.com/Lutio0215/Capps   " << endl;
    cout << "                                        " << endl;
    cout << "                                        " << endl;
    cout << "                                        " << endl;
    system("pause");
    mainTable();

}

int main() {
    system("title 阴阳猜数字v4.0");
    system("color 97");
    system("mode con cols=40 lines=20");
    mainTable();
    return 0;
}
