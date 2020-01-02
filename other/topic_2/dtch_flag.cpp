using namespace std;

#include <iostream>
#include <vector>

class DutchFlag {
 public:
  static void sort(vector<int> &arr) {
    // TODO: Write your code here   
    int left = 0, right = arr.size()-1;
    for(int i = left; i <= right; ) {
      //categorize
      if(arr[i] == 0) {
        swap(arr,left,i);
        ++left,++i;
      }
      else if(arr[i] == 1) {
        ++i;
      }
      else {
        swap(arr,i,right);
        right--;
        //could be 0,1,2 
        //next iteration will take care of it
      }
    }
    return;
  }
  private:
  static void swap(vector<int> &arr, int left, int right) {
    int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
    return;
  }
};