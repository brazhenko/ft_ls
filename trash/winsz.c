#include <curses.h>
#include <stdio.h>
#include <sys/ioctl.h>

int			main(void)
{
	struct winsize size;

	if (ioctl(0, TIOCGWINSZ, (char *)&size) < 0)
	    printf("TIOCGWINSZ error");
	printf("%d rows, %d columns\n", size.ws_row, size.ws_col);
}
