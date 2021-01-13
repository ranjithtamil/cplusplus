//TODO: For delete, you can optimize it more by going from both sides (traverse from head or tail, whichever is closer, and delete)
class SingleLinkedList;
class SingleLinkedList {
public:
    int val;
    SingleLinkedList* next;
    SingleLinkedList* prev;
    SingleLinkedList(int x) {
        val=x;
    }
};
class MyLinkedList {
public:
    SingleLinkedList* head;
    SingleLinkedList* tail;
    int siz;
    /** Initialize your data structure here. */
    MyLinkedList() {
        head=NULL;
        tail=NULL;
        siz=0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */ 
    //index>=0
    int get(int index) {
        if(index>=siz) {
            return -1;
        }
        if(index<0) {
            return -1;
        }
        
        if(siz-index<=(index/2)) {
            //start from tail
            SingleLinkedList* curr=tail;
            int i=0;
            while(i<siz-1-index) {
                curr=curr->prev;
                i++;
            }
            return curr->val;
        }
        else {
            SingleLinkedList* curr=head;
            int i=0;
            while(i<index) {
                curr=curr->next;
                i++;
            }
            return curr->val;
        }
        return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        if(head==NULL) {
            SingleLinkedList* ele = new SingleLinkedList(val);
            head=ele;
            tail=ele;
            siz++;
            return;
        }
        if(head==tail) {
            SingleLinkedList* ele = new SingleLinkedList(val);
            ele->next=head;
            head->prev=ele;
            tail->prev=ele;     //may not be required
            head=ele;
            siz++;
            return;
        }
        SingleLinkedList* ele = new SingleLinkedList(val);
        ele->next=head;
        head->prev=ele;
        head=ele;
        siz++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if(tail==NULL) {
            SingleLinkedList* ele = new SingleLinkedList(val);
            head=ele;
            tail=ele;
            siz++;
            return;
        }
        if(head==tail) {
            SingleLinkedList* ele = new SingleLinkedList(val);
            ele->next=tail->next;   //may not be required
            ele->prev=tail;
            tail->next=ele;
            tail=ele;
            siz++;
            return;
        }
        SingleLinkedList* ele = new SingleLinkedList(val);
        ele->next=tail->next;   //may not be required
        ele->prev=tail;
        tail->next=ele;
        tail=ele;
        siz++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    //index>=0
    void addAtIndex(int index, int val) {
        if(index==siz) {
            addAtTail(val);
            return;
        }
        if(index>siz) {
            return;
        }
        if(index<0) {
            index=0;
        }
        if(index==0) {
            addAtHead(val);
            return;
        }
        
        if(siz-index<=(index/2)) {
            //start from tail
            SingleLinkedList* curr= tail;
            int i=0;
            while(i<siz-1-index) {
                curr=curr->prev;
                i++;
            }
            SingleLinkedList* ele = new SingleLinkedList(val);
            ele->prev=curr->prev;
            ele->next=curr;
            (curr->prev)->next=ele;
            curr->prev=ele;
            siz++;
            return;
        }
        else {
            SingleLinkedList* curr=head;
            SingleLinkedList* pred=head;
            int i=0;
            while(i<index) {
                pred=curr;
                curr=curr->next;
                i++;
            }
            SingleLinkedList* ele = new SingleLinkedList(val);
            ele->prev=pred;
            ele->next=curr;
            curr->prev=ele;
            pred->next=ele;
            siz++;
            return;
        }
        
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index<0 || index>=siz) {
            return;
        }
        
        if(siz==1) {
            head=NULL;
            tail=NULL;
            siz--;
            return;
        }
        
        if(index==siz-1) {
            //delete last element and update tail
            SingleLinkedList* curr=tail;
            (curr->prev->next)=NULL;
            tail=curr->prev;
            siz--;
            delete curr;
            return;
        }
        
        if(index==0) {
            //delete first element and update head
            SingleLinkedList* curr=head;
            head=head->next;
            siz--;
            delete curr;
            return;
        }
        
        
        SingleLinkedList* curr=head;
        SingleLinkedList* pred=head;
        int i=0;
        while(i<index) {
            pred=curr;
            curr=curr->next;
            i++;
        }
        pred->next=curr->next;
        if(curr->next!=NULL) {
            (curr->next)->prev=pred;
        }
        siz--;
        delete curr;
        if(siz==1) {
            head=pred;
            tail=pred;
            return;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
