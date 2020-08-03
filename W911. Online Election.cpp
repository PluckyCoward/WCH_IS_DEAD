class TopVotedCandidate {
public:
    vector<int> data;
    vector<int> time;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        vector<int> count(persons.size(), 0);
        int num = 0, index = 0;
        for (int i = 0; i < persons.size(); i++) {
            time.push_back(times[i]);
            count[persons[i]]++;
            if (count[persons[i]] >= num) {
                num = count[persons[i]];
                index = persons[i];
                data.push_back(index);
            }
            else {
                data.push_back(index);
            }
        }
    }
    
    int q(int t) {
        int l = 0, r = time.size();
        while (l < r) {
            int m = l + (r - l) / 2;
            if (time[m] > t) {
                r = m;
            }
            else {
                l = m + 1;
            }
        }
        return data[l - 1];
    }
};