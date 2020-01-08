class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int i = 0, j = 0;
        vector<vector<int>> res;
        while(i < A.size() && j < B.size()) {
            if(A[i][0] >= B[j][0] && A[i][0] <= B[j][1]
            || B[j][0] >= A[i][0] && B[j][0] <= A[i][1]) {
                res.push_back(vector<int> ({max(A[i][0],B[j][0]),min(A[i][1],B[j][1])}));
            }
            if(A[i][1] < B[j][1])
                i++;
            else
                j++;
        }
        return res;
    }
};