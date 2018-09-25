//760. Find Anagram Mappings 
class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        int * hash = new int[100000];
        vector<int> result;
        for (int i = 0; i < B.size(); ++i)
        {
        	hash[B[i]] = i;
        }
        for (int j = 0; j < A.size(); ++j)
        {
        	result.push_back(hash[A[j]]);
        }
        delet [] hash;
        return result;
    }
};

//665. Non-decreasing Array
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
		int counter = 0;
		for (int i = 1; i < nums.size()-1; ++i)
		      {

		      	if (nums[i-1] > nums[i] && nums[i]>nums[i+1])
		      	{
		      		counter+=2;
		      	}
		      	else if(nums[i-1]>nums[i]) counter++;
		      	
		      	if (counter >= 2)
		      	{
		      		return false;
		      	}
		      }  
		return true;    
    }
};


//461. Hamming Distance
class Solution {
public:
    int hammingDistance(int x, int y) {
        bitset<32> xBS(x);
        bitset<32> yBS(y);
        int count = 0;
        for(int i = 0; i < 32; i++)
        {
            if(xBS[i] != yBS[i])
            {
                count++;
            }
        }
        return abs(count);
    }
};

//476. Number Complement
class Solution {
public:
    int findComplement(int num) {
        bitset<32> numBS(num);
        int result = 0;
        bitset<32> = rBS(result)
        int count = 0;
        for (int i = 0; i < 32; ++i)
        {	
        	if (numBS[i] != 0)
        	{
        		break;
        	}
        	count++;
        }
        for (int i = count; i < count; ++i)
        {
        	/* code */
        }
    }
};

//771. Jewels and Stones
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int hash[500000] = {0};
        int counter =0 ;
        for(int i = 0; i < J.length(); ++i){
            hash[J[i]]++;
        }
        for( int i = 0; i < S.length(); ++i){
            if(hash[S[i]]!=0) counter++;
        }
        return counter;
    }
};

//657. Judge Route Circle
class Solution {
public:
    bool judgeCircle(string moves) {
        int hash[1000] = {0};
        for(int i = 0; i<moves.length();i++){
            hash[moves[i]]++;
        }
        char up = 'U',dn='D',lf='L',ri='R';
        if((hash[up]!=hash[dn])||(hash[lf]!=hash[ri]))
            return false;
        return true;
    }
};

//412. Fizz Buzz
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        string buffer;
        for(int i = 1; i<=n;i++ ){
            if(i%15==0) buffer="FizzBuzz";
            else if(i%5==0) buffer="Buzz";
            else if(i%3==0) buffer="Fizz";
            else buffer = to_string(i);
            
            result.push_back(buffer);
        }
        return result;
    }
};

//344. Reverse String
class Solution {
public:
    string reverseString(string s) {
    
        reverse(s.begin(),s.end());    
        return s;
    }
};

//728. Self Dividing Numbers
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> vec;
        for(int i = left; i <= right; i++)
        {
            int val = i, num = i;
            int tmp = 0;
            while(num)
            {
                if(num / 10 >= 1 && num != 10) //num > 10
                {
                    tmp = num % 10;
                    if(tmp == 0)
                        break;
                    else
                    {
                        if(val % tmp == 0)
                        {
                            num /= 10;
                            continue;
                        }
                        else
                            break;
                    }
                }
                else if(num == 10) //num = 10
                {
                    break;
                }
                else if(num / 10 == 0) //num < 10
                {
                    if(val % num == 0)
                        vec.push_back(val);
                    break;
                }
            }
        }
        return vec;
    }
};

//169. Majority Element
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> all;
        for(int i=0;i<nums.size();i++){
            all[nums[i]] +=1;
        }
        for(map<int,int>::iterator it=all.begin(); it!=all.end(); it++){
            if(it->second>nums.size()/2) return it->first;
        }
        return 0;
    }
};

