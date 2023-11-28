#include<iostream>
#include<iomanip>
#include<string>
#include"Ham_ngoai.cpp"
#include<fstream>
#ifndef __node__cpp__
#define __node__cpp__
using namespace std;
typedef long long ll;
typedef double db;
typedef string str;

template<class keys,class T>
class node{
private:
	node *parent,*left,*right;
	keys key;
	T data;
public:
	node(){
		this->left=this->right=this->parent=nullptr;
	}
	node(keys k,T e){
		this->left=this->right=this->parent=nullptr;
		this->key=k;this->data=e;
	}
	node *&get_left(){	return this->left;	}
	node *&get_right(){	return this->right;	}
	node *&get_parent(){return this->parent;}
	T &get_data(){		return this->data;	}
	keys &get_key(){	return this->key;	}
	bool has_left(){	return this->left!=nullptr;		}
	bool has_right(){	return this->right!=nullptr;	}
	bool has_parent(){	return this->parent!=nullptr;	}
};
#endif
