#include "ft_ls.h"

void			print_usage(char c)
{
	ft_putstr("ls : illegal option -- ");
	ft_putchar(c);
	ft_putstr("\n");
	ft_putendl("usage: ls [-Ralrt]");
	exit(0);
}
