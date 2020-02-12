//lc 502
class Solution {
public:
    struct compCapital{
        bool operator()(const pair<int,int> &a, pair<int,int> &b) {
            return a.first > b.first;
      }  
    };
    struct compProfit{
        bool operator()(const pair<int,int> &a, pair<int,int> &b) {
            return a.first < b.first; //max heap
        }
    };
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        int total_capital = W;
        priority_queue<pair<int,int>,vector<pair<int,int>>,compCapital> min_q;
        priority_queue<pair<int,int>,vector<pair<int,int>>,compProfit> max_q;
        for(int i = 0; i < Capital.size(); ++i)
            min_q.push(make_pair(Capital[i],i));
        for(int i = 0; i < k; ++i) {
            while(!min_q.empty() && min_q.top().first <= total_capital) {
                int key = min_q.top().second;
                max_q.push(make_pair(Profits[key],key));
                min_q.pop();
            }
            if(max_q.empty())
                break;
            total_capital += max_q.top().first;
            max_q.pop();
        }
        return total_capital;
    }
};