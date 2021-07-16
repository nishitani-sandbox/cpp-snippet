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

  array_iterator operator ++(int)
  {
    array_iterator copy = *this;
    ++*this;
    return copy;
  }

  array_iterator & operator --()
  {
    --i;
    return *this;
  }

  array_iterator operator --(int)
  {
    array_iterator copy = *this;
    --*this;
    return copy;
  }

  bool operator ==(array_iterator const & right)
  {
    return i == right.i;
  }

  bool operator !=(array_iterator const & right)
  {
    return i != right.i;
  }

  array_iterator & operator +=(std::size_t n)
  {
    i += n;
    return *this;
  }

  array_iterator operator +(std::size_t n) const
  {
    auto copy = *this;
    copy += n;
    return copy;
  }

  typename Array::reference operator [](std::size_t n) const
  {
    return *(this + n);
  }

  bool operator < (array_iterator const & right) const
  {
    return i < right.i;
  }

  bool operator <= (array_iterator const & right) const
  {
    return i <= right.i;
  }


  bool operator > (array_iterator const & right) const
  {
    return i > right.i;
  }

  bool operator >= (array_iterator const & right) const
  {
    return i >= right.i;
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
  std::for_each(std::begin(a), std::end(a), [](auto x) {
    std::cout << x << "\n"s;
  });
}
