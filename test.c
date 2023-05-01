#include<fcntl.h>
#include<stdio.h>

int main(void)
{
    int fd = open ("map.ber", O_RDWR);
    if (fd < 0)
        printf("erroe\n");
    printf("hello %d\n", fd);
    
}