/**
 * Created by OkAndGreat on 2021/12/19.
 * 通过c++引用互换俩个数
 */

#include <iostream>
#include "MusicPlayer.h"

using namespace std;

void swap(int &num1, int &num2) {
    cout << "num1地址" << &num1 << endl;
    cout << "num2地址" << &num2 << endl;
    num1 = num1 + num2;
    num2 = num1 - num2;
    num1 = num1 - num2;
}

typedef struct {
    int cnt;
} Data;

//常量引用 不可以修改值
__attribute__((unused)) void InsertData(const Data &data) {
    //会报错
    //Cannot assign to variable 'data' with const-qualified type 'const Data &'
//    data.cnt = 10;
}

int main54() {
    int num1 = 1;
    int num2 = 2;

    cout << "num1地址" << &num1 << endl;
    cout << "num2地址" << &num2 << endl;

    swap(num1, num2);

    cout << num1 << endl;
    cout << num2 << endl;

    //开辟在栈空间的，函数弹栈自动回收
    MusicPlayer musicPlayer1;
    musicPlayer1.start();

    //开辟在堆空间的
    //需要自己回收
    auto *musicPlayer = new MusicPlayer(100);
    cout << musicPlayer->getTime() << endl;
    delete musicPlayer;

    return 0;
}

