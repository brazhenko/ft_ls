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

void	ft_exit(char *str)
{
	ft_putstr(str);
	exit(0);
}

int		main(int c, char **v)
{
	char			*flags;
	int				last_flag;
	t_file			*cur_dir;
	struct stat		test;

	cur_dir = NULL;
	flags = parse_flags(c, v, &last_flag);
	printf("%d\n", last_flag);
	if (c == last_flag + 1)
	{
		if (flags['R'])
			ls_files_r(".");
		else
			ls_dir(opendir("."), ".");
	}
	(last_flag++);
	{
		while (last_flag < c)
		{
			cur_dir = to_list(v[last_flag], v[last_flag], cur_dir);
			last_flag++;
		}
		while (cur_dir)
		{
			if (stat(cur_dir->name, &test) == -1)
			{
				printf("no such file or directory\n");
			}
			else
				printf("%s\n", cur_dir->name);
			cur_dir = cur_dir->prev;
		}
	}
	printf("\n\n");

	return (0);
}
