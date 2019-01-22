#include "ft_ls.h"

int				main(void)
{
	for (register int i = 0; i < 20000; i++)
	{
		if (getpwuid(i))
			printf("%d   %s\n", i, getpwuid(i)->pw_name);
	}
	return (0);
}
