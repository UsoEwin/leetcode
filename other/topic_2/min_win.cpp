using namespace std;

#include <iostream>
#include <limits>
#include <vector>

class ShortestWindowSort {
 public:
  static int sort(const vector<int>& arr) {
    // TODO: Write your code here
    int left = 0, right = arr.size()-1;
    while(left < arr.size()-1 && arr[left] <= arr[left+1])
      left++;
    if(left == arr.size()-1)
      return 0;
    while(right > 0 && arr[right-1] <= arr[right])
      right--;
    int sub_min = std::numeric_limits<int>::max(), sub_max = numeric_limits<int>::min();
    for(int i = left; i <= right; ++i) 
      sub_max = max(arr[i],sub_max), sub_min = min(arr[i],sub_min);
    while(left > 0 && arr[left-1] > sub_min)
      left--;
    while(right < arr.size()-1 && arr[right+1] < sub_max)
      right++;
    return right-left+1;
  }
};