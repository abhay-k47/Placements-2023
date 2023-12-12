/**
 * @file BST.cpp
 * @author Abhay Keshari (akabhay9585@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-11-14
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
struct Node
{
  T value;
  Node* left;
  Node* right;
  Node* parent;
  explicit Node(const T& value, Node* parent = nullptr);
};

template <typename T>
class BST
{
public:
  enum ORDER
  {
    PRE,
    IN,
    POST
  };
  BST();
  BST(const std::vector<T>& v);
  bool search(const T& value) const;
  void insert(const T& value);
  void remove(const T& value);
  // T findByOrder(size_t k) const;
  T predecessor(const T& value) const;
  T successor(const T& value) const;
  void print(ORDER order, char separator = '\n') const;

private:
  Node<T>* root;
  bool searchUtil(const Node<T>* node, const T& value) const;
  Node<T>* insertUtil(Node<T>* node, const T& value);
  Node<T>* removeUtil(Node<T>* node, const T& value);
  Node<T>* rotateLeft(Node<T>* x);
  Node<T>* rotateRight(Node<T>* x);
  void preorder(const Node<T>* root, char separator) const;
  void inorder(const Node<T>* root, char separator) const;
  void postorder(const Node<T>* root, char separator) const;
};

template <typename T>
Node<T>::Node(const T& value, Node* parent)
    : value(value)
    , left(nullptr)
    , right(nullptr)
    , parent(parent)
{
}

template <typename T>
BST<T>::BST()
    : root(nullptr)
{
}

template <typename T>
BST<T>::BST(const std::vector<T>& v)
    : root(nullptr)
{
  for (const T& value : v)
    root = insertUtil(root, value);
}

template <typename T>
bool BST<T>::search(const T& value) const
{
  cout << value << ": ";
  return searchUtil(root, value);
}

template <typename T>
void BST<T>::insert(const T& value)
{
  root = insertUtil(root, value);
}

template <typename T>
void BST<T>::remove(const T& value)
{
  root = removeUtil(root, value);
}

template <typename T>
T BST<T>::predecessor(const T& value) const
{
  if (root == nullptr || root->left == nullptr)
    return static_cast<T>(INT32_MIN);
  Node<T>* temp = node->left;
  while (temp->right != nullptr)
    temp = temp->right;
  return temp->value;
}

template <typename T>
T BST<T>::successor(const T& value) const
{
  if (root == nullptr || root->right == nullptr)
    return static_cast<T>(INT32_MIN);
  Node<T>* temp = node->right;
  while (temp->left != nullptr)
    temp = temp->left;
  return temp->value;
}

template <typename T>
void BST<T>::print(BST::ORDER order, char separator) const
{
  switch (order)
  {
    case PRE:
      preorder(root, separator);
      break;
    case IN:
      inorder(root, separator);
      break;
    case POST:
      postorder(root, separator);
      break;
    default:
      cout << "parameter: order is invalid" << endl;
  }
}

template <typename T>
bool BST<T>::searchUtil(const Node<T>* node, const T& value) const
{
  if (node == nullptr)
    return false;
  else if (value < node->value)
    return searchUtil(node->left, value);
  else if (value > node->value)
    return searchUtil(node->right, value);
  else
    return true;
}

/** returns new root node of the subtree after inserting a new node with the value = `value` */
template <typename T>
Node<T>* BST<T>::insertUtil(Node<T>* node, const T& value)
{
  if (node == nullptr)
    return new Node(value);
  else if (value < node->value)
  {
    node->left = insertUtil(node->left, value);
    node->left->parent = node;
  }
  else if (value > node->value)
  {
    node->right = insertUtil(node->right, value);
    node->right->parent = node;
  }
  return node;
}

/** returns new root node of the subtree after removing the node with the value = `value` */
template <typename T>
Node<T>* BST<T>::removeUtil(Node<T>* node, const T& value)
{
  if (node == nullptr)
    return nullptr;
  else if (value < node->value)
  {
    node->left = removeUtil(node->left, value);
    if (node->left != nullptr)
      node->left->parent = node;
    return node;
  }
  else if (value > node->value)
  {
    node->right = removeUtil(node->right, value);
    if (node->right != nullptr)
      node->right->parent = node;
    return node;
  }
  if (node->left == nullptr)
  {
    Node<T>* temp = node->right;
    delete node;
    return temp;
  }
  else if (node->right == nullptr)
  {
    Node<T>* temp = node->left;
    delete node;
    return temp;
  }
  else
  {
    Node<T>* temp = node->left;
    while (temp->right != nullptr)
      temp = temp->right;
    node->value = temp->value;
    if (temp == temp->parent->left)
      temp->parent->left = temp->left;
    else
      temp->parent->right = temp->left;
    if (temp->left != nullptr)
      temp->left->parent = temp->parent;
    delete temp;
    return node;
  }
}

/*
       x                      y
      / \                   /   \
    T1   y                 x     z
        / \        --->  /  \   /  \
      T2   z            T1  T2 T3  T4
          / \
        T3   T4
*/
template <typename T>
Node<T>* BST<T>::rotateLeft(Node<T>* x)
{
  if (x == nullptr || x->right == nullptr)
    return x;
  Node<T>*y = x->right, *T2 = y->left;
  y->left = x;
  x->parent = y;
  x->right = T2;
  if (T2)
    T2->parent = x;
  return y;
}

/*
           x                   y
          / \                /   \
         y   T4             z     x
        / \        --->   /  \   /  \
       z   T3            T1  T2 T3  T4
      / \
    T1   T2
*/
template <typename T>
Node<T>* BST<T>::rotateRight(Node<T>* x)
{
  if (x == nullptr || x->left == nullptr)
    return x;
  Node<T>*y = x->left, *T3 = y->right;
  y->right = x;
  x->parent = y;
  x->left = T3;
  if (T3)
    T3->parent = x;
  return y;
}

template <typename T>
void BST<T>::preorder(const Node<T>* node, char separator) const
{
  if (node == nullptr)
    return;
  cout << node->value << separator;
  preorder(node->left, separator);
  preorder(node->right, separator);
}

template <typename T>
void BST<T>::inorder(const Node<T>* node, char separator) const
{
  if (node == nullptr)
    return;
  inorder(node->left, separator);
  cout << node->value << separator;
  inorder(node->right, separator);
}

template <typename T>
void BST<T>::postorder(const Node<T>* node, char separator) const
{
  if (node == nullptr)
    return;
  postorder(node->left, separator);
  postorder(node->right, separator);
  cout << node->value << separator;
}

int main(int argc, char const* argv[])
{
  srand(time(0));
  vector<int> v;
  for (int i = 0; i < 50; i++)
    v.push_back(rand() % 50);
  BST<int> bst(v);
  bst.print(BST<int>::IN, ' ');
  cout << endl;
  for (int i = 0; i < 50; i++)
    cout << bst.search(rand() % 70) << endl;
  for (int i = 0; i < 100; i++)
  {
    bst.remove(rand() % 70);
    bst.print(BST<int>::IN, ' ');
    cout << endl;
  }
  return 0;
}
