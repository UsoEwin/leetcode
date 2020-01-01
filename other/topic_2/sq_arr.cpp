using namespace std;

#include <iostream>
#include <vector>

class SortedArraySquares {
 public:
  static vector<int> makeSquares(const vector<int>& arr) {
    int n = arr.size(), left = 0, right = arr.size()-1;
    int sq_idx = n-1;
    vector<int> squares(n);
    // TODO: Write your code here
    while(left <= right) {
      int left_sq = arr[left]*arr[left], right_sq = arr[right]*arr[right];
      if(left_sq <= right_sq)
        squares[sq_idx--]=right_sq,right--;
      else 
        squares[sq_idx--]=left_sq,left++;
    }
    return squares;
  }
};