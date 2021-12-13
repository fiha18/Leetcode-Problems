ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode* temp = head->next;
        head->next = NULL;
        while(temp!=NULL)
        {
           ListNode* temp2 = temp->next;
            temp->next = head;
            head = temp;
            temp= temp2;
        }
        return head;
    }