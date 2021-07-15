struct S {
  int i;

  S()
    : i(3) {}

  S(int i)
    : i(i)
  {
    std::cout << "constructor called\n"s;
  }

  S(S const & other)
    : S(other.i)
  {
    std::cout << "delegating constructor called\n"s;
  }
};

int main()
{
  S a(1);
  S b = a;
  std::cout << "b.i: " << b.i << "\n"s;
  // S c() does not work!
  // S c = S() works!
  S c;
  c.i = 3;
  std::cout << "c.i: " << c.i << "\n"s;
}
