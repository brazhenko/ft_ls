/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:33:06 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/01/19 05:58:45 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			print_flags(char *flags)
{
	int		i;

	i = 'a';
	while (i < 128)
	{
		if (flags[i])
			write(1, "1", 1);
		else
			write(1, "0", 1);
		i++;
	}
}

int		main(int c, char *v[])
{
	int 			last_flag;
	char 			*flags;
	t_file			*args;

	args = NULL;
	flags = parse_flags(c, v, &last_flag);
	print_flags(flags);
	printf("---%d\n", last_flag);
	if (c == last_flag + 1)
	{
		if (flags['R'])
			ls_files_r(".");
		else
			ls_dir(opendir("."), ".");
	}
	else
	{
		while (last_flag < c)
		{

			args = to_list(NULL, v[last_flag], v[last_flag], args);
			last_flag++;
		}
		printf("_______________________\n");
		while (args)
		{
			printf("%s     ", args->name);
			args = args->prev;
		}
	}
	return (0);
}
