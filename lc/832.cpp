//lc 832
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        if(A.size() < 1)
            return A;
        int m = A.size(), n = A[0].size();
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < (n+1)>>1; ++j) {
                int temp = A[i][j]^1;
                A[i][j] = A[i][n-j-1]^1;
                A[i][n-j-1] = temp;
            }
        }
        return A;
    }
};