#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int pid = fork();
    if (pid < 0) {
        perror("fork error");
        exit(-1);
    }else if (pid == 0) {
        sleep(5);
        exit(255);
    }
    //pid_t wait(int *status);
    //  status: 用于获取退出原因
    //  返回值：退出的子进程的pid
    //int statu;
    //int ret = wait(&statu);
    //
    //pid_t waitpid(pid_t pid, int *status, int options);
    //pid:  
    //  -1  :   等待任意子进程退出
    //  >0  :   等待指定的子进程退出
    //status：用于获取退出原因
    //options：
    //      WNOHANG     将waitpid设置为非阻塞
    //返回值：-1：错误  0：没有子进程退出  >0：退出子进程的pid
    int statu;
    int ret;
    while((ret = waitpid(pid, &statu, WNOHANG)) == 0) {
        printf("打麻将~~！\n");
        sleep(1);
    }
    if (!(statu & 0x7f)) {
        printf("%d-%d---child exit code:%d\n", ret, pid, 
                (statu >> 8) & 0xff);
    }
    if (WIFEXITED(statu)) {
        printf("%d-%d---child exit code:%d\n", ret, pid, 
                WEXITSTATUS(statu));
    }
    if (WIFSIGNALED(statu)) {
        printf("exit signal:%d\n", WTERMSIG(statu));
    }
    while(1) {
        printf("---------\n");
        sleep(1);
    }
    return 0;
}
