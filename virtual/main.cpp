class A
{
  public:
    virtual void foo() { std::cout << "called by A\n"s; }
};

class B : public A
{
  public:
    void foo() { std::cout << "called by B\n"s; }
};

int main()
{
  B b;
  A a = b;
  b.foo();
  a.foo();
}
