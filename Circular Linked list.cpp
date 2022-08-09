#include <iostream>

using namespace std;

struct node{
    int info;
    node* next;
};

class List{
    private:
        node* head;
        node* temp, *temp1;
        int key;

    public:
        List();
        void Print();
        void Insert();
        void InsertAtFirst();
        void Delete();
        // ~List();
        
};

List::List(){
    head = temp = temp1 = NULL;
}

void List::Insert(){

    if (head==NULL){
        head=new node;
        cout<<"Enter Data: ";
        cin>>head->info;
        head->next=head;
        return;
    }
    else{
        temp=head;
        cout<<"Enter the value after you want to enter: ";
        cin>>key;
        do{
            if(temp->info == key){
                temp1 = new node;
                cout << "Enter new data: ";
                cin >> temp1->info;
                temp1->next = temp->next;
                temp->next = temp1;
            }
            temp = temp->next;
        }while(temp != head);
    }
}

void List::InsertAtFirst(){
    if (head == NULL){
        head = new node;
        cout << "Enter Data for inserting at first: ";
        cin >> head->info;
        head->next = head;
        return;
    }
    else{
        temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp1 = new node;
        cout << "Enter Data for inserting at first: ";
        cin >> temp1->info;
        temp1->next = head;
        temp->next = temp1;
        head = temp1;
        return;
    }
}

void List::Delete(){
    if (head == NULL)
        return;
    else{
        temp = head;
        cout << "Enter data you want to delete: ";
        cin >> key;

        do{
            if (temp->info == key){

                // If there's only one node
                if(head->next == head){
                    delete temp;
                    temp = head = NULL;
                    return;
                }
                // deletion of first node
                else if (temp == head){

                    while(temp->next != head){
                        temp = temp->next;
                    }

                    temp->next = head->next;
                    temp1 = head;
                    head = head->next;
                    delete temp1;
                    return;
                }

                // deletion of other nodes
                else{
                    temp = head;
                    bool check = false;

                    do{
                        if (temp->next->info == key){
                            temp1 = temp->next;
                            temp->next = temp->next->next;
                            delete temp1;
                            temp1 = NULL;
                            check = true;
                        }
                        temp = temp->next;
                    }
					while(temp != head);

                    if (check == false)
                        cout << "Element Not Found!\n";
    
                }
            }

            temp = temp->next;
        }while(temp != head);
    }
}

void List::Print(){
    if (head != NULL){
        temp = head;
        
        do{
            cout << temp->info << " ";
            temp = temp->next;
        }while(temp != head);
        cout << endl;
    }

    else
        cout << "Link List is empty.\n";
}
void replace(){
	if(head==NULL){
		cout<<"List is empty:";
	else
	}
	
}
int main(){
    List obj;
    for(int i = 0; i < 2; i++)
        obj.Insert();
        obj.Insert();
        obj.Insert();
        obj.InsertAtFirst();
        obj.Delete();
        
        obj.Print();
}
