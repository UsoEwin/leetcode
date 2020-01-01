using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class MinimumWindowSubstring {
 public:
  static string findSubstring(const string &str, const string &pattern) {
    // TODO: Write your code here
    unordered_map<char,int> dict;
    int left = 0, sub_start = 0, matched = 0, min_len = str.size()+1;
    for(auto x : pattern)
      dict[x]++;
    for(int right = 0; right < str.size(); ++right) {
      char right_char = str[right];
      if(dict.find(right_char) != dict.end()) {
        dict[right_char]--;
        if(dict[right_char] == 0)
          matched++;
      }
      //another way is to count every match, see the sol review, 
      //but to be consistent, use the dict size will be preferred.
      while(matched == dict.size()) {
        if(right-left+1 < min_len) {
          sub_start = left; 
          min_len = right-left+1;
        }
        char left_char = str[left++];
        if(dict.find(left_char) != dict.end()) {
          if(dict[left_char] == 0)
            matched--;
          dict[left_char]++;
        }
      }
    }
    return min_len == str.size()+1 ? "":str.substr(sub_start,min_len);
  }
};