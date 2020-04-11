/*
 * 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        string str;
        for (auto c : s){
            // if(c == ' '){
            //     str += "%20";
            // }else{
            //     str += c;
            // }
            c == ' ' ? str += "%20" : str += c;
        }
        return str;
    }
};

int main(){
    string str = "We are the world.";
    Solution s;
    cout << s.replaceSpace(str) << endl;
}