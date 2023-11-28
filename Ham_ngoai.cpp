#include<bits/stdc++.h>
#ifndef __Ham_ngoai__cpp__
#define __Ham_ngoai__cpp__

using namespace std;
using ll  = long long;
using db  = double;
using str = string;

// Cac ham bool 
bool KT_KT(char s){
	if(s>=65&&s<=90){
		return true;
	}else if(s>=97&&s<=122){
		return true;
	}else if(s==32){
		return true;
	}else if(s>=48&&s<=57){
		return true;
	}else if(s==39){
		return true;
	}
	return false;
}
bool KT_Chuoi(str s){
	for(ll i=0;i<s.length();i++){
		if(!KT_KT(s[i])){
			return false;
		}
	}
	return true;
}
bool operator==(str s1,str s2){
	return s1.compare(s2)==0;
}

// Cac ham str
str all_upper(str s){
	for(ll i=0;i<s.length();i++){
		if(s[i]<=122&&s[i]>=97){
			s[i]=s[i]-32;
		}
	}
	return s;
}
str all_lower(str s){
	for(ll i=0;i<s.length();i++){
		if(s[i]<=90&&s[i]>=65){
			s[i]=s[i]+32;
		}
	}
	return s;
}
str deleteSpace(str s){
	return (s[0]==' ')?s.substr(1,s.length()):s;
}

// Cac ham void
void cutWord(str s,str &s1,str &s2){
	ll k=0;
	bool found=false;
	while(found==false){
		if(s[k]==':'){
			found=true;
		}else{
			k++;
		}
	}
	s1=s.substr(0,k);
	s2=s.substr(k+1,s.length());s2=deleteSpace(s2);
}

// Cac ham input
str input_word(str ss){
	str s;
	cout<<"Nhap "<<ss<<" ban muan them: ";
	getline(cin,s);
	while(!KT_Chuoi(s)){
		cout<<"Vui long khong nhap ki tu dac biet (tru: \"-\", \"'\"):";
		getline(cin,s);
	}
	return all_lower(s);
}

#endif


