using namespace std;

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

class TripletSumCloseToTarget {
 public:
  static int searchTriplet(vector<int>& arr, int targetSum) {
    // TODO: Write your code here
    int min_diff  = numeric_limits<int>::max(), res = targetSum;
    for(int i = 0; i < arr.size()-2; ++i) {
      int left = i+1, right = arr.size()-1;
      while(left < right) {
        int sum = arr[left] + arr[right] + arr[i];
        int curr_diff = targetSum - sum;
        if(abs(curr_diff) < abs(min_diff))
          min_diff = curr_diff;
        if(curr_diff == 0)
          return targetSum;
        if(curr_diff > 0)
          left++;
        else
          right--;
      }
    }
    return targetSum-min_diff;
  }
};
