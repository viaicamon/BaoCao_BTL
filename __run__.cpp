#include<iostream>
#include"Dictionary.cpp"
#include<conio.h>
#ifndef __App_Dictionary__cpp__
#define __App_Dictionary__cpp__
class App_Dictionary{
private:
	Dictionary a;
public:
	App_Dictionary(){}
	int menu(){
		int n;		
		cout<<"Vui long thuc hien cac thao tac sau: \n";
		cout<<"1. Doc danh sach file!\n";
		cout<<"2. Ghi tu dien trong cay vao file!\n";
		cout<<"3. Them tu moi!\n";
		cout<<"4. Xoa tu!\n";
		cout<<"5. Cap nhat lai ngghia mot tu!\n";
		cout<<"6. Tim kiem mot tu trong cay!\n";
		cout<<"0. Thoat!\n";
		cout<<"Lua chon cua ban: ";cin>>n;cin.ignore();		
		return n;
	}
	int chon_4(){
		int n;
		cout<<"1. Xoa tu theo tu tieng Anh!\n";
		cout<<"2. Xoa tu theo tu tieng Viet!\n";
		cout<<"Phim bat ki de thoat!\n";
		cout<<"Vui long chon: ";cin>>n;cin.ignore(1e9,'\n');
		return (n==1||n==2)?n:-1;
	}
	int chon_5(){
		int n;
		cout<<"1. Cap nhat lai nghia tu theo tu tieng Anh!\n";
		cout<<"2. Cap nhat lai nghia tu theo tu tieng Viet!\n";
		cout<<"Phim bat ki de thoat!\n";
		cout<<"Vui long chon: ";cin>>n;cin.ignore(1e9,'\n');
		return (n==1||n==2)?n:-1;
	}
	int chon_6(){
		int n;
		cout<<"1. Tim kiem theo tu tieng Anh!\n";
		cout<<"2. Tim kiem theo ngghia tu!\n";
		cout<<"Phim bat ki de thoat!\n";
		cout<<"Vui long chon: ";cin>>n;cin.ignore(1e9, '\n');
		return (n==1||n==2)?n:-1;
	}
	void run(){
		int chon,check=0;
		do{
			do{
				chon=menu();
			}while( chon > 6 || chon < 0 );
			switch(chon){
				case 1:{//	Doc file
					str s;
					cout<<"Nhap ten file ban muan doc: ";getline(cin,s);
					a.input(s);
					break;
				}
				case 2:{//	ghi tu dien vao file
					str s;
					cout<<"Nhap ten file ban muan luu(neu khong co se tu tao file moi): ";getline(cin,s);
					a.output(s);
					break;
				}
				case 3:{//	them moi mot tu
					a.add(); 
					break;
				}
				case 4:{//	Xoa 1 tu
					int n=chon_4();
					if(n==-1)	break;
					switch(n){
						case 1:{
							a.deleteWord_EN();
							break;
						}
						case 2:{
							a.deleteWord_VN();
							break;
						}
					}
					break;
				}
				case 5:{//	cap nhat lai tu
					int n=chon_5();
					if(n==-1)	break;
					switch(n){
						case 1:{
							a.uppdate_EN();
							break;
						}
						case 2:{
							str s1, s2;
							cout<<"Nhap nghia tu ban muan cap nhat: ";getline(cin,s1);
							cout<<"Nhap nghia ma ban muan thay cho tu "<<s1<<" : ";getline(cin,s2);
							a.uppdate_VN(s1,s2);
							break;
						}
					}
					break;
				}
				case 6:{//	Tim kiem tu
					int n=chon_6();
					if(n==-1)	break;
					switch(n){
						case 1:{
							str s;cout<<"Nhap tu ban muan tim kiem: ";getline(cin,s);
							a.search_EN(s);
							break;
						}
						case 2:{
							a.search_VN();
							break;
						}
					}
					break;
				}
				default:{//	thoat
					cout<<"Xin chao va hen gap lai!";
					return;
					break;
				}		
			}
			getch();
			system("cls");
		}while( chon <= 6 && chon > 0 );
	}
};
#endif
