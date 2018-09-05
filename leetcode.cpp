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