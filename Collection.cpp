/**
 * Created by OkAndGreat on 2021/12/22.
 * C++中的集合框架
 */

#include <iostream>


#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>

using namespace std;

void Vector() {
    vector<int> vector1;

    vector<int> vector2(10);

    vector<int> vector3(10, 0);

    vector<int> vector4;


    // 插入数据
    vector4.insert(vector4.begin(), 40);
    vector4.insert(vector4.begin(), 60);

    // 取第一个和修改第一个数据
    cout << " 修改前：vector4.front():" << vector4.front() << endl;
    vector4.front() = 99;
    cout << " 修改后：vector4.front():" << vector4.front() << endl;

    // 取最后一个和修改最后一个数据
    cout << " 修改前：vector4.back():" << vector4.back() << endl;
    vector4.back() = 777;
    cout << " 修改后：vector4.back():" << vector4.back() << endl;

    // 移除第一个元素（内部：通过迭代器的位置 进行移除）删除
    vector4.erase(vector4.begin());

    // 循环打印，默认 从大到小输出
    for (int i: vector4) {
        cout << "item:" << i << endl;
    }

    //通过迭代器遍历
    for (int &iteratorVar: vector4) {
        // 迭代器 当中指针操作  iteratorVar++
        cout << "迭代器：" << iteratorVar << endl;
    }
}

void Stack() {
    stack<int> stack;

    // 压栈
    stack.push(30);
    stack.push(60);
    stack.push(90);

    while (!stack.empty()) {
        // 获取栈顶的元素 但不会移除
        int top = stack.top();
        cout << "获取栈顶的元素：" << top << endl;
        //删除栈顶元素 返回值为void
        stack.pop();
    }
}

void Queue() {
    queue<int> queue;

    queue.push(20);
    queue.push(40);
    queue.push(60);

    //取第一个元素
    cout << " 修改前： queue.front():" << queue.front() << endl;
    queue.front() = 88;
    cout << " 修改后： queue.front():" << queue.front() << endl;

    // 取最后一个元素
    cout << " 修改前： queue.back():" << queue.back() << endl;
    queue.back() = 88;
    cout << " 修改后： queue.back():" << queue.back() << endl;

    while (!queue.empty()) {
        cout << "while1:" << queue.front() << endl;

        // 删除前面的元素
        queue.pop();
    }
}

void PriorityQueue() {
    //优先级队列 插入元素会自动排序
    //升序
    priority_queue<int, vector<int>, less<int>> priorityQueue;
    //降序
    // priority_queue<int ,vector<int>, greater<int>> priorityQueue;

    priorityQueue.push(10);
    priorityQueue.push(20);
    priorityQueue.push(30);
    priorityQueue.push(40);
    priorityQueue.push(50);
    priorityQueue.push(60);

    cout << priorityQueue.top() << endl; // 60

    while (!priorityQueue.empty()) {
        cout << "while1:" << priorityQueue.top() << endl;
        priorityQueue.pop();
    }
}

void List(){
    cout << "List" << endl;
    list<int> listVar;

    // 插入操作
    listVar.push_front(50); // 插入到前面
    listVar.push_front(80);
    listVar.push_front(450);
    listVar.push_back(60); // 插入到后面
    listVar.push_back(60);
    listVar.push_back(650);
    listVar.insert(listVar.begin(), 70); // 插入到前面
    listVar.insert(listVar.end(), 80); // 插入到后面

    // 修改
    listVar.back() = 88;
    listVar.front() = 55;

    // 删除
    listVar.erase(listVar.begin()); // 删除最前面的
    listVar.erase(listVar.end()); // 删除最后面的

    // list 迭代器
    for (list<int>::iterator it = listVar.begin(); it != listVar.end() ; it ++) {
        cout << *it << endl;
    }
}

void Set(){
    //升序排列
    set<int, less<int>> setVar;

    setVar.insert(1);
    setVar.insert(3);
    setVar.insert(2);
    setVar.insert(4);

    // 重复插入
    pair<set<int, less<int>>::iterator, bool> res = setVar.insert(8);

    // res.first 获取第一个元素 迭代器   当前迭代器   最后一个位置
    // res.second 获取第二个元素 bool
    bool insert_success = res.second;
    if (insert_success) {
        cout << "恭喜你，插入成功" << endl;

        // 插入成功后，我用第一个元素遍历
        for (; res.first != setVar.end(); res.first ++) {
            cout << *res.first << endl;
        }

    } else {
        cout << "哎，插入失败.." << endl;
    }

    // 全部遍历  auto 自动推到
    for (auto it = setVar.begin(); it != setVar.end() ; it ++) {
        cout << *it << endl;
    }
}

int main() {

    cout << "=========================================================" << endl;

    Vector();

    cout << "=========================================================" << endl;

    Stack();

    cout << "=========================================================" << endl;

    Queue();

    cout << "=========================================================" << endl;

    PriorityQueue();

    cout << "=========================================================" << endl;

    List();

    cout << "=========================================================" << endl;

    Set();

    cout << "=========================================================" << endl;


    return 0;
}