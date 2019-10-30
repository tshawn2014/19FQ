#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string scheme(string s){
	size_t found;
	found = s.find("://");
	if (found == string::npos) return s;
	cout<<"scheme:"<<s.substr(0,found)<<endl;
	return s.substr(found+3);
}

string domain(string s){
	size_t found;
	if (s=="") return s;
	found = s.find(":");
	if (found == string::npos) found = s.find("/");
	if (found == string::npos){ 
		cout<<"domain:"<<s<<endl;
		return "";
	} else {
		cout<<"domain:"<<s.substr(0,found)<<endl;
		return s.substr(found);
	}
	
}

void remain(string s){
	size_t found[] = {s.find(':'),s.find('/'),s.find('?'),s.find('#')};
	size_t small;
	if (found[0] != string::npos){
		small = *min_element(found+1,found+4);
		cout<<"port:"<<s.substr(found[0]+1, small==string::npos?small:small-found[0]-1)<<endl;
	}
	if (found[1] != string::npos){
		small = *min_element(found+2,found+4);
		cout<<"path:"<<s.substr(found[1]+1, small==string::npos?small:small-found[1]-1)<<endl;
	}	
	if (found[2] != string::npos){
		small = *min_element(found+3,found+4);
		cout<<"query_string:"<<s.substr(found[2]+1, small==string::npos?small:small-found[2]-1)<<endl;
	}
	if(found[3] != string::npos){
		cout<<"fragment_id:"<<s.substr(found[3]+1)<<endl;
	}
}

int main(){
	string input;
	do{
		getline(cin, input);
		input = scheme(input);
		if (input=="") continue;
		input = domain(input);
		if (input=="") continue;
		remain(input);
		cout<<endl;
	}while (cin.peek()!=EOF);
	return 0;
}
