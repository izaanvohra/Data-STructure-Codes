#include<iostream>
using namespace std;

struct Node{
	int info;
	Node *prev;
};
class Stack{
	Node *top,*temp;
	public:
		stack(){
			top=NULL;
			temp=NULL;
		}
		void push(int x){
			if(top==NULL){
				top=new Node;
				top->info=x;
				top->prev=NULL;
				return;
			}
			temp=new Node;
			temp->info=x;
			temp->prev=top;
			top=temp;
			temp=NULL;
		}
		void pop(){
			if(top==NULL){
				cout<<"Stack Underflow"<<endl;
				return;
			}
			temp=top;
			top=top->prev;
			delete temp;
			temp=NULL;
		}
		void peek(){
			cout<<"\n"<<top->info<<endl;
		}
		void print(){
		
			while(top->prev!=NULL){
				cout<<top->info<<"\t";
				top=top->prev;
			}
		}
};
int main(){
	Stack s;
    s.push(5);
    s.push(6);
    s.push(4);
    s.push(8);
    s.push(9);
    s.push(2);
    s.push(1);
    
    s.pop();
    s.peek();
    s.print();
}