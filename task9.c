#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/utsname.h>

void help_print()
{
    printf("-h                  Print help and exit\n");
}

int
main(int argc,char** argv)
{
    char* opts = "h";

    struct utsname minfo;
    uname(&minfo);
    char buff[255];
    gethostname(buff, 255);

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
            
        }
    }

    printf("Machine name: %s\n",minfo.nodename);
    printf("Machine type: %s\n",minfo.machine);
    printf("System name: %s\n",minfo.sysname);
    printf("Release: %s\n",minfo.release);
    printf("Version: %s\n",minfo.version);
    printf("Host name: %s\n",buff);
    printf("Host ID: %ld\n",gethostid());
    
    return EXIT_SUCCESS;
}
