#include <bits/stdc++.h>
using namespace std;

//链表节点
struct Node
{
    //要储存的信息
    string name;
    int age;
    
    //用名为nxt的Node指针来指向当前节点的下一个节点
    Node *nxt = nullptr;
};
Node *head; //哨兵

int main()
{
    //建立链表
    head = new Node();
    Node *p = new Node();
    p->name = "xiao ming";
    p->age = 233;
    head->nxt = p;
    
    cout << head->nxt->name << endl
         << head->nxt->age << endl;

    return 0;
}