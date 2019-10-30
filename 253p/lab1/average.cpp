#include <cstdio>
#include <cstdlib>
#include <cstring>

#define NUM_MAX_LEN 20

using namespace std;

bool check_init_input(int args, char ** argv){
        if(args !=  2){
                printf("Wrong number of arguments!\n");
                return false;
	}
	return true;
}

FILE * read_file(FILE * fp, char * file_name){
	if(!(fp = fopen(file_name, "r")))
		printf("Failed to open or file doesn't exit!\n");
	return fp;
}

double get_average(FILE * fp){
	int num = 0;
	double sum = 0.0, temp = 0.0;
	char in[NUM_MAX_LEN+1] = {0}, *pEnd = nullptr;
	while(!feof(fp)){
		memset(in, 0, sizeof(in));
		fgets(in, sizeof(in)-1,fp);
		if (in[0]<48 ||  in[0]>57){
			printf("Ignore one line!\n");
			continue;
		}
		temp = strtod(in,&pEnd);
		if (pEnd[0] == '\0'||pEnd[0] == '\n'){
			sum += temp;
			num++;
		} else {
			printf("Special character in one line, ignore.\n");
		} 
	}
	pEnd = nullptr;
	return num?sum/num:0;	
}

int main(int args, char ** argv){
	if(!check_init_input(args, argv)) return 1;
	double * array = nullptr;
	char * file_name = argv[1];
	FILE * fp;
	file_name = argv[1];
	if(!(fp = read_file(fp, file_name))) return 1;
	printf("The average in file '%s' is %lf\n",argv[1],  get_average(fp));
	fclose(fp);
	return 0;
}
