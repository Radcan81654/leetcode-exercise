//有序数组的平方
//https://leetcode.cn/problems/squares-of-a-sorted-array/description/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ret;
        for (int left = 0, right = nums.size() - 1; left <= right;)
        {
            if (nums[left] * nums[left] > nums[right] * nums[right])
            {
                ret.push_back(nums[left] * nums[left]);
                left++;
            }
            else
            {
                ret.push_back(nums[right] * nums[right]);
                right--;
            }
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};





//长度最小的子数组
//https://leetcode.cn/problems/minimum-size-subarray-sum/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0, count = 0, ret = INT_MAX;//[left,right)
        while (left <= right && right != nums.size())
        {


            count += nums[right];
            right++;
            while (count >= target)
            {
                int tmp = right - left;
                ret = tmp < ret ? tmp : ret;

                count -= nums[left];
                left++;
            }
        }
        return ret == INT_MAX ? 0 : ret;

    }
};

