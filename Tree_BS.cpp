#include<iostream>
#include<iomanip>
#include<string>
#include"Ham_ngoai.cpp"
#include"node.cpp"
#include<fstream>
#ifndef __Tree_BS__cpp__
#define __Tree_BS__cpp__
using namespace std;
typedef long long ll;
typedef double db;
typedef string str;

template<class keys,class T>
class Tree_BS{
private:
	node<keys,T> *root;
	ll num;
public:
	Tree_BS(){	root=nullptr;	num=0;	}
	ll size(){	return this->num;		}
	bool empty(){	return root==nullptr;	}
//	Them 1 node
	void add(keys k,T e){	root=add(root,k,e);num++;	}
	node<keys,T>*add(node<keys,T> *r,keys k,T e){
		node<keys,T> *newNode=new node<keys,T>(k,e);
		node<keys,T> *current;
		node<keys,T> *p;
		if(r==nullptr)			return newNode;
		else{
			current=r;
			p=nullptr;
			while(1){
				p=current;
				if(k<p->get_key()){
					current=current->get_left();
					if(current==nullptr){
						p->get_left()=newNode;
						newNode->get_parent()=p;
						return r;
					}
				}else{
					current=current->get_right();
					if(current==nullptr){
						p->get_right()=newNode;
						newNode->get_parent()=p;
						return r;
					}
				}
			}
		}
	}
//	Cac phuong thuc de tim node - tim phan tu theo key hoac theo data
	//	Tim theo key:
	void search_key(keys k){
		node<keys,T> *p=search_key(root,k);
		if(p)	cout<<p->get_key()<<": "<<p->get_data()<<endl;
		else	cout<<"Khong co phan tu can tim!\n";
	}	
	bool TF_search_key(keys k){//	Kiem tra xem co key trong tree ko
		return (search_key(root,k))?true:false;
	}
	node<keys,T> *search_key(node<keys,T> *r,keys k){//	Phuong thuc tim kiem chinh
		if(r==nullptr)						return nullptr;
		else{
			if(k>r->get_key())				return search_key(r->get_right(),k);
			else if(k==r->get_key())		return r;
			else if(k<r->get_key())			return search_key(r->get_left(),k);
		}
	}
	//	Tim kiem theo data:
	void search_data(T e){
		node<keys,T> *p;
		search_data(root,e,p);
		if(p)	cout<<p->get_key()<<": "<<p->get_data()<<endl;
		else	cout<<"Khong co phan tu can tim!\n";
	}
	void search_data(node<keys,T> *r,T e,node<keys,T> *&p){//	Phuong thuc chinh
		if(r==nullptr)		return;
		else{
			if(r->get_data()==e)	p=r;
			if(r->has_left())	search_data(r->get_left(),e,p);		
			if(r->get_right())	search_data(r->get_right(),e,p);
		}
	}
//	Tim node trai hoac phai nhat:	
	node<keys,T> *get_mostLeft(node<keys,T> *r){// 	Tim node trai nhat
		node<keys,T> *p=r;
		while(p->has_left())		p=p->get_left();		
		return p;
	}	
	node<keys,T> *get_mostRight(node<keys,T> *r){//	Tim node phai nhat
		node<keys,T> *p=r;
		while(p->has_right())		p=p->get_right();		
		return p;
	}
//	Xoa 1 phan tu khoi cay:
	//	Xoa 1 phan tu theo key:
	void remove(node<keys,T> *r){
		node<keys,T> *p;
		if(!r->has_right() && !r->has_left()){
			p=r->get_parent();
			if(p!=nullptr){
				if(r==p->get_left())		p->get_left()=nullptr;
				else						p->get_right()=nullptr;
			}
		}else if(r->has_left() && !r->has_right()){
			p=r->get_parent();
			if(p->get_left()==r)			p->get_left()=r->get_left();
			else							p->get_right()=r->get_left();
		}else{
			p=r->get_parent();
			if(p->get_right()==r)			p->get_right()=r->get_right();
			else							p->get_left()=r->get_right();
		}
		delete r;
	}
	void remove(keys k){
		node<keys,T> *p=search_key(root,k);
		if(p==nullptr)				return;
		if(p->has_right() && p->has_left()){
			node<keys,T> *mostLeft=get_mostLeft(p->get_right());
			p->get_data() = mostLeft->get_data();
			p->get_key()  = mostLeft->get_key();
			remove(mostLeft);
		}else			remove(p);
		num--;
	}
	//	Xoa theo data:
	void remove_data(T e){
		node<keys,T> *p;
		search_data(root,e,p);
		remove(p->get_key());
	}
//	Uppdate cac data cua node:
	//	uppdate theo key:
	void uppdate_key(keys k,T e){
		node<keys,T> *p=search_key(root,k);
		if(p){
			cout<<"Cap nhat thanh cong!\n";
			p->get_data()=e;
		}else	cout<<"Khong co thong tin!\n";
	}
	//	uppdate theo data:
	void uppdate_data(T e1,T e2){
		uppdate_data(root,e1,e2);
	}
	void uppdate_data(node<keys,T> *r,T e,T e2){
		node<keys,T> *p=nullptr;
		if(r==nullptr)			return;
		else{
			uppdate_data(r->get_left(),e,e2);
			if(r->get_data()==e)	r->get_data()=e2;
			uppdate_data(r->get_right(),e,e2);
		}
	}
//	Cac phuong thuc duyet phan tu: 	
	void inOrder(){//	Duyet phan tu ra ngoai man hinh
		ll i=0;	inOrder(root,i);cout<<endl;
	}
	void preOrder(){
		ll i=0;	preOrder(root,i);cout<<endl;
	}
	void postOrder(){
		ll i=0;	postOrder(root,i);cout<<endl;
	}
	void inOrder(node<keys,T> *r,ll i){
		if(r!=nullptr){
			inOrder(r->get_left(),i++);
			cout<<left<<setw(20)<<r->get_key()<<": "<<r->get_data()<<endl;
			inOrder(r->get_right(),i++);
		}
	}
	void preOrder(node<keys,T> *r,ll i){
		if(r!=nullptr){
			cout<<left<<setw(20)<<r->get_key()<<": "<<r->get_data()<<endl;
			preOrder(r->get_left(),i++);
			preOrder(r->get_right(),i++);
		}
	}
	void postOrder(node<keys,T> *r,ll i){
		if(r!=nullptr){
			postOrder(r->get_left(),i++);
			postOrder(r->get_right(),i++);
			cout<<left<<setw(20)<<r->get_key()<<": "<<r->get_data()<<endl;
		}
	}
	void inOrder(ofstream &f){//	Duyet phan tu vao file
		inOrder(root,f);
	}
	void inOrder(node<keys,T> *r,ofstream &f){
		if(r!=nullptr){
			inOrder(r->get_left(),f);
			f<<r->get_key()<<": "<<r->get_data()<<endl;
			inOrder(r->get_right(),f);
		}
	}
	
};
#endif

//int main(   ){
//	Tree_BS<str,str> a;
//	a.add("hello","xin chao");
//	a.add("how much","bao nhieu");
//	a.add("how ofen","tan suat");
//	a.add("add","cong");
//	a.add("in","trong");
//	a.add("on","tren");
//	a.inOrder();
//	
//	a.uppdate_data("cong", "cong them");
//	a.uppdate_key("in", "ben trong");
//	a.inOrder();
//	a.search_data("ben trong");
//	return 0;
//}
