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
  size++;
}

void fill(char * data, char b, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    data[i] = b;
  }
}


char * createarray(int a);

int main()
{
  size_t b;
  char a;
  size_t size;
  size_t capacity;
  char * res = nullptr;
  while (std::cin >> b && std::cin >> a)
  {
    char * data = createarray(b);
    fill(data, a, b);
    if (size >= capacity)
    {
      resize(res, size, capacity);
    }

  }
}
