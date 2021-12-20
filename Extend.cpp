/**
 * Created by OkAndGreat on 2021/12/20.
 * 继承&多继承&二义性
 */

#include <iostream>

using namespace std;

class Object {
public:
    int color = 0;

    void showColor() {
        cout << "color is -->" << color << endl;
    }
};

class Person : public virtual Object {
public:
    char *name;
    int age;

public:
    Person(char *name, int age) : name(name) {
        this->age = age;
        cout << "Person 构造函数" << endl;
    }

    void print() {
        cout << this->name << " , " << this->age << endl;
    }
};

class Animal : public virtual Object {
public:
    int age;
};

// 1.默认是 私有继承: private Person
// 2.私有继承：在子类里面是可以访问父类的成员，但是在类的外面不行
// 3.公开继承，才可以访问父类的成员
class Student : public Person, public Animal {

private:
    char *course;

public:
    Student(char *name, int age, char *course) : Person(name, age), course(course) {
        cout << "Student 构造函数" << endl;
    }
};

int main() {
    Student stu("李元霸", 99, "C++");

    // 公开继承，才可以拿父类的成员
    stu.name = "李四";

    //student继承自Animal 和 Person 而这俩个类都有age属性
    //解决方法一：student覆盖
    //二：指定
    stu.Person::age = 10;
    stu.Animal::age = 12;

    //使用虚基类 适用于菱形继承
    stu.showColor();

    return 0;
}

