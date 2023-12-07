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

void delete_at_any_position(Node *&head, int position)
{
    if (position < 1)
    {
        cout << "Positions start with 1." << endl;
        return;
    }
    else if (position == 1)
    {
        // delete head
        Node *deletedNode = head;
        if (head == NULL)
        {
            cout << "There is no value in the list." << endl;
            return;
        }
        head = head->next;
        delete deletedNode;
        return;
    }
    else
    {
        Node *temp = head;
        for (int i = 1; i < position - 1; i++)
        {
            if (temp->next == NULL)
            {
                cout << "There is only " << i + 1 << " elements in the list." << endl;
                return;
            }
            temp = temp->next;
        }
        if (temp->next == NULL)
        {
            return;
        }
        Node *deletedNode = temp->next;
        temp->next = temp->next->next;

        delete deletedNode;
    }
}

void insert_at_any_position(Node *&head, int position, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        cout << "There is no element in the list. " << val << " inserted at start." << endl;
        head = newNode;
        return;
    }
    else if (position == 0)
    {
        // insert at head
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        return;
    }
    else
    {
        Node *temp = head;
        for (int i = 1; i < position; i++)
        {
            if (temp->next == NULL)
            {
                cout << "There is only " << i << " elements in the list." << endl;
                return;
            }

            temp = temp->next;
        }
        Node *newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void print_reveres(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    print_reveres(head->next);
    cout << head->value << " ";
}

void insert_at_tail_N_complexity(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

void insert_at_tail(Node *&head, int val)
{
    if (head == NULL)
    {
        Node *newNode = new Node(val);
        head = newNode;
        return;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        Node *newNode = new Node(val);
        temp->next = newNode;
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

void size(Node *head)
{
    int i = 0;
    while (head != NULL)
    {
        head = head->next;
        i++;
    }
    cout << i << endl;
}

int main()
{
    Node *head = NULL;
    while (1)
    {
        cout << "Option-0: Insert many value" << endl;
        cout << "Option-1: Insert a value at tail" << endl;
        cout << "Option-2: Insert a value anywhere" << endl;
        cout << "Option-3: Print full Linked list" << endl;
        cout << "Option-4: Delete a value anywhere" << endl;
        cout << "Option-5: Size of list" << endl;
        cout << "Option-6: Terminate" << endl;

        int opt;
        cin >> opt;
        if (opt == 0)
        {
            cout << "Insert a values separated by space : ";
            int val;
            while (true)
            {
                cin >> val;
                if (val == -1)
                {
                    break;
                }
                insert_at_tail(head, val);
            }
        }
        else if (opt == 1)
        {
            cout << "Insert a value : ";
            int val;
            cin >> val;
            insert_at_tail(head, val);
        }
        if (opt == 2)
        {
            cout << "Insert position : ";
            int pos;
            cin >> pos;
            cout << "Insert a value : ";
            int val;
            cin >> val;
            insert_at_any_position(head, pos, val);
        }
        else if (opt == 3)
        {
            print(head);
        }
        else if (opt == 4)
        {
            cout << "Position : ";
            int pos;
            cin >> pos;
            delete_at_any_position(head, pos);
        }
        else if (opt == 5)
        {
            size(head);
        }
        else if (opt == 6)
        {
            break;
        }
    }

    return 0;
}