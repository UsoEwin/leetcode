using namespace std;

#include <iostream>
#include <vector>

class SingleNumber {
  public:
    static int findSingleNumber(const vector<int>& arr) {
      // TODO: Write your code here
      int num = 0;
      for(auto x : arr) 
        num ^= x; 
      return num;
    }
};