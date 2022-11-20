// Фомичев Андрей Михайлович, II Вариант
// ЛР15

/*
Описать класс, реализующий бинарное дерево, 
обладающее возможностями добавления новых 
элементов, удаления существующих, поиска 
элемента по ключу, а также последовательного 
доступа ко всем элементам.
*/

// P.S. На aнглийской винде лаба не компилится
// из-за цыганского названия файла.cpp

#include <iostream>
using namespace std;
struct Node
{
	int value;
	Node *left;
	Node *right;
};

class Binary
{
public:
	Binary();
	~Binary();
	void insert(int key);
	Node *search(int key);
	void remove_tree();
	void inorder_print();
	void deleteNode(Node *&root, int key);

private:
	void remove_tree(Node *leaf);
	void insert(int key, Node *leaf);
	Node *search(int key, Node *leaf);
	void inorder_print(Node *leaf);
	Node *root;
};

Binary::Binary()
{
	root = NULL;
}

Binary::~Binary()
{
	remove_tree();
}

void Binary::remove_tree(Node *leaf)
{
	if (leaf != NULL)
	{
		remove_tree(leaf->left), remove_tree(leaf->right);
		delete leaf;
	}
}
void Binary::insert(int key, Node *leaf)
{
	if (key < leaf->value)
		if (leaf->left != NULL)
			insert(key, leaf->left);
		else
			leaf->left = new Node,
			leaf->left->value = key,
			leaf->left->left = NULL,
			leaf->left->right = NULL;
	else if (key >= leaf->value)
		if (leaf->right != NULL)
			insert(key, leaf->right);
		else
			leaf->right = new Node,
			leaf->right->value = key,
			leaf->right->right = NULL,
			leaf->right->left = NULL;
}
void Binary::insert(int key)
{
	if (root != NULL)
	{
		insert(key, root);
	}
	else
	{
		root = new Node;
		root->value = key;
		root->left = NULL;
		root->right = NULL;
	}
}

Node* Binary::search(int key, Node *leaf)
{
	if (leaf != NULL)
	{
		if (key == leaf->value)
			return leaf;
		if (key < leaf->value)
			return search(key, leaf->left);
		return search(key, leaf->right);
	}
	return NULL;
}
Node* getMinimumKey(Node* curr)
{
    while (curr->left != nullptr) {
        curr = curr->left;
    }
    return curr;
}
void searchKey(Node* &curr, int key, Node* &parent)
{
    while (curr != nullptr && curr->value != key)
    {
        parent = curr;
        if (key < curr->value)
            curr = curr->left;
        else
            curr = curr->right;
    }
}
// void deleteNode(Node *&root, int key)
// {
// 	Node *parent = nullptr;
// 	Node *curr = root;
// 	searchKey(curr, key, parent);
// 	if (curr == nullptr)
// 		return;
// 	if (curr->left == nullptr && curr->right == nullptr)
// 	{
// 		if (curr != root)
// 			if (parent->left == curr)
// 				parent->left = nullptr;
// 			else
// 				parent->right = nullptr;
// 		else
// 			root = nullptr;
// 		free(curr);
// 	}
// 	else if (curr->left && curr->right)
// 	{
// 		Node *successor = getMinimumKey(curr->right);
// 		int val = successor->value;
// 		deleteNode(root, successor->value);
// 		curr->value = val;
// 	}
// 	else
// 	{
// 		Node *child = (curr->left) ? curr->left : curr->right;
// 		if (curr != root)
// 			if (curr == parent->left)
// 				parent->left = child;
// 			else
// 				parent->right = child;
// 		else
// 			root = child;
// 		free(curr);
// 	}
// }
Node* Binary::search(int key)
{
	return search(key, root);
}

void Binary::remove_tree()
{
	remove_tree(root);
}

void Binary::inorder_print()
{
	inorder_print(root);
	cout << "\n";
}

void Binary::inorder_print(Node *leaf)
{
	if (leaf != NULL)
	{
		inorder_print(leaf->left);
		cout << leaf->value << " ";
		inorder_print(leaf->right);
	}
}

int main()
{
	Binary *T = new Binary();
	T->insert(10);
	T->insert(6);
	T->insert(14);
	T->inorder_print();
	delete T;
}

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
/*                                                  */
/*               Пояснение к работе 😊             */
/*                                                  */
/* Простая реализация бинарного дерева, которую     */
/* можно встретить на любом собеседовании на        */
/* программиста, два метода search и searchKey      */
/* были реализованы как самостоятельные единицы     */
/* первая ищет узел по значению, вторая нужна для   */
/* поиска приращения дерева в случае удаления узла  */
/*                                                  */
/* Так же не совсем понял, как должно происходить   */
/* удаление узла, поэтому написал мою версию этого  */
/* процесса, в случае если моя задумка верна,       */
/* раскомментить код и использовать.                */
/*                                                  */
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
