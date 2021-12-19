/**
 * Created by OkAndGreat on 2021/12/19.
 * 常量指针 指针常量 常量指针常量
 */

int main(){
    int number = 9;
    int number2 = 8;

    // 常量指针 不允许去修改【常量指针】存放地址所对应的值
    const int * numberP1 = &number;
    // *numberP1 = 100; // 报错，

    //  指针常量 不允许重新指向【指针常量】存放的地址
    int* const numberP2 = &number;
    // numberP2 = &number2; //

    // 常量指针常量
    const int * const numberP3 = &number;
    // *numberP3 = 100; // 报错，不允许去修改【常量指针常量】存放地址所对应的值
    // numberP3 = &number2; // 报错，不允许重新指向【常量指针常量】存放的地址

    return 0;
}

