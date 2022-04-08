#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev, *next;
};

class DoublyLinkedList
{
    Node *head, *temp;

    public:

        DoublyLinkedList()
        {
            temp = head = NULL;
        }

        // Insert at Head
        void insert_at_head( int key)
        {
            if ( head == NULL)
            {
                head = new Node;
                head -> data = key;
                head -> next = NULL;
                head -> prev = NULL;

                temp = NULL;
                return;
            }

            
            temp = new Node;
            temp -> data = key;
            temp -> next = head;
            temp -> prev = NULL;
            head -> prev = temp;
            head = temp;

            temp = NULL;
            return;
        }

        void insert_at_key( int find, int key)
        {
            if ( head == NULL)
            {
                cout << "\nList is empty." << endl;

                return;
            }

            temp = head;

            while ( temp != NULL)
            {
                if ( temp -> data == find)
                {
                    Node *temp1 = new Node;
                    temp1 -> data = key;
                    temp1 -> next = temp -> next;
                    temp1 -> prev = temp;
                    temp -> next = temp1;
                    temp1 -> next -> prev = temp1;

                    return;
                }

                temp = temp -> next;
            }

            cout << "\nKey not found." << endl;

            temp = NULL;
            return;
        }

        void deletion( int key)
        {
            if ( head == NULL)
            {
                cout << "\nList is empty." << endl;
                return;
            }

            temp = head;

            while ( temp != NULL)
            {
                if ( temp -> data == key)
                {
                    if ( temp == head)
                    {
                        temp = head = NULL;
                        delete temp;

                        return;
                    }

                    Node * temp1 = temp -> prev;
                    temp1 -> next = temp -> next;
                    temp -> next -> prev = temp1;
                    delete temp;

                    temp = NULL;
                    return;
                }

                temp = temp -> next;
            }

            cout << "\nKey not found." << endl;
            return;
        }

        void print()
        {
            if ( head == NULL)
            {
                cout << "\nList is empty." << endl;
                
                return;
            }

            temp = head;

            while ( temp != NULL)
            {
                cout << temp -> data << "\t";
                temp = temp -> next;
            }

            cout << endl;
            temp = NULL;
            return;
        }
};

int main()
{
    DoublyLinkedList l;

    l.insert_at_head( 1);
    l.insert_at_head( 2);
    l.insert_at_head( 3);
    l.insert_at_head( 4);
    l.insert_at_head( 5);

    l.insert_at_key( 3, 10);

    l.print();
    
    l.deletion( 3);

    l.print();
}