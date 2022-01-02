#include <iostream>

using namespace std;
int a = 10;

void test01(){
    int a= 20;
    cout <<"a = "<<a<< endl;//就近取局部變量

    cout <<"::a = "<< ::a<<endl; //使用作用域:: 可以用全局變量
}

namespace A {
    int a = 100;
    namespace C {
        int a = 1000;
    }
}
namespace B {
    int a = 200;
}
void test02()
{
    cout<<"全局::a= "<<::a<<endl;
    cout<<"namespace A::a= "<<A::a<<endl;
    cout<<"namespace B::a= "<<B::a<<endl;
}

void test03()
{
    cout <<"namespace A::C::a = "<< A::C::a << endl;
}

namespace A {
    int c = 100;
}
void test04()
{
    cout <<"namespace A::c = "<< A::c<<endl;
}

namespace A {
    void func()
    {
        cout <<"namespace A::func , a = "<<a<<endl;
        cout <<"namespace A::func , c = "<<c<<endl;
    }
    void fund();
}
void test05()
{
    A::func();
}

void A::fund()
{
    cout <<"namespace A::fund , a = "<<a<<endl;
    cout <<"namespace A::fund , c = "<<c<<endl;
}
void test06()
{
    A::fund();
}

namespace veryLongName {
    int b = 134;
    void fune() { cout << "hello namespace veryLongName"<<endl;}
}

void test07()
{
    using namespace veryLongName;
    cout <<"b = "<<b<<endl;
    fune();
}

void test07_2()
{
    namespace shortname = veryLongName;
    cout <<"short::b = "<<shortname::b<<endl;
    using namespace shortname;
    cout <<"short::b = "<<shortname::b<<endl;
}

void test07_3()
{
    using veryLongName::b;
    cout << " b = "<<b<<endl;
    veryLongName::fune();
}
namespace D {
    void func() {cout <<"func "<<endl;	}
    void func(int a ) {cout <<"int func "<<endl;	}
    void func(int a, int b ) {cout <<"int int func "<<endl;	}
}
void test08()
{
    using D::func;
    func();
    func(1);
    func(1,2);
}

namespace E {
    int a = 10;
}
namespace F {
    int a = 20;
}
void test09()
{

    //cout<<"a = "<<a<<endl;
    cout<<"E::a = "<<E::a<<endl;
    cout<<"F::a = "<<F::a<<endl;
}
int main()
{
//    test01();
//    test02();
//    test03();
//    test04();
//    test05();
//    test06();
//    test07();
//    test07_2();
//    test07_3();
//    test08();
    test09();
    return 0;
}
