/*
 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。
 * 答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int numWays(int n) {
        // ! 其实就是斐波那契数列的另一种形式
        //保存之前数据
        int jumpOne = 1;
        int jumpTwo = 1;
        int sum = 1;
        for (int i = 2;i <= n; i++){
            sum = (jumpOne + jumpTwo) % 1000000007;
            jumpOne = jumpTwo;
            jumpTwo = sum;
        }
        return sum;
    }
};