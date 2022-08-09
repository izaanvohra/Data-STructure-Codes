#include<iostream>
#include<list>
using namespace std;
class Hash{
    int BUCKET;                    // No. of buckets  and Pointer to an array containing buckets
    list<int> *table;
    
	public:
        Hash(int V);                 
        void insertItem(int x);    
        void deleteItem(int key);  
        int hashFunction(int x){   // hash function to map values to key
        	return (x % BUCKET);
        }
        void displayHash();
};
Hash::Hash(int b){
    this->BUCKET = b;
    table = new list<int>[BUCKET];
}

void Hash::insertItem(int key){
    int index = hashFunction(key);
    table[index].push_back(key);
}


void Hash::deleteItem(int key){          // get the hash index of key
    int index = hashFunction(key);
 	list <int> :: iterator i;
	for (i = table[index].begin();
	i != table[index].end(); i++){
		if (*i == key)
		break;
    }
if (i != table[index].end())             // if key is found in hash table, remove it
table[index].erase(i);
}

void Hash::displayHash() {               // function to display hash table
	for (int i = 0; i < BUCKET; i++) {
	cout << i;
	for (auto x : table[i])
	cout << " --> " << x;
	cout << endl;
    }
}
int main()
{
int a[] = {15, 11, 27, 8, 12};          // array that contains keys to be mapped
int n = sizeof(a)/sizeof(a[0]);
// insert the keys into the hash table
Hash h(7); // 7 is count of buckets in
// hash table
for (int i = 0; i < n; i++)
h.insertItem(a[i]);
h.deleteItem(12);           // delete 12 from hash table
h.displayHash();            
return 0;
}