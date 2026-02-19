#include <iostream>

namespace novikov
{
  char** extend(char** seqv, size_t s, size_t k);
  char** cut(char** seqv, size_t s);
  int* extend(int* lens, size_t s, size_t k);
  int* cut(int* lens, size_t s);
}

int main()
{
  size_t size = 0;
  char c = ' ';
  size_t size_seqv = 0;
  size_t cap_seqv = 3;
  int* lens = nullptr;
  char** seqv = nullptr;
  try
  {
    lens = new int[cap_seqv];
    seqv = new char*[cap_seqv];
    
    for(size_t i = 0; i < cap_seqv; ++i)
    {
      seqv[i] = nullptr;
    }
    
    while(std::cin >> size >> c)
    {
      if(size == 0)
      {
        continue;
      }
      
      char* seq = new char[size];
      
      for(size_t i = 0; i < size; ++i)
      {
        seq[i] = c;
      }
      
      if(size_seqv == cap_seqv)
      {
        lens = novikov::extend(lens, cap_seqv, cap_seqv + 3);
        seqv = novikov::extend(seqv, cap_seqv, cap_seqv + 3);
        cap_seqv += 3;
      }
      
      lens[size_seqv] = size;
      seqv[size_seqv] = seq;
      size_seqv++;
    }
    
    if(size_seqv > 0)
    {
      for(size_t i = size_seqv; i > 0; --i)
      {
        size_t idx = i - 1;
        for(int j = lens[idx] - 1; j >= 0; --j)
        {
          std::cout << seqv[idx][j];
        }
      }
    }
    
    std::cout << std::endl;
    
    for(size_t i = 0; i < size_seqv; ++i)
    {
      delete[] seqv[i];
    }
    delete[] seqv;
    delete[] lens;
    
    return 0;
  }
  catch(const std::bad_alloc&)
  {
    std::cerr << "Bad alloc.\n";
    
    if(seqv)
    {
      for(size_t i = 0; i < size_seqv; ++i)
      {
        delete[] seqv[i];
      }
      delete[] seqv;
    }
    
    delete[] lens;
    
    return 2;
  }
}

char** novikov::extend(char** seqv, size_t s, size_t k)
{
  char** new_seqv = new char*[k];
  for(size_t i =0; i < s; ++i)
  {
    new_seqv[i] = seqv[i];      
  }
  for(size_t i = s; i<k; ++i)
  {
    new_seqv[i] = nullptr;
  }
  delete[] seqv;
  return new_seqv;
}

char** novikov::cut(char**seqv, size_t s)
{
  char** new_seqv = new char*[s];
  for(size_t i =0; i<s; ++i)
  {
    new_seqv[i] = seqv[i];
  }
  delete[] seqv;
  return new_seqv;
}
int* novikov::extend(int* lens, size_t s, size_t k)
{
  int* new_lens = new int[k];
  for(size_t i =0; i<s; ++i)
  {
    new_lens[i] = lens[i];
  }
  for(size_t i = s; i<k; ++i)
  {
    new_lens[i] = 0;
  }
  delete[] lens;
  return new_lens;
}

int* novikov::cut(int* lens, size_t s)
{
  int* new_lens = new int[s];
  for(size_t i =0; i<s; ++i)
  {
    new_lens[i] = lens[i];
  }
  delete[] lens;
  return new_lens;
}