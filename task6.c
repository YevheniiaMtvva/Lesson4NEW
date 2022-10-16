//#include <bits/getopt_core.h>
//#include <bits/getopt_core.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

extern char** environ;

void help_print()
{
    printf("-h                  Print help and exit\n");
    printf("-e [ENV_NAME]       Gets name of environment variable\n");
    printf("-v [ENV_VALUE]      Gets value for variable\n");
}

int
main(int argc, char** argv)
{
    if(argc == 1)
    {
        printf("setenvir -h for usage\n");

        return EXIT_SUCCESS;
    }
    char* opts = "he:v:";

    int flag = 0;
    char* envname;
    char* envval;
    int opt;
    while( (opt = getopt(argc, argv, opts)) != -1 )
    {
        switch (opt)
        {
            case 'h':
            {
                help_print();
                return EXIT_SUCCESS;
            }

            case 'e':
            {
                envname = optarg;
                flag++;
                char* val = getenv(envname);
                if(!val)
                {
                    printf("No environment variable with such name!\n");

                    break;
                }

                printf("Current value of %s = %s\n",envname,val);

                break;
            }

            case 'v':
            {
                envval = optarg;
                flag++;
                printf("New value: %s\n",envval);
                break;
            }
        }
    }
    if(flag != 2)
    {
        printf("-e and -v arguments required!\n");

        return EXIT_FAILURE;
    }
    else if (flag == 2)
    {
        setenv(envname, envval, 0);

        printf("New value: %s = %s\n",envname,getenv(envname));
    }

    return EXIT_SUCCESS;
}
