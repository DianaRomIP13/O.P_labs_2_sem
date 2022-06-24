#pragma once
#include <iostream>

using namespace std;

class Node
{
public:
	char symbol;
	Node* LEFT;
	Node* RIGHT;
};

class Tree
{
	Node* root;
public:
	Tree() : root(0) {};
	void AddElement(char s);
	void printTree();
	void printLeafs();
private:
	int getLevels(Node*);
	void printTree(Node*, int);
	void AddElement(Node*&, char);
	void printLeafs(Node*);
};