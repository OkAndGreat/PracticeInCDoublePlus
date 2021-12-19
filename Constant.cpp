/**
 * Created by OkAndGreat on 2021/12/19.
 *
 */

#include <iostream>

using namespace std;

int main1() {

    const int num = 100;

    //会报错
    //Cannot initialize a variable of type 'int *' with an rvalue of type 'const int *'
    //c里面通过指针可以修改
//    int *numP = &num;
//    *numP = 10;

}
