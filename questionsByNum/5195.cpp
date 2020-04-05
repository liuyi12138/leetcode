class Solution {
 public:
  typedef pair<int, char> P;
  string longestDiverseString(int a, int b, int c) {
    string ans;
    vector<P> v;
    v.emplace_back(a, 'a');
    v.emplace_back(b, 'b');
    v.emplace_back(c, 'c');
    while (v[0].first || v[1].first || v[2].first) {
      sort(v.begin(), v.end());
      if (helper(v[2].first, v[2].second, ans)) {
        continue;
      } else if (v[1].first > 0 && helper(v[1].first, v[1].second, ans)) {
        continue;
      } else if (v[0].first > 0 && helper(v[0].first, v[0].second, ans)) {
        continue;
      } else {
        break;
      }
    }
    return ans;
  }

  bool helper(int& a, char ach, string& s) {
    int size = s.size();
    if (size < 2 || s[size - 1] != ach || s[size - 2] != ach) {
      s += ach;
      a--;
      return true;
    } else {
      return false;
    }
  }
};
