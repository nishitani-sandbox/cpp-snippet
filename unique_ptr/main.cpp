template <typename T>
class unique_ptr
{
  private:
    T * ptr = nullptr;
  public:
    unique_ptr() {}
    explicit unique_ptr(T * ptr)
      : ptr(ptr) {}
    ~unique_ptr()
    {
      delete ptr;
    }

    unique_ptr(const unique_ptr &) = delete;
    unique_ptr & operator =(const unique_ptr &) = delete;

    unique_ptr(unique_ptr && r)
      : ptr(r.ptr)
    { r.ptr = nullptr; }
    unique_ptr & operator = (unique_ptr && r)
    {
      delete ptr;
      ptr = r.ptr;
      r.ptr = nullptr;
    }

    T & operator * () noexcept { return *ptr; }
    T * operator -> () noexcept { return ptr; }
    T * get() noexcept { return ptr; };
};

int main()
{
  auto v = unique_ptr(new std::vector<int>{0, 1, 2, 3, 4});
  v->push_back(5);
  std::for_each(v->begin(), v->end(), [](auto i){ std::cout << i << "\n"s; });
}
