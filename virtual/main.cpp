class A
{
  public:
    virtual void foo() = 0;
};

class B : public A
{
  public:
    void foo() { std::cout << "called by B\n"s; }
};

class C : public B
{
  public:
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
