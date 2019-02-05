//
// Created by Lommy greenhands Reznak mo reznak on 2019-01-21.
//

#include "ft_ls.h"

static void bin(int k)
{
	if (k >= 2)
		bin(k / 2);
	char n =  k % 2 + '0';
	write(1, &n, 1);
}

void 		print_mode(int mode)
{
    printf("%c", (S_ISDIR(mode)) ? 'd' : '-');
	printf("%c", (mode & 256) ? 'r' : '-');
    printf("%c", (mode & 128) ? 'w' : '-');
    printf("%c", (mode & 64) ? 'x' : '-');

    printf("%c", (mode & 32) ? 'r' : '-');
    printf("%c", (mode & 16) ? 'w' : '-');
    printf("%c", (mode & 8) ? 'x' : '-');

    printf("%c", (mode & 4) ? 'r' : '-');
    printf("%c", (mode & 2) ? 'w' : '-');
    if (mode & 1)
        printf("x");
    else if (mode & 512)
        printf("T");
    else
        printf("-");
}
