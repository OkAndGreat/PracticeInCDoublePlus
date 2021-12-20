/**
 * Created by OkAndGreat on 2021/12/20.
 * 友元函数和友元类
 */

#include <iostream>

using namespace std;

class Dog {
private:
    //定义友元类 友元类可以操纵私有属性
    friend class Person;

    string name;
};

class Person {
private:
    int age = 0;
    Dog dog;

public:
    explicit Person(int age) {
        this->age = age;
    }

    int getAge() {
        return this->age;
    }

    //定义友元类 友元类可以操纵私有属性
    void changeDogName(string name) {
        dog.name = name;
    }

    void getDogName() {
        cout << "DogName:" << dog.name << endl;
    }

    // 定义友元函数
    friend void updateAge(Person *person, int age);
};

// 友元函数的实现，可以访问所以私有成员
void updateAge(Person *person, int age) {
    person->age = age;
}

int main() {
    Person person = Person(9);
    updateAge(&person, 88);
    cout << person.getAge() << endl;


    person.changeDogName("进喜");
    person.getDogName();
    return 0;
}