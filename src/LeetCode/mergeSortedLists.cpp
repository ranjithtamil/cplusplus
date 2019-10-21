/*
21. Merge Two Sorted Lists
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head=NULL;
        ListNode* last=NULL;
        
        while(l1!=NULL && l2!=NULL) {
            int temp;
            if(l1->val < l2->val) {
                temp = l1->val;
                l1=l1?l1->next:NULL;
            }
            else {
                temp = l2->val;
                l2=l2?l2->next:NULL;
            }
            ListNode* l3= new ListNode(temp);
            if(head==NULL) {
                head=l3;
                last=l3;
            }
            else {
                last->next=l3;
                last=l3;
            }
            
        }
        
        while(l1) {
            ListNode *l3 = new ListNode(l1->val);
            if(head==NULL) {
                head=l3;
                last=l3;
            }
            else {
                last->next=l3;
                last=l3;
            }
            l1=l1?l1->next:NULL;
        
        }
        
        while(l2) {
            ListNode *l3 = new ListNode(l2->val);
            if(head==NULL) {
                head=l3;
                last=l3;
            }
            else {
                last->next=l3;
                last=l3;
            }
            l2=l2?l2->next:NULL;
        }
        return head;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* l1 = stringToListNode(line);
        getline(cin, line);
        ListNode* l2 = stringToListNode(line);
        
        ListNode* ret = Solution().mergeTwoLists(l1, l2);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
