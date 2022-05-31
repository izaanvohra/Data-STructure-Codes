#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

// BST: Left Child Node is less than Parent, Right Child Node is greater than Parent.
class BST
{
    private:

        Node *root, *temp, *temp1;

    public:

        BST()
        {
            root = NULL;
        }

        Node * getRoot()
        {
            return root;
        }
        
        void insert( int key, Node *& temp)
        {
            if ( root == NULL)
            {
                temp = new Node;
                temp -> data = key;
                temp -> left = temp -> right = NULL;
                root = temp;

                return;
            }

            if ( key == temp -> data)
            {
                cout << "\nDuplicate value." << endl;
                return;
            }

            if ( key > temp -> data)
            {
                if ( temp -> right == NULL)
                {
                    
                    temp1 = new Node;
                    temp1 -> data = key;
                    temp -> right = temp1;
                    temp1 -> left = temp1 -> right = NULL;

                    return;
                }
                insert ( key, temp -> right);

                return;
            }

            if ( key < temp -> data)
            {
                if ( temp -> left == NULL)
                {

                    temp1 = new Node;
                    temp1 -> data = key;
                    temp -> left = temp1;
                    temp1 -> left = temp1 -> right = NULL;

                    return;
                }
                insert ( key, temp -> left);

                return;
            }
        }

        // Searching data in BST. return ADDRESS of searched data.
        Node * search( int key, Node *& temp)
        {
            if ( root == NULL)
            {
                cout << "\nTree is empty." << endl;
                return NULL;
            }

            if ( temp -> data == key)
            {
                return temp;
            }

            if ( ( temp -> right != NULL) && ( key > temp -> data))
            {
                return search( key, temp -> right);
                
            }

            if ( ( temp -> left != NULL) && ( key < temp -> data))
            {
                return search( key, temp -> left);
            }

            if ( temp -> left == NULL && temp -> right == NULL)
            {
                cout << "\nData not found." << endl;
                return NULL;
            }
        }

        void row( Node *& temp)
        {
            if ( temp -> left != NULL)
                cout << temp -> left -> data << "\t";
            
            if ( temp -> right != NULL)
            cout << temp -> right -> data << "\t";

            return;
        }

        void print_level( Node *& temp)
        {
            if ( root == NULL)
            {
                cout << "\nTree is empty." << endl;
                return;
            }

            if ( temp == root)
            {
                cout << temp -> data << "\t";
                cout << temp -> left -> data << "\t";
                cout << temp -> right -> data << "\t";
            }

            if ( temp -> left != NULL)
                row( temp -> left);

            if ( temp -> right != NULL)
                row( temp -> right);

            if ( temp -> left != NULL)
                print_level( temp -> left);

            if ( temp -> right != NULL)
                print_level( temp -> right);

            return;
        }

        // Tree Traversal ( Pre Order )
        void print_pre( Node *& temp)
        {
            if ( root == NULL)
            {
                cout << "\nTree is empty." << endl;
                return;
            }

            cout << temp -> data << "\t";

            if ( temp -> left != NULL)
                print_pre( temp -> left);
            
            if ( temp -> right != NULL)
                print_pre( temp -> right);
            
            return;
        }

        // Tree Traversal ( In Order )
        void print_in( Node *& temp)
        {
            if ( root == NULL)
            {
                cout << "\nTree is empty." << endl;
                return;
            }

            if ( temp -> left != NULL)
                print_in( temp -> left);

            cout << temp -> data << "\t";

            if ( temp -> right != NULL)
                print_in( temp -> right);
        }

        // Tree Traversal ( Post Order )
        void print_post( Node *& temp)
        {
            if ( root == NULL)
            {
                cout << "\nTree is empty." << endl;
                return;
            }

            if ( temp -> left != NULL)
                print_post( temp -> left);

            if ( temp -> right != NULL)
                print_post( temp -> right);
            
            cout << temp -> data << "\t";
        }

