struct Trie {
    Trie* links[26];
    bool isEnd = false;

    void insert(string word) {
        Trie *node = this;
        for (char c : word) {
            if (node->links[c - 'a'] == NULL)
                node->links[c - 'a'] = new Trie();
            node = node->links[c - 'a'];
        }
        node->isEnd = true;
    }

};

class Solution {
public:
    vector<string> res;
    Trie* root = new Trie();
    vector<int> failure;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        failure = vector<int>(s.length(), 0);
        for (auto word : wordDict) {
            root->insert(word);
        }
        dfs(s, "", root, 0);
        return res;
    }

    int dfs(string s, string sr, Trie* trie, int pos) {
        if (trie->links[s[pos] - 'a'] == NULL) 
            return 0;
        trie = trie->links[s[pos] - 'a'];
        sr += s[pos];
        if (pos == s.length() - 1) {
            if (trie->isEnd) {
                res.emplace_back(sr);
                return 1;
            }
            return 0;
        }
        int cnt = 0;
        cnt += dfs(s, sr, trie, pos + 1);
        if (trie->isEnd && failure[pos+1] == 0)
            if (dfs(s, sr + " ", root, pos + 1))
                cnt++;
            else failure[pos + 1] = 1;
        if(cnt) return 1;
        return 0;
    }
};