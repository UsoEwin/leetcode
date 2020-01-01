using namespace std;

#include <iostream>
#include <vector>

class RemoveElement {
 public:
  static int remove(vector<int>& arr, int key) {
      int next_element = 0;
      for(int i = 0; i < arr.size(); ++i) {
          if(arr[i] != key)
            arr[next_element++] = arr[i]; 
      }
      return next_element;
  }
};