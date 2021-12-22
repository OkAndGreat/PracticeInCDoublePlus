/**
 * Created by OkAndGreat on 2021/12/22.
 * C++模板函数
 */
#include <iostream>

using namespace std;

// 模板函数  == Java的泛型解决此问题
template <typename T>
void addAction(T n1, T n2) {
    cout << "模板函数：" << n1 + n2 << endl;
}

template <typename V,typename K>
void add(K n1,V n2){
    cout << "模板函数：" << n1 + n2 << endl;
}

int main() {
    addAction(1, 2);
    addAction(10.2f, 20.3f);
    addAction(545.34, 324.3);
    addAction<string>("AAA", "BBB");

    add(2, 324.3);
    add(54, 324.3f);
    return 0;
}

