class Trie {
public:
    bool isEnd;
    Trie* links[26];
    /** Initialize your data structure here. */
    Trie() {
        isEnd = false;
        memset(links, 0, sizeof(links));
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node = this;
        for (char c : word) {
            if (node->links[c - 'a'] == NULL) {
                node->links[c - 'a'] = new Trie();
            }
            node = node->links[c - 'a'];
        }
        node->isEnd = true;
    }
};

class Solution {
public:
    int fin = 0;
    Trie* root;

    bool dfs(int index, string& word, Trie* r, int cut){
        if(r->links[word[index] - 'a'] == NULL) 
            return false;
        r = r->links[word[index] - 'a'];
        
        if (index == word.length() - 1) 
            return r->isEnd && cut;

        if (r->isEnd)
            return dfs(index + 1, word, root, 1) || dfs(index + 1, word, r, cut);
        return dfs(index + 1, word, r, cut);
            
    }

    static bool cmp(string a,string b)
    {
	    if(a.size()!=b.size())
	    	return a.size()>b.size();
	    else return a<b;
    }

    string longestWord(vector<string>& words) {
        root = new Trie();
        sort(words.begin(), words.end(), cmp);
        for(auto& w: words){
            Trie* cur = root;
            cur->insert(w);
        }
        for(int i = 0; i < words.size() - 1; i++){
            if(dfs(0, words[i], root, 0))
                return words[i];
        }

        return "";

        }
    };