#include <iostream>
#include <map>
using namespace std;

typedef struct node{
    int data;
    node *next;
}node;

node* init(int a[], int n, int m){
    node *head, *p, *q;
    for(int i=0; i<n; ++i){
        node *nd = new node();
        nd->data = a[i];
        if(i==m) q = nd;
        if(i==0){
            head = p = nd;
            continue;
        }
        p->next = nd;
        p = nd;
    }
    p->next = q;
    return head;
}

node* loopstart(node *head){
    if(head==NULL) return NULL;
    node *fast = head, *slow = head;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
        if(fast==slow) break;
    }
    if(!fast || !fast->next) return NULL;
    slow = head;
    while(fast!=slow){
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}

map<node*, bool> hash;
node* loopstart1(node *head){
    while(head){
        if(hash[head]) return head;
        else{
            hash[head] = true;
            head = head->next;
        }
    }
    return head;
}
int main(){
    int n = 10, m = 3;// m<n  // 如果 m == 9, 那么 循环链表，就只 在最后的一个 node 中循环，效果没有那么好 
    int a[] = {
        3, 2, 1, 3, 5, 6, 2, 6, 3, 1 
    };
    node *head = init(a, n, m);
    //node *p = loopstart(head);
    node *p = loopstart1(head);
    if(p)
        cout<<p->data<<endl;
    return 0;
}
