void * memcpy(void * dest, void const * src, std::size_t n)
{
  auto d = static_cast<std::byte *>(dest);
  auto s = static_cast<std::byte const *>(src);

  for (std::size_t i = 0; i != n; ++i) {
    d[i] = s[i];
  }

  return dest;
}

template <typename To, typename From>
To bit_cast(From const & from)
{
  To to;
  memcpy(&to, &from, sizeof(To));
  return to;
}

template <typename T>
void print_raw_address(T ptr)
{
  std::cout << bit_cast<std::uintptr_t>(ptr) << "\n"s;
}

struct Object
{
  int x = 123;
  int y = 456;
  int z = 789;
};

int main()
{
  Object object;
  std::byte * start = bit_cast<std::byte *>(&object);
  int * x = bit_cast<int *>(start + 0);
  int * y = bit_cast<int *>(start + 4);
  int * z = bit_cast<int *>(start + 8);
  std::cout << *x << "\n"s << *y << "\n"s << *z << "\n"s;
}
