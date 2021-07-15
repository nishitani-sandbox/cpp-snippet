struct S
{
  int data {};
  S & THIS() { return *this; }
};

int main()
{
  S s1;
  s1.THIS().data = 123;
  std::cout << s1.data << "\n"s;
}
