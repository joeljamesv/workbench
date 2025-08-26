/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
*/

#include <iostream>
#include <vector>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        std::map<int, std::vector<int>> hashmap;
        std::vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            hashmap[target - nums[i]].push_back(i);
        }

        int flag=0;
        for(int i=0;i<nums.size();i++)
        {
            if(hashmap.find(nums[i])!=hashmap.end())
            {
                if(i==hashmap[nums[i]][0])
                {
                    if(hashmap[nums[i]].size()==1)
                    {
                        continue;
                    }
                    else
                    {
                        flag=1;
                    }
                }
                result.push_back(i);
                if(flag==0)
                {
                    result.push_back(hashmap[nums[i]][0]);
                }
                else
                {
                    result.push_back(hashmap[nums[i]][1]);
                }
                break;
            }
            
        }

        return result;
    }
};