#ifndef _MY_LS_H
#define _MY_LS_H
const char* dtos(int mon);
void show_stat(char *filename, int indent);
void go_into_dir(char *filename, int indent);
void check_list(int argc, char **argv);
#endif
