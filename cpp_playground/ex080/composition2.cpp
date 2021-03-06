// HAS-A relationship (composition using pointers)

#include <iostream>

class B
{
private:
    int data[100];

public:
    B()
    {
        std::cout << "Object of class B at memory " << this << " having size " << sizeof(*this) << " created" << std::endl;
    }
    ~B()
    {
        std::cout << "Object of class B at memory " << this << " having size " << sizeof(*this) << " destroyed" << std::endl;
    }
};

class A
{
private:
    int x;
    B *b; // composition (strong containment)
public:
    A()
    {
        b = new B();
        std::cout << "Object of class A at memory " << this << " having size " << sizeof(*this) << " created" << std::endl;
    }
    ~A()
    {
        std::cout << "Object of class A at memory " << this << " having size " << sizeof(*this) << " destroyed" << std::endl;
        delete b;
    }
};

int main()
{
    A obj1;
    A obj2;

    return 0;
}
