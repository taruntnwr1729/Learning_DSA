
#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
// THIS QUESTION I DID ON LEETCODE LIKE PLATFORM



class Solution {
public:
    ListNode* reverseList(ListNode* head) {
       ListNode* prev = nullptr;
       ListNode* current = head;
       ListNode* nextNode;
       if (head==NULL || head->next == NULL){
        return head;
       } 
       while(current!=NULL){
            nextNode = current->next;
            current->next = prev;

            prev = current;
            current = nextNode;
       }

       return prev;
    }

    
};