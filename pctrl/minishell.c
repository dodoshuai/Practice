#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    while(1) {
        //等待标准输入
        printf("[san@localhost]$ ");
        fflush(stdout);
        char buf[1024] = {0};
        //%[^\n]  获取字符串直到遇到\n
        //%*c   将一个字符从缓冲区中取出
        if (scanf("%[^\n]%*c", buf) != 1) {
            getchar();
            continue;
        }
        //解析输入的数据
        //buf:[     ls      -a      ]
        //[ls] [-a]
        char *argv[32];
        int argc = 0;
        char *ptr = buf;
        while(*ptr != '\0') {
            if (!isspace(*ptr)) {
                //当前位置是非空白字符
                argv[argc++] = ptr;
                while(!isspace(*ptr) && *ptr != '\0') {
                    ptr++;
                }
            }
            *ptr = '\0';
            ptr++;
        } 
        argv[argc] = NULL;
        //判断命令是否是内建命令
        if (strcmp(argv[0], "cd") == 0) {
            //int chdir(const char *path);
            //改变当前工作路径
            chdir(argv[1]);
            continue;
        }
        //创建子进程---执行任务
        int pid = fork();
        if (pid < 0) {
            continue;
        }else if (pid == 0) {
            //子进程---执行其它任务----程序替换
            if (execvp(argv[0], argv) < 0) {
                perror("");
            }
            //替换失败就退出
            exit(0);
        }
        //等待子进程退出--避免僵尸进程
        wait(NULL);
    }
    return 0;
}
