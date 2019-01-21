//
// Created by Lommy greenhands Reznak mo reznak on 2019-01-21.
//

#include "ft_ls.h"

void 		print_mode(int mode)
{
	// printf("%d    ", mode);
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
