using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class StringAnagrams {
 public:
  static vector<int> findStringAnagrams(const string &str, const string &pattern) {
    vector<int> resultIndices;
    // TODO: Write your code here
    int left = 0, match = 0;
    unordered_map<char,int> dic;
    for(auto x : pattern) {
      dic[x]++;
    }
    for(int right = 0; right < str.size(); ++right) {
      char right_char = str[right];
      if(dic.find(right_char) != dic.end()) {
        dic[right_char]--;
        if(dic[right_char] == 0)
          match++;
      }
      if(right >= pattern.size()) {
        char left_char = str[left];
        if(dic.find(left_char) != dic.end()) {
          if(dic[left_char] == 0)
            match--;
          dic[left_char]++;
        }
        left++;
      }
      if(match == dic.size())
        resultIndices.push_back(left);
    }
    return resultIndices;
  }
};
