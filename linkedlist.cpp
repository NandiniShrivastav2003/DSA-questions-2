#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
Node *insertAtBeg(Node *curr, int data)
{
    Node *head = new Node(data);
    head->next = curr;
    return head;
}
Node *insertAtEnd(Node *head, int data)
{
    Node *temp = new Node(data);
    Node *curr = head;
    if (head == NULL)
    {
        return temp;
    }
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;
    temp->next = NULL;
    return head;
}
Node *deleteFirNode(Node *head)
{
    head = head->next;
    return head;
}
Node *deleteLastNode(Node *head){
    Node *temp=head;
    while(temp->next->next != NULL){
        temp=temp->next;
    }
    temp->next=NULL;
    return head;
}
Node *insertAtGivenPos(Node *head,int pos,int data){
    Node *temp=new Node(data);
    Node *curr=head;
    int i=1;
    while(i<pos-1){
        curr=curr->next;
        i++;
    }
    temp->next=curr->next;
curr->next=temp;

return head;
}
void printList(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << (curr->data) << " ";
        curr = curr->next;
    }
}
int  searchinLL(Node *head,int x){
    Node *curr=head;
    while(curr != NULL){
if(curr->data == x)
{
    cout<<"found\n";
return x;
}
curr=curr->next;
    }
    return -1;
}
int main()
{
    Node *head = new Node(5);
    Node *temp1 = new Node(15);
    Node *temp2 = new Node(25);
     Node *temp3 = new Node(35);
     head->next = temp1;
    temp1->next = temp2;
    temp2->next=temp3;
    cout << "before\n";
    printList(head);
    cout << "\n";
    head = insertAtBeg(head, 5);
    printList(head);
    head = insertAtEnd(head, 10);
    printList(head);
    cout << "\n";
    head = deleteFirNode(head);
    printList(head);
     cout << "\n";
     head = deleteLastNode(head);
    printList(head);
     cout << "\n";
   head = insertAtGivenPos(head,2,95);
    head = insertAtGivenPos(head,4,5);
    printList(head);
    cout<<searchinLL(head,45);

    return 0;
}