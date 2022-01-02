#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  bool isPalindrome(string s) {
    static const char *alphabet = "qwertyuiopasdfghjklzxcvbnm1234567890QWERTYUIOPASDFGHJKLZXCVBNM";
    size_t left = s.find_first_of(alphabet);
    if (string::npos != left) {
      size_t right = s.find_last_of(alphabet);
      while (left < right) {
        char l = tolower(s[left]);
        char r = tolower(s[right]);
        if (tolower(s[left]) != tolower(s[right])) {
          return false;
        }

        left = s.find_first_of(alphabet, left + 1);
        if (string::npos == left) { break; }
        right = s.find_last_of(alphabet, right - 1);  // right should never be 0: (0 - 1) is size_t overflow
        if (string::npos == right) { break; }
      }
    }

    return true;
  }
};

void TestIsPalindrome() {
  Solution s;
  assert(s.isPalindrome("A man, a plan, a canal: Panama"s));
  assert(not s.isPalindrome("race a car"s));
  assert(s.isPalindrome(" "s));
  assert(not s.isPalindrome(",,,,,,,,,,,,acva"s));
}

int main() {
  TestIsPalindrome();
  std::cout << "Ok!" << std::endl;
  return 0;
}
