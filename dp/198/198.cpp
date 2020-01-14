#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int m_length = nums.size();
        if(m_length == 0)
            return 0;
        else if(m_length == 1) {
            return nums[0];
        }
        else if(m_length == 2) {
            return nums[0] > nums[1] ? nums[0] : nums[1];
        }
        else {
            vector<int> ans;
            ans.push_back(nums[0]);
            ans.push_back(nums[1]);
            for (int i = 2; i < m_length; i++)
            {
                ans.push_back(get_max(ans, i - 1) + nums[i]);
            }
            return get_max(ans, ans.size());
        }
    }

protected:
    int get_max(vector<int>& num_max, int flag) {
        int m_max = num_max[0];
        for (int i = 1; i < flag; i++)
        {
            if (m_max < num_max[i])
                m_max = num_max[i];
        }
        return m_max;
    }
};

int main()
{
    Solution s;
    int data[] = {2, 7, 9, 3, 1};
    vector<int> tes(begin(data), end(data));
    cout << s.rob(tes) << endl;
    getchar();
    return 0;
}