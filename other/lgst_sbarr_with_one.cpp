using namespace std;

#include <iostream>
#include <vector>

class ReplacingOnes {
 public:
  static int findLength(const vector<int>& arr, int k) {
    int  maxLength = 0, oneCnt = 0, left = 0;
    // TODO: Write your code here
    for(int right = 0; right < arr.size(); ++right) {
      if(arr[right] == 1)
        oneCnt++;
      if(right-left+1> k + oneCnt) {
        if(arr[left] == 1)
          oneCnt--;
        left++;
      }
      maxLength = max(maxLength,right-left+1);
    }
    return maxLength;
  }
};