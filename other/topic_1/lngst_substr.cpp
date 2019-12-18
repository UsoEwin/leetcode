using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class CharacterReplacement {
 public:
  static int findLength(const string& str, int k) {
    int maxLength = 0, maxRepeatLetterCnt = 0, left = 0;
    unordered_map<char,int> dic;
    // TODO: Write your code here
    for(int right = 0; right < str.size(); ++right) {
      maxRepeatLetterCnt = max(maxRepeatLetterCnt,++dic[str[right]]);
      // this is if because we are not working on set/map cardinal
      // which make sure reduce window size by 1 will meet the condition
      if(right-left+1 > k+maxRepeatLetterCnt) {
        dic[str[left]]--;
        left++;
      }
      maxLength = max(maxLength,right-left+1);
    }
    return maxLength;
  }
};
