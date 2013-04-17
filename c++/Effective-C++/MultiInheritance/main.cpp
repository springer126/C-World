#include <iostream>
#include "apue.h"


using namespace std;


class A
{
public:
    A(int i = 1):a(i){}
    //virtual void f(){}

    int a;
};

class B:virtual public A
{
public:
    B(int i = 1):A(i*10),b(i){}
    //virtual void f(){}
private:
    int b;
};

class C:virtual public A
{
public:
    C(int i = 1):A(i),c(i){}
   // virtual void f(){}
private:
    int c;
};

class D:public B,public C
{
public:
    D(int i = 1):A(i),B(i+1),C(i+2),d(i+3){}
    //virtual void f(){}
private:
    int d;
};

int main()
{
    D d;
    int *p = (int *)&d;
    cout << sizeof(d)<<" "<<&d<< endl;

    cout <<hex<< *p ;
    int *pp = (int *)*p;
    cout <<" "<< *pp << endl;

    p++;
    cout << *p << endl;

    p++;
    cout << *p;
    int *pp2 = (int *)*p;
    cout <<" "<< *pp2 << endl;

    p++;
    cout << *p << endl;
    p++;
    cout << *p << endl;
    p++;
    cout << *p << endl;

    A *pa = &d;
    B *pb = &d;
    C *pc = &d;
    D *pd = &d;
    cout << pa <<" "<<pb<<" "<<pc <<" "<<pd<<endl;

    cout << "==============performance test=============="<<endl;
    int index = 0;
    clock_t t;
    t = clock();
    for(index = 0;index<100000000;index++)
        pa->a = index;
    t  = clock() - t;
    cout << "pa->a : "<<(float)t/CLOCKS_PER_SEC<<" s." << endl;

    t = clock();
    for(index = 0;index<100000000;index++)
        pb->a = index;
    t  = clock() - t;
    cout << "pb->a : "<<(float)t/CLOCKS_PER_SEC<<" s." << endl;

    t = clock();
    for(index = 0;index<100000000;index++)
        pc->a = index;
    t  = clock() - t;
    cout << "pc->a : "<<(float)t/CLOCKS_PER_SEC<<" s." << endl;

    t = clock();
    for(index = 0;index<100000000;index++)
        pd->a = index;
    t  = clock() - t;
    cout << "pd->a : "<<(float)t/CLOCKS_PER_SEC<<" s." << endl;

    cout << "==============performance test=============="<<endl;

    A a;
    B b;
    C c;
    cout << sizeof(a) << " " << sizeof(b) << " " <<sizeof(c) <<endl;
    cout << ((int*)(A *)&b) - ((int *)&b) <<endl;
    p = (int *)&b;
    cout << p <<" " <<*p <<" "<<*((int *)*p) << endl;
    p++;
    cout << p <<" "<< *p << endl;
    p++;
    cout << p <<" "<< *p << endl;
    return 0;
};
