class Solution {
public:
    string removeDuplicateLetters(string s) 
    {
        int n = s.size();
        int last[26] = {0};
        for(int i = 0; i < n; ++i)
        {
            last[s[i] - 'a'] = i; 
        }
        int seen[26] = {0};
        string stack = "";
        for(int i = 0; i < n; ++i)
        {
            while(stack.size() and stack.back() > s[i] and last[stack.back() - 'a'] > i and seen[s[i] - 'a'] == 0)
            {
                seen[stack.back() - 'a'] = 0;
                stack.pop_back();
            }
            if(seen[s[i] - 'a'] == 0) 
                stack.push_back(s[i]), seen[s[i] - 'a'] = 1;
        }
        return stack;
    }
};
