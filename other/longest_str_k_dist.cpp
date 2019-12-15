#include<unordered_map>
#include<iostream>
#include<string>

using namespace std;

class solution {
    public:
    static findLenth(const string& str, int k) {
        int max_lenth = 0, left = 0;
        unordered_map<char,int> dic;
        for(int right = 0; right < str.size(); ++right) {
            dic[str[right]]++;
            while(dic.size() > k) {
                dic[str[left]]--;
                if(dic[str[left]] == 0)
                    dic.erase(str[left]);
                left++;
            }
            max_lenth = max(right-left+1,max_lenth);
        }
        return max_lenth;
    }
}