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

    // --- DFS function ---
    bool dfs(int start, string& s, TrieNode* root, vector<int>& memo) {
        if (start == s.size()) return true;          // reached the end of s
        if (memo[start] != -1) return memo[start];   // already computed

        TrieNode* node = root;
        for (int i = start; i < s.size(); i++) {
            int idx = s[i] - 'a';
            if (!node->ch[idx]) break;               // no match, stop this path
            node = node->ch[idx];
            if (node->end) {
                // found a word ending here, try the rest
                if (dfs(i + 1, s, root, memo))
                    return memo[start] = true;
            }
        }

        return memo[start] = false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie* myTrie = new Trie();
        for (auto& word : wordDict) {
            myTrie->insert(word);
        }

        vector<int> memo(s.size(), -1);  // -1: unvisited, 0: false, 1: true
        return dfs(0, s, myTrie->root, memo);
    }
};
