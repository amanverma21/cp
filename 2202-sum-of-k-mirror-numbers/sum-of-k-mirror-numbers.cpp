class Solution {
public:
    long ans = 0;
    vector<int> v;

    void res() {
        v.resize(v.size() + 1);
        for (int& x : v)
            x = 0;
        v[0] = v.back() = 1;
    }

    void solve() {
        if (check())
            res();
        else {
            int a = (v.size() - 1) >> 1, b = v.size() >> 1;
            if (v[a] != 9)
                v[a] = v[b] = v[b] + 1;
            else {
                v[a] = v[b] = 0;
                while (true) {
                    ++v[--a], ++v[++b];
                    if (v[a] == 10)
                        v[a] = v[b] = 0;
                    else
                        break;
                }
            }
        }
    }

    bool check() {
        if (v.size() == 0)
            return true;
        for (int x : v)
            if (x != 9)
                return false;
        return true;
    }

    bool verge(int k) {
        long num = 0;
        for (int x : v)
            num = num * 10 + x;

        vector<int> p;
        for (long n = num; n; n /= k)
            p.push_back(n % k);

        for (int a = 0, b = p.size() - 1; a < b; ++a, --b)
            if (p[a] != p[b])
                return false;

        ans += num;
        return true;
    }

    long long kMirror(int k, int n) {

        while (n) {
            solve();
            if (verge(k))
                --n;
        }

        return ans;
    }
};