//有效的括号
//https://leetcode.cn/problems/valid-parentheses/description/
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            else if (s[i] == ')' && !st.empty())
            {
                if (st.top() == '(')
                    st.pop();
                else
                    return false;

            }
            else if (s[i] == '}' && !st.empty())
            {
                if (st.top() == '{')
                    st.pop();
                else
                    return false;
            }
            else if (s[i] == ']' && !st.empty())
            {
                if (st.top() == '[')
                    st.pop();
                else
                    return false;
            }
            else
                return false;
        }
        return st.empty();

    }
};


//删除字符串中的所有相邻重复项
//https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/
class Solution {
public:
    string removeDuplicates(string s) {
        stack<int> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (st.empty() || st.top() != s[i])
            {
                st.push(s[i]);
            }
            else
            {
                st.pop();
            }
        }
        string ret;
        while (!st.empty())
        {
            ret.push_back(st.top());
            st.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;

    }
};