template <typename Array>
struct array_iterator
{
  Array & a;
  std::size_t i;

  array_iterator(Array & a, std::size_t i)
    : a(a), i(i) {}

  typename Array::reference operator *() const
  {
    return a[i];
  }

  typename Array::reference operator [](std::size_t n) const
  {
    return *(this + n);
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

  bool operator ==(array_iterator const & right) const
  {
    return i == right.i;
  }

  bool operator !=(array_iterator const & right) const
  {
    return i != right.i;
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

template <typename Array>
struct array_const_iterator
{
  Array const & a;
  std::size_t i;

  array_const_iterator(Array const & a, std::size_t i)
    : a(a), i(i) {}

  array_const_iterator(typename array_iterator<Array>::iterator const & iter)
    : a(iter.a), i(iter.i) {}

  typename Array::const_reference operator *() const
  {
    return a[i];
  }

  typename Array::const_reference operator [](std::size_t n) const
  {
    return *(this + n);
  }

  array_const_iterator & operator ++()
  {
    ++i;
    return *this;
  }

  array_const_iterator operator ++(int)
  {
    array_iterator copy = *this;
    ++*this;
    return copy;
  }

  array_const_iterator & operator --()
  {
    --i;
    return *this;
  }

  array_const_iterator operator --(int)
  {
    array_iterator copy = *this;
    --*this;
    return copy;
  }

  array_const_iterator & operator +=(std::size_t n)
  {
    i += n;
    return *this;
  }

  array_const_iterator operator +(std::size_t n) const
  {
    auto copy = *this;
    copy += n;
    return copy;
  }

  bool operator ==(array_const_iterator const & right) const
  {
    return i == right.i;
  }
 
  bool operator !=(array_const_iterator const & right) const
  {
    return i != right.i;
  }

  bool operator < (array_const_iterator const & right) const
  {
    return i < right.i;
  }

  bool operator <= (array_const_iterator const & right) const
  {
    return i <= right.i;
  }


  bool operator > (array_const_iterator const & right) const
  {
    return i > right.i;
  }

  bool operator >= (array_const_iterator const & right) const
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
  using const_iterator = array_const_iterator<array>;

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

  const_iterator cbegin()
  {
    return const_iterator(*this, 0);
  }

  const_iterator cend()
  {
    return const_iterator(*this, N);
  }
};

int main()
{
  array<int, 5> a = {1, 2, 3, 4, 5};
  std::for_each(std::begin(a), std::end(a), [](auto x) {
    std::cout << x << "\n"s;
  });

  array<int, 5> b = {1, 2, 3, 4, 5};
  auto i = b.begin();
  *i = 100;
  std::cout << *i << "\n"s;
}
