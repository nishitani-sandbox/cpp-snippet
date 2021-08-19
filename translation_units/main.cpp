#include "foo.h"
#include "bar.h"

int main()
{
  std::cout << "foo1: "s << foo1() << "\n"s
    "foo2: "s << foo2() << "\n"s
    "bar1: "s << bar1() << "\n"s
    "bar2: "s << bar2() << "\n"s;
}