//151. Reverse Words in a String
class Solution {
public:
    string reverseWords(string s) {
        vector<char> buffer;
        string result;
        for(int i = 0; i < s.length(); i++){
            buffer.push_back(s[i]); //need to check ' '
            if(s[i] == ‘ ’){
                for(j = 0; j < buffer.size();j++){
                    result = result + buffer.back();
                    buffer.pop_back();
                }
            }
        }
        return result;
    }
};

class Solution
{
public:
    string reverseWords(string s) {
        std::vector<char> buffer;
        string result;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] != ' ')
            {
                buffer.push_back(s[i]);
            }
            if (s[i] == ' ')
            {
                int k = buffer.size();
                for (int j = 0; j < k; ++j)
                {
                    result = result + buffer.back();
                    buffer.pop_back();
                }
                result+=' ';
            }
        }
            int k = buffer.size();
                for (int j = 0; j < k; ++j)
                {
                    result = result + buffer.back();
                    buffer.pop_back();
                }
        return result;
    }
    
};

class Solution {
public:
    string reverseWords(string s)
    {
        int spaceIdx = -1;
        const int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == ' ' || i == n - 1)
            {
                if (i == n - 1)
                    i++;
                int l = spaceIdx + 1;
                int r = i - 1;
                while (l < r)
                    swap(s[l++], s[r--]);
                spaceIdx = i;
            }
        }
        return s;
    }
};

//500. Keyboard Row
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ret;
        for(int i = 0; i<words.size();++i){
            if(std::regex_match(words[i],regex("[qwertyuiopQWERTYUIOP]*")) || 
              std::regex_match(words[i],regex("[asdfghjklASDFGHJKL]*")) ||
              std::regex_match(words[i],regex("[zxcvbnmZXCVBNM]*")))
                ret.push_back(words[i]);
        
        }
        return ret;
    }
};

//485. Max Consecutive Ones
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max1 = 0,counter = 0;
        for(int i = 0; i<nums.size();++i){
            if(nums[i] == 0) max1 = counter>max1?counter:max1,counter = 0;
            else counter++;
        }
        max1 = counter>max1?counter:max1;
        return max1;
    }
};

//21. Merge Two Sorted Lists
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *ptr1 = l1, *ptr2 = l2;
        ListNode *head = new ListNode(0);
        ListNode *prev_next = head;
        while(ptr1 != NULL || ptr2 != NULL){
            if(ptr1 == NULL){
                //insert ptr2
                ListNode *new_node = new ListNode(ptr2->val);
                prev_next->next = new_node;
                prev_next = new_node;
                ptr2 = ptr2->next;
            }
            else if(ptr2 == NULL){
                ListNode *new_node = new ListNode(ptr1->val);
                prev_next->next = new_node;
                prev_next = new_node;
                ptr1 = ptr1->next;
            }
            else{
                //both not empty
                if(ptr2->val <= ptr1->val){
                    ListNode * new_node = new ListNode(ptr2->val);
                    prev_next->next = new_node;
                    prev_next = new_node;
                    ptr2 = ptr2->next;
                }
                else{
                    ListNode *new_node = new ListNode(ptr1->val);
                    prev_next->next = new_node;
                    prev_next = new_node;
                    ptr1 = ptr1->next;
                    }
                
            }
        }
        return head->next;
    }
};

//69. Sqrt(x)
class Solution {
public:
    int mySqrt(int x) {
    
        if(x == 2 || x == 1) return 1;
        else if(x == 0) return 0;
        unsigned int i = 0;
        for(; i < x; ++i){
            if(i*i<=x && (i+1)*(i+1)>x)
                return i;
        }
    }
};

