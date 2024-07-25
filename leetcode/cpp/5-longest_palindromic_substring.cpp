#include<string>

std::string propagate(const std::string &s, int back, int front) {
  while((back-1) >= 0 && (front+1) < s.length() && s[back-1] == s[front+1]) {
    back--; front++;
  }
  return s.substr(back, front-back+1);
}

std::string longestPalindrome(std::string s) {
  if (s.length() <= 1) return s;
  int back, front;
  std::string longest = s.substr(0,1), aux;
  for (back = 0; front < s.length(); back++) {
    // even palindrome
    front = back+1;
    if (s[front] == s[back]) {
      aux = propagate(s, back, front);
      if (aux.length() > longest.length()) longest = aux;
    }

    // odd palindrome
    front = back+2;
    if (front < s.length() && s[back] == s[front]) {
      aux = propagate(s, back, front);
      if (aux.length() > longest.length()) longest = aux;
    }
  }
  return longest;
}
