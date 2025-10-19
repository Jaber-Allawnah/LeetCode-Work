class Solution {
    class TrieNode {
    public:
        TrieNode* ch[26];
        bool end;
        TrieNode() {
            for (int i = 0; i < 26; i++) ch[i] = nullptr;
            end = false;
        }
    };

    class Trie {
    public:
        TrieNode* root;
        Trie() { root = new TrieNode(); }

        void insert(const string& word) {
            TrieNode* p = root;
            for (char c : word) {
                int j = c - 'a';
                if (!p->ch[j]) p->ch[j] = new TrieNode();
                p = p->ch[j];
            }
            p->end = true;
        }
    };

    bool dfs(int start, string& s, TrieNode* root, vector<int>& memo) {
        if (start == s.size()) return true;//if the string is nothing          
        if (memo[start] != -1) return memo[start];// if it is either visited or not  

        TrieNode* node = root;
        for (int i = start; i < s.size(); i++) {
            int idx = s[i] - 'a';//find the index of the current letter in the string
            if (!node->ch[idx]) break;               
            node = node->ch[idx];
            if (node->end) {
                
                if (dfs(i + 1, s, root, memo))
                    return memo[start] = true;
            }
        }

        return memo[start] = false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie* myTrie = new Trie();
        for (string word : wordDict) {
            myTrie->insert(word);
        }

        vector<int> memo(s.size(), -1);// vector full of -1, 0 is unvisted and 1 is visited 
        return dfs(0, s, myTrie->root, memo);
    }
};
