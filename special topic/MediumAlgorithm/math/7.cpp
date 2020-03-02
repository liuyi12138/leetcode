class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        int m1 = numerator > 0 ? 1 : -1;
		int m2 = denominator > 0 ? 1 : -1;
		long long num = abs((long long)numerator);
		long long den = abs((long long)denominator);
		long long t = num / den;
		long long res = num%den;
		string ans=to_string(t);
		if (m1*m2 == -1 && (t > 0 || res > 0)) ans = '-' + ans;
		if (res == 0) return ans;
		ans += '.';
		unordered_map<long long, int> m;
		string s = "";
		int pos = 0;
		while (res != 0)
		{
			if (m.find(res) != m.end())
			{
				s.insert(m[res], "(");
				s += ')';
				return ans + s;
			}
			m[res] = pos;
			s += to_string((res * 10) / den);
			res = (res * 10) % den;
			pos++;
		}
		return ans + s;
    }
};
