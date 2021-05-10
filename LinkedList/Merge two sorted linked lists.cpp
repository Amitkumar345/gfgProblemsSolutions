// LINK: https://practice.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1#
////EXAMPLE
// Input:
// N = 4, M = 3 
// valueN[] = {5,10,15,40}
// valueM[] = {2,3,20}
// Output: 2 3 5 10 15 20 40


// ********EDITORIAL at gfg has MANY POINTER on POINTER approach
struct Node* SortedMerge(struct Node* a, struct Node* b)
{
    /*
    // recursion
    if(a==NULL)return b;
    if(b==NULL)return a;
    if(a->data < b->data){
        a->next = SortedMerge(a->next,b);
        return a;
    }else{
        b->next = SortedMerge(a,b->next);
        return b;
    }
    */
    
    // second method using POINTER ON POINTER CONCEPT
    struct Node* head = NULL;
    struct Node** ref=&head;
    while(a && b){
        if(a->data < b->data){
            *ref = a;
            a=a->next;
        }else{
            *ref =b;
            b= b->next;
        }
        ref=&((*ref)->next);
    }
    *ref=(a)?a:b;
    return head;
}
