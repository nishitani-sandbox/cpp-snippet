class A
{
  public:
    virtual ~A() = default;
    virtual void foo() { std::cout << "called by A\n"s; }
};

class B : public A
{
  public:
    // void foo() { std::cout << "called by B\n"s; } also OK
    virtual void foo() { std::cout << "called by B\n"s; }
};

A* genA()
{
  static A a;
  return &a;
}

B* genB()
{
  static B b;
  return &b;
}

int main()
{
  A* ia = dynamic_cast<A*>(genB());
  ia->foo();

  B* ib = dynamic_cast<B*>(genA());
  ib->foo();
}
