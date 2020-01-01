using namespace std;

#include <iostream>
#include <vector>

class RemoveDuplicates {
 public:
  static int remove(vector<int>& arr) {
    // TODO: Write your code here
    int left = 0;
    for(int right = 0; right < arr.size(); right++) {
      if(arr[right] != arr[left]) {
        arr[++left] = arr[right];
      }
    }
    return left+1;
  }
};
