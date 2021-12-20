/**
 * Created by OkAndGreat on 2021/12/20.
 * C++静态属性和静态方法
 *  1.通过类名::静态成员访问静态（字段/函数）
 * 2.静态的属性必须要初始化，然后再实现
 * 3.静态的函数只能取操作静态的属性和方法
 */

#include <iostream>

using namespace std;

class StaticClass{
private:
    int id;
public:
    static int cnt;
    StaticClass(int id):id(id){
        cout << "这种写法等同于 this->id = id" << endl;
    }

    static void MakeCntPlus(){
        cout << "cnt的值为（改变前）" << cnt << endl;
        cnt++;
        cout << "cnt的值为（改变后）" << cnt << endl;
    }
};

//要实现 否则会编译失败
int StaticClass::cnt = 0;

int main(){
    //栈区开辟内存
    StaticClass staticClass(12);

    StaticClass::cnt = 0;
    //Warning:Static member accessed through instance
    staticClass.cnt = 10;
    StaticClass::MakeCntPlus();

    return 0;
}

