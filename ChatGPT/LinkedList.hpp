/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Author: Daniel Emond with ChatGPT
//
// Description: C++ solution to implement a simple linked list class.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class LinkedList {
public:
    ListNode* head;
    LinkedList() : head(NULL) {}
    
    void insert(int val) {
        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = newNode;
        } else {
            ListNode* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    
    void display() {
        ListNode* temp = head;
        while (temp) {
            std::cout << temp->val << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};
