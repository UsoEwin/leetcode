//lc 895
class FreqStack {
private:
    unordered_map<int,stack<int> *> stk_map;
    unordered_map<int,int> freq_map;
    int max_freq;
public:
    void push(int x) {
        auto freq = ++freq_map[x];
        if(stk_map.find(freq) == stk_map.end()) {
            stack<int> *stk = new stack<int>;
            stk_map[freq] = stk;
            stk_map[freq]->push(x);
        }
        else
            stk_map[freq]->push(x);
        max_freq = max_freq > freq ? max_freq : freq;
    }
    
    int pop() {
        int  res = stk_map[max_freq]->top();
        stk_map[max_freq]->pop();
        freq_map[res]--;
        if(stk_map[max_freq]->empty())
            max_freq--;
        return res;
    }
};