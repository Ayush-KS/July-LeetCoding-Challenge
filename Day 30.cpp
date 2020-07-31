// Word Break II

class Trie {
public:
    /** Initialize your data structure here. */
    Trie** children;
    bool isTerminal;
    Trie() {
        isTerminal = false;
        children = new Trie*[26];
        for(int i = 0; i < 26; i++)
            children[i] = NULL;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* root = this;
        for(int i = 0; i < word.size(); i++) {
            int child = word[i] - 'a';
            if(!root -> children[child]) {
                root -> children[child] = new Trie();
            }
            root = root -> children[child];
        }
        
        root -> isTerminal = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* root = this;
        
        for(int i = 0; i < word.size(); i++) {
            int child = word[i] - 'a';
            if(!root -> children[child]) {
                return false;
            }
            root = root -> children[child];
        }
        
        return root -> isTerminal;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* root = this;
        
        for(int i = 0; i < prefix.size(); i++) {
            int child = prefix[i] - 'a';
            if(!root -> children[child]) {
                return false;
            }
            root = root -> children[child];
        }
        
        return true;
    }
};



#define f first
#define s second



class Solution {
public:
    
    vector<string> op;
    
    
    vector<string> helper(string s, int si, Trie* root, vector<pair<bool, vector<string>>>& visited) {
        
        if(visited[si].f)
            return visited[si].s;
        
        string word = "";
        vector<string> ret;
        Trie* temp = root;
        int ei = si;
        visited[ei].f = true;
        while(si < s.size()) {
            int c = s[si] - 'a';
            Trie* child = temp -> children[c];
            if(!child)
                break;
            word += s[si];
            if(child -> isTerminal) {
                if(si + 1 == s.size()) {
                    ret.push_back(word);
                }
                vector<string> small = helper(s, si + 1, root, visited);
                for(string str : small) {
                    ret.push_back(word + " " + str);
                }
            }
            si++;
            temp = child;
        }
        visited[ei].s = ret;
        return ret;
    }
    
    vector<string> wordBreak(string s, vector<string>& dict) {
        Trie* root = new Trie();
        for(string str : dict) {
            root -> insert(str);
        }
        vector<pair<bool, vector<string>>> visited(s.size() + 1, {0, {}});
        return helper(s, 0, root, visited);
    }
};