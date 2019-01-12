#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int num;
    Node *nxt;
};

Node *head;

int main()
{
    //linked list init
    head=new Node();
    head->nxt=nullptr;
    //build linked list
    int n; cin>>n;
    while (n>0)
    {
        int lastDig=n%10;
        n/=10;
        Node *p=new Node();
        p->num=lastDig;
        p->nxt=head->nxt;
        head->nxt=p;
    }
    //visit linked list
    Node *p=head;
    while (p->nxt!=nullptr)
    {
        p=p->nxt;
        cout<<p->num;
    }
    return 0;
}