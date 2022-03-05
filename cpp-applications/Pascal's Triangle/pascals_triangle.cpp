#include <iostream>
#include <vector>

size_t pascals_triangle(size_t e, size_t r, bool print = false) {
  std::vector<std::vector<size_t>> pt = {{1}, {1, 1}};
  size_t n = r;

  for (auto r = 1; r < n - 1; r++) {
    std::vector<size_t> row = {1};
    for (auto e = 1; e <= r; e++)
      row.push_back(pt[r][e - 1] + pt[r][e]);
    row.push_back(1);
    pt.push_back(row);
  }
  if (print) {
    for (auto &i : pt) {
      for (auto &j : i)
        std::cout << j << " ";
      std::cout << '\n';
    }
  }
  return pt[n - 1][e - 1];
}

int main(int argc, char **argv) {
  if (argc == 1)
    std::cout << "Syntax: pascals_triangle [element] [row] [-f for full]\n";
  if (argc == 3)
    std::cout << pascals_triangle(std::stoll(argv[1]), std::stoll(argv[2]))
              << '\n';
  else if (argc == 4)
    if ((std::string)argv[3] == "-f")
      pascals_triangle(std::stoll(argv[1]), std::stoll(argv[2]), true);
}