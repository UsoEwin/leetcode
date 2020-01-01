using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class TripletWithSmallerSum {
 public:
  static int searchTriplets(vector<int> &arr, int target) {
    int count = 0;
    // TODO: Write your code here
    sort(arr.begin(),arr.end());
    for(int i = 0; i < arr.size()-2; i++) {
      int left = i+1, right = arr.size()-1;
      while(left < right) {
        int sum = arr[i] + arr[left] + arr[right];
        if(sum < target) {
          //purpose of this is to replace every single arr[right],so right-left is the cnt since left != right
          count += right-left;
          left++;
        }
        else 
          right--;
      }
    }
    return count;
  }
};