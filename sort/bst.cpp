#include <iostream>
#include <chrono>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create_node(int key)
{
    node *newnode = new node;
    newnode->data = key;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node *insert(int key, struct node *root)
{
    if (root == NULL)
    {
        root = create_node(key);
    }
    else
    {
        if (key < root->data)
        {
            root->left = insert(key, root->left);
        }
        else
        {
            root->right = insert(key, root->right);
        }
    }
    return root;
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        //std::cout << root->data;
        inorder(root->right);
    }
}
int main()
{
    using std::chrono::high_resolution_clock;
    using std::chrono::duration;
    struct node *root = NULL;
    int a = 1000000;
    for (int i = 0; i < a; i++)
    {
        root = insert(rand(), root);
    }
    auto t1 = high_resolution_clock::now();
    inorder(root);
    auto t2 = high_resolution_clock::now();
    duration<double,std::milli> ms_double = t2-t1;
    std::cout<<float(ms_double.count()/1000)<<"\ts"<<"\n";
    std::cout<<ms_double.count()<<"\tms";
}