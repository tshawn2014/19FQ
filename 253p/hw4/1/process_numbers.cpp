#include <fstream>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <string>

using namespace std;

int main(){
	ifstream in("random_numbers.txt");
	if (!in) {cout<<"File open error!\n";return 1;}
	ofstream out_odd("odd.txt"), out_even("even.txt");
	copy_if(istream_iterator<string>(in), istream_iterator<string>(),ostream_iterator<string>(out_odd," "), [](string i){return stoi(i)&1;}); 
	in.clear();
	in.seekg(0, in.beg);
	copy_if(istream_iterator<string>(in), istream_iterator<string>(),ostream_iterator<string>(out_even," "), [](string i){return !(stoi(i)&1);}); 
	in.close();
	return 0;
}
