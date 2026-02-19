#include <iostream>

namespace novikov
{
  char** extend(char** seqv, size_t s, size_t k)
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
  char** cut(char**seqv, size_t s)
  {
    char** new_seqv = new char*[s];
    for(size_t i =0; i<s; ++i)
    {
      new_seqv[i] = seqv[i];
    }
    delete[] seqv;
    return new_seqv;
  }

}

int main()
{
  int num = 0;
  size_t size = 0;
  char c = ' ';
  char* seq;
  size_t size_seqv = 0;
  size_t cap_seqv = 3;
  char** seqv = new char*[cap_seqv];
  try
  {
    while(std::cin)
    { 
      if(std::cin>>size)
      {
      char* ceq = new char[size]; 
      }
      else
      {
        std::cerr<<"Invalid argument.\n";
        return 1;
      }
      if(std::cin>>c)
      {
        for(size_t i = 0; i<size; ++i)
        {
          seq[i] = c;
        }
      }
      else
      {
        std::cerr<<"Invalid argument.\n";
        return 1;
      }
      if(size_seqv == cap_seqv)
      {
        seqv = novikov::extend(seqv, cap_seqv, size_seqv+3);
        cap_seqv += 3;
      }
      seqv[cap_seqv] = seq;
      cap_seqv++;
    }
  }
  catch(std::bad_alloc)
  {
    std::cerr<<"Bad alloc.\n";
    return 2;
  }
}
