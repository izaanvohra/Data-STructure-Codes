#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

class Linked_List
{
    Node *head, *current, *temp;
	public:
		Linked_List(){
            head = NULL;
        }

        // Insert new node at Head
        void insert_at_head( int key){
            if ( head==NULL){
                head=new Node;
                head->data = key;
                head->next = NULL;
				return;
            }
			temp = new Node;
            temp->data = key;
            temp->next = head;
            head = temp;
			return;
        }

        // Insert new node at Tail
        void insert_at_tail( int key){
            if ( head==NULL){
                head = new Node;
                head->data=key;
                head->next=NULL;
				return;
            }

            temp=head;

            while(temp->next!=NULL)
                temp=temp->next;

            Node *temp1=new Node;
            temp1->data=key;
            temp1->next=NULL;
            temp->next=temp1;
			return;
        }

        // Insert at given key
        void insert_at_key( int find, int key){
            if(head==NULL){
                cout <<"\nList is empty."<< endl;
                return;
            }

            temp=head;

            while(temp!=NULL){
                if ( temp->data==find){
                    Node  *temp1=new Node;
                    temp1->data=key;
                    temp1->next=temp->next;
                    temp->next=temp1;
					return;
                }

                temp=temp->next;
            }

            cout << "\nKey not found." << endl;
            return;
        }

        
        void deletion( int key){
            Node *temp1 = search( key);

            temp=head;
            
            while(temp->next != temp1)
                temp=temp->next;

            temp->next=temp1->next;
            delete temp1;

            return;
        }

        Node *search( int key){
            if (head==NULL){
                cout << "\nList is empty.";
                return NULL;
            }

            temp=head;

            while(temp!=NULL)
            {
                if(temp->data==key){
                    return temp;
                }
                temp=temp->next;
            }
        }

        void print(){
            if ( head == NULL){
                cout << "\nList is empty." << endl;
                return;}

            temp = head;

            while (temp!=NULL){
                cout <<temp->data << "\t";
                temp=temp->next;
            }

            cout <<endl;

            return;
        }
};

int main()
{
    Linked_List l;

    l.insert_at_tail(11);
    l.insert_at_tail(12);
    l.insert_at_tail(13);
    l.insert_at_tail(14);
    l.insert_at_tail(15);
    l.insert_at_tail(16);
    l.deletion(16);
    l.insert_at_key(12,6);
    l.print();
}
