/*
 * 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
 * 输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如，
 * 数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。  
 */  

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minArray(vector<int>& numbers) {
        //解法一：垃圾解法，he ！！！ tui
        // sort(numbers.begin(),numbers.end());
        // return numbers[0];

        //解法二：二分查找,其他也没有找到好的方法
        int high = numbers.size() - 1;
        int low  = 0;
        while (low < high){
            int mid = (low + high) / 2;
            if (numbers[mid] > numbers[high]){
                low = mid + 1;
            }else if (numbers[mid] < numbers[high]){
                high = mid;
            }else{
                high --;
            }
        }
        return numbers[low];
    }
};