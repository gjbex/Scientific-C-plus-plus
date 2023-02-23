#include <iostream>
#include <memory>
#include <typeinfo>

struct A {
    virtual void f() const = 0;
    void p() const { std::cout << "A::p()" << std::endl; }
    ~A() = default;
};

struct B : public A {
    void f() const override { std::cout << "B::f()" << std::endl; }
    void p() const { std::cout << "B::p()" << std::endl; }
};

struct C : public A {
    void f() const override { std::cout << "C::f()" << std::endl; }
    void p() const { std::cout << "C::p()" << std::endl; }
};

int main() {
    B b;
    std::cout << "B: ";
    b.f();
    b.p();
    C c;
    std::cout << "C: ";
    c.f();
    c.p();
    std::cout << "A = B: ";
    std::unique_ptr<A> a = std::make_unique<B>();
    a->f();
    a->p();
    if (B* a_cast = dynamic_cast<B*>(a.get()); a_cast) {
        std::cout << "a is a B: ";
        a_cast->p();
    }
    if (!dynamic_cast<C*>(a.get()))
        std::cout << "a is not a C\n";
    std::cout << "A = C: ";
    a = std::make_unique<C>();
    a->f();
    a->p();
    if (typeid(*a.get()) != typeid(B))
        std::cout << "a is not a B\n";
    if (typeid(*a.get()) == typeid(C)) {
        std::cout << "a is a C: ";
        static_cast<C*>(a.get())->p();
    }
    return 0;
}
