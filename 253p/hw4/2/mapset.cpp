#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <map>
#include <set>

using namespace std;

static set<string> exclude;
static map<string, int> frequency;	
//static ofstream file;

struct t{
	void operator()(string s){
		if (exclude.find(s)==exclude.end()) return;
		if (frequency.find(s) == frequency.end()) frequency[s] = 1;
		else frequency[s]++;
	}
}counter;
int main(){
	ifstream sample("sample_doc.txt"), stopwords("stopwords.txt");
	if (!sample || !stopwords) { cout<<"Open file error!\n"; return 1;}
	copy(istream_iterator<string>(stopwords), istream_iterator<string>(), inserter(exclude,begin(exclude)));
	stopwords.close();
	for_each(istream_iterator<string>(sample), istream_iterator<string>(),counter);
	sample.close();
	//file.open("frequency.txt");
	ofstream file("frequency.txt");
	for_each(frequency.begin(),frequency.end(),[&file](pair<string, int> el){
		cout<<el.first<<" - "<<el.second<<endl;
		file<<el.first<<" - "<<el.second<<endl;
	});
	file.close();
	return 0;
}
