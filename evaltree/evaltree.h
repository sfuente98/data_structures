/*
 * evaltree.h
 *
 *  Created on: 20/10/2015
 *      Author: clase
 */

#ifndef EVALTREE_H_
#define EVALTREE_H_

#include <cctype>
#include <string>
#include <sstream>
#include <queue>
#include <stack>
#include "exception.h"

class EvalTree;

class TreeNode {
private:
	char value;
	TreeNode *left, *right;

	bool isOperator() const;
	bool isVariable() const;
	bool isOperand() const;

public:
	TreeNode(char);
	TreeNode(char, TreeNode*, TreeNode*);
	int depth() const;
	void inorder(std::stringstream&) const;
	void postorder(std::stringstream&) const;
	void preorder(std::stringstream&) const;
	void levelOrder(std::stringstream&) const;
	int howManyLeaves() const;
	char minValue() const;
	bool find(char) const;
	double eval(double x) const;
	TreeNode* derive() const;
	void removeChilds();
	TreeNode* copy() const;
	friend class EvalTree;
};

TreeNode::TreeNode(char c) :value(c), left(0), right(0){}

TreeNode::TreeNode(char c, TreeNode* le, TreeNode* ri) :value(c), left (le), right(ri) {}

bool TreeNode::isOperator() const {
    return (value == '+' || value == '-' || value == '*' || value == '/');
}

bool TreeNode::isVariable() const {
	return (value == 'x');
}

bool TreeNode::isOperand() const {
	return (value >= '0' && value <='9');
}

int TreeNode::depth() const {
    int le = -1;
    int ri = -1;
    int de = -1;

    if(left != 0){
        le = left->depth();
    }
    if(right != 0){
        ri = right->depth();
    }
    de = (le > ri)? le : ri;
	return (de + 1);
}

void TreeNode::inorder(std::stringstream &aux) const {
	if(left != 0){
        left->inorder(aux);
	}
	aux << value << " ";
	if(right != 0){
        right->inorder(aux);
	}
}

void TreeNode::postorder(std::stringstream &aux) const {
	if(left != 0){
        left->postorder(aux);
	}
    if(right != 0){
        right->postorder(aux);
	}
	aux << value << " ";
}

void TreeNode::preorder(std::stringstream &aux) const {
	aux << value << " ";
	if(left != 0){
        left->preorder(aux);
	}
    if(right != 0){
        right->preorder(aux);
	}
}

int TreeNode::howManyLeaves() const {
    int le = 0, ri = 0, res;
    if(left != 0){
        le = left->howManyLeaves();
    }
    if(right != 0){
        ri = right->howManyLeaves();
    }
    res = le + ri;
    if(res == 0)
        res = 1;
	return res;
}

char TreeNode::minValue() const {
    char le = '0', ri = '0';
    if(isOperand()){
        return value;
    }else if(isOperator()){
        if(left != 0){
            le = left->minValue();
        }
        if(right != 0){
            ri = right->minValue();
        }
        return ((le < ri)? le : ri);
    }
	return '9';
}

bool TreeNode::find(char val) const {
    bool  res = false;

    if(value == val){
        return true;
    }
    if(left != 0){
        res = left->find(val);
    }
    if(res == true){
         return res;
    }
    if (right != 0){
        res = right->find(val);
    }
    if(res == true){
         return res;
    }
    return false;
}

double TreeNode::eval(double x) const {
        double le  = 0, ri = 0;
        if(isVariable()){
            return x;
        }else if(isOperand()){
            return (value - '0');
        }else if(isOperator()){
            if(left != 0){
                le = left->eval(x);
            }
            if(right != 0){
                ri = right->eval(x);
            }
            switch(value){
            	case '+': return( le + ri);
                case '-': return( le - ri);
                case '*': return( le * ri);
                case '/':
                    if(ri == 0){
                        throw IllegalAction();
                    }
                    return( le / ri);
            }
        }
        return 0;
}

void TreeNode::removeChilds() {
    if(left != 0){
        left->removeChilds();
        delete left;
        left = 0;
    }
    if(right != 0){
        right->removeChilds();
        delete right;
        right = 0;
    }
}

TreeNode* TreeNode::derive() const {
	TreeNode  *da, *a, *db, *b, *m1, *m2, *m3, *sum, *div;
    if(isVariable()){
        return new TreeNode('1');
    }else if (isOperand()){
        return new TreeNode('0');
    }else if (isOperator()){
        switch(value){
            case '+': return new TreeNode('+', left->derive(), right->derive());
            case '-': return new TreeNode('-', left->derive(), right->derive());
            case '*':
                a = left->copy();
                db = right->derive();
                m1 = new TreeNode('*',a,db);

                b = right->copy();
                da = left->derive();
                m2 = new TreeNode('*',b,da);

                sum = new TreeNode('+',m1, m2);
                return sum;
            case '/':
                a = left->copy();
                db = right->derive();
                m1 = new TreeNode('*', a,db);

                b = right->copy();
                da = left->derive();
                m2 = new TreeNode('*',b ,da);

                sum = new TreeNode('-',m1,m2);

                m3 = new TreeNode('*', right->copy(), right->copy());

                div = new TreeNode('/', sum, m3);
                return div;
        }
    }
	return 0;
}

