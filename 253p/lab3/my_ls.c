#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <string.h>
#include <dirent.h>

const char* dtos(int mon){
	switch(mon){
		case 1: return "Jan";
		case 2: return "Feb";
		case 3: return "Mar";
		case 4: return "Apr";
		case 5: return "May";
		case 6: return "Jun";
		case 7: return "Jul";
		case 8: return "Aug";
		case 9: return "Sep";
		case 10: return "Oct";
		case 11: return "Nov";
		case 12: return "Dec";
		default: return "";
	}
}

void show_stat(char *path, char *filename, int indent);

void go_into_dir(char *path, char *filename, int indent){
	struct dirent *de= NULL;
	DIR *dr = opendir(filename);
	if (dr == NULL){
		printf("Could not open current dir\n");
		return;
	}
	while ((de = readdir(dr)) != NULL){
		if (strcmp(de->d_name,".")==0 || strcmp(de->d_name,"..")==0) continue;
		show_stat(path, de->d_name, indent+1);
	}
	closedir(dr);
}

void show_stat(char *path, char *filename, int indent){
	struct stat buffer;
	struct passwd *pws = NULL;
	struct tm dt;
	int p;
	char *integrated_filename = "/";
	intgrated_filename = strcat(path,integrated_filename);
	intgrated_filename = strcat(integrated_filename,filename);
	p = stat(integrated_filename, &buffer);
	for (int i = 0; i <indent;i++){
                printf("    ");
        }
	if (p != 0){
		printf("Unable to get stat of %s\n", filename);
		return;
	}
	printf(S_ISDIR(buffer.st_mode)?"d":"-");
	printf(buffer.st_mode & S_IRUSR?"r":"-");
	printf(buffer.st_mode & S_IWUSR?"w":"-");
	printf(buffer.st_mode & S_IXUSR?"x":"-");
	printf(buffer.st_mode & S_IRGRP?"r":"-");
	printf(buffer.st_mode & S_IWGRP?"w":"-");
	printf(buffer.st_mode & S_IXGRP?"x":"-");
	printf(buffer.st_mode & S_IROTH?"r":"-");
	printf(buffer.st_mode & S_IWOTH?"w":"-");
	printf(buffer.st_mode & S_IXOTH?"r":"-");
	printf("\t%d", buffer.st_nlink);
	printf("\t%s", getpwuid(buffer.st_uid)->pw_name);
	printf("\t%s", getgrgid(buffer.st_gid)->gr_name);
	printf("\t%d", buffer.st_size);
	dt = *(gmtime(&buffer.st_mtime));
	printf("\t%s %d %d:%d", dtos(dt.tm_mon), dt.tm_mday, dt.tm_hour,dt.tm_min);
	printf("\t%s\n", filename);
	if(S_ISDIR(buffer.st_mode)){
		go_into_dir(filename, 0);
	}
}

void check_list(int argc, char **argv){
	struct stat buffer;
	int i;
	for (i=1;i<argc;i++){
		if (stat(argv[i], &buffer) != 0) printf("%s doesn't exist.\n", argv[i]);
		 else show_stat("."argv[i], 0);
	}
}	

/*
int main(int argc, char **argv){
	if (argc==1){
		char current[] = ".";
		go_into_dir(current,0);
		return 0;
	}
	check_list(argc, argv);
	return 0;
}
*/
