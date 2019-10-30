#include <cstdio>
#include <unordered_map>
#include <cstdlib>

#define require(e) if (!(e)) fprintf(stderr, "FAILED line %d        %s: %s       %s\n", __LINE__, __FILE__, __func__, #e)

using namespace std;

char *remain = nullptr;

size_t strlen(const char *s){
	size_t num = 0;
	if (s == nullptr) {
		printf("NULL pointer input!\n");
		return 0;
	}
	while(s[num] != '\0') num++;
	return num;
}

char *strcpy(char *dest, const char *src){ // return a pointer to dst. 
	size_t num;
	if (src == nullptr) {
		dest = nullptr;
		return nullptr;
	} else if(dest == nullptr){
		printf("NULL pointer input!\n");
		return nullptr;
	}
	for(num=0;src[num] != '\0';num++) dest[num] = src[num];
	dest[num] = '\0';
	return dest;
}

char *strncpy(char *dest, const char *src, size_t n){
	size_t i =0;
        if (src == nullptr) {
                dest = nullptr;
                return nullptr;
        } else if(dest == nullptr){
                printf("NULL pointer input!\n");
                return nullptr;
        }
	for(;src[i]!='\0' && i<n;i++) dest[i] = src[i];
	dest[i] = '\0';
	return dest;	
}

int strcmp(const char *str1, const char *str2){
	int i = 0;
	if (str1 == nullptr || str2 == nullptr){
		printf("Input string is null.\n");
	}
	while(str1[i]!='\0' && str2[i]!='\0' && str1[i] == str2[i]) i++;
	return str1[i] - str2[i];
}

char *strcat(char *dest, const char *src){
	int i = 0, j = 0;
	if (src == nullptr) return dest;
	char *new_dest;
	new_dest = (char*)malloc(strlen(dest)+strlen(src)+1);
	for(;dest[i] != '\0';i++) new_dest[i] = dest[i];
	for(;src[j] != '\0';i++,j++) new_dest[i] = src[j];
	new_dest[i] = '\0';
	return new_dest;
}

int strncmp(const char *str1, const char *str2, size_t n){
	size_t i = 0;
	if(n==0) return 0;
	if (str1 == nullptr || str2 == nullptr){
		printf("Input string is null!\n");
	}
	while(i<n && str1[i]!='\0' && str2[i]!='\0' && str1[i] == str2[i]) i++;
	return i==n?str1[i-1] - str2[i-1]:str1[i]-str2[i];
}

char *strchr(char *str, int character){
	if (str == nullptr){
		printf("Input string is null!\n");
	}
	char *pointer = str;
	while(*pointer!='\0'){
		if(*pointer == character) return pointer;
		pointer++;
	}
	return nullptr;
}

const char *strchr(const char *str, int character){
        if (str == nullptr){
                printf("Input string is null!\n");
        }
	const char *pointer = str;
	while(*pointer!='\0'){
		if(*pointer == character) return pointer;
		pointer++;
	}
	return nullptr;
}

char *strpbrk(char *str1, const char *str2){
	// fastest way is to use a hash map
        if (str1 == nullptr || str2 == nullptr){
                printf("Input string is null!\n");
        }
	unordered_map<int, bool> m;
	for(int i = 0;str2[i]!='\0';i++) m[str2[i]] = true;
	for(;*str1!='\0';str1++)
		if (m.find(*str1)!=m.end()) return str1;
	return nullptr;	
}

const char *strpbrk(const char *str1, const char *str2){
        if (str1 == nullptr||str2 == nullptr){
                printf("Input string is null!\n");
        }
	unordered_map<int, bool> m;
	for(int i = 0;str2[i]!='\0';i++) m[str2[i]] = true;
	for(;*str1!='\0';str1++)
		if(m.find(*str1)!=m.end()) return str1;
	return nullptr;
}

char *strstr(char *str1, const char *str2){//str1 is the haystack, str2 is the needle
	int N = strlen(str1), M = strlen(str2), i=0,j;
	for (;i<N-M+1;i++){
		for(j=0;j<M;j++){
			if(*(str1+i+j)!=*(str2+j)) break;
			if (j==M-1) return str1+i;
		}
	}
	return nullptr;
}

const char *strstr(const char *str1, const char *str2){
	int N = strlen(str1), M = strlen(str2), i=0,j;
	for (;i<N-M+1;i++){
		for(j=0;j<M;j++){
			if(*(str1+i+j)!=*(str2+j)) break;
			if (j==M-1) return str1+i;
		}
	}
	return nullptr;
}

