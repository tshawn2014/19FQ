#include <string>
#include <iostream>

using namespace std;

int gettypeofchar(const char &c){
	switch (c){
		case 33:case 37:case 38:case 42:case 43:case 45:
		case 60:case 61:case 62:case 124:
			return 'o'; // operators
		case 34: return 's'; //string
		case 39: return 'c'; //char
		case 35:case 40:case 41:case 46:
		case 58:case 59:case 91:case 93:case 123:case 125:
			return 't'; //special char
		case 47: return '/';//denote
		default: break;
	}
	if (c>48 && c<=57) return 'd'; //number 1-9
	else if (c == 48) return '0'; //number 0
	else if ((c>=65 && c<=90) || (c>=97 && c<=122) || c == 95) return 'a'; //alphabets
	else return 'u'; //other special char
}

int deal_with_state_0(string s, int& i, int& j){
	char type = gettypeofchar(s.at(j));
	if (type=='u'||type=='t'){ 
		if (type == 't') cout<<s.at(j)<<endl;
		i = ++j;
		return 0;
	}
	j++;
	switch(type){
		case '0': return 1;//number 0
		case 'd': return 2;//number 1-9
		case 'c': return 3;//char
		case 's': return 4;//string
		case 'o': return 5;//operator
		case 'a': return 6;//alpabet
		case '/': return 7;//denote
		default: return -1;
	}
}

int deal_with_state_1(int& i, int& j){
	i = ++j;
	cout<<'0'<<endl;
	return 0;
}

int deal_with_state_2(string s, int& i, int& j){
        char c;
        do{
                c = gettypeofchar(s.at(j));
                if (c == 'd' || c == '0') j++;
                else{
                        break;
                }
        }while(j<(int)s.size());
        if (j==(int)s.size()-1){
                cout<<s.substr(i,j-i+1)<<endl;
                i = ++j;
        } else {
                cout<<s.substr(i,j-i)<<endl;
                i = j;
        }
        return 0;
}

int deal_with_state_3(string s, int& i, int& j){
	if (j+2>=(int)s.size()) return -1;
	if (s.at(j) == '\'' && s.at(j+1)!='\''){
		cout<<"\'\'"<<endl;
		i = ++j;
		return 0;
	} else if (s.at(j+1) == '\''){
		cout<<s.substr(i,3)<<endl;
		j++;
		i = ++j;
		return 0;
	} else if(s.at(j)=='\\'&&s.at(j+2)=='\''){
		cout<<s.substr(i,4)<<endl;
		j = j+2;
		i = ++j;
		return 0;
	}
	return -1;
}

int deal_with_state_4(string s, int&i, int& j){
	int N = (int)s.size();
	while(j<N){
		if(s.at(j)=='"' &&s.at(j-1)!='\\'){
			cout<<s.substr(i,j-i+1)<<endl;
			i = ++j;
			return 0;
		}
		j++;
	}
	return -1;
}

int deal_with_state_5(string s,int&i, int& j){
	if ('o'==gettypeofchar(s.at(j))){
		cout<<s.substr(i,2)<<endl;
		i = ++j;
		return 0;
	} else {
		cout<<s.at(i)<<endl;
		j = ++i;
		return 0;
	}	
}

int deal_with_state_6(string s, int& i, int& j){
	while('a'==gettypeofchar(s.at(j))||'d'==gettypeofchar(s.at(j))) j++;
	cout<<s.substr(i,j-i)<<endl;
	i = j;
	return 0;
}

int deal_with_state_7(string s, int& i, int& j){
	if (gettypeofchar(s.at(j))=='o'&&s.at(j)!='*'){
		cout<<s.substr(i,2)<<endl;
		i = ++j;
		return 0;
	} else if(s.at(j)!='*'){
		cout<<s.at(i)<<endl;
		j = ++i;
		return 0;
	} else{
		while(j<(int)s.size()){
			if(s.at(j)=='/'&&s.at(j-1)=='*'){
				i = ++j;
				return 0;
			}
			j++;
		}
	}
	return -1;
}

int gettoken(string input){
	int i=0,j=0,N=(int)input.size(), state=0;
	while(j<N){
		switch(state){
			case 0: state = deal_with_state_0(input,i,j);break;//init
			case 1: state = deal_with_state_1(i,j);break;//number 0
			case 2: state = deal_with_state_2(input,i,j);break;//intgers
			case 3: state = deal_with_state_3(input,i,j);break;//char
			case 4: state = deal_with_state_4(input,i,j);break;//string
			case 5: state = deal_with_state_5(input,i,j);break;//operator
			case 6: state = deal_with_state_6(input,i,j);break;//alphabet
			case 7: state = deal_with_state_7(input,i,j);break;//denote
			default: printf("Syntax error.\n");return -1;
		}
	}
	return 0;
}

int main(){
	string input;
	do{
		getline(cin,input);
		input += " ";
		if(-1==gettoken(input)) break;
	}while(cin.peek()!=EOF);
	return 0;	
}
