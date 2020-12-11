class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.length();
        int index = 0;
        queue<int> radiant, dire;
        for (auto s : senate) {
            if (s == 'R') radiant.push(index++);
            else dire.push(index++);
        }
        while (!radiant.empty() && !dire.empty()) {
            int r = radiant.front();
            int d = dire.front();
            radiant.pop();
            dire.pop();
            if (r < d)
                radiant.push(r + n);
            else
                dire.push(r + n);
        }
        if (radiant.empty()) return "Dire";
        return "Radiant";
    }
};