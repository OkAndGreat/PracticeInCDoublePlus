/**
 * Created by OkAndGreat on 2021/12/20.
 * 操作符重载
 */

// 1.类外运算符重载。

#include <iostream>
using namespace std;

class Position {
private:
    int x,y;

public:
    Position(int x, int y) : x(x), y(y) {}

    void setX(int x) {
        this->x = x;
    }
    void setY(int y) {
        this->y = y;
    }
    int getX() {
        return this->x;
    }
    int getY() {
        return this->y;
    }

    //使用const减小内存开销
    Position operator - (const Position & position){
        int x = this->x - position.x;
        int y = this->y - position.y;
        return Position(x, y);
    }

    void operator ++() { //  ++对象
        this->x = this->x + 1;
        this->y = this->y + 1;
    }

    void operator ++ (int) { // 对象++
        this->x = this->x + 1;
        this->y = this->y + 1;
    }
};

//类外操作符重载
// 在真实开发过程中，基本上都是写在类的里面的，为什么？答：外部不能获取内部私有成员
// 把+重载
Position operator + (Position position1, Position position2) {
    int x = position1.getX() + position2.getX();
    int y = position1.getY() + position2.getY();

    Position res(x, y);
    return res;
}



int main() {
    Position position1(1000, 2000);
    Position position2(3000, 4000);

    Position position = position1 + position2;
    cout << position.getX() << " , " << position.getY() << endl;

    position = position1 - position2;
    cout << position.getX() << " , " << position.getY() << endl;

    return 0;
}


