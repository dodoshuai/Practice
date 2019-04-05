#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    //close(1);
    
    int fd = open("./test.txt", O_RDWR);
    if (fd < 0) {
        perror("open error");
        return -1;
    }
    //将要打印的数据，不写入标准输出，而是写入test.txt
    dup2(fd, 1);
    //\n刷新缓冲区，仅仅针对标准输出文件才有效
    //其它文件，\n仅仅具备换行效果
    printf("fd:%d\n", fd);//stdout  ->   1 ---> test.txt
    fflush(stdout);

    //close是系统调用接口，关闭文件时不会刷新缓冲区（因为我们所说的这个     缓冲区是stdout的缓冲区（用户态的缓冲区））
    close(fd);
    return 0;
}
