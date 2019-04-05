/*exec函数族中接口的使用*/
//谁调用就对谁进行程序替换

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    printf("leihoua~~bite~~\n");
    //execl("./test", "test", "-l", NULL);
    //execlp("ls", "ls", "-l", NULL);
    char *env[32];
    env[0] = "MYENV=1000";
    env[1] = NULL;
    //execle("./test", "test", "-a", NULL, env);

    char *argv[32];
    argv[0] = "test";
    argv[1] = "zhang";
    argv[2] = NULL;
    execve("./test", argv, env);
    printf("nihao~~bite~~\n");
    return 0;   
}