//2. Add Two Numbers
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *p1 = l1,*p2 = l2, *ret = new ListNode(0);
        ListNode *cur = ret, *nxt = ret;
        int carry = 0;
        int sum = 0;
        while(p1 != NULL || p2 != NULL)
        {
            if(carry  == 1)
            {   
                if(p1 != NULL && p2 != NULL)
                sum = p1->val + p2->val + 1;
                
                else if(p1 == NULL) 
                    sum = p2->val + 1;
                
                else
                    sum = p1->val + 1;
                
                nxt = new ListNode((sum)%10);
                if (sum >= 10) carry = 1;
                else carry = 0;
                cur->next = nxt;
                cur = nxt;
                
                
            }
            else
            {  
                if(p1 != NULL && p2 != NULL)
                sum = p1->val + p2->val;
                
                else if(p1 == NULL) 
                    sum = p2->val;
                
                else
                    sum = p1->val;
                
                nxt = new ListNode((sum)%10);
                if (sum >= 10) carry = 1;
                else carry = 0;
                cur->next = nxt;
                cur = nxt;
            }
            if(p1 != NULL && p2 != NULL){
            p1 = p1->next;
            p2 = p2->next;
            }
            else if(p1 == NULL)
                p2 = p2->next;
            else
                p1 = p1->next;
        }
        if(carry == 1)
            cur->next = new ListNode(1);
        return ret->next;
    }
};
//3. Longest Substring Without Repeating Characters
//this should also be able to be done in map
/*
        map<int,int> all;
        for(int i=0;i<nums.size();i++){
            all[nums[i]] +=1;
        }
        for(map<int,int>::iterator it=all.begin(); it!=all.end(); it++){
            if(it->second>nums.size()/2) return it->first;
        }
*/
class Solution {
public:
int lengthOfLongestSubstring(string s) {
        
        vector <int> record(256,-11); //need 256 slot since ascii
        int start = -1, maxlen = 0;
        for(int i = 0; i < s.length(); ++i) {
            if(record[s[i]] > start)
                start = record[s[i]];  //renew the start point
            record[s[i]] = i;
            maxlen = max(maxlen,i-start);
        }
    return maxlen;
    }
};
//20. Valid Parentheses
class Solution {
public:
    bool isValid(string s) {
        stack<char> container;
        for(char &c : s) {
            if(container.empty())
                container.push(c);
            else if( (c == ')' && container.top() == '(') || (c == ']' && container.top() == '[') ||  (c == '}' && container.top() == '{') )
                container.pop();
            else
                container.push(c);
        }
        if(container.empty())
            return true;
        else
            return false;
    }
};
//674. Longest Continuous Increasing Subsequence
//similar to 3
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        
        int start  = -1, maxlen = 1;
        if(nums.size() == 1) return 1;
        if(nums.size() == 0) return 0;
        for(int i = 1; i <nums.size(); i++)
        {
            if(nums[i] <= nums[i-1])
                start = i-1;
            maxlen = max(maxlen,i-start);
        }
            return maxlen;
    }
};
//66. Plus One
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        vector<int> ret;
        
        for(int i = digits.size()-1; i>=0; i--){
            ret.insert(ret.begin(),(digits[i]+carry)%10);
            if(digits[i]+carry >= 10) carry = 1;
            else carry  = 0;
        }
        if(carry == 1)//indicates one more
            ret.insert(ret.begin(),1);

        return ret;
    }
};
//366. Find Leaves of Binary Tree
//O(n)
class Solution {
    public:
    vector<vector<int>> findLeaves(TreeNode* root){
        vector<vector<int>> ret;
        int h = height(root);
        for(int i = 0; i < h+1; ++i) //heigh begins with 0, so there is one more
            ret.push_back(vector<int>());
        int p = makeVec(root, ret);
        return ret;
    }
    private:
    //get the heigh
    int height(TreeNode* root){
        if(!root) return -1;
        return 1 + max(height(root->left),height(root->right));
    }
    int makeVec(TreeNode* root, vector<vector<int>>& ret){
        if (!root) return -1;
        int level = 1 + max(makeVec(root->right,ret),makeVec(root->left,ret));
        if(level < ret.size())
            ret[level].push_back(root->val);
        return level;
    }
};
//366. Find Leaves of Binary Tree
//a better way using unorder set
class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {        
        // use map to get all the levels.
        unordered_map<int, vector<int>> mp; // level->Node_values
        int n = traverse(root, mp); // return the height of the value.
        // pass map data to res.
        vector<vector<int>> res(n + 1, vector<int>());
        for (int i = 0; i <= n; i++) {
            res[i] = mp[i];
        }
        return res;
    }
