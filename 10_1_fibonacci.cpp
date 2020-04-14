/* 
* 写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项。斐波那契数列的定义如下：
* F(0) = 0,   F(1) = 1
* F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
* 斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。
* 答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int fib(int n) {
        //解法一：寻常递归会超时
        // return (n >= 0 && n <= 1) ? 1 : fib(n-1) + fib(n-2);
        
        //解法二：保存之前的数据 减少递归产生的数据
        // int num[101];
        // num[0] = 0;
        // num[1] = 1;

        // for (int i = 2; i <= n; i++) {
        //     num[i] = (num[i-2] + num[i-1]) % 1000000007;
        // }
        // return num[n];
        // ! 或者是
        // if(n == 0){
        //     return num[0];
        // }
        // if(num[n]){
        //     return num[n];
        // }
        // return num[n] = ( fib(n-1) + fib(n-2) ) % 1000000007;

        //解法三：迭代
        // int preVal = 1;
        // int prePreVal = 0;
        // if(n < 2)
        //     return n;
        // int  loop = 2;
        // int returnVal = 0;
        // while(loop <= n)
        // {
        //     returnVal = (preVal + prePreVal) % 1000000007;
        //     /*更新记录结果*/
        //     prePreVal = preVal;
        //     preVal = returnVal;
        //     loop++;
        // }
        // return returnVal;

        //解法四：尾递归
        if (n < 2){
            return n;
        }else{
            return fibProcess(n,0,1,2);
        }

        //TODO 解法五：矩阵快速幂解法
    }

    //解法四：尾递归
    int fibProcess(int end,int prePreVal,int preVal,int begin){
        int returnVal = (prePreVal + preVal) % 1000000007;
        if(begin == end){
            return returnVal;
        }else{
            begin++;
            return fibProcess(end,preVal,returnVal,begin);
        }
    }
};

int main(){
    Solution s;
    cout << s.fib(95) << endl;
}