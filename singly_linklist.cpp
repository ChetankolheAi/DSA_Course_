#include<iostream>
#include<map>
#include<string>
using namespace std;

class node{
    public:
    node* next=NULL;
    int data;
    node(int val){
        data=val;
        next=NULL;
    }
};
void insertattail(node* &head, int value){
    node* n = new node(value);
    node* temp=head;
    if(head==NULL){
        head=n;
    }
    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=n;

        
    }
}
void insertathead(node* &head, int value){
    node* n=new node(value);
    n->next=NULL;
    if(head==NULL){
        head=n;
    }
    else{
        n->next=head;
        head=n;
    }
}

void insertat_k(node* head, int value, int position){
    node* n=new node(value);
    node* temp=head;
    int count=0;
    while (count<position-2){
        count++;
        temp=temp->next;
    }
    n->next=temp->next;
    temp->next=n;
    
}


void createloop(node* head, int loopstart){
    if(!head){
    return;
    }
    node* Loopstartnode= NULL;
    node* current =head;

    int index=0;
    while(current->next){
        if(index==loopstart){
            Loopstartnode=current;

        }
        current= current->next;
        index++;
    }
        if(Loopstartnode){
            current->next=Loopstartnode;
        }

    
}
void display(node* &head){
    node* temp=head;
    if(head==NULL){
       cout<<"Link list empty"; 
    }
    else{
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<endl;
    }
}

int length_ofll(node* &head){
    node* temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
        
    }

    return count;
}

node* reverse(node* &head){
    node* prevptr=NULL;
    node* crtptr=head;
    node* nextptr;
    while(crtptr!=NULL){
        nextptr=crtptr->next;
        crtptr->next=prevptr;

        prevptr=crtptr;
        crtptr=nextptr;
    }
    head=prevptr;
    return head;
}

void middlenode(node* &head){
    node* slow=head;
    node* fast=head;
    while(fast!=NULL){
        fast=fast->next;

        if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;    
        }

    }
    cout<<"The Middle Node is :- "<<slow->data;
    cout<<endl;

}

node* reversek(node* &head , int k){
       node* crrtptr=head;
       node* prevptr=NULL;
       node* nextptr;
       int count=0;
       while(crrtptr!=NULL && count<k){
            nextptr=crrtptr->next;
            crrtptr->next=prevptr;

            prevptr=crrtptr;
            crrtptr=nextptr;
            count++;

       }
       if(head!=NULL){
        node* newhead=reversek(nextptr,k);
        head->next=newhead;
       }

       return prevptr;
}

void palindrome(node* &head){
    node* fast=head;
    node* slow=head;
    node* slowprev;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
            slowprev=slow;
            slow=slow->next;
        }
    }
    slowprev->next=NULL;
    node* head2=reverse(slow);
    node* temp1=head;
    node*temp2=head2;
    while(temp1!=NULL){
        if(temp1->data==temp2->data){
            temp1=temp1->next;
            temp2=temp2->next;
        }
        else{
            cout<<"NO ,The Given Linklist Is Not Palindrome "<<endl;
            break;
        }
        if(temp1==NULL){
            cout<<"Yes , The Given LinkList Is Palindrome"<<endl;
        }
       
    }




}

void Cycle_detect(node* &head ){

    map<node*,bool>m;
    node* temp=head;
    while(temp!=NULL){
        if(m[temp]==true){
            cout<<"Cycle present"<<endl;
            return;
        }
        else{
            m[temp]=true;
        }
         temp=temp->next;
    }
    cout<<"Cycle Not present"<<endl;


}
int main(){

    node* head= NULL;
    insertattail(head,9);
    // insertattail(head,5);
    insertattail(head,6);
    insertattail(head,3);
    // insertattail(head,3);
    insertattail(head,6);
    insertattail(head,5);
    insertattail(head,9);
    insertattail(head,9);
    insertat_k(head,5,2);
    Cycle_detect(head);
    createloop(head,6);
    Cycle_detect(head);

   
    // node* newhead=reversek(head , 2);
    // display(newhead);
       
    
   
   
    return 0;
}