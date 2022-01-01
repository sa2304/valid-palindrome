#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  bool isPalindrome(string s) {
    auto is_alnum = [](const char c) {
      return isalnum(c);
    };
    auto left = find_if(s.begin(), s.end(), is_alnum);
    auto right = find_if(s.rbegin(), s.rend(), is_alnum);
    while (s.end() != left and s.rend() != right) {
      if (tolower(*left) != tolower(*right)) {
        return false;
      }

      left = find_if(next(left), s.end(), is_alnum);
      right = find_if(next(right), s.rend(), is_alnum);
    }

    return true;
  }
};

void TestIsPalindrome() {
  Solution s;
  assert(s.isPalindrome("A man, a plan, a canal: Panama"s));
  assert(not s.isPalindrome("race a car"s));
  assert(s.isPalindrome(" "s));
}

int main() {
  TestIsPalindrome();
  std::cout << "Ok!" << std::endl;
  return 0;
}
