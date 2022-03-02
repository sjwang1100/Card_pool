// 卡池.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <Windows.h>
#include "CardPool.h"

using namespace std;

int main()
{
    reset();
    cout << "Ini done" << endl;
    int a = 0;
    while (true) {
        //Aesthetic Display
        //Sleep(500);
        cout << ". ";
        //Sleep(500);
        cout << ". ";
        //Sleep(500);
        cout << ". ";
        //Sleep(500);

        //Print Result
        cout << result().x << endl;
        if (result().x[1] == 'r') {
            cout << a;
            break;
        }
        a++;
    }
}


