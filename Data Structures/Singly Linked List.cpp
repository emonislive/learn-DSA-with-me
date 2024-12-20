#include <iostream>
using namespace std;
#define endl '\n'

// Node class representing each element in the linked list
class node
{
public:
    int data;     // Data stored in the node
    node *next;   // Pointer to the next node
    node(int val) // Constructor to initialize node with data
    {
        data = val;
        next = NULL;
    }
};

// Global head and tail pointers to manage the linked list
node *head = NULL;
node *tail = NULL;

// Function to count the number of nodes in the linked list
void count_Lists()
{
    int c = 0;
    node *temp = head;   // Start from the head
    while (temp != NULL) // Traverse until the end
    {
        c++; // Increment counter for each node
        temp = temp->next;
    }
    cout << "Size of The Linked List: ";
    cout << c << endl;
}

// Function to display all the elements of the linked list
void display()
{
    cout << "The Lists are: ";
    node *temp = head;   // Start from the head
    while (temp != NULL) // Traverse the list
    {
        cout << temp->data << " "; // Print node's data
        temp = temp->next;
    }
    cout << endl;
}

// Function to insert a new node at the head of the linked list
void insert_At_Head(int val)
{
    node *n = new node(val); // Create a new node with the given value
    if (head == NULL)        // If the list is empty
    {
        head = n; // Update head to the new node
        tail = n; // Update tail to the new node
        return;
    }
    n->next = head; // Link the new node to the current head
    head = n;       // Update head to the new node
}

// Function to insert a new node at the tail of the linked list
void insert_At_Tail(int val)
{
    node *n = new node(val); // Create a new node with the given value
    if (head == NULL)        // If the list is empty
    {
        head = n; // Update head to the new node
        tail = n; // Update tail to the new node
        return;
    }
    tail->next = n; // Link the current tail to the new node
    tail = n;       // Update tail to the new node
}

// Function to delete the node at the head of the linked list
void delete_At_Head()
{
    if (head == NULL) // If the list is empty
    {
        cout << "List is empty!" << endl;
        return;
    }
    node *deleteNode = head; // Store the current head
    head = head->next;       // Update head to the next node
    if (head == NULL)        // If the list becomes empty
        tail = NULL;         // Update tail to NULL
    delete deleteNode;       // Free the memory of the deleted node
}

// Function to delete the node at the tail of the linked list
void delete_At_Tail()
{
    if (head == NULL) // If the list is empty
    {
        cout << "List is empty!" << endl;
        return;
    }
    if (head->next == NULL) // If there is only one node
    {
        delete head; // Delete the head node
        head = NULL; // Update head to NULL
        tail = NULL; // Update tail to NULL
        return;
    }
    node *temp = head;         // Start from the head
    while (temp->next != tail) // Traverse until the second last node
    {
        temp = temp->next;
    }
    delete tail;       // Delete the tail node
    temp->next = NULL; // Set the next of the second last node to NULL
    tail = temp;       // Update tail to the second last node
}

void delete_At_Any_Position()
{
    int pos;
    cout << "Enter the position to delete: "; // Ask user for the position
    cin >> pos;
    if (pos < 1) // If the position is invalid
    {
        cout << "Invalid Position" << endl;
        return;
    }
    if (pos == 1) // If the position is 1
    {
        delete_At_Head();
        return;
    }
    int c = 1;                          // Counter to track the position
    node *temp = head;                  // Start from the head
    while (temp != NULL && c < pos - 1) // Traverse until the previous node
    {
        temp = temp->next;
        c++;
    }
    if (temp == NULL || temp->next == NULL) // If the position is invalid
    {
        cout << "Invalid Position" << endl;
        return;
    }
    node *deleteNode = temp->next; // Store the node to delete
    temp->next = temp->next->next; // Link the previous node to the next node
    if (temp->next == NULL)        // If the deleted node was the last node
        tail = temp;
    delete deleteNode;
}

int main()
{
    // Menu for user interaction
    cout << "|---------------------------------------|" << endl;
    cout << "|         Choose Option: (1-8)          |" << endl;
    cout << "|---------------------------------------|" << endl;
    cout << "|      Option '1': Insert at Head       |" << endl;
    cout << "|---------------------------------------|" << endl;
    cout << "|      Option '2': Insert at Tail       |" << endl;
    cout << "|---------------------------------------|" << endl;
    cout << "|Option '3': Insert at Specific Position|" << endl;
    cout << "|---------------------------------------|" << endl;
    cout << "|       Option '4': Display List        |" << endl;
    cout << "|---------------------------------------|" << endl;
    cout << "| Option '5': Count the Size of the List|" << endl;
    cout << "|---------------------------------------|" << endl;
    cout << "|       Option '6': Delete at Head      |" << endl;
    cout << "|---------------------------------------|" << endl;
    cout << "|       Option '7': Delete at Tail      |" << endl;
    cout << "|---------------------------------------|" << endl;
    cout << "|   Option '8': Delete at Any Position  |" << endl;
    cout << "|---------------------------------------|" << endl;
    cout << "|        Option '9': Exit Program       |" << endl;
    cout << "|---------------------------------------|" << endl;

    int operation, val; // Variables to store user input
    while (true)        // Infinite loop to process user commands
    {
        cout << "|->Option: ";
        cin >> operation; // Get user's choice
        switch (operation)
        {
        case 1: // Insert at head
            cout << "Insert Value: ";
            cin >> val;
            insert_At_Head(val);
            cout << "Data Inserted at Head" << endl;
            break;
        case 2: // Insert at tail
            cout << "Insert Value: ";
            cin >> val;
            insert_At_Tail(val);
            cout << "Data Inserted at Tail" << endl;
            break;
        case 4: // Display
            display();
            break;
        case 5: // Count the size of the list
            count_Lists();
            break;
        case 6: // Delete at head
            delete_At_Head();
            cout << "Head Node Deleted" << endl;
            break;
        case 7: // Delete at tail
            delete_At_Tail();
            cout << "Tail Node Deleted" << endl;
            break;
        case 8: // Delete at any position
            delete_At_Any_Position();
            cout << "Node Deleted" << endl;
            break;
        case 9: // Exit program
            cout << "|BYEEEEE (*_*)" << endl;
            return 0; // Exit the program
        default:      // Invalid input
            cout << "|----------------------------------|" << endl;
            cout << "|     Wrong Input. Try Again..     |" << endl;
            cout << "|----------------------------------|" << endl;
        }
    }
    return 0;
}
