class A
{
  public:
    virtual ~A() {
      std::cout << "A's destructor\n"s;
    }
    virtual void foo() = 0;
};

class B : public A
{
  public:
    ~B() {
      std::cout << "B's destructor\n"s;
    }
    void foo() { std::cout << "called by B\n"s; }
};

class C : public B
{
  public:
    ~C() {
      std::cout << "C's destructor\n"s;
    }
    void foo() { std::cout << "called by C\n"s; }
};

int main()
{
  C c;
  B b = c;
  A* a = &b;

  c.foo();
  b.foo();
  a->foo();
}
