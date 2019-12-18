using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class NoRepeatSubstring {
 public:
  static int findLength(const string& str) {
    int maxLength = 0, left = 0;
    unordered_map<char,int> dic;
    // TODO: Write your code here
    for(int right = 0; right < str.size(); ++right) {
      char rightChar = str[right];
      if(dic.find(rightChar) != dic.end()) {
        left = max(left,dic[rightChar]+1);
      }
      dic[rightChar] = right;
      maxLength = max(maxLength,right-left+1);
    }
    return maxLength;
  }
};