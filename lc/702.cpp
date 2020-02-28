//lc 702
class Solution {
public:
    int search(const ArrayReader& reader, int key) {
        int left = 0, right = 1;
        while(reader.get(right) != 2147483647 && reader.get(right) < key) {
            left = right+1;
            right <<= 1;
        }
        while(left <= right) {
            int mid = left+(right-left)/2;
            if(reader.get(mid) > key)
                right = mid-1;
            else if(reader.get(mid) < key)
                left = mid+1;
            else
                return mid;
        }
        return -1;
    }
};