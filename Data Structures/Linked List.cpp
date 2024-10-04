#include <iostream>
using namespace std;
#define endl '\n'

// Define the node class
class node
{
public:
    int data;     // Data part of the node
    node *next;   // Pointer to the next node
    node(int val) // Constructor to initialize a node
    {
        data = val;
        next = NULL;
    }
};
// Function to merge two sorted linked lists and return the merged sorted list 
node *mergeTwoSortedList(node *&head, node *&head2)
{
    
    if (head == NULL)   // Base case: if head is NULL, return head2 (end of list1 reached)
        return head2;
    
    if (head2 == NULL)  // Base case: if head2 is NULL, return head (end of list2 reached)
        return head;

    node *merged;
    if (head->data < head2->data) // Compare the data values of the current nodes of list1 and list2
    {
        merged = head; // If head's data is smaller, set merged to head
        merged->next = mergeTwoSortedList(head->next, head2); // Recursively merge the next node of list1 with list2
    }
    else
    {
        merged = head2; // If head2's data is smaller or equal, set merged to head2
        merged->next = mergeTwoSortedList(head, head2->next); // Recursively merge list1 with the next node of list2
    }
    return merged; // Return the merged sorted list
}

// Function to insert a node at the end of the list
void insertAtTail(node *&head, int val)
{
    node *n = new node(val); // Create a new node
    if (head == NULL)        // If the list is empty, new node becomes the head
    {
        head = n;
        return;
    }
    node *temp = head;         // Temporary pointer to traverse the list
    while (temp->next != NULL) // Traverse to the last node
    {
        temp = temp->next;
    }
    temp->next = n; // Link the last node to the new node
}

// Function to insert a node at the beginning of the list
void insertAtHead(node *&head, int val)
{
    node *n = new node(val); // Create a new node
    n->next = head;          // Point the new node to the current head
    head = n;                // Update the head to the new node
}

// Function to delete the head node
void deleteAtHead(node *&head)
{
    node *nodeToDelete = head; // Pointer to the node to be deleted
    head = head->next;         // Update the head to the next node
    delete nodeToDelete;       // Delete the old head node
}

// Function to delete a node with a given value
void deletion(node *&head, int val)
{
    if (head == NULL) // If the list is empty, return
    {
        return;
    }
    if (head->next == NULL) // If there is only one node, delete the head
    {
        deleteAtHead(head);
        return;
    }
    node *temp = head; // Temporary pointer to traverse the list

    while (temp->next->data != val) // Traverse to the node before the node to be deleted
    {
        temp = temp->next;
    }
    node *nodeToDelete = temp->next; // Pointer to the node to be deleted
    temp->next = temp->next->next;   // Unlink the node from the list
    delete nodeToDelete;             // Delete the node
}

// Function to display the linked list
void display(node *head)
{
    node *temp = head;   // Temporary pointer to traverse the list
    while (temp != NULL) // Traverse until the end of the list
    {
        cout << temp->data << "->"; // Print the data of the current node
        temp = temp->next;          // Move to the next node
    }
    cout << "NULL" << endl; // Print NULL at the end of the list
}

// Function to reverse the linked list
node *linkedListReverse(node *&head)
{
    node *prev = NULL;   // Previous pointer
    node *curr = head;   // Current pointer
    node *nextPtr;       // Next pointer
    while (curr != NULL) // Traverse until the end of the list
    {
        nextPtr = curr->next; // Store the next node
        curr->next = prev;    // Reverse the link

        prev = curr;    // Move the previous pointer to the current node
        curr = nextPtr; // Move the current pointer to the next node
    }
    return prev; // Return the new head of the reversed list
}

int main()
{
    node *head = NULL;  // Initialize the head to NULL (list 1)
    node *head2 = NULL; // Initialize the second head to NULL (list 2)
    cout << "Inserting Values to the end: ";
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtTail(head, 7);
    insertAtTail(head, 8);
    display(head); // Display the list
    cout << endl;

    cout << "Inserting Values at first: ";
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    display(head); // Display the list
    cout << endl;

    cout << "Delete a value(3): ";
    deletion(head, 3); // Delete node with value 3
    display(head);     // Display the list
    cout << endl;

    cout << "Delete the first/head value(8): ";
    deleteAtHead(head); // Delete the head node
    display(head);      // Display the list
    cout << endl;

    cout << "Second List: "; // Adding 2nd Linked List
    insertAtTail(head2, 3);
    insertAtTail(head2, 4);
    insertAtTail(head2, 8);
    insertAtTail(head2, 9);
    display(head2);
    cout << endl;

    cout << "Merge Two Sorted List: ";
    node *mergedHead = mergeTwoSortedList(head, head2); // Merging two sorted List together.
    display(mergedHead);
    cout << endl;

    cout << "Reverse LinkedList: ";
    node *newHead = linkedListReverse(head); // Reverse the list
    display(newHead);                        // Display the reversed list
    cout << endl;

    return 0;
}
