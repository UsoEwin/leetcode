using namespace std;

#include <iostream>
#include <unordered_map>
#include <vector>

class MaxFruitCountOf2Types {
 public:
  static int findLength(const vector<char>& arr) {
    int maxLength = 0, left = 0;
    unordered_map<char,int> dic;
    // TODO: Write your code here
    for(int right = 0; right < arr.size(); ++right) {
      dic[arr[right]]++;
      while(dic.size() > 2) {
        dic[arr[left]]--;
        if(dic[arr[left]] == 0)
          dic.erase(arr[left]);
        left++;
      }
      maxLength = max(right-left+1,maxLength);
    }
    return maxLength;
  }
};