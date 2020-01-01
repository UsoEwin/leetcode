using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class TripletSumToZero {
 public:
  static vector<vector<int>> searchTriplets(vector<int> &arr) {
    vector<vector<int>> triplets;
    // TODO: Write your code here
    sort(arr.begin(),arr.end());
    for(int i = 0; i < arr.size()-2; ++i) {
      if(i > 0 && arr[i] == arr[i-1])
        continue;
      int left = i+1,right = arr.size()-1;
      while(left < right) {
        long long sum = arr[left] + arr[right];
        if(sum == -arr[i]) {
          triplets.push_back({arr[i],arr[left],arr[right]});
          left++,right--;
          while(left < right && arr[left] == arr[left-1])
            left++;
          while(left < right && arr[right] == arr[right+1])
            right--;
        }
        else if(sum < -arr[i]) 
          left++;
        else
          right--;
      }
    }
    return triplets;
  }
};