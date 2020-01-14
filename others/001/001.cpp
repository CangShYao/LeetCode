#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // create a Remainder of every number
        map<int, int> num_side;
        // vector of answer
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            // temp number to save Remainder
            int tmp = target - nums.at(i);
            // if match, put answer and return answer
            if(num_side.count(tmp) == 1)
            {
                ans.push_back(num_side[tmp]);
                ans.push_back(i);
                break;
            }
            // if num_side don't contain temp
            // then insert this number and it's position
            num_side.insert(pair<int, int>(nums.at(i), i));
        }
        return ans;
    }
};