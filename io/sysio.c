/*系统调用接口使用*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main()
{
    //mode_t umask(mode_t mask);
    //设置调用进程的文件创建权限掩码
    umask(0);
    //int open(const char *pathname, int flags, mode_t mode);
    //  pathname：  要打开的文件路径名
    //  flags： 选项参数
    //      必选其一：
    //          O_RDONLY    只读
    //          O_WRONLY    只写
    //          O_RDWR      读写
    //      可选项：
    //          O_CREAT     文件存在则打开，不存在则创建
    //          O_TRUNC     将文件长度截断为0（清空原有内容）
    //          O_APPEND    追加
    //  mode:   权限 0664
    //      (mode & ~umask)
    //  返回值：文件描述符（正整数）（系统调用接口的操作句柄）失败：-1
    int fd = open("./test.txt", O_RDWR | O_CREAT | O_APPEND | O_TRUNC, 0664);
    if (fd < 0) {
        perror("open error");
        return -1;
    }
    char *ptr = "jintianzhilaile 20 ren\n";
    //ssize_t write(int fd, const void *buf, size_t count);
    //  fd:     open返回的文件描述符
    //  buf：   要写入的数据
    //  count： 要写入的数据长度
    //  返回值：实际写入的数据长度（字节）  失败：-1
    int ret = write(fd, ptr, strlen(ptr));
    if (ret < 0) {
        perror("write error");
        return -1;
    }

    //off_t lseek(int fd, off_t offset, int whence);
    //  fd:     open返回的文件描述符
    //  offset: 偏移量
    //  whence：偏移起始位置
    //          SEEK_SET    文件起始位置
    //          SEEK_CUR    当前读写位置
    //          SEEK_END    文件末尾位置
    //  返回值：从文件起始位置到当前读写位置的偏移量 失败：-1
    lseek(fd, 0, SEEK_SET);

    char buf[1024] = {0};
    //ssize_t read(int fd, void *buf, size_t count);
    //  fd:     open返回的文件描述符
    //  buf:    内存首地址，用于存储读取的数据
    //  count： 要读取的数据长度
    //  返回值：实际读取的数据长度（字节） 失败：-1
    ret = read(fd, buf, 1023);
    if (ret < 0) {
        perror("read error");
        return -1;
    }
    printf("read buf:[%d-%s]\n", ret, buf);

    //int close(int fd);
    close(fd);
    return 0;
}
