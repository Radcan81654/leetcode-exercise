//二分查找
//https://leetcode.cn/problems/binary-search/submissions/581598866/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        for (int left = 0, right = nums.size() - 1; left <= right;)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            else if (target > nums[mid])
            {
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        return -1;

    }
};
//移除元素
//https://leetcode.cn/problems/remove-element/submissions/581600586/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for (auto i = nums.begin(); i != nums.end();)
        {
            if (*i == val)
            {
                nums.erase(i);
            }
            else
                i++;
        }
        return nums.size();
    }
};


//最长回文子串
//https://leetcode.cn/problems/longest-palindromic-substring/
class Solution {
public:
    string longestPalindrome(string s) {
        string ret;
        for (int i = 0; i < s.size(); i++)
        {
            for (int left = i, right = i; left >= 0 && right < s.size(); left--, right++)
            {
                if (s[left] != s[right])
                {
                    break;
                }
                else
                {
                    string tmp = s.substr(left, right - left + 1);
                    ret = ret.size() > tmp.size() ? ret : tmp;
                }
            }
            for (int left = i, right = i + 1; left >= 0 && right < s.size(); left--, right++)
            {
                if (s[left] != s[right])
                {
                    break;
                }
                else
                {
                    string tmp = s.substr(left, right - left + 1);
                    ret = ret.size() > tmp.size() ? ret : tmp;
                }
            }
        }
        return ret;
    }
};