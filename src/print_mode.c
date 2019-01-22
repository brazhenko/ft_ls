//
// Created by Lommy greenhands Reznak mo reznak on 2019-01-21.
//

#include "ft_ls.h"
static void bin( int k )
{
	if (k >= 2)
		bin(k / 2);
	char n =  k % 2 + '0';
	write(1, &n, 1);
}

void 		print_mode(int mode)
{


	// printf("--%d--", !(mode & 256 / 256));
//	ft_putchar('r' * (mode & 256 / 256) + '-' * !(mode & 256 / 256));
//	ft_putchar('w' * (mode & 128 / 128) + '-' * !(mode & 128 / 128));
//	ft_putchar('x' * (mode & 64 / 64) + '-' * !(mode & 64 / 64));
//	ft_putchar('r' * (mode & 32 / 32) + '-' * !(mode & 32 / 32));
//	ft_putchar('w' * (mode & 16 / 16) + '-' * !(mode & 16 / 16));
//	ft_putchar('x' * (mode & 8 / 8) + '-' * !(mode & 8 / 8));
//	ft_putchar('r' * (mode & 4 / 4) + '-' * !(mode & 4 / 4));
//	ft_putchar('w' * (mode & 2 / 2) + '-' * !(mode & 2 / 2));
//	ft_putchar('x' * (mode & 1 / 1) + '-' * !(mode & 1 / 1));
//	bin(mode);
//	puts("            ");

// извини, у нас пиздец с буфером((
	
	// if (S_ISDIR(mode))
	// 	write(1, "d", 1);
	// else
	// 	write(1, "-", 1);
	// if (mode & 256)
	// 	write(1, "r", 1);
	// else
	// 	write(1, "-", 1);
	// if (mode & 128)
	// 	write(1, "w", 1);

	// else
	// 	write(1, "-", 1);
	// if (mode & 64)
	// 	write(1, "x", 1);
	// else
	// 	write(1, "-", 1);
	// if (mode & 32)
	// 	write(1, "r", 1);
	// else
	// 	write(1, "-", 1);
	// if (mode & 16)
	// 	write(1, "w", 1);
	// else
	// 	write(1, "-", 1);
	// if (mode & 8)
	// 	write(1, "x", 1);
	// else
	// 	write(1, "-", 1);
	// if (mode & 4)
	// 	write(1, "r", 1);
	// else
	// 	write(1, "-", 1);
	// if (mode & 2)
	// 	write(1, "w", 1);
	// else
	// 	write(1, "-", 1);
	// if (mode & 1)
	// 	write(1, "x", 1);
	// else
	// 	write(1, "-", 1);

	if (S_ISDIR(mode))
		printf("d");
	else
		printf("-");
	if (mode & 256)
		printf("r");
	else
		printf("-");
	if (mode & 128)
		printf("w");

	else
		printf("-");
	if (mode & 64)
		printf("x");
	else
		printf("-");
	if (mode & 32)
		printf("r");
	else
		printf("-");
	if (mode & 16)
		printf("w");
	else
		printf("-");
	if (mode & 8)
		printf("x");
	else
		printf("-");
	if (mode & 4)
		printf("r");
	else
		printf("-");
	if (mode & 2)
		printf("w");
	else
		printf("-");
	if (mode & 1)
		printf("x");
	else
		printf("-");
}
