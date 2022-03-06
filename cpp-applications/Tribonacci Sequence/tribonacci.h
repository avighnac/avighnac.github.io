#include <vector>
#include "add.h"

std::vector<std::string> tribonacci(std::vector<std::string> signature, int n) {
    std::vector<std::string> answer;
    if (n == 0) return answer;
    if (n == 1) {
        answer.push_back(signature[0]);
        return answer;
    }
    if (n == 2) {
        answer.push_back(signature[0]);
        answer.push_back(signature[1]);
        return answer;
    }

    for (int i = 0; i < n-3; i++) {
        std::string a = signature[signature.size()-1];
        std::string b = signature[signature.size()-2];
        std::string c = signature[signature.size()-3];

        signature.push_back(add(add(a, b), c));
    }

    return signature;
}