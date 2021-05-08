// Link: https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1#
// Finding start of the loop and removing it

void removeLoop(Node* head)
    {
        Node *hare=head,*tor=head;
        while(true){
            hare = hare->next->next;
            tor = tor->next;
            if(hare == NULL || hare->next == NULL)return;
            if(tor == hare)break;
        }
        //  First Method 
        Node *p=head;
        if(tor == head){
            while(p->next != head)p=p->next;
            p->next = NULL;
            return;
        }
        while(p->next != tor->next){
            p=p->next;
            tor=tor->next;
        }
        tor->next = NULL;
        // ///////
        
        /*
        // Second approach = taking two pointers moving at distance equal to size of loop 
        int c = 0;
        Node* p1=tor;
        while(true){
            p1=p1->next;
            c++;
            if(p1 == tor)break;
        }
        Node *p2=head;
        p1 = head;
        for(int i=0;i<c;i++){
            p1=p1->next;
            if(p1->next == p2){
                p1->next = NULL;
                return;
            }
        }
        while(true){
            if((p1->next) == (p2->next)){
                p1->next = NULL;
                break;
            }
            p1=p1->next;
            p2=p2->next;
        }
        */
    }
