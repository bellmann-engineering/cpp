#include <string>
#include <iostream>

class B 
{
    public:
	    virtual const char* foo() { return "foo"; }
};

class A : public B
{
    public:
	    const char* foo() { return "bar"; }
};

int main() 
{ 
    B* o1 = new B();
    B* o2 = new A();
    A* o3 = new A();
    std::cout << o1->foo() << std::endl;
    std::cout << o2->foo() << std::endl;
    std::cout << o3->foo() << std::endl;

    return 0;
}
