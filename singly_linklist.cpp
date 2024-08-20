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
       cout<<"Link listf empty"; 
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


node* reversek(node* &head, int k) {
    node* crrtptr = head;
    node* prevptr = NULL;
    node* nextptr;
    int count = 0;
    while (crrtptr != NULL && count < k) {
        nextptr = crrtptr->next;
        crrtptr->next = prevptr;
        prevptr = crrtptr;
        crrtptr = nextptr;
        count++;
    }
    if (crrtptr != NULL) { 
        node* newhead = reversek(crrtptr, k); 
        head->next = newhead; 
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


//This is an Another method or alternative method to check whether the cycle is present or not;
void Cycle_detect_SF(node* head){
    node* slow=head;
    node* fast=head;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }

        //there is simple logic if both the nodes i.e slow and fast comes at same nodes then the cycle is present
        if(fast==slow){
            cout<<"Cycle is Present in Given Linklist"<<endl;
            return;
        }

    }
    cout<<"Cycle Not present in Given Linklist"<<endl;
}


//deletion of duplicate node in sorted link list ;
void del_duplicate_sorted(node* head){
    node* prev=head;
    node* temp=head->next;
    

    while(temp!=NULL){ 

       
        if(prev->data==temp->data){
            prev->next=temp->next;
            temp->next=NULL;
            delete(temp);
            temp=prev->next;
             
          
        }
        else{

            prev=prev->next;
            temp=temp->next;
        }
        
    }
  
}


//deletion of Duplicate nodes in Unsorted Linklist;
void del_duplicate_Unsorted(node* head){

}

void insertattail_withtail(node* newnode, node* &head, node* &tail ){
  //2 case -> LL is empty or non-empty;
  if(head == NULL && tail == NULL) {
  
    head = newnode;

    tail = newnode;
  }
  else {

    tail->next = newnode;
    tail = newnode;
    cout<<"ok";
    
  }

}
//sorting 0 , 1 , 2 in linklist
void zero_one_two_sort(node* head){

    node* zerohead=NULL;
    node* zerotail=NULL;

    node* onehead=NULL;
    node* onetail=NULL;
    
    node* twohead=NULL;
    node* twotail=NULL;

    node* temp=head;
 



    while(temp!=NULL){
            
        node* tempmove=temp;
        temp=temp->next;
        tempmove->next=NULL;
  
        if(tempmove->data==0){
       
            insertattail_withtail(tempmove,zerohead,zerotail);

        }
        else if(tempmove->data==1){
         
            insertattail_withtail( tempmove,onehead,onetail);

        }
        else if(tempmove->data==2){

            insertattail_withtail(tempmove,twohead,twotail);

        }
     
    }
    if(zerohead!=NULL){
        if(onehead!=NULL){
            zerotail->next=onehead;
           
            onetail->next=twohead;
        }
        else{
            zerotail->next=twohead;
        }
         head=zerohead;
        
    }
    else{
        if(onehead!=NULL){
            onetail->next=twohead;
            head=onehead;
        }
        else{
            head=twohead;
        }
    }


}

void add_1(node* &head){
   
    head=reverse(head);
    node* temp=head;
    int carry=1;

    while(temp!=NULL){
        int sum =carry+temp->data;
        int digit =sum%10;
        carry=(sum-digit)/10;
        temp->data=digit;

        if(temp->next==NULL && carry!=0){
            //check karo   at last node carry zero hey ya nhai aagar zero he to well and good but aagar zero nahi he to create new node
                node* newnode = new node(carry);
                newnode->next=NULL;  
                temp->next=newnode;
                temp=temp->next;
        }
        temp=temp->next;
    }
    node* newhead=reverse(head);
    head=newhead;
}

node* ppp(node* &head,int k){
    node* prev=NULL;
    node* crrt=head;
    node* next;
    int count=0;
    while(crrt!=NULL && count<k){
        next=crrt->next;
        crrt->next=prev;
        prev=crrt;
        crrt=next;
        count++;

    }
    if(head!=NULL)
    {
    node* newnode=ppp(next,k);
    head->next=newnode;
    }
   return prev;
}
int main(){

    node* head= NULL;
    insertattail(head,9);
    insertattail(head,8);
    insertattail(head,5);
  insertattail(head,9);

    insertattail(head,1);
    insertattail(head,5);
    insertattail(head,1);
    insertattail(head,0);
    display(head);
   


    //16.08.2024
    // Cycle_detect(head);
    // del_duplicate_sorted(head);
    // zero_one_two_sort(head);
    // display(head);

    //17.8.2024 
    //add_1(head);
    // node* reversed_head=reversek(head,2);
    // display(reversed_head);
    //practice ___ reverse_in_group....

       
    
   
   
    return 0;
}