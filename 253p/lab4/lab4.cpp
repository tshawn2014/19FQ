#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

void product(vector<int> input, vector<string> &output){
	int N = (int)input.size();
	int *left = new int[N], *right = new int[N];
	left[0] = right[N-1] = 1;
	for (int i = 1;i<N;i++){
		left[i] = left[i-1]*input.at(i-1);
		right[N-i-1] = right[N-i]*input.at(N-i);
	}
	for (int i = 0;i<N;i++){
		output.push_back(to_string(left[i]*right[i]));
	}
	delete[] left;
	delete[] right;
}

int main(int argc, char **argv){
	vector<int> input;
	vector<string> output;
	if (argc <= 2) {
		cout<<"Wrong input"<<endl;
		return 1;
	}
	for(int i=1;i<argc;i++) input.push_back(stoi(argv[i]));
	product(input, output);
	copy(output.begin(),output.end(),ostream_iterator<string>(cout, " "));
	return 0;
}

