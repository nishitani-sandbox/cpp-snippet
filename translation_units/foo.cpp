const int VALUE1 = 3;
extern const int VALUE2;
const int VALUE2 = 5;

int foo1() {
  return VALUE1;
}

int foo2() {
  return VALUE2;
}
