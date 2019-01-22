//
// Created by Lommy greenhands Reznak mo reznak on 2019-01-21.
//

#include "ft_ls.h"

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

	if (mode & 256)
		write(1, "r", 1);
	else
		write(1, "-", 1);
	if (mode & 128)
		write(1, "w", 1);

	else
		write(1, "-", 1);
	if (mode & 64)
		write(1, "x", 1);

	else
		write(1, "-", 1);
	if (mode & 32)
		write(1, "r", 1);
	else
		write(1, "-", 1);
	if (mode & 16)
		write(1, "w", 1);
	else
		write(1, "-", 1);
	if (mode & 8)
		write(1, "x", 1);
	else
		write(1, "-", 1);
	if (mode & 4)
		write(1, "r", 1);
	else
		write(1, "-", 1);
	if (mode & 2)
		write(1, "w", 1);
	else
		write(1, "-", 1);
	if (mode & 1)
		write(1, "x", 1);
	else
		write(1, "-", 1);
}
