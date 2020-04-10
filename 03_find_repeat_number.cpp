/*
 * 找出数组中重复的数字。
 * 在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。
 * 数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个
 * 数字重复了几次。请找出数组中任意一个重复的数字。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#include <set>

using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        std::ios::sync_with_stdio(false);

        //解法一，排序后遍历    这样耗时
        // int find = -1;
        // if (nums.size() < 2){
        //     return find;
        // }
        // std::sort(nums.begin(),nums.end());
        // for (int i = 0; i < nums.size() - 1; i++){
        //     if (nums.at(i) == nums.at(i+1)) {
        //         find = nums.at(i);
        //         break;
        //     }
        // }
        // return find;

        //解法二，Set 不知道为什么还是耗时
        // set<int> numbers;
        // for (auto number : nums){
        //     if (numbers.count(number) == 1){
        //         return number;
        //     }else {
        //         numbers.insert(number);
        //     }
        // }
        // return -1;

        //解法三 bool判空   windows和linux下写法不一样
        // bool *flag = new bool(nums.size());
        // memset(flag,false,nums.size());
        // for(int i = 0; i < nums.size(); i++)
        //     if(flag[nums[i]])
        //         return nums[i];
        //     else
        //         flag[nums[i]] = true;
        // return -1;

        //解法四 利用动态数组，而不是新建bool数组 时间最短
        for (int i = 0; i < nums.size(); i++){
            while (nums[i] != i){
                if (nums[i] == nums[nums[i]]){
                    return nums[i];
                }
                swap(nums[i],nums[nums[i]]);
            }
        }
        return -1;
        
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    vector<int> nums = {1, 2, 5, 7, 5};
    Solution s;
    cout << s.findRepeatNumber(nums) << endl;
    return 0;
}