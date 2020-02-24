//lc 241
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        if(input.find("*") == string::npos && input.find("-") == string::npos
          && input.find("+") == string::npos) {
            res.push_back(stoi(input));
        }
        else {
            for(int i = 0; i < input.size(); ++i) {
                char chr = input[i];
                if(!isdigit(chr)) {
                    vector<int> left_vals = diffWaysToCompute(input.substr(0,i));
                    vector<int> right_vals = diffWaysToCompute(input.substr(i+1));
                    for(auto x:left_vals) {
                        for(auto y:right_vals) {
                            if(chr == '+')
                                res.push_back(x+y);
                            else if(chr == '-')
                                res.push_back(x-y);
                            else if(chr == '*')
                                res.push_back(x*y);
                        }
                    }
                }
            }
        }
        return res;
    }
};