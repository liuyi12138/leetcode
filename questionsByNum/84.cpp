class Solution {
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> s;
        int ans = 0;
        heights.push_back(0);
        for (int i = 0; i < heights.size(); ++i)
        {
            while (!s.empty() && heights[s.top()] >= heights[i])
            {
                int h = heights[s.top()];
                s.pop();
                if (s.empty())
                    ans = max(ans, i * h);
                else
                    ans = max(ans, (i - s.top() - 1) * h);
            }
            s.push(i);
        }
        return ans;
    }
};