private:
    int traverse(TreeNode* root, unordered_map<int, vector<int>>& mp) {
        if (!root) return -1;
        //leaf node case
        if (!root->left && !root->right) {
            mp[0].push_back(root->val);
            return 0;
        }
        int l = traverse(root->left, mp);
        int r = traverse(root->right, mp);
        int res = max(l, r) + 1;
        mp[res].push_back(root->val);
        return res;
    }
};
//205. Isomorphic Strings
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<pair<int,int> > hash1(256,pair<int,int>(0,0));
        vector<pair<int,int> > hash2(256,pair<int,int>(0,0));
        for(int i = 0; i < s.length(); ++i){
            if(hash1[s[i]].first != hash2[t[i]].first || hash2[t[i]].second != hash1[s[i]].second)
                return false;
            hash1[s[i]].first = i;
            hash1[s[i]].second++;
            hash2[t[i]].first = i;
            hash2[t[i]].second ++;
        }
        return true;
    }
};
//or use unordered set
class Solution{
public:
    bool isIsomorphic(string s, string t) {
        // patterns: counts (first) and last indices (second)
        unordered_map<char, pair<int,int>> pat_s, pat_t; 
        for(int i = 0; i < s.size(); i++)
        {
            auto &ps = pat_s[s[i]], &pt = pat_t[t[i]];
            if(ps.first != pt.first or ps.second != pt.second)
                return false;
            ps.first++, pt.first++;
            ps.second = pt.second = i;
        }
        return true;
    }
}
//149. Max Points on a Line
//my code, using linear algebra O(n^2)

//a god like code, 0ms, random number
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if (points.size() <= 2) return points.size();
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, points.size() - 1);
        int best = 1;
        for (int trial = 0; trial < points.size() + 100; trial++) {
            int ai = dis(gen);
            int bi = dis(gen);
            if (ai == bi) continue;
            auto &a = points[ai];
            auto &b = points[bi];
            Point aa(b.x - a.x, b.y - a.y);
            if (aa.x == 0 && aa.y == 0) {
                int score = 0;
                for (auto p : points) {
                    if (p.x == a.x && p.y == a.y) {
                        score++;
                    }
                }
                best = max(best, score);
                continue;
            }
            int score = 0;
            for (auto p : points) {
                Point bb(p.x - a.x, p.y - a.y);
                if ((int64_t)aa.x * (int64_t)bb.y - (int64_t)bb.x * (int64_t)aa.y == 0) score++;
            }
            best = max(best, score);
        }
        return best;
    }
};
//206. Reverse Linked List
//don't forget the initial value
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        ListNode *now,*next,*last;
        now = head;
        next = NULL;//otherwise runtime error
        last = NULL;
        while(now != NULL){
            next = now->next;
            now->next = last;
            last = now;
            now = next;
        }
        head = last;
        return head;
    }
};
//215. Kth Largest Element in an Array
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        make_heap(nums.begin(),nums.end());
        for(int i = 1; i < k; ++i)
        {
            pop_heap (nums.begin(),nums.end());
            nums.pop_back();
        }
        return nums.front();
    }
};
//this can also be done in partitioning like quick sort
//cont'd, implement your own heap
class Solution {
	public:
    void sink(vector<int>& heap, int i) {
        while(true) {
            int left = (i << 1) + 1;
            int right = (i << 1) + 2;
            int largest = i;
            if(left < heap.size() && heap[largest] < heap[left]) largest = left;
            if(right < heap.size() && heap[largest] < heap[right]) largest = right;
            if(i == largest) break;
            swap(heap[i], heap[largest]);
            i = largest;
        }
    }
    void make_heap(vector<int>& heap) {
        for(int i = (heap.size() - 2) >> 1; i >= 0; --i)
            sink(heap, i);
    }

