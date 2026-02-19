#include <iostream>

void resize(char * data, size_t & size, size_t & capacity)
{
  char * new_data = new char[capacity * 2];
  for (size_t i = 0; i < size; i++)
  {
    new_data[i] = data[i];
  }
  delete[] data;
  data = new_data;
  capacity *= 2;
}

void fill(char * data, char b, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    data[i] = b;
  }
}

void fillarray(char * res, char * data, size_t & size, size_t b, size_t & capacity)
{
  if (size + b > capacity)
  {
    resize(res, size, capacity);
  }
  for (size_t i = 0; i < b; i++)
  {
    res[size++] = data[i];
  }

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
      fillarray(res, data, size, b, capacity);
    }
    catch (const std::bad_alloc &)
    {
      delete[] data;
      delete[] res;
      return 2;
    }
  }

  std::cout << res;
  delete[] data;
  delete[] res;
}
