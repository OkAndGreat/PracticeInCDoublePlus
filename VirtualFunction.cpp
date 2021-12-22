/**
 * Created by OkAndGreat on 2021/12/22.
 * 虚函数
 * 类似于Java中的多态 C++默认不支持多态
 */

#include <iostream>

using namespace std;

class BaseActivity {
public:
    virtual void onStart() {
        cout << "BaseActivity onStart" << endl;
    }

};

class HomeActivity : public BaseActivity {
public:
    void onStart() {
        // 重写父类的函数
        cout << "HomeActivity onStart" << endl;
    }
};

class LoginActivity : public BaseActivity {
public:
    void onStart() {
        // 重写父类的函数
        cout << "LoginActivity onStart" << endl;
    }
};

// 在此函数 体系多态，例如：你传入HomeActivity，我就帮你运行HomeActivity
void startToActivity(BaseActivity & baseActivity) {
    baseActivity.onStart();
}

int main() {
    auto *homeActivity = new HomeActivity();
    auto *loginActivity = new LoginActivity();

    startToActivity(*homeActivity);
    startToActivity(*loginActivity);

    /**
     * 运行结果
     * BaseActivity onStart
     * BaseActivity onStart
     *
     * 给BaseActivity的onStart加上virtual后
     *
     * HomeActivity onStart
     * LoginActivity onStart
     */

    delete homeActivity;
    delete loginActivity;


    cout << endl;

    BaseActivity * activity1 = new HomeActivity();
    BaseActivity * activity2 = new LoginActivity();
    startToActivity(*activity1);
    startToActivity(*activity2);
    delete activity1;
    delete activity2;


    return 0;
}

