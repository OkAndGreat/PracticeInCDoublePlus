/**
 * Created by OkAndGreat on 2021/12/19.
 * 命名空间
 */

#include <iostream>

//写在这就是全局的
//using namespace std;


namespace myNameSpace {
    //写在这就只能这个作用域使用
    using namespace std;

    void print() {
        cout << "print from namespace myNameSpace" << endl;
    }
}

int main() {

    myNameSpace::print();

    using namespace myNameSpace;
    print();

}

