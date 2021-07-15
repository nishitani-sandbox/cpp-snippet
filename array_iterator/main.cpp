template <typename Array>
struct array_iterator
{
  Array & a;
  std::size_t i;

  array_iterator(Array & a, std::size_t i)
    : a(a), i(i) {}

  typename Array::reference operator *()
  {
    return a[i];
  }

  array_iterator & operator ++()
  {
    ++i;
    return *this;
  }

  array_iterator & operator --()
  {
    --i;
    return *this;
  }
};


template <typename T, std::size_t N>
struct array
{
  using value_type = T;
  using reference = T &;
  using const_reference = T const &;
  using size_type = std::size_t;
  using iterator = array_iterator<array>;

  value_type storage[N];

  reference operator [](size_type i)
  {
    return storage[i];
  }

  const_reference operator [](size_type i) const
  {
    return storage[i];
  }

  iterator begin()
  {
    return iterator(*this, 0);
  }

  iterator end()
  {
    return iterator(*this, N);
  }
};

int main()
{
  array<int, 5> a = {1, 2, 3, 4, 5};
  auto iter = a.begin();

  std::cout << *iter << "\n"s;
  std::cout << *++iter << "\n"s;
}
