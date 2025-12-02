#include "get_next_line.h"

int main(void)
{
    int     fd;
    int     fd1;
    char    *line;
    char    *line1;

    
    fd = open("test.txt", O_RDONLY);
    fd1 = open("test1.txt", O_RDONLY);
while(1)
{
    if((line = get_next_line(fd)) != NULL)
        printf("%s",line);
 
    if((line1 = get_next_line(fd1)) != NULL)
        printf("%s", line1);
    
}
}

