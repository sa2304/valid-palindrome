#include <cassert>
#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  bool isPalindrome(string s) {
    // FIXME
    return false;
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
