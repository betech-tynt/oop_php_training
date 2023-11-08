/*
Xét 4 lớp A B C D. Lớp B và C có chung lớp cơ sở A. Lớp D dẫn xuất từ C. Cả 4 lớp đều có phương thức xuat(). xét hàm
    void hien (A *p)
    {
        p -> xuat();
    }

    Không cần biết tới địa chỉ của đối tượng nào sẽ truyền cho đối con trỏ p, lời gọi trong hàm luôn luôn gọi tới phương thức A::xuat() vì con trỏ p kiểu A. Như vậy bốn câu lệnh:
    hien(&a);
    hien(&b);
    hien(&c);
    hien(&d);
    Trong hàm main dưới đây đều gọi tới A::xuat().

    // CT 6 - 01
*/

#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <ctype.h>

using namespace std;

class A
{
    private:
        int n;
public:
    A()
    {
        n = 0;
    }
    A(int n1)
    {
        n = n1;
    }
    void xuat()
    {
        cout << "\nLop A: " << n;
    }
    int getN()
    {
        return n;
    }
};

class B : public A
{
    public:
    B() : A()
    {

    }
    B(int n1) : A(n1)
    {

    }
    void xuat()
    {
        cout << "\nLop B: " << getN();
    }
};

class C : public A
{
    public:
    C() : A()
    {

    }
    C(int n1) : A(n1)
    {

    }
    void xuat()
    {
        cout << "\nLop C: " << getN();
    }
};

class D : public C
{
    public:
    D() : C()
    {

    }
    D(int n1) : C(n1)
    {

    }
    void xuat()
    {
        cout << "\nLop D: " << getN();
    }
};

void hien(A *p)
{
    p -> xuat();
}
int main()
{
    A a(1);
    B b(2);
    C c(3);
    D d(4);
    // clrscr();
    system("cls");
    hien(&a);
    hien(&b);
    hien(&c);
    hien(&d);
    _getch();
}