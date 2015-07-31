#include <iostream>

using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head)
			return head;
		auto resPrev = new ListNode(0);
		resPrev -> next = head;
		auto cur = resPrev;
		while(1){
			auto subCur = cur;
			int i;
			for(i = 0; i<k; ++i){
				if(!subCur -> next){
					break;
				}
				else{
					subCur = subCur ->next;
				}
			}
			if(i != k)
				break;
			//auto tail = subCur -> next;
			subCur = cur -> next;
			auto tailPrev = subCur;
			ListNode * prev, *tmp;
			prev = subCur;
            subCur = subCur -> next;
			for(i = 0; i<k-1; ++i){
				
				tmp = subCur -> next;
				subCur -> next = prev;
				prev = subCur;
				subCur = tmp;
			}
			cur -> next = prev;
			tailPrev -> next = subCur;
            cur = tailPrev;
		}
		return resPrev->next;
    }
};

int main(int argc, char ** argv){
    ListNode a(1),b(2),c(3),d(4),e(5);
    a.next = &b;b.next=&c;c.next=&d;d.next = &e;
    Solution s;
    auto ans = s.reverseKGroup(&a, 4);
    while (ans) {
        cout<<ans->val<<"-->";
        ans = ans->next;
    }
    cout<<endl;
    return 0;
}

