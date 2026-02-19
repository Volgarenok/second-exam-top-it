#include <iostream>
#include <cstddef>
#include <cstring>
#include <new>

namespace shigarev
{
  struct pair_t
  {
    unsigned int count_;
    char ch_;
  };

  class CharArray
  {
  public:
    CharArray():
      data_(nullptr),
      size_(0)
    {
    }

    ~CharArray()
    {
      delete [] data_;
    }

    void append(char ch)
    {
      char * grown = new char [size_ + 1];
      for (std::size_t i = 0; i < size_; ++i)
      {
        grown[i] = data_[i];
      }
      grown[size_] = ch;
      delete [] data_;
      data_ = grown;
      ++size_;
    }

    std::size_t getSize() const
    {
      return size_;
    }

    char operator [](std::size_t i) const
    {
      return data_[i];
    }

  private:
    char * data_;
    std::size_t size_;
  };

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

    std::size_t getSize() const
    {
      return size_;
    }

    const pair_t & operator [](std::size_t i) const
    {
      return data_[i];
    }

  private:
    pair_t * data_;
    std::size_t size_;
  };

  void fillPairs(const CharArray & chars, PairArray & pairs)
  {
    std::size_t n = chars.getSize();
    if (n == 0)
    {
      return;
    }

    char currentCh = chars[0];
    unsigned int currentCount = 1;

    for (std::size_t i = 1; i < n; ++i)
    {
      if (chars[i] == currentCh)
      {
        currentCount++;
      }
      else
      {
        pairs.append(currentCount, currentCh);
        currentCh = chars[i];
        currentCount = 1;
      }
    }
    pairs.append(currentCount, currentCh);
  }
}

int main(int argc, char ** argv)
{
  bool isReverse = false;
  if (argc > 1)
  {
    if (argc == 2 && std::strcmp(argv[1], "reverse") == 0)
    {
      isReverse = true;
    }
    else
    {
      std::cerr << "Error: invalid command line arguments\n";
      return 1;
    }
  }

  shigarev::CharArray chars;
  char tempCh = '\0';
  while (std::cin >> tempCh)
  {
    try
    {
      chars.append(tempCh);
    }
    catch (const std::bad_alloc &)
    {
      std::cerr << "Error: memory allocation failed\n";
      return 2;
    }
  }

  shigarev::PairArray pairs;
  try
  {
    shigarev::fillPairs(chars, pairs);
  }
  catch (const std::bad_alloc &)
  {
    std::cerr << "Error: memory allocation failed\n";
    return 2;
  }

  std::size_t numPairs = pairs.getSize();
  if (numPairs == 0)
  {
    std::cout << '\n';
  }
  else if (isReverse)
  {
    for (std::size_t i = numPairs; i > 0; --i)
    {
      std::cout << pairs[i - 1].count_ << " " << pairs[i - 1].ch_ << '\n';
    }
  }
  else
  {
    for (std::size_t i = 0; i < numPairs; ++i)
    {
      std::cout << pairs[i].count_ << " " << pairs[i].ch_ << '\n';
    }
  }

  return 0;
}
