/*
 * eval_tree.h
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
#include "../includes/exception.h"

#include <iostream>

enum node_type {OPERATOR, NUMBER};

typedef union {
	char op;
	int number;
} tree_value;

class eval_tree;

class tree_node {
private:
	node_type type;
	tree_value value;
	tree_node *left, *right;

public:
	tree_node(node_type, tree_value);
	tree_node(node_type, tree_value, tree_node*, tree_node*);
	int depth() const;
	void inorder(std::stringstream&) const;
	void postorder(std::stringstream&) const;
	void preorder(std::stringstream&) const;
	void breadth_order(std::stringstream&) const;
	int leaves() const;
	int min_value() const;
	bool find(node_type, tree_value) const;
	long eval() const;
	void remove_childs();
	tree_node* copy() const;
	
	friend class eval_tree;
};

tree_node::tree_node(node_type t, tree_value v)
	: type(t), value(v), left(0), right(0) {}

tree_node::tree_node (node_type t, tree_value v, 
	tree_node* le, tree_node* ri) 
	: type(t), value(v), left (le), right(ri) {}

int tree_node::depth() const {
    int le = 0;
    int ri = 0;
    int de = 0;
    
    if (left == 0 && right == 0) {
    	return 1;
    }

    if (left != 0) {
        le = left->depth();
    }
    
    if (right != 0) {
        ri = right->depth();
    }
    
    de = (le > ri)? le : ri;
    
	return (de + 1);
}

void tree_node::inorder(std::stringstream &aux) const {
	if (left != 0) {
        left->inorder(aux);
	}
	
	if (type == NUMBER) {
		aux << value.number << " ";
	} else {
		aux << value.op << " ";
	}
	
	if (right != 0) {
        right->inorder(aux);
	}
}

void tree_node::postorder(std::stringstream &aux) const {
	if (left != 0) {
        left->postorder(aux);
	}
	
    if (right != 0) {
        right->postorder(aux);
	}
	
	if (type == NUMBER) {
		aux << value.number << " ";
	} else {
		aux << value.op << " ";
	}
}

void tree_node::preorder(std::stringstream &aux) const {
	if (type == NUMBER) {
		aux << value.number << " ";
	} else {
		aux << value.op << " ";
	}
	
	if (left != 0) {
        left->preorder(aux);
	}
	
    if (right != 0) {
        right->preorder(aux);
	}
}

int tree_node::leaves() const {
    int le = 0, ri = 0;
    
    if (left == 0 && right == 0) {
    	return 1;
    }
    
    if (left != 0) {
        le = left->leaves();
    }
    
    if (right != 0) {
        ri = right->leaves();
    }
    
    return (le + ri);
}

int tree_node::min_value() const {
	int le, ri;
	
    if (type == NUMBER) {
        return value.number;
    }

    if (type == OPERATOR) {
        if (left != 0) {
            le = left->min_value();
        }
        
        if (right != 0) {
            ri = right->min_value();
        }
        
        return ((le < ri)? le : ri);
    }
}

bool tree_node::find(node_type t, tree_value v) const {
    bool  res = false;

	if (t == NUMBER && type == NUMBER) {
		return (value.number == v.number);
	}
	
	if ( (t == OPERATOR && type == OPERATOR) &&
		 (v.op == value.op) ) {
		return true;
	}
	
	if (left != 0) {
        res = left->find(t, v);
    }
    if(res == true){
         return res;
    }
    
    
    if (right != 0){
        res = right->find(t, v);
    }
    if(res == true){
         return res;
    }
    
    return false;
}

long tree_node::eval() const {
    long le  = 0, ri = 0;
    if(type == NUMBER){
        return value.number;
	} 	
	
	if (left != 0) {
        le = left->eval();
    }
    
    if (right != 0) {
        ri = right->eval();
    }
    
    switch(value.op){
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

void tree_node::remove_childs() {
    if (left != 0) {
        left->remove_childs();
        delete left;
        left = 0;
    }
    
    if (right != 0) {
        right->remove_childs();
        delete right;
        right = 0;
    }
}

tree_node* tree_node::copy() const {
    tree_node * new_node = new tree_node(type, value);
    
    if (left != 0) {
        new_node->left = left->copy();
    }
    
    if (right != 0) {
        new_node->right = right->copy();
    }
    
	return new_node;
}

class eval_tree {
private:
	tree_node *root;

	std::queue<std::string> tokenize(std::string);

public:
	eval_tree();
	eval_tree(std::string);
	~eval_tree();
	bool empty() const;
	int depth() const;
	std::string inorder() const;
	std::string postorder() const;
	std::string preorder() const;
	std::string breadth_order() const;
	int leaves() const;
	int min_value() const;
	bool find(node_type, tree_value) const;
	long eval() const;
	void removeAll();
};

eval_tree::eval_tree() {
    root = 0;
}

std::queue<std::string> eval_tree::tokenize(std::string str) {
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

eval_tree::eval_tree(std::string str) {
	root = 0;
	std::stack<tree_node*> s;
	std::queue<std::string> tokens = tokenize(str);
	std::string aux;
	tree_node *left, *right, *new_node;
	tree_value val;

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
			
			val.op = aux[0];
			new_node = new tree_node(OPERATOR, val, left, right);
			s.push(new_node);
		} else if (isdigit(aux[0])) {
			val.number = atoi(aux.c_str());
			new_node = new tree_node(NUMBER, val);
			s.push(new_node);
		}
	}
	new_node = s.top(); s.pop();
	if (!s.empty()) {
		throw IllegalAction();
	}
	root = new_node;
}

eval_tree::~eval_tree() {
    removeAll();
}

bool eval_tree::empty() const {
    return (root == 0);
}

int eval_tree::depth() const {
	if (empty()) {
        return 0;
    } else {
        return root->depth();
    }
}

std::string eval_tree::inorder() const {
	std::stringstream aux;
    if (!empty()) {
        root->inorder(aux);
	}
	return aux.str();
}

std::string eval_tree::preorder() const {
	std::stringstream aux;
    if (!empty()) {
        root->preorder(aux);
	}
	return aux.str();
}

std::string eval_tree::postorder() const {
	std::stringstream aux;
    if (!empty()) {
        root->postorder(aux);
	}
	return aux.str();
}

std::string eval_tree::breadth_order() const {
	std::stringstream aux;
	std::queue<tree_node*> q;

	if (!empty()) {
        q.push(root);
        while(!q.empty()){
            tree_node* node = q.front();
            q.pop();
            
            if (node->type == NUMBER) {
				aux << node->value.number << " ";
			} else {
				aux << node->value.op << " ";
			}
			
            if (node->left!=0) {
                q.push(node->left);
            }
            
            if (node->right!= 0) {
                q.push(node->right);
            }
        }
	}
	return aux.str();
}

int eval_tree::leaves() const {
    if (empty()) {
        return 0;
	} else {
       return root->leaves();
	}
}

int eval_tree::min_value() const {
    if (empty()) {
        throw IllegalAction();
	} else {
        return root->min_value();
	}
}

bool eval_tree::find(node_type t, tree_value v) const {
    if (empty()) {
        return false;
	} else {
        return root->find(t, v); 
	}
}

long eval_tree::eval() const {
	if (empty()) {
        throw IllegalAction();
	} else {
        return root->eval();
	}
}

void eval_tree::removeAll() {
    if (!empty()) {
        root->remove_childs();
        delete root;
        root = 0;
    }
}
#endif /* EVALTREE_H_ */
