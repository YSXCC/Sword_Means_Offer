/*
 * 输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

 /*
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> result;
        if(head == NULL){
            return result;
        }
        
        //解法1，迭代求解
        // ListNode* next = NULL;
        // ListNode* last = NULL;
        
        // while (head){
        //     next = head->next;
        //     head->next = last;
        //     last = head;
        //     head = next;
        // }
        // while(last){
        //     result.push_back(last->val);
        //     last = last->next;
        // }
        // return result;

        //解法二，algorithm的函数
        // while (head){
        //     result.push_back(head->val);
        //     head = head->next;
        // }
        // reverse(result.begin(),result.end());
        // return result;

        //解法三,栈
        // stack<int> s;
        // while (head){
        //     s.push(head->val);
        //     head = head->next;
        // }
        // while (!s.empty()){
        //     result.push_back(s.top());
        //     s.pop();
        // }
        // return result;

        //解法四，递归
        if(head == nullptr){
            return result;
        }
        result = reversePrint(head->next);
        result.push_back(head->val);
        return result;
    }
};

int main(){
    Solution s;
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(3);
    ListNode* node3 = new ListNode(2);

    node1->next = node2;
    node2->next = node3;

    vector<int> result = s.reversePrint(node1);
    for(auto x : result){
        cout << x << endl;
    } 
    return 0;
}