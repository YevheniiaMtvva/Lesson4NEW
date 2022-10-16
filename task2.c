#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void help_print()
{
    printf("-h      Print help\n");
    printf("-o      Path to output file\n");
    printf("-c      No output mode\n");
}

int
main(int argc,char** argv)
{
    if(argc == 1)
    {
        printf("Opt test\n");
        printf("opts -h for help\n");

        return EXIT_SUCCESS;
    }

    char* opts = "hco:";

    int omode = 1;
    char* path_to_output;

    int opt;
    while( (opt = getopt(argc, argv, opts)) != -1)
    {
        switch (opt)
        {
            case 'h':
            {
                help_print();
                break;
            }

            case 'o':
            {
                strcpy(path_to_output, optarg);
                
                printf("-o opt: %c\n",opt);
                printf("Output path: %s\n",path_to_output);

                break;
            }

            case 'c':
            {
                omode = 0;
                printf("No output mode enabled, output path will be ignored!\n");
                break;
            }
        }
    }

}
