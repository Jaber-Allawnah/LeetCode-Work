class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string s) {
        TrieNode* current = root;

        for (char c : s) {
            int index = c - 'a';

            if (current->children[index] == nullptr) {
                current->children[index] = new TrieNode();
            }

            current = current->children[index];
        }

        current->isEnd = true;
    }

    string returnLongestPrefix() {
        string longestPrefix = "";
        TrieNode* current = root;

        while (current && !current->isEnd) {
            int count = 0;
            int index = -1;

            for (int i = 0; i < 26; i++) {
                if (current->children[i] != nullptr) {
                    count++;
                    index = i;
                }
            }

            if (count != 1) {
                break;
            }

            longestPrefix += char('a' + index);
            current = current->children[index];
        }

        return longestPrefix;
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie* myTrie=new Trie();
        for(int i=0;i<strs.size();i++){
            myTrie->insert(strs[i]);
        }
        return myTrie->returnLongestPrefix();
    }
};