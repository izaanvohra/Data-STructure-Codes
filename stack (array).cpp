#include<iostream>
using namespace std;
class stack{
	int *top,*stk;
	int size=0;
	
	public:
		stack(){
			top=NULL;
			cout<<"Enter size of Stack";
			cin>>size;
			stk=new int [size];
		}
		void push(int x){
			if(top==NULL){
				top=stk;
				*top=x;
				return;
			}
			if(top==stk+(size-1)){
				cout<<"Stack overflow";
			}
			top++;
			*top=x;
		}
		void pop(){
			if(top==NULL){
				cout<<"Stack underflow";
				return;
			}
			if(top==stk){
				top=NULL;
				return;
			}
			top--;
		}
		void peek(){
			cout<<"\n"<<*top<<endl;
		}
		void print(){
			while(top!=NULL){
				cout<<*top<<"\t";
				pop();
				
			}
		}
};
int main(){
	stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.pop();
	s.peek();
	s.print();
}