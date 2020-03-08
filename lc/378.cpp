//lc 378
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        if(n*n < k)
            return -1;
        int left = matrix[0][0], right = matrix[n-1][n-1];
        pair<int,int> left_right;
        while(left < right) {
            int mid = left+(right-left)/2;
            left_right.first = left, left_right.second = right;
            int cnt = countNum(matrix,mid,left_right);
            if(cnt == k)
                return left_right.first;
            else if(cnt < k)
                left = left_right.second;
            else
                right = left_right.first;
        }
        return left;
    }
private:
    int countNum(vector<vector<int>>& matrix, int mid, pair<int,int> &left_right) {
        int n = matrix.size();
        int row = n-1, col = 0, cnt = 0;
        while(row >= 0 && col < n) {
            if(matrix[row][col] > mid) {
                left_right.second = min(left_right.second,matrix[row][col]);
                row--;
            }
            else {
                left_right.first = max(left_right.first,matrix[row][col]);
                cnt += row+1;
                col++;
            }
        }
        return cnt;
    }
};