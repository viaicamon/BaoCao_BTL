#include<iostream>
#include"Tree_BS.cpp"
#include"Ham_ngoai.cpp"

class Dictionary{
private:
	Tree_BS<str,str> tree_D;
public:
//	Cac phuong thuc khoi tao:
	Dictionary(){}
	Dictionary(ifstream &f){
		ll n;f>>n;f.ignore();
		str s,s1,s2;
		for(ll i=0;i<n;i++){
			getline(f,s);(s,s1,s2);
			tree_D.add(s1,s2);
		}
	}
	Dictionary(str tenfile){
		ifstream f(tenfile);
		ll n;f>>n;f.ignore();
		str s,s1,s2;
		for(ll i=0;i<n;i++){
			getline(f,s);cutWord(s,s1,s2);
			tree_D.add(s1,s2);
		}
		f.close();
	}
//	Cac phuong thuc kiem tra va xem so tu:
	ll size(){
		return tree_D.size();
	}
	bool empty(){
		return tree_D.empty();
	}
//	Cac phuong thuc nhap:
	void add(){
		str s1,s2;
		s1=input_word("tu tieng Anh");
		s2=input_word("tu tien Viet");
		tree_D.add(s1,s2);
	}
	void input(){
		ll n;cout<<"Nhap so luong tu vung ban muan them: ";cin>>n;cin.ignore();
		for(ll i=0;i<n;i++){
			add();
		}
	}
	void input(ifstream &f){
		ll n;f>>n;f.ignore();
		str s,s1,s2;
		for(ll i=0;i<n;i++){
			getline(f,s);cutWord(s,s1,s2);
			tree_D.add(s1,s2);
		}
	}
	void input(str tenfile){
		ifstream f(tenfile);
		ll n;f>>n;f.ignore();
		str s,s1,s2;
		for(ll i=0;i<n;i++){
			getline(f,s);cutWord(s,s1,s2);
			tree_D.add(s1,s2);
		}
		f.close();
	}
	void uppdate_EN(str s1,str s2){
		tree_D.uppdate_key(s1,s2);
	}
	void uppdate_EN(){
		str s1,s2;
		cout<<"Nhap tu ban muan thay doi: ";getline(cin,s1);
		tree_D.search_key(s1);
		if(!tree_D.TF_search_key(s1)){
			return;
		}
		cout<<"Nhap nghia ban muan cap nhat: ";getline(cin,s2);
		tree_D.uppdate_key(s1,s2);
	}
	void uppdate_VN(str s1,str s2){
		tree_D.uppdate_data(s1,s2);
	}
//	Cac ham xuat:
	void print(){
		cout<<tree_D.size()<<endl;
		tree_D.inOrder();
	}
	void output(ofstream &f){
		f<<"So tu: "<<tree_D.size()<<".\n";
		tree_D.inOrder(f);
	}
	void output(str s){
		ofstream f(s);
		f<<tree_D.size()<<"\n";
		tree_D.inOrder(f);
		f.close();
	}
//	Ham tim kiem:
	void search_EN(){
		str s;
		cout<<"Nhap tu ban muan tra nghia: ";getline(cin,s);
		tree_D.search_key(s);
	}
	void search_VN(){
		str s;
		cout<<"Nhap tu ban muan tra nghia: ";getline(cin,s);
		tree_D.search_data(s);
	}
	void search_EN(str s){
		tree_D.search_key(s);
	}
//	Ham xoa tu:
	void deleteWord_EN(){
		str s;
		cout<<"Nhap tu ban can xoa: ";getline(cin,s);
		tree_D.remove(s);
	}
	void deleteWord_VN(){
		str s;
		cout<<"Nhap nghia cua tu ban can xoa: ";getline(cin,s);
		tree_D.remove_data(s);
	}
};

//int main(){
//	Dictionary a;
//	a.input("hehe.txt");
//	a.print();
//	cout<<">=============================<\n";
////	a.uppdate_EN("begin","nhanh len");
////	a.deleteWord_VN();
//	ofstream f("hihi.txt");
//	a.output(f);
//	f.close();
////	a.print();
//	
//	return 0;
//}
