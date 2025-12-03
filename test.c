#include "get_next_line.h"
#include "get_next_line_bonus.h"

int main(void)
{
    int     fd;
    int     fd1;
    char    *line;
  

    
    fd = open("test.txt", O_RDONLY);
    fd1 = open("test1.txt", O_RDONLY);
line = get_next_line(fd);
printf("%s",line);
line = get_next_line(fd1);
printf("%s",line);
line = get_next_line(fd);
printf("%s",line);
line = get_next_line(fd1);
printf("%s",line);
}
