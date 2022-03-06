#include <string>
#include <vector>

std::vector<int> digitize(std::string str_n)  {
  std::vector<int> answer;
  for (int i = str_n.length()-1; i > -1; i--) answer.push_back(str_n[i]-48);
  return answer;
}

std::string add(const std::string& a1, const std::string& b1) {
  std::string a = a1;
  std::string b = b1;
  if (a1 == "") a = "0";
  if (b1 == "") b = "0";

  std::vector<int> a_vec = digitize(a);
  std::vector<int> b_vec = digitize(b); 
  if (a.length() > b.length()) for (auto i=0; i<a.length()-b.length(); i++) b_vec.push_back(0);
  if (a.length() < b.length()) for (auto i=0; i<b.length()-a.length(); i++) a_vec.push_back(0);

  std::vector<int> addition;
  for (int i=0; i<(int)a_vec.size(); i++) addition.push_back(a_vec[i] + b_vec[i]); //Adding every digit of a and b

  for (int i=0; i<(int)a_vec.size(); i++) {
      if (std::to_string(addition[i]).length() == 2 && i != a_vec.size()-1) {
          int carry_forward = addition[i] / 10;
          addition[i+1] += carry_forward;
          addition[i] -= carry_forward * 10;
      }
  }

  std::string answer;
  for (int i = addition.size()-1; i > -1; i--) answer += std::to_string(addition[i]); //Re-Reversing the array

  return answer;
}