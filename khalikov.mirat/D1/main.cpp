#include <iostream>

void reverse(char * res, size_t size)
{
  for (size_t i = 0; i < size/2; i++)
  {
    char temp = res[i];
    res[i] = res[size - i - 1];
    res[size - i - 1] = temp;
  }
}

char * resize(char * data, size_t & size, size_t & capacity)
{
  char * new_data = new char[capacity * 2];
  for (size_t i = 0; i < size; i++)
  {
    new_data[i] = data[i];
  }
  delete[] data;
  capacity *= 2;
  return new_data;
}

void fill(char * data, char b, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    data[i] = b;
  }
}

char * fillarray(char * res, char * data, size_t & size, size_t b, size_t & capacity)
{
  if (size + b > capacity)
  {
    res = resize(res, size, capacity);
  }
  for (size_t i = 0; i < b; i++)
  {
    res[size++] = data[i];
  }
  return res;
}

char * createarray(int a)
{
  return new char[a];
}

int main()
{
  size_t b;
  char a;
  size_t size = 0;
  size_t capacity = 10;
  char * res = createarray(capacity);
  char * data = nullptr;
  while (std::cin >> b && std::cin >> a)
  {
    try
    {
      data = createarray(b);
      fill(data, a, b);
      res = fillarray(res, data, size, b, capacity);
    }
    catch (const std::bad_alloc &)
    {
      delete[] data;
      return 2;
    }
    delete[] data;
  }
  if (!(std::cin.eof()))
  {
    return 1;
  }
  reverse(res, size);
  std::cout << res << '\n';
  delete[] res;
}
