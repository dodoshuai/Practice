/*进程终止demo*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main()
{
    int pid = fork();
    if (pid < 0) {
        perror("fork error");
        printf("fork error %s\n", strerror(errno));
    }
    printf("hello bit!!");
    int i = 0;
    for (i = 0; i < 256; i++) {
        printf("%s\n", strerror(i));
    }
    sleep(3);
    _exit(255);
    exit(0);
    return 0;
}
