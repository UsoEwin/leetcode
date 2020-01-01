using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class WordConcatenation {
 public:
  static vector<int> findWordConcatenation(const string &str, const vector<string> &words) {
    vector<int> resultIndices;
    // TODO: Write your code here
    unordered_map<string,int> dict;
    int word_size = words[0].size(), word_len = words.size();
    for(string  x : words)
      dict[x]++;
    //since basic unit is word, there is overlap, we use two dict to track
    for(int i = 0; i < str.size() - word_len*word_size + 1; ++i) {
      unordered_map<string,int> word_seen;
      for(int j = 0; j < word_len; ++j) { //matched every single word in words
        int next_idx = i + j*word_size;
        string next_word = str.substr(next_idx,word_size);
        if(dict.find(next_word) == dict.end())
          break;
        word_seen[next_word]++;
        if(word_seen[next_word] > dict[next_word])
          break;
        if(j == word_len-1) // find all word in words
          resultIndices.push_back(i);
      }
    }
    return resultIndices;
  }
};
