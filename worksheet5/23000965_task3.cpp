#include <iostream>
using namespace std;

struct MyNode
{
   int data;
   struct MyNode *next;
};

void push(struct MyNode** head, int MyNode_data)
{
    struct MyNode* newMyNode = new MyNode;

    newMyNode->data = MyNode_data;

    newMyNode->next = *head;

    *head = newMyNode;
}

void insertAfter(struct MyNode* prev_MyNode, int MyNode_data)
{
    if (prev_MyNode == NULL)
    {
        cout<<"Previous node cannot be NULL";
        return;
    }
    struct MyNode* newMyNode = new MyNode;

    newMyNode->data = MyNode_data;

    newMyNode->next = prev_MyNode->next;

    prev_MyNode->next = newMyNode;
}

void insertNode(struct MyNode** head, int MyNode_data)
{
    struct MyNode* newMyNode = new MyNode;

    newMyNode->data = MyNode_data;

    newMyNode->next = NULL;

    if (*head == NULL)
    {
        *head = newMyNode;
        return;
    }

    struct MyNode *last = *head;
    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = newMyNode;
}

void showList(struct MyNode *MyNode)
{
    while (MyNode != NULL)
    {
        cout<<MyNode->data<<"-->";
        MyNode = MyNode->next;
    }

    if(MyNode == NULL)
        cout<<"null";
}

int main()
{
    struct MyNode* head = NULL;

    insertNode(&head, 10);
    push(&head, 20);
    push(&head, 30);
    insertNode(&head, 40);
    insertAfter(head->next, 50);
    cout<<"Final linked list: "<<endl;
    showList(head);

    return 0;
}
