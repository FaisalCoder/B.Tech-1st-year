#include <iostream>
#include <new>
#include<stack>
using namespace std;


 class node{public:
    node*left,*right;
    int key;
};

void MakeTree ( node* root, int data, int& count2)
{
    stack<int> s;

    node * make = new node;
    make->key = data;
    make->right = NULL;
    make->left = NULL;

    int count = count2+1;
    count2++;

    int c = count/2;

    while( c != 1)
    {
        s.push(c);
        c = c/2;

    }

    node * p = root;
    while( s.empty() == false )
    {
        c = s.top();
        s.pop();
        if ( c%2 == 0)p = p->left;
        else p = p->right;
    }
    cout << count << endl;
    if ( count %2 == 0) p->left = make;
    else p->right = make;

}

void DFS ( node* root)
{
    stack <node*> s;
    s.push(root);
    node * temp;

    while( !s.empty())
    {
        temp = s.top();
        s.pop();

        cout << temp->key <<  " ";

        if ( temp->left != 0)
        s.push(temp->left);

        if ( temp->right != 0)
        s.push(temp->right);

    }
    cout << endl;
}

void Inorder( node * p)
{

    stack<node*> s;
    do
    {
        while( p != 0)
        {
            s.push(p);
            p = p->left;
        }


        if ( !s.empty())
        {
            p = s.top();
            s.pop();
            cout << p->key << " ";
            p = p->right;

        }
    }while( !s.empty() || p != NULL);

}

void Inorder2(node* root)
{
    if ( root != 0)
    {
        Inorder2(root->left);
        cout << root->key << " ";
        Inorder2(root->right);
    }

}

int main()
{
    stack<node*> S;
    node * root2 = new node;
    root2->key = 1;
    root2->left = NULL;
    root2->right = NULL;
    int count2 = 1;


    MakeTree(root2,2,count2);
   MakeTree(root2,3,count2);
    MakeTree(root2,4,count2);
    MakeTree(root2,5,count2);
    MakeTree(root2,6,count2);
    MakeTree(root2,7,count2);
    MakeTree(root2,8,count2);
    MakeTree(root2,9,count2);
    DFS(root2);
  Inorder(root2);

    return 0;
}

