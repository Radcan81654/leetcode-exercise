//https://leetcode.cn/problems/restore-ip-addresses/
class Solution {
private:
    vector<string> result;

    bool isValid(const string& s, int start, int end) {
        if (start > end) {
            return false;
        }
        if (s[start] == '0' && start != end) { // ǰ��0
            return false;
        }
        int num = 0;
        for (int i = start; i <= end; i++) {
            if (s[i] > '9' || s[i] < '0') { // �������ַ����Ϸ�
                return false;
            }
            num = num * 10 + (s[i] - '0');
            if (num > 255) { // ����255�˲��Ϸ�
                return false;
            }
        }
        return true;
    }
    // startIndex: ��������ʼλ�ã�pointNum:��Ӷ��������
    void backtrack(string& s, int startIndex, int pointNum) {
        if (pointNum == 3) { // ��������Ϊ3ʱ���ָ�����
            // �жϵ��Ķ����ַ����Ƿ�Ϸ�������Ϸ��ͷŽ�result��
            if (isValid(s, startIndex, s.size() - 1)) {
                result.push_back(s);
            }
            return;
        }
        for (int i = startIndex; i < s.size(); i++) {
            if (isValid(s, startIndex, i)) { // �ж� [startIndex,i] ���������Ӵ��Ƿ�Ϸ�
                s.insert(s.begin() + i + 1, '.');  // ��i�ĺ������һ������
                pointNum++;
                backtrack(s, i + 2, pointNum);   // ���붺��֮����һ���Ӵ�����ʼλ��Ϊi+2
                pointNum--;                         // ����
                s.erase(s.begin() + i + 1);         // ����ɾ������
            }
            else break; // ���Ϸ���ֱ�ӽ�������ѭ��
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        result.clear();
        if (s.size() < 4 || s.size() > 12) return result; // ���Ǽ�֦��
        backtrack(s, 0, 0);
        return result;
    }
};
