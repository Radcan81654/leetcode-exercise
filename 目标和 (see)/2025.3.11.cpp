//https://leetcode.cn/problems/target-sum/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];
        if (abs(target) > sum)
            return 0; // û�з���
        if ((target + sum) % 2 == 1)
            return 0; // û�з���
        int bagSize = (target + sum) / 2;

        //�ڷ���[0,i]������������Ԫ�ص�ʱ�����ǵĺ�ǡ����jʱ����dp[i][j]�ַ��÷���
        vector<vector<int>> dp(nums.size(), vector<int>(bagSize + 1, 0));

        // ��ʼ��������
        if (nums[0] <= bagSize)
            dp[0][nums[0]] = 1;

        // ��ʼ�������У�������������ֵ�ڵ��ƹ�ʽ�о�����˸�ֵ
        dp[0][0] = 1;

        int numZero = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) numZero++;
            dp[i][0] = (int)pow(2.0, numZero);
        }

        // ���±���˳�����п��Եߵ�
        for (int i = 1; i < nums.size(); i++) { // �У�������Ʒ
            for (int j = 0; j <= bagSize; j++) { // �У���������
                if (nums[i] > j)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i]];
                //��ǰ��������ȡ���ڡ����÷�nums[i]�������������"�÷�nums[i]"�����������
            }
        }
        return dp[nums.size() - 1][bagSize];
    }
};