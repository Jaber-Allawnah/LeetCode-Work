class TrieNode{
    public:
    TrieNode* children[26];
    bool isEnd;
    TrieNode(){
        isEnd=false;
        for(int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
    
};
class Trie{
    TrieNode* root;
    public:
    string longestPrefix;
    Trie(){
        root=new TrieNode();
        longestPrefix="";
    }

    void insert(string s){
        TrieNode* current=root;
        for(char c: s){
            int index=c-'a';
            if(current->children[index]!=nullptr){
                current=current->children[index];
                continue;
            }
            current->children[index]=new TrieNode();
            current=current->children[index];
        }
        current->isEnd=true;
    }

    string returnLongestPrefix(){
        int count=0;
        int index=0;
        TrieNode* current=root;
        while(current&&!current->isEnd){
            for(int j=0;j<26;j++){
                if(current->children[j]!=nullptr){
                    count++;
                    index=j;
                }

            }
            if(count!=1){
                break;
            }  
                longestPrefix+=char('a'+index);
                current=current->children[index];
            count=0;
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