    int findKthLargest(vector<int>& nums, int k) {
        // max heap
        k = nums.size() - k + 1;
        vector<int> heap(nums.begin(), nums.begin() + k);
        (make_heapheap);

        for(int i = k; i < nums.size(); ++i) {
            if(nums[i] < heap.front()) {
                // heap.push_back(nums[i]);
                swap(heap.front(), nums[i]);
                sink(heap, 0);
            }
        }
        return heap.front();
    }
};
//27. Remove Element
//also can use double pointer
class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        vector<int> help(0);
        int count = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] != val)
            {
                help.push_back(nums[i]);
                count ++;
            }
        }
        for(int i = 0; i<count;i++)
        {
            nums[i] = help[i];    
        }
        return count;
    }
};
//268. Missing Number
//sum it up using arithmetic sequence formula
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0, sum2 = 0;
        sum = (nums.size())*(1+nums.size())/2;
        for(int i = 0; i < nums.size(); i++)
        {
            sum2 += nums[i];
        }
        return (sum-sum2);
    }
};
//a bit manipulation version
int missingNumber(vector<int>& nums) 
{
        int size = nums.size(), result = 0;
        for (int i = 0; i != size; result ^= (i ^ nums[i]), ++i);
        return result ^ size;
}
//15. 3Sum
//notice should discuss sum, initial sorting need nlogn
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        if(nums.size() < 3) return ret;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size(); i++)
        {
            if(i > 0 && nums[i] == nums [i-1])
                continue;
            int lf = i + 1, rg = nums.size() - 1;
            while(lf < rg)
                
            {        
                int sum = nums[i] + nums[lf] + nums[rg];
                    if(sum == 0)
                        
                    {   
                       
                        ret.push_back({nums[i],nums[lf],nums[rg]});
                        lf++,rg--;
                        while(lf < rg && nums[lf] == nums[lf-1])
                        {
                            lf++;
                        }
                        while(lf < rg && nums[rg] == nums[rg+1] && rg < nums.size())
                        {
                            rg--;    
                        }
                    }
                    else if(sum < 0)//indicate the left side not big enough
                    lf++;
                    else
                    rg--;
             
            }
            
        }
        return ret;
    }
};

//278. First Bad Version
//basically a binary search
//notice the upper and lower bound
class Solution {
public:
    int firstBadVersion(int n) {
        
        long long l = 0, r = n , id =(l+r)/2;
        while(l < r + 1)
        {
            id = (l + r)/2;
            if(isBadVersion(id))
                r = id - 1;
            else
                l = id + 1;
            
        }
        return l;
    }
};
//35. Search Insert Position
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        int mid = l + (r-l)/2;
        while(l < r)
        {   
            mid = l + (r-l)/2;
            
            if(nums[mid] < target)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};
//turn off the synch in system
//can somehow boost the performance
//actually not
/*
static const auto io_sync_off = [] () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();
*/
#include<iostream>
#include<unordered_map>
using namespace std;

struct RListNode {
   int key;
   int val;
   RListNode *next;
   RListNode *pre;
   RListNode(int x) : val(x), next(NULL),pre(NULL) {}
};




//dont use consecutive data structure like 
struct DListNode {
   int key;
   int val;
   DListNode *next;
   DListNode *prev;
   DListNode(int x) : val(x), next(NULL),prev(NULL) {}
};