TreeNode* TreeNode::copy() const {
    TreeNode * newNode = new TreeNode(value);
    if(left != 0){
        newNode->left = left->copy();
    }
    if(right != 0){
        newNode->right = right->copy();
    }
	return newNode;
}

class EvalTree {
private:
	TreeNode *root;

	std::queue<std::string> tokenize(std::string);

public:
	EvalTree();
	EvalTree(std::string) throw (IllegalAction);
	~EvalTree();
	bool empty() const;
	int height() const;
	std::string inorder() const;
	std::string postorder() const;
	std::string preorder() const;
	std::string levelOrder() const;
	int howManyLeaves() const;
	char minValue() const throw (IllegalAction);
	bool find(char) const;
	double eval(double) const throw (IllegalAction) ;
	EvalTree* derive() const;
	void removeAll();
	bool isFull() const;
	int internalNodes() const;
	bool isPerfect() const;
	bool isDegenerate() const;
};

EvalTree::EvalTree() {
    root = 0;
}

std::queue<std::string> EvalTree::tokenize(std::string str) {
	int i = 0;
	int length = str.size();
	std::string aux;
	std::queue<std::string> result;

	while (i < length) {
		if (isdigit(str[i])) {
			aux.clear();
			do {
				aux += str[i];
				i++;
			} while(isdigit(str[i]));
			result.push(aux);
		} else if (isspace(str[i])) {
			i++;
		} else {
			aux.clear();
			aux += str[i];
			result.push(aux);
			i++;
		}
	}
	return result;
}

EvalTree::EvalTree(std::string str) throw (IllegalAction) {
	root = 0;
	std::stack<TreeNode*> s;
	std::queue<std::string> tokens = tokenize(str);
	std::string aux;
	TreeNode *left, *right, *newNode;

	while (!tokens.empty()) {
		aux = tokens.front(); tokens.pop();
		if (aux == "+" || aux == "-" || aux == "*" || aux == "/") {
			if (s.empty()) {
				throw IllegalAction();
			}
			left = s.top(); s.pop();
			if (s.empty()) {
				throw IllegalAction();
			}
			right = s.top(); s.pop();
			newNode = new TreeNode(aux[0], left, right);
			s.push(newNode);
		} else if (aux[0] == 'x' || isdigit(aux[0])) {
			newNode = new TreeNode(aux[0]);
			s.push(newNode);
		}
	}
	newNode = s.top(); s.pop();
	if (!s.empty()) {
		throw IllegalAction();
	}
	root = newNode;
}

EvalTree::~EvalTree() {
    removeAll();
}

bool EvalTree::empty() const {
    return (root == 0);
}

int EvalTree::height() const {
	if(empty())
        return 0;
    else
        return root->depth() + 1;
}

std::string EvalTree::inorder() const {
	std::stringstream aux;
    if(!empty())
        root->inorder(aux);
	return aux.str();
}

std::string EvalTree::preorder() const {
	std::stringstream aux;
    if(!empty())
        root->preorder(aux);
	return aux.str();
}

std::string EvalTree::postorder() const {
	std::stringstream aux;
    if (!empty())
        root->postorder(aux);
	return aux.str();
}

std::string EvalTree::levelOrder() const {
	std::stringstream aux;
	std::queue<TreeNode*> q;

	if(!empty()){
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            aux<< node->value << " ";
            if(node->left!=0){
                q.push(node->left);
            }
            if(node->right!= 0){
                q.push(node->right);
            }
        }
	}

	return aux.str();
}

int EvalTree::howManyLeaves() const {
    if(empty())
        return 0;
	else
       return root->howManyLeaves();
}

char EvalTree::minValue() const throw (IllegalAction) {
    if(empty())
        throw IllegalAction();
    else
        return root->minValue();
}

bool EvalTree::find(char c) const {
    if(empty())
        return false;
    else
        return root->find(c);
}

double EvalTree::eval(double x) const throw (IllegalAction) {
	if(empty())
        throw IllegalAction();
    else
        return root->eval(x);
}

EvalTree* EvalTree::derive() const {
	EvalTree *n;

	n = new EvalTree();
	if(root != 0)
        n->root = root->derive();
	return n;
}

void EvalTree::removeAll() {
    if(!empty()){
        root->removeChilds();
        delete root;
        root = 0;
    }
}
#endif /* EVALTREE_H_ */
