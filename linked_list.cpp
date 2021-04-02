#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

void print_list(Node* n)
{
    while(n!=NULL)
    {
        cout<<n->data<<" ";
        n = n->next;
    }
    cout<<endl;
}

void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head_ref;

    *head_ref = new_node;
}

void append(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;

    Node* head = *head_ref;

    while(head->next != NULL)
    {
        head = head->next;
    }
    head->next = new_node;
}

void append2(Node* head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    
    while(head_ref->next != NULL)
    {
        head_ref = head_ref->next;
    }
    head_ref->next = new_node;
    new_node->next = NULL;



}
void insertAfter(Node* prev_node,int new_data)
{
    if(prev_node ==NULL)
    {
        cout<<"the given previous node cannot be NULL";
    }
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = prev_node->next;

    prev_node->next = new_node;
}

void delete_Node(Node** head_ref, int key)
{
    Node* head = *head_ref;
    Node* prev = NULL;
    Node* temp = head->next;

    if(head->data==key)
    {
        *head_ref = head->next;
        return;
    }

    while(temp->next != NULL)
    {   
        if(temp->data==key)
        {
            head->next = temp->next;
            return;
        }
        head= head->next;
        temp= temp->next;
    }

}


int main()
{
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    head = new Node();
    second = new Node();
    third = new Node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    print_list(head);

    cout<<"Push 4"<<endl;
    push(&head, 4);
    print_list(head);

    cout<<"Append 5"<<endl;
    append(&head, 5);
    print_list(head);

    cout<<"Insert After 6"<<endl;
    insertAfter(head->next, 6);
    append2(head,7);
    print_list(head);

    cout<<"Delete 5"<<endl;
    delete_Node(&head, 5);
    print_list(head);


    return 0;

}