static const auto io_sync_off = [] () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();
//actual LRU Cache
class LRUCache
{
    private:
        unordered_map<int,DListNode*> map_idx;
        DListNode *head;
        DListNode *tail;
        int        capacity = 0;
        int        elementCount = 0;
    public:
    LRUCache(int cap)
    {
        capacity = cap;
        head = new DListNode(-1);
        tail = new DListNode(-1);
        head->next = tail;
        tail->prev = head; 
    }
    int get(int key)
    {
        auto isExist = map_idx.find(key);
        if(isExist == map_idx.end())
            return -1; // can not find
        DListNode *temp = isExist->second;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        temp->next = head->next;
        head->next->prev = temp;
        head->next = temp;
        temp->prev = head;
        return temp->val;
    }
    void put(int key, int value)
    {
        auto isExist = map_idx.find(key);
        if(isExist == map_idx.end())
        {
            if(elementCount < capacity)
                quickInsert(key,value);
            else
                fullInsert(key,value);
            return;
        }
        //since the value presented, renew it's position
        DListNode *temp = isExist->second;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        temp->next = head->next;
        head->next->prev = temp;
        head->next = temp;
        temp->prev = head;
        temp->val = value;//need renew the value
        return;
    }
    
    void quickInsert(int key, int value)
    {
        elementCount+=1;
        DListNode *pNewNode = new DListNode(value);
        pNewNode->key = key;
        map_idx[key] = pNewNode;
        pNewNode->next = head->next;
        head->next->prev = pNewNode;
        pNewNode->prev = head;
        head->next = pNewNode;
        return;
    }
    
    void fullInsert(int key, int value)
    {
        //need to remove the last
        DListNode *pDel = tail->prev;
        tail->prev = tail->prev->prev;
        tail->prev->next = tail;
        map_idx.erase(pDel->key);
        delete pDel;
        quickInsert(key,value);
        return;
    }
};
//should inplement the LRU cache using stl list later
//notice how to use unordered map here 

//88. Merge Sorted Array
//pay attention to the start point
//should be end of the array
static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution 
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        int pN1 = m-1,pN2 = n-1, pW = m+n-1;

        while(pN1 >= 0 && pN2 >= 0)
        {
        	if(nums1[pN1] >nums2[pN2])
        	{
        		nums1[pW] = nums1[pN1];
        		pN1--,pW--;
        	}
        	else
        	{
        		nums1[pW] = nums2[pN2];
        		pN2--,pW--;
        	}
        }
        if(pN1 >= 0)
        {
        	while(pN1 >= 0)
        	{
        		nums1[pW] = nums1[pN1];
        		pN1--,pW--;
        	}
        }
        else
        {
        	while(pN2 >= 0)
        	{
        		nums1[pW] = nums2[pN2];
        		pN2--,pW--;
        	}
        }
        return;
    }
};
//26. Remove Duplicates from Sorted Array
class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
    	//note the initialization
        int count = 0;
        if(nums.size() == 0)
            return count;
        else if(nums.size() == 1)
            return 1;
        int write = 1,read = 1;
        count++;
        while(read < nums.size())
        {
            if(nums[read] == nums[read-1])
            {
                read++;
                continue;
            }
            else
            {
            	nums[write] = nums[read++];
            	write++;
            	count++;
            }
        }
        return count;
    }
};
//9. Palindrome Number
static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        long long ret = 0;
        int y = x;
        while(y > 0)
        {
            ret = ret*10 + (y%10);
            y = y/10;
   vb     }
        if(ret == x) return true;
        return false;
    }
};

static const auto io_sync_off = [] () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

//335. Self Crossing
class Solution
{
public:
    bool isSelfCrossing(vector<int>& x)
    {
        x.insert(x.begin(), 4, 0);

        int len = x.size();
        int i = 4;

        // outer spiral
        for (; i < len && x[i] > x[i - 2]; i++);
        // in this case
        // all outer spiral
        if (i == len) return false;

        // check border
    	//if there is crossing,
    	//make x[i-1] negative
    	//this can also be a special case
        if (x[i] >= x[i - 2] - x[i - 4])
        {
            x[i - 1] -= x[i - 3];
        }

        // inner spiral
        for (i++; i < len && x[i] < x[i - 2]; i++);

        return i != len;
    }
};
//709. To Lower Case
class Solution {
public:
    string toLowerCase(string str) {
        int diff = 'a' - 'A';
        for(int i = 0; i < str.length(); ++i)
        {
            if(str[i]>= 'A' && str[i]<='Z')
                str[i] += diff;
        }
        return str;
    }
};