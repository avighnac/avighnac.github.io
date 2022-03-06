#include <iostream>
#include <sstream>
#include <vector>
#include "tribonacci.h"

std::vector<std::string> string_into_words(std::string str) {
  std::string word;
  std::vector<std::string> answer;
  for (auto i : str) {
    if (i == ' ') {
      answer.push_back(word);
      word = "";
    }
    word.push_back(i);
  }
  std::stringstream ss(word);
  answer.push_back(word);

  std::vector<std::string> newanswer;
  for (auto i : answer) {
    std::string word;
    for (auto j : i) {
      if (j != ' ') word.push_back(j);
    }
    newanswer.push_back(word);
  }
  return newanswer;
}

int main(int argc, char *argv[]) {
    if (argc == 3) {
        std::string sequence_str = argv[1];
        std::string n_str = argv[2];

        std::vector<std::string> sequence = string_into_words(sequence_str);
        std::stringstream ss(n_str); int n; ss >> n;

        std::vector<std::string> answer = tribonacci(sequence, n);
        for (auto i : answer) std::cout << i << " ";
    }
}