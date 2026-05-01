/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* x = findFromEnd(dummy, n + 1);
        x->next = x->next->next;
        return dummy->next;
    }
private:
    ListNode* findFromEnd(ListNode* head, int n) {
      ListNode* p1 = head;
      for (int i = 0; i < n; i++) {
        p1 = p1->next;
      }
      ListNode* p2 = head;
      while (p1 != nullptr) {
        p1 = p1->next;
        p2 = p2->next;
      }
      return p2;
    }
};
// @lc code=end

