//有效的字母异位词
//https://leetcode.cn/problems/valid-anagram/description/
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> arr(26, 0);
        for (auto i : s)
            arr[i - 'a']++;
        for (auto i : t)
            arr[i - 'a']--;
        for (auto i : arr)
        {
            if (i != 0)
                return false;
        }
        return true;


    }
};
//两个数组的交集
//https://leetcode.cn/problems/intersection-of-two-arrays/description/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        unordered_map<int, int> umap;
        for (auto i : nums1)
        {
            umap[i] = 1;
        }
        for (auto i : nums2)
        {
            if (umap[i] == 1)
                umap[i] = 2;
        }
        for (auto i : umap)
        {
            if (i.second == 2)
                ret.push_back(i.first);
        }
        return ret;
//正解：
        class Solution {
        public:
            vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
                unordered_set<int> result_set; // 存放结果，之所以用set是为了给结果集去重
                unordered_set<int> nums_set(nums1.begin(), nums1.end());
                for (int num : nums2) {
                    // 发现nums2的元素 在nums_set里又出现过
                    if (nums_set.find(num) != nums_set.end()) {
                        result_set.insert(num);
                    }
                }
                return vector<int>(result_set.begin(), result_set.end());
            }
        };





    }
};
//查找共用字符
//https://leetcode.cn/problems/find-common-characters/description/
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ret;
        if (!words.size())
            return ret;
        vector<int> hash(26, 0);
        for (auto i : words[0])
            hash[i - 'a']++;
        for (int i = 1; i < words.size(); i++)
        {
            vector<int> tmphash(26, 0);
            for (int j = 0; j < words[i].size(); j++)
                tmphash[words[i][j] - 'a']++;
            for (int k = 0; k < 26; k++)
                hash[k] = min(hash[k], tmphash[k]);
        }

        for (int i = 0; i < 26; i++)
        {
            while (hash[i])
            {
                string tmp(1, 'a' + i);
                ret.push_back(tmp);
                hash[i]--;
            }
        }
        return ret;
    }
};