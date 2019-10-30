#include "my_ls.h"

int main(int argc, char **argv){
        if (argc==1){
                go_into_dir(".",0);
                return 0;
        }
        check_list(argc, argv);
        return 0;
}

