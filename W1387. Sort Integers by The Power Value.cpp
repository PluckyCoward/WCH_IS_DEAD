//递归
class Solution {
public:
    static int getK(int x) {
        if (x == 1) return 0;
        if (x % 2 == 1)
            return getK(3 * x + 1) + 1;
        else return getK(x / 2) + 1;
    }

    static bool cmp(int a, int b) {
        if (getK(a) != getK(b)) return getK(a) < getK(b);
        else
            return a < b;
    }
    int getKth(int lo, int hi, int k) {
        vector<int> res;
        for (int i = lo; i <= hi; i++) {
            res.push_back(i);
        }
        sort(res.begin(), res.end(), cmp);
        return res[k - 1];
    }
};

//记忆化
unordered_map<int, int> f;

int getK(int x) {
    if (f.find(x) != f.end()) return f[x];
    if (x == 1) return f[x] = 0;
    if (x % 2 == 1)
        return f[x] = getK(3 * x + 1) + 1;
    else return f[x] = getK(x / 2) + 1;
}

bool cmp(int a, int b) {
    if (getK(a) != getK(b)) return getK(a) < getK(b);
    else
        return a < b;
}
class Solution {
public:
    int getKth(int lo, int hi, int k) {
        vector<int> res;
        for (int i = lo; i <= hi; i++) {
            res.push_back(i);
        }
        sort(res.begin(), res.end(), cmp);
        return res[k - 1];
    }
};
