#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node(int value)
    {
        this->value = value;
        this->next = NULL;
    }
};

void insert_at_head(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void insert_at_tail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void delete_any_position(Node *&head, int position)
{
    if (position == 0)
    {
        Node *deleteNode = head;
        head = head->next;
        delete deleteNode;
    }
    else
    {
        Node *temp = head;
        for (int i = 0; i < position - 1; i++)
        {
            if (temp->next == NULL||temp->next->next == NULL)
            {
                return;
            }
            temp = temp->next;
        }
        if (temp->next == NULL)
        {
            return;
        }
        Node *deletedNode = temp->next;
        temp->next = deletedNode->next;
        delete deletedNode;
    }
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    Node *head = NULL;
    int count;
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        int position, val;
        cin >> position >> val;
        if (position == 0)
        {
            insert_at_head(head, val);
        }
        else if (position == 1)
        {
            insert_at_tail(head, val);
        }
        else if (position == 2)
        {
            delete_any_position(head, val);
        }
        print(head);
    }
    return 0;
}
