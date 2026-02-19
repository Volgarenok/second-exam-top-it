#include <cstddef>
#include <iostream>
#include <new>

namespace shigarev {

struct Pair {
  unsigned int count;
  char ch;
};

bool readPair(unsigned int & count, char & ch)
{
  return static_cast< bool >(std::cin >> count >> ch);
}

class PairArray {
public:
  PairArray():
    data_(nullptr),
    size_(0)
  {}

  ~PairArray()
  {
    delete[] data_;
  }

  size_t size() const
  {
    return size_;
  }

  void append(unsigned int count, char ch)
  {
    Pair * grown = new Pair[size_ + 1];
    for (size_t i = 0; i < size_; ++i) {
      grown[i] = data_[i];
    }
    grown[size_] = {count, ch};
    delete[] data_;
    data_ = grown;
    ++size_;
  }

  size_t computeLength() const
  {
    size_t total = 0;
    for (size_t i = 0; i < size_; ++i) {
      total += data_[i].count;
    }
    return total;
  }

  const Pair & operator[](size_t i) const
  {
    return data_[i];
  }

private:
  Pair * data_;
  size_t size_;
};

class CharSequence {
public:
  explicit CharSequence(const PairArray & pairs):
    length_(pairs.computeLength()),
    data_(new char[length_])
  {
    size_t pos = 0;
    for (size_t i = 0; i < pairs.size(); ++i) {
      for (unsigned int j = 0; j < pairs[i].count; ++j) {
        data_[pos] = pairs[i].ch;
        ++pos;
      }
    }
  }

  ~CharSequence()
  {
    delete[] data_;
  }

  size_t length() const
  {
    return length_;
  }

  void printReverse() const
  {
    for (size_t i = length_; i > 0; --i) {
      std::cout << data_[i - 1];
    }
    std::cout << '\n';
  }

private:
  size_t length_;
  char * data_;
};

}

int main() {
  shigarev::PairArray arr;
  unsigned int count = 0;
  char ch = '\0';
  while (std::cin.peek() != EOF) {
    if (!shigarev::readPair(count, ch)) {
      if (!std::cin.eof()) {
        std::cerr << "Error: failed to read a pair\n";
        return 1;
      }
      break;
    }
    try {
      arr.append(count, ch);
    } catch (const std::bad_alloc &) {
      std::cerr << "Error: memory allocation failed\n";
      std::cout << '\n';
      return 2;
    }
  }

  try {
    const shigarev::CharSequence seq(arr);
    seq.printReverse();
  } catch (const std::bad_alloc &) {
    std::cerr << "Error: memory allocation failed\n";
    std::cout << '\n';
    return 2;
  }

  return 0;
}
