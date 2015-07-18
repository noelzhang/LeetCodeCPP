/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
		if(!head)
			return ture;
		ListNode *mid, * fast, * slow, * tmp;
		fast = slow = head;
		fast = fast ->next;
		while(fast && fast ->next && fast ->next ->next){
			fast = fast ->next ->next;
			slow = slow ->next;
		}
		
    }
};
