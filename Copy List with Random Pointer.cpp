/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
   private:
    void attail(Node* &head,Node* &tail,int val){
        Node* temp=new Node(val);
        if(head==NULL){
            head=temp;
            tail=temp;
            
        }
        else{
            tail->next=temp;
            tail=temp;
        }
    }
    public:
    Node *copyRandomList(Node *head)
    {
        //Write your code here
        Node* temp=head;
        Node* clonehead=NULL;
        Node* clonetail=NULL;
        while(temp!=NULL){
            attail(clonehead,clonetail,temp->val);
            temp=temp->next;
        }
        
        Node* orignal=head;
        Node* clone=clonehead;
        while(orignal!=NULL&&clone!=NULL){
            Node* next1=orignal->next;
          orignal->next=clone;
           orignal=next1;
           
           next1=clone->next;
            clone->next=orignal;
            clone =next1;
        }
        
        
         temp=head;
        clone=clonehead;
        while(temp!=NULL){
            if(temp->next!=NULL){
                if(temp->random!=NULL){
                    temp->next->random=temp->random->next;
                }
                else{
                    temp->next->random=temp->random;
                }
                temp=temp->next->next;
            }
            
        }
        orignal=head;
        clone=clonehead;
        while(orignal!=NULL&&clone!=NULL){
            orignal->next=clone->next;
            orignal=orignal->next;
            if(orignal!=NULL)
            clone->next=orignal->next;
            clone=clone->next;
        }
        return clonehead;
    }

};
