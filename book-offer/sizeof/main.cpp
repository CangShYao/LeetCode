#include <iostream>
using namespace std;

class B {
};

class C {
    C(){}
    ~C(){}
};

class D {
    virtual void fun();
};

int main()
{
    int a[] = {1, 2, 3, 4};
    cout << "the array size is " << sizeof(a) << endl;
    // 如果是数字的标识符，那么显示的是数组的大小
    cout << "the empty class size is " << sizeof(B) << endl;
    // 如果是一个空的class，理论上应该为0，但是class在声明的时候就必须占有一定的大小
    cout << "have a consuter class size is " << sizeof(C) << endl;
    // 有没有构造函数与析构函数都一样
    cout << "have a virtual funcation class's size is " << sizeof(D) << endl;
    // 拥有虚函数的class，编译器会为class添加一个虚函数指针列表，sizeof得到的就是指针的大小*数量
    // 64位操作系统中指针占8个字节，32为操作系统中指针占4个字节
    system("pause");
}