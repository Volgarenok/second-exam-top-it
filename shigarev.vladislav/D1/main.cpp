#include <cstddef>
#include <iostream>
#include <new>

namespace shigarev
{
  struct pair_t
  {
    unsigned int count_;
    char ch_;
  };

  bool readPair(unsigned int & count, char & ch)
  {
    return static_cast< bool >(std::cin >> count >> ch);
  }

  class PairArray
  {
  public:
    PairArray():
      data_(nullptr),
      size_(0)
    {
    }

    ~PairArray()
    {
      delete [] data_;
    }

    const pair_t & operator [](std::size_t i) const
    {
      return data_[i];
    }

    std::size_t getSize() const
    {
      return size_;
    }

    void append(unsigned int count, char ch)
    {
      pair_t * grown = new pair_t [size_ + 1];
      for (std::size_t i = 0; i < size_; ++i)
      {
        grown[i] = data_[i];
      }
      grown[size_].count_ = count;
      grown[size_].ch_ = ch;
      delete [] data_;
      data_ = grown;
      ++size_;
    }

    std::size_t computeLength() const
    {
      std::size_t total = 0;
      for (std::size_t i = 0; i < size_; ++i)
      {
        total += data_[i].count_;
      }
      return total;
    }

  private:
    pair_t * data_;
    std::size_t size_;
  };

  class CharSequence
  {
  public:
    explicit CharSequence(const PairArray & pairs):
      length_(pairs.computeLength()),
      data_(new char [length_])
    {
      std::size_t pos = 0;
      for (std::size_t i = 0; i < pairs.getSize(); ++i)
      {
        for (unsigned int j = 0; j < pairs[i].count_; ++j)
        {
          data_[pos] = pairs[i].ch_;
          ++pos;
        }
      }
    }

    ~CharSequence()
    {
      delete [] data_;
    }

    std::size_t getLength() const
    {
      return length_;
    }

    void printReverse() const
    {
      for (std::size_t i = length_; i > 0; --i)
      {
        std::cout << data_[i - 1];
      }
      std::cout << '\n';
    }

  private:
    std::size_t length_;
    char * data_;
  };
}

int main()
{
  shigarev::PairArray arr;
  unsigned int count = 0;
  char ch = '\0';

  while (std::cin.peek() != EOF)
  {
    if (!shigarev::readPair(count, ch))
    {
      if (!std::cin.eof())
      {
        std::cerr << "Error: failed to read a pair\n";
        return 1;
      }
      break;
    }

    try
    {
      arr.append(count, ch);
    }
    catch (const std::bad_alloc &)
    {
      std::cerr << "Error: memory allocation failed\n";
      return 2;
    }
  }

  try
  {
    const shigarev::CharSequence seq(arr);
    seq.printReverse();
  }
  catch (const std::bad_alloc &)
  {
    std::cerr << "Error: memory allocation failed\n";
    return 2;
  }

  return 0;
}
