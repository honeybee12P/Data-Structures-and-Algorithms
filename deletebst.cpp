#include <iostream>
#include<cstdio>
using namespace std;
struct Node{
  int data;
  struct Node *left;
  struct Node *right;
};

Node* FindMin(Node* root){
  while(root->left != NULL) root = root->left;
  return root;
}

struct Node* Delete(struct Node *root, int data){
  if(root == NULL) return root;
  else if(data < root->data) root->left = Delete(root->left,data);
  else if(data > root->data) root->right = Delete(root->right, data);
  else {
    // Case 1: No Child
    if(root->left == NULL && root->right == NULL){
      delete root;
      root = NULL;
    // Case 2: one child
    } else if(root->left == NULL){
      struct Node *temp = root;
      root = root->right;
      delete temp;
    } else if(root->right == NULL){
      struct Node *temp = root;
      root = root->left;
      delete temp;
    } else{
      struct Node *temp = FindMin(root->right);
      root->data = temp->data;
      root->right = Delete(root->right, temp->data);
    }
  }
  return root;
}

void Inorder(Node *root){
  if(root == NULL) return;
  Inorder(root->left);
  printf("%d ",root->data);
  Inorder(root->right);
}

Node* Insert(Node *root, char data){
  if(root == NULL){
    root = new Node();
    root->data = data;
    root->left = root->right = NULL;
  } else if(data <= root->data){
    root->left = Insert(root->left, data);
  } else {
    root->right = Insert(root->right, data);
  }
  return root;
}

int main ()
{
  /* Let us create following BST
              75
           /     \
          55        85
         /  \      /  \
       35   65    75   90 
      /  \ / \    / \   / \
    25  45 60 70 72 80 89  91*/
  Node* root = NULL;
  root = Insert(root, 75);
  root = Insert(root, 55);
  root = Insert(root, 35);
  root = Insert(root, 65);
  root = Insert(root, 85);
  root = Insert(root, 75);
  root = Insert(root, 90);
  root = Insert(root, 25);
  root = Insert(root, 45);
  root = Insert(root, 60);
  root = Insert(root, 70);
  root = Insert(root, 72);
  root = Insert(root, 80);
  root = Insert(root, 89);
  root = Insert(root, 91);  
  cout << "Tree before deleting node\t"; 
  Inorder(root);
  cout << "\n";
  cout << "Deleting leaf node 25\n";
  root = Delete(root,25 );
  cout << "\n";
  cout << " Tree after deleting node 25\t";
  Inorder(root);
  cout << "\n";
  cout << "Deleting 65 so that it's replacing node is a leaf node\n";
  root = Delete(root,65);
  cout << "\n";
  cout << "Tree after deleting node 65\t";
  Inorder(root);
  cout << "\n";
  cout << "Deleting node 85. This time the predecessor replacement is not a leaf node\n";
  root = Delete(root,85);
  cout << "\n";
  cout << "Tree after deleting node 85\t";
  Inorder(root);
  cout << "\n";
  cout<<"Inorder Traversal of the tree after all modifications\t ";
  Inorder(root);
  cout<<"\n";
  return 0;
}
 
