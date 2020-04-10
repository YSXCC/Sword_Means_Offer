/*
 * 在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，
 * 每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一
 * 个整数，判断数组中是否含有该整数。
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        std::ios::sync_with_stdio(false);   //cin不经过缓冲区
        if (matrix.size() == 0) {
            return false;
        }

        int height = matrix.size() - 1;
        int h = 0;
        int width  = matrix[0].size() - 1;

        //从右上角取值（h = 0,width = (matrix[0].size() - 1)和target比较）
        while (h <= height && width >= 0) {
            if (matrix[h][width] == target) {
                return true;
            }else if (matrix[h][width] < target) {
                h++;
            }else {
                width--;
            }
        } 
        return false;
    }
};

int main(){
    vector<vector<int>> array = {
        {1,   4,  7, 11, 15},
        {2,   5,  8, 12, 19},
        {3,   6,  9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    // vector<vector<int>> array = {
    //     {-5},
    // };
    Solution s;
    cout << s.findNumberIn2DArray(array,5) << endl;
    return 0;
}