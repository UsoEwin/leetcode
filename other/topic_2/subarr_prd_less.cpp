using namespace std;

#include <deque>
#include <iostream>
#include <vector>

class SubarrayProductLessThanK {
 public:
  static vector<vector<int>> findSubarrays(const vector<int>& arr, int target) {
    vector<vector<int>> result;
    // TODO: Write your code here
    int left = 0, product = 1;
    for(int right = 0; right < arr.size(); ++right) {
      product *= arr[right];
      while(product >= target && left < arr.size()) {
        product /= arr[left];
        left++;
      }
      vector<int> temp_list;
      //using deque
      //deque<int> temp_list;
      for(int i = right; i >= left; --i) {
        //temp_list.push_front(arr[i]);
        //vector<int> res;
        //std::move(std::begin(temp_list),std::end(temp_list),std::back_inserter(res));
        //result.push_back(res);
        temp_list.insert(temp_list.begin(),arr[i]);
        result.push_back(temp_list);
      }
    }
    return result;
  }
};
