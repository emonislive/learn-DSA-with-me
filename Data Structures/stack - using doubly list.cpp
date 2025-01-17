#include <iostream>
using namespace std;
#define endl '\n'

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int val)
    {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList
{
public:
    Node *head = NULL;
    Node *tail = NULL;
    int nodeSize = 0;

    void push(int val) // Insert At Tail
    {
        nodeSize++;
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = NULL;
        tail = newNode;
    }
    void pop() // Delete At Tail
    {
        if (head == NULL || tail == NULL)
            return;
        nodeSize--;
        Node *deleteNode = tail;
        if (head == tail)
        {
            head = NULL;
            tail = NULL;
        }
        else
        {
            tail = tail->prev;
            tail->next = NULL;
        }
        delete deleteNode;
    }
    void top()
    {
        if (tail == NULL || head == NULL)
        {
            cout << "NULL" << endl;
            return;
        }
        cout << tail->data << endl;
    }
    void size()
    {
        if (nodeSize < 0)
            nodeSize = 0;
        cout << nodeSize << endl;
    }
    bool empty()
    {
        if (head == NULL || tail == NULL)
            return true;
        else
            return false;
    }
    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    DoublyLinkedList st;
    // insert
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    // print the list
    st.print();

    // size
    st.size();

    // delete
    st.pop();
    st.pop();
    // st.pop(); // uncomment the 3 lines to check the empty function
    // st.pop();
    // st.pop();
    
    // size
    st.size();

    // print the list
    st.print();

    // last
    st.top();

    // check if the stack is empty or not
    if (st.empty())
        cout << "Stack is empty" << endl;
    else
        cout << "Stack is not empty" << endl;
}
