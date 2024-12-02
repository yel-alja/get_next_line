#include "get_next_line.h"


int main()
{
	int fd = open("te",O_RDONLY);
	char *s;
	
	while ((s = get_next_line(fd)))
	{
		printf("%s",s);
		free(s);
	}
//	printf("\n%s\n",get_next_line(fd));
close(fd);
return 0;
}
