#include <bits/stdc++.h>

using namespace std;

class DoublyNode
{
public:
    int value;
    DoublyNode *next;
    DoublyNode *prev;
    DoublyNode(int value)
    {
        this->value = value;
        this->next = NULL;
        this->prev = NULL;
    }
};

void print(DoublyNode *head)
{
    // O(n) complexity
    while (head != NULL)
    {
        cout << head->value << " ";
        head = head->next;
    }
};

void insert_at_tail(DoublyNode *&head, DoublyNode *&tail, int val)
{
    // O(1) complexity
    DoublyNode *newNode = new DoublyNode(val);
    if (tail == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void print_reverse(DoublyNode *tail)
{
    // O(n) complexity
    while (tail != NULL)
    {
        cout << tail->value << " ";
        tail = tail->prev;
    }
};

int size(DoublyNode *head)
{
    int i = 0;
    while (head != NULL)
    {
        head = head->next;
        i++;
    }
    return i;
}

void insert_at_any_position(DoublyNode *&head, DoublyNode *&tail, int position, int val)
{
    DoublyNode *newNode = new DoublyNode(val);
    if (head == NULL)
    {
        // head null && update tail
        cout << "There is no element in the list. " << val << " inserted at start." << endl;
        head = newNode;
        tail = newNode;
        return;
    }
    else if (position == 0)
    {
        // insert at head
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }
    else if (position == size(head))
    {
        // insert at tail
        insert_at_tail(head, tail, val);
    }
    else
    {
        // any position insert
        // O(n) complexity
        DoublyNode *temp = head;
        for (int i = 1; i < position; i++)
        {
            if (temp->next == NULL)
            {
                cout << "There is only " << i << " elements in the list." << endl;
                return;
            }

            temp = temp->next;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        if (newNode->next != NULL)
        {
            newNode->next->prev = newNode;
        }
        temp->next = newNode;
    }
}

void delete_at_any_position(DoublyNode *&head, DoublyNode *&tail, int position)
{
    // positioning from 1,2,3,4,5,6
    if (position > size(head))
    {
        cout << "invalid";
        return;
    }
    else if (position == 1)
    {
        // delete head

        if (size(head) == 1)
        {
            head = NULL;
            tail = NULL;
        }
        else
        {
            DoublyNode *deletedNode = head;
            head = head->next;
            head->prev = NULL;
            delete deletedNode;
        }
        return;
    }
    else if (position == size(head))
    {
        // delete tail
        if (size(head) == 1)
        {
            head = NULL;
            tail = NULL;
            return;
        }
        else
        {
            DoublyNode *deletedNode = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete deletedNode;
        }
        return;
    }
    else if (position > 1)
    {
        DoublyNode *temp = head;
        for (int i = 1; i < position - 1; i++)
        {
            temp = temp->next;
        }
        DoublyNode *deletedNode = temp->next;
        temp->next = deletedNode->next;
        deletedNode->next->prev = temp;
        delete deletedNode;
    }
}

int main()
{

    DoublyNode *head = NULL;
    DoublyNode *tail = NULL;
    while (true)
    {
        int inp;
        cin >> inp;
        if (inp == -1)
        {
            break;
        }
        insert_at_tail(head, tail, inp);
    }

    // insert_at_tail(head, tail, 1);
    // insert_at_tail(head, tail, 2);
    // insert_at_tail(head, tail, 3);
    // insert_at_tail(head, tail, 4);
    // insert_at_tail(head, tail, 5);
    insert_at_any_position(head, tail, 2, 1000);

    delete_at_any_position(head, tail, 5);

    print(head);
    cout << endl;
    print_reverse(tail);

    return 0;
}
