//��Ч������
//https://leetcode.cn/problems/valid-parentheses/description/
//���⣺
class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0) return false; // ���s�ĳ���Ϊ������һ��������Ҫ��
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') st.push(')');
            else if (s[i] == '{') st.push('}');
            else if (s[i] == '[') st.push(']');
            // ����������������ַ���ƥ��Ĺ����У�ջ�Ѿ�Ϊ���ˣ�û��ƥ����ַ��ˣ�˵��������û���ҵ���Ӧ�������� return false
            // �ڶ�������������ַ���ƥ��Ĺ����У�����ջ��û������Ҫƥ����ַ�������return false
            else if (st.empty() || st.top() != s[i]) return false;
            else st.pop(); // st.top() �� s[i]��ȣ�ջ����Ԫ��
        }
        // ��һ���������ʱ�����Ѿ����������ַ���������ջ��Ϊ�գ�˵������Ӧ��������û����������ƥ�䣬����return false�������return true
        return st.empty();
    }
};

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


//ɾ���ַ����е����������ظ���
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