        Node * succesor( int key)
        {
            temp1 = NULL;

            temp = search( key, root);

            if ( temp -> right != NULL) // if right sub tree is not NULL
            {
                temp = temp -> right;

                if ( temp -> left != NULL) // if right subtree has a left subtree
                {
                    while ( temp -> left != NULL)
                    {
                        temp = temp -> left;
                    }
                }
                return temp;
            }

            temp = root;

            while ( temp -> data != key)
            {

                if ( temp -> data > key)
                {
                    temp1 = temp;
                }

                if ( ( temp -> right != NULL) && ( key > temp -> data))
                {
                    temp = temp -> right;

                    if ( temp -> data > key)
                    {
                        temp1 = temp;
                    }
                }

                if ( ( temp -> left != NULL) && ( key < temp -> data))
                {
                    temp = temp -> left;

                    if ( temp -> data > key)
                    {
                        temp1 = temp;
                    }
                }
            }

            if ( temp1 == NULL)
            {
                return NULL;
            }

            return temp1;
        }

        Node * delete_node( int key, Node * temp, Node * temp1 = NULL) // temp = node to be deleted, temp1 = parent node
        {
            if ( temp == NULL)
                return NULL;
            
            if ( temp -> data == key)
            {
                // If Node to be deleted is a leaf.
                if ( temp -> left == NULL && temp -> right == NULL)
                {
                    if ( temp1 -> left == temp)
                    {
                        temp1 -> left = NULL;
                        delete temp;
                        return NULL;
                    }
                    if ( temp1 -> right == temp)
                    {
                        temp1 -> right = NULL;
                        delete temp;
                        return NULL;
                    }
                }

                // If Node to be deleted has one child.
                if ( temp -> left == NULL || temp -> right == NULL)
                {
                    if ( temp1 -> left == temp)
                    {
                        if ( temp -> left != NULL)
                        {
                            temp1 -> left = temp -> left;
                            delete temp;
                            return NULL;
                        }

                        if ( temp -> right != NULL)
                        {
                            temp1 -> left = temp -> right;
                            delete temp;
                            return NULL;
                        }
                    }
                    if ( temp1 -> right == temp)
                    {
                        if ( temp -> left != NULL)
                        {
                            temp1 -> right = temp -> left;
                            delete temp;
                            return NULL;
                        }

                        if ( temp -> right != NULL)
                        {
                            temp1 -> right = temp -> right;
                            delete temp;
                            return NULL;
                        }
                    }
                }

                // If Node to be deleted has two children

                Node * succ = succesor( key);       // Find successor of Node to be deleted/swapped
                int swap = succ -> data;            // Save data of successor
                delete_node( succ -> data, root);   // Delete successor Node
                temp -> data = swap;                // Swap data of successor into Node
                return NULL;
            }

            if ( key < temp -> data && temp -> left != NULL)
                delete_node( key, temp -> left, temp1 = temp);

            if ( key > temp -> data && temp -> right != NULL)
                delete_node( key, temp -> right, temp1 = temp);
        }

        int maxDepth( Node *& temp)
        {
            if ( temp == NULL)
            {
                return -1;
            }

            else
            {
                int l = maxDepth( temp -> left);
                int r = maxDepth( temp -> right);

                if ( l > r)
                    return l + 1;
                else
                    return r + 1;
            }
        }

        void heap( Node *& temp)
        {
            if ( root == NULL)
            {
                cout << "\nTree is empty." << endl;
                return;
            }

            if ( temp -> left == NULL && temp -> right == NULL)
                return;

            if ( temp -> right -> data <= temp -> data)
            {

                int swap = temp -> right -> data;

                temp -> right -> data = temp -> data;

                temp -> data = swap;
            }

            if ( temp -> left -> data <= temp -> data)
            {

                int swap = temp -> left -> data;

                temp -> left -> data = temp -> data;

                temp -> data = swap;
            }

            if ( temp -> right != NULL)
                heap( temp -> right);

            if ( temp -> left != NULL)
                heap( temp -> left);

            return;
        }
};

int main()
{
    BST tree;

    Node * r = tree.getRoot(); // using getRoot function since root is a private class variable

    tree.insert( 5,  r);
    tree.insert( -15,  r);
    tree.insert( 17,  r);
    tree.insert( 1333,  r);
    tree.insert( 7555,  r);
    tree.insert( 6,  r);
    tree.insert( 90,  r);
    tree.insert( 0,  r);
    tree.insert( 69,  r);
    tree.insert( 3,  r);

    cout << "\nLevel Order" << endl;

    tree.print_level( r);

}