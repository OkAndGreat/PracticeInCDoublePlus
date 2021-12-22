/**
 * Created by OkAndGreat on 2021/12/22.
 * 纯虚函数和全纯虚函数
 * 纯虚函数类似于Java里的抽象方法
 * 全纯虚函数类似于Java里的接口
 */

#include <iostream>

using namespace std;

//有纯虚函数的类无法被实例化
class BaseActivity {
private:
    void setContentView(const string& layoutResID) {
        cout << "setContentView : " << layoutResID << endl;
    }

public:
    void onCreate() {
        setContentView(getLayoutID());

        initView();
        initData();
        initListener();
    }

    // 纯虚函数
    // virtual string getLayoutID(); // 虚函数
    virtual string getLayoutID() = 0; // 纯虚函数
    virtual void initView() = 0;

    virtual void initData() = 0;

    virtual void initListener() = 0;
};

// MainActivity如果没有全部重写父类的纯虚函数，则自己也相当于Java里的抽象类，且也不能被实例化
class MainActivity : public BaseActivity {

    string getLayoutID() override {
        return "R.layout.activity_main";
    }

    void initView() override {
        cout << "initView" << endl;
    }

    void initData() override {
        cout << "initData" << endl;
    }

    void initListener() override {
        cout << "initListener" << endl;
    }
};

//类里面全是纯虚函数就是全纯虚函数
class onClickListener{
    virtual void onClick(int ViewID) = 0;
};

/**
 * 运行结果
 * setContentView : R.layout.activity_main
 * initView
 * initData
 * initListener
 */

int main(){
    auto mainActivity = new MainActivity();
    mainActivity->onCreate();
}

