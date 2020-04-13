/*
 * 用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，
 * 分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 
 * 操作返回 -1 )
 */ 

//!不知道为什么会有这样沙雕的题，就是翻过来，倒回去

#include <iostream>
#include <stack>

using namespace std;

class CQueue {
public:
    stack<int> s1;
    stack<int> s2;

    CQueue() {

    }
    
    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
        if(s1.empty()){
            return -1;
        }
        
        while (!s1.empty()) {
            int tmp = s1.top();
            s1.pop();
            s2.push(tmp);
        }

        int res  = s2.top();
        s2.pop();
        while (!s2.empty()) {
            int tmp = s2.top();
            s2.pop();
            s1.push(tmp);
        }
        return res;
    }
};

/*
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */