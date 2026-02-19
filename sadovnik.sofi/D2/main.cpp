#include <iostream>
#include <cstring>
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
      const std::size_t new_cap = (capacity_ == 0) ? 4 : capacity_ * 2;
      char* const new_data = new char[new_cap];
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

}

int main(int argc, char* argv[])
{
  using namespace sadovnik;

  bool reverse_mode = false;
  if (argc == 2) {
    if (std::strcmp(argv[1], "reverse") == 0) {
      reverse_mode = true;
    } else {
      std::cerr << "Invalid argument: " << argv[1] << '\n';
      return 1;
    }
  } else if (argc > 2) {
    std::cerr << "Too many arguments\n";
    return 1;
  }

  CharArray sequence;
  char ch;

  while (std::cin >> ch) {
    try {
      sequence.push_back(ch);
    } catch (const std::bad_alloc&) {
      std::cerr << "Memory allocation failed\n";
      return 2;
    }
  }

  if (sequence.size() == 0) {
    std::cout << '\n';
    return 0;
  }

  if (!reverse_mode) {
    std::size_t i = 0;
    while (i < sequence.size()) {
      char current = sequence[i];
      std::size_t run_start = i;
      while (i < sequence.size() && sequence[i] == current) {
        ++i;
      }
      std::size_t run_length = i - run_start;
      std::cout << run_length << ' ' << current << '\n';
    }
  } else {
    std::size_t i = sequence.size();
    while (i > 0) {
      --i;
      char current = sequence[i];
      std::size_t run_end = i;
      while (i > 0 && sequence[i - 1] == current) {
        --i;
      }
      std::size_t run_length = run_end - i + 1;
      std::cout << run_length << ' ' << current << '\n';
    }
  }

  return 0;
}
