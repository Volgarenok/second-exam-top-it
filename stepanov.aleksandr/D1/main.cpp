#include <iostream>

namespace stepanov
{
  using repeatedChar = std::pair<size_t, char>;
  repeatedChar readLine(std::istream& in, bool& success);
  repeatedChar* readInput(std::istream& in, size_t& size);
}

int main()
{
  size_t size = 0;
  stepanov::repeatedChar* data = nullptr;
  try {
    data = stepanov::readInput(std::cin, size);
  } catch (const std::bad_alloc& e) {
    std::cout << '\n';
    std::cerr << "bad alloc\n";
    return 2;
  } catch (const std::runtime_error& e) {
    std::cout << '\n';
    std::cerr << e.what() << '\n';
    return 1;
  }

  for (size_t id = size; id > 0; id--) {
    for (size_t rpt = 0; rpt < data[id - 1].first; rpt++) {
      std::cout << data[id - 1].second;
    }
  }
  std::cout << '\n';
  delete[] data;
  return 0;
}

stepanov::repeatedChar stepanov::readLine(std::istream& in, bool& success)
{
  repeatedChar line = {0, '\0'};
  if (!(in >> line.first)) {
    return line;
  }
  if (!(in >> line.second)) {
    success = false;
  }
  return line;
}

stepanov::repeatedChar* stepanov::readInput(std::istream& in, size_t& size)
{
  const size_t step = 10;
  size_t capacity = 10;
  auto* mem = new stepanov::repeatedChar[capacity];

  bool success = true;
  auto c = readLine(in, success);
  while (!in.eof() && success) {
    if (size + 1 >= capacity) {
      stepanov::repeatedChar* newMem = nullptr;
      try {
        newMem = new stepanov::repeatedChar[capacity + step];
      } catch (const std::bad_alloc& e) {
        delete[] mem;
        throw;
      }
      capacity += step;
      for (size_t i = 0; i < size; i++) {
        newMem[i] = mem[i];
      }
      delete[] mem;
      mem = newMem;
    }
    mem[size] = c;
    size++;
    c = readLine(in, success);
  }

  if (!success) {
    delete[] mem;
    throw std::runtime_error("bad input");
  }
  return mem;
}
