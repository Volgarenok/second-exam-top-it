#include <iostream>
#include <memory>
#include <new>

namespace sadovnik
{

class CharBuffer
{
public:
  void pushBack(char ch)
  {
    constexpr std::size_t INITIAL_CAPACITY = 16;
    constexpr std::size_t GROWTH_FACTOR = 2;

    if (size_ == capacity_)
    {
      std::size_t new_capacity = (capacity_ == 0) ? INITIAL_CAPACITY
                                                  : capacity_ * GROWTH_FACTOR;
      auto new_data = std::make_unique<char[]>(new_capacity);
      for (std::size_t i = 0; i < size_; ++i)
      {
        new_data[i] = data_[i];
      }
      data_ = std::move(new_data);
      capacity_ = new_capacity;
    }
    data_[size_++] = ch;
  }

  std::size_t size() const { return size_; }
  const char* data() const { return data_.get(); }

private:
  std::unique_ptr<char[]> data_;
  std::size_t size_ = 0;
  std::size_t capacity_ = 0;
};

bool readAndBuild(CharBuffer& buffer)
{
  unsigned count;
  char ch;
  while (std::cin >> count >> ch)
  {
    for (unsigned i = 0; i < count; ++i)
    {
      buffer.pushBack(ch);
    }
  }
  return std::cin.eof();
}

}

int main()
{
  sadovnik::CharBuffer buffer;
  try
  {
    if (!sadovnik::readAndBuild(buffer))
    {
      std::cerr << "Input error\n";
      return 1;
    }
  }
  catch (const std::bad_alloc&)
  {
    std::cerr << "Memory allocation failed\n";
    std::cout << std::endl;
    return 2;
  }

  if (buffer.size() > 0)
  {
    for (std::size_t i = buffer.size(); i > 0; --i)
    {
      std::cout << buffer.data()[i - 1];
    }
  }
  std::cout << std::endl;
  return 0;
}

