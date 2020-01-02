using namespace std;

#include <iostream>
#include <string>

class BackspaceCompare {
 public:
  static bool compare(const string &str1, const string &str2) {
    // TODO: Write your code here
    int idx1 = str1.size()-1, idx2 = str2.size()-1;
    while(idx1 >= 0 || idx2 >= 0) {
      idx1 = getNextIdx(str1,idx1);
      idx2 = getNextIdx(str2,idx2);
      if(idx1 < 0 && idx2 < 0)
        return true;
      if(idx1 < 0 || idx2 < 0)
        return false;
      if(str1[idx1] != str2[idx2])
        return false;
      idx1--,idx2--;
    }
    return true;
  }
 private:
  static int getNextIdx(string str, int idx) {
    int backspace_cnt = 0;
    while(idx >= 0) {
      if(str[idx] == '#')
        backspace_cnt++;
      else if(backspace_cnt > 0)
        backspace_cnt--;
      else
        break;
      idx--;
    }
    return idx;
  }
};