#include <iostream>
#include <new>

namespace sadovnik {

class CharArray {
public:
  CharArray()
    : data_(nullptr)
    , size_(0)
    , capacity_(0)
  {
  }

  ~CharArray()
  {
    delete[] data_;
  }

  CharArray(const CharArray&) = delete;
  CharArray& operator=(const CharArray&) = delete;

  CharArray(CharArray&& other) noexcept
    : data_(other.data_)
    , size_(other.size_)
    , capacity_(other.capacity_)
  {
    other.data_ = nullptr;
    other.size_ = 0;
    other.capacity_ = 0;
  }

  CharArray& operator=(CharArray&& other) noexcept
  {
    if (this != &other) {
      delete[] data_;
      data_ = other.data_;
      size_ = other.size_;
      capacity_ = other.capacity_;
      other.data_ = nullptr;
      other.size_ = 0;
      other.capacity_ = 0;
    }
    return *this;
  }

  void push_back(char c)
  {
    if (size_ >= capacity_) {
      std::size_t new_cap = (capacity_ == 0) ? 4 : capacity_ * 2;
      char* new_data = new char[new_cap];
      for (std::size_t i = 0; i < size_; ++i) {
        new_data[i] = data_[i];
      }
      delete[] data_;
      data_ = new_data;
      capacity_ = new_cap;
    }
    data_[size_++] = c;
  }

  char& operator[](std::size_t index)
  {
    return data_[index];
  }

  const char& operator[](std::size_t index) const
  {
    return data_[index];
  }

  std::size_t size() const
  {
    return size_;
  }

private:
  char* data_;
  std::size_t size_;
  std::size_t capacity_;
};

} // namespace sadovnik

int main()
{
  using namespace sadovnik;

  CharArray sequence;

  unsigned int count;
  char ch;

  while (std::cin >> count >> ch) {
    if (count == 0) {
      continue;
    }
    try {
      for (unsigned int i = 0; i < count; ++i) {
        sequence.push_back(ch);
      }
    } catch (const std::bad_alloc&) {
      std::cerr << "Memory allocation failed\n";
      std::cout << '\n';
      return 2;
    }
  }

  if (!std::cin.eof()) {
    std::cerr << "Invalid input format\n";
    return 1;
  }

  for (std::size_t i = sequence.size(); i > 0; --i) {
    std::cout << sequence[i - 1];
  }
  std::cout << '\n';

  return 0;
}