size_t strspn(const char *str, const char *set){
	int i = 0;
	unordered_map<int, bool> m;
	for (int c=0;set[c]!='\0';c++) m[set[c]] = true;
	for(;*str!='\0';str++)
		if(m.find(*str)!=m.end()) i++;
	return i;
}

char *strtok(char *str, const char *delimiters){
	unordered_map<int,bool> m;
	if (str==nullptr && remain==nullptr){
		return nullptr;
	} else if (str==nullptr) str = remain;
	for (int i = 0;delimiters[i];i++) m[delimiters[i]] = true;
	while(m.find(*str)!=m.end()) str++;
	char *temp = nullptr;
	for(int i = 0;str[i] !='\0';i++){
		if(m.find(str[i])!=m.end()){
			temp = str+i;
			break;
		}
	}
	if (temp == nullptr) return nullptr;
	if (*(temp)!='\0'&&*(temp+1)!='\0') remain = temp+1;
	*temp = '\0';
	return str; 
}

void test_strcmp(){
	char a_array[] = "hello",b_array[] = "hello", c_array[] = "he";
	char *a = a_array, *b = b_array, *c = c_array;
	require(strcmp(a,b)==0);
	require(strcmp(c,a)<0);
	require(strcmp(a,c)>0);
	require(strcmp("","abc")<0);
}

void test_strlen(){
        require(strlen("")==0);
        require(strlen("hello")==5);
        require(strlen("this\0")==4);
}

void test_strcpy(){
	char src_array[] = "source";
	char *src = src_array, *dest;
	dest = (char *)malloc(sizeof(src));
	require(strcmp(strcpy(dest,src),src)==0);
	require(strcmp(strcpy(dest,""),"")==0);
	require(strcmp(strcpy(dest,"Lol"),"Lol")==0);
	free(dest);
}

void test_strcat(){
	char dest1_array[] = "\0", dest2_array[] = "hello";
	char *dest1 = dest1_array, *dest2 = dest2_array;
	dest1 = strcat(dest1, dest2);
	require(strcmp(dest1,"hello")==0);
	free(dest1);
	dest1 = dest1_array;
	dest2 = strcat(dest2,dest1);
	require(strcmp(dest2,"hello")==0);
	free(dest2);
	dest2 = dest2_array;
	char dest3_array[] = "abc", *dest3 = dest3_array;
	dest3 = strcat(dest3,dest2);
	require(strcmp(dest3,"abchello")==0);
	free(dest3);
}

void test_strncmp(){
	char a_array[] = "hello", b_array[] = "hell", c_array[] = "";
	char *a = a_array, *b = b_array, *c = c_array;
	require(strncmp(a,b,1)==0);
	require(strncmp(a,c,5)>0);
	require(strncmp(a,b,4)==0);
	require(strncmp("love","lose",2)==0);
	require(strncmp(a,"he",2)==0);
}

void test_strchr(){
	char a[] = "abcdefg", b[] = "";
	require(*strchr(a,'a')=='a');
	require(*strchr("abcdefg",'g')=='g');
	require(strchr(a,'h')==nullptr);
	require(strchr(b,'a')==nullptr);
}

void test_strpbrk(){
	char a[] = "abcdefg", b[] = "de", c[] = "";
	require(strcmp(strpbrk(a,b),"defg")==0);
	require(strpbrk(a,c)==nullptr);
	require(strcmp(strpbrk("helloworld","word"),"oworld")==0);
}

void test_strstr(){
	char haystack[] = "abcdabcdabcde",needle[] = "abcde";
	require(strcmp(strstr("abcdabcdabcde",needle),"abcde")==0);
	require(strcmp(strstr(haystack,"cda"),"cdabcdabcde")==0);
	require(strstr(haystack,"")==nullptr);
	require(strstr(haystack,"fabc")==nullptr);
}

void test_strspn(){
	char str[] = "1234hahah23", set[] = "1234567890";
	require(strspn(str,set)==6);
	require(strspn("sadfas","")==0);
	require(strspn("1234hahah23", "ha")==5);
}

void test_strtok(){
	char str[] = "- This, a sample string.", *pch, nodelimiters[] = "nodelimiters";
	require(strtok(nodelimiters, ",.- ")==nullptr);
	require(strcmp(pch=strtok(str, ".,- "),"This")==0);
	require(strcmp(pch=strtok(nullptr, ".,- "),"a")==0);
}

int main(){
	test_strlen();
	test_strcmp();
	test_strcpy();
	test_strcat();
	test_strncmp();
	test_strchr();
	test_strpbrk();
	test_strstr();
	test_strspn();
	test_strtok();
	return 0;
}
