using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class Interval {
 public:
  int start;
  int end;

  Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

class ConflictingAppointments {
 public:
  static bool canAttendAllAppointments(vector<Interval>& intervals) {
    // TODO: Write your code here
    sort(intervals.begin(),intervals.end(),compIntervals);
    for(int i = 0; i < intervals.size()-1; ++i) {
      if(intervals[i+1].start <intervals[i].end)
        return false;
    }
    return true;
  }
 private:
  static bool compIntervals(Interval a, Interval b) {
    return a.start < b.start;
  }
};