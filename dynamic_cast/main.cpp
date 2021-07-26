class A
{
  public:
    virtual ~A() = default;
    void foo() { std::cout << "called by A\n"s; }
};

class B : public A
{
  public:
    void foo() { std::cout << "called by B\n"s; }
};

A* genA() {
  static A a;
  return &a;
}

int main()
{
  auto b = dynamic_cast<B*>(genA());
  b->foo();
}
