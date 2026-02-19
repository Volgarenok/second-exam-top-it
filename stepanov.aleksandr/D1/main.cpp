#include <iostream>

namespace stepanov
{
  using repeatedChar = std::pair<size_t, char>;
  repeatedChar readLine(std::istream& in, bool& badInput);
  repeatedChar* readInput(std::istream& in, size_t& size, bool& badInput);
}

int main()
{
  size_t size = 0;
  stepanov::repeatedChar* data = nullptr;
  bool wasBadInput = false;
  try {
    data = stepanov::readInput(std::cin, size, wasBadInput);
  } catch (const std::bad_alloc& e) {
    std::cout << '\n';
    std::cerr << "bad alloc\n";
    return 2;
  }

  for (size_t id = size; id > 0; id--) {
    for (size_t rpt = 0; rpt < data[id - 1].first; rpt++) {
      std::cout << data[id - 1].second;
    }
  }
  std::cout << '\n';
  delete[] data;

  if (wasBadInput) {
    std::cerr << "bad input\n";
    return 1;
  }

  return 0;
}

stepanov::repeatedChar stepanov::readLine(std::istream& in, bool& badInput)
{
  repeatedChar line = {0, '\0'};
  if (!(in >> line.first)) {
    if (!in.eof()) {
      badInput = true;
    }
    return line;
  }
  if (!(in >> line.second)) {
    badInput = true;
  }
  return line;
}

stepanov::repeatedChar* stepanov::readInput(std::istream& in, size_t& size, bool& badInput)
{
  const size_t step = 10;
  size_t capacity = 10;
  auto* mem = new stepanov::repeatedChar[capacity];

  auto c = readLine(in, badInput);
  while (!in.eof() && !badInput) {
    if (size + 1 > capacity) {
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
    c = readLine(in, badInput);
  }
  return mem;
}
