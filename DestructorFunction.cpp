/**
 * Created by OkAndGreat on 2021/12/19.
 * 析构函数
 */

#include <iostream>
#include <malloc.h>

using namespace std;

class Student{

    int * intArr = (int *) malloc(sizeof(int) * 2);

public:
    /**
     * 会先执行双参构造再执行单参才执行空参构造函数
     */
     int isMale = 0;
    Student(): Student(NULL){
        cout << "空参构造函数执行了" << endl;
    }

    Student(int height): Student(height,NULL){
        cout << "单参构造函数执行了" << endl;
    }

    Student(int height,int weight){
        cout << "双参构造函数执行了" << endl;
    }

    // 析构函数 对象被回收时会执行这个函数
    // delete时候，析构函数会执行
    // free不会执行析构函数 malloc也不会调用构造函数
    //在析构函数中执行释放堆区资源工作
    ~Student(){
        cout << "Been Recycle" << endl;
        free(intArr);
    }

    //拷贝构造函数
    Student(const Student & student){
        isMale = 666;
    }

private:
    int isAsian = 0;
};

int main78(){
    Student *student = new Student();
    delete student;
    student = NULL;

    Student stu;

    Student copyStu1 = stu;
    cout << "copyStu1 is Male:"<< copyStu1.isMale << endl;

    Student copyStu2;
    copyStu2 = stu;
    cout << "copyStu2 is Male:"<< copyStu2.isMale << endl;

}