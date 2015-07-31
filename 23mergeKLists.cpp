/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
	ListNode * merge2Lists(ListNode * first, ListNode * second){
		ListNode * res = new ListNode(0);
		auto cur = res;
		while(first && second){
			if(first -> val < second -> val){
				cur ->next = first;
				first = first -> next;
			}
			else{
				cur -> next = second;
				second = second -> next;
			}
			cur = cur -> next;
		}
		if(first)
			cur ->next = first;
		else
			cur ->next = second;
		return res->next;
	}
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	if(lists.size()==0)
    		return NULL;
    	if(lists.size()==1)
    		return lists[0];
        vector<ListNode*> tmp;
        for(int i = 0; i<lists.size()-1; i+=2){
        	tmp.push_back(merge2Lists(lists[i], lists[i+1]);
        }
        return mergeKLists(tmp);
    }
};