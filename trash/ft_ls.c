/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 21:20:07 by lreznak-          #+#    #+#             */
/*   Updated: 2019/01/04 18:21:44 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					main(int c, char **v)
{
	char			*flags;
	int				i;
	t_file			*files;
	struct stat		file;
	t_file			*dirs;

	files = NULL;
	dirs = NULL;
	flags = (char *)malloc(127);
	i = 1;
	if (c == 1)
		ls_files(".");
	else
	{
		while (i < c)
		{
			while (i < c && parse_flag(v[i], &flags))
			{
				printf("CHECK\n");
				i++;
			}
			while (i < c)
			{
				if (stat(v[i], &file) == 0)
				{
					add_to_lst(&files, file_creator(v[i], 1));
					// ft_putendl(v[i]);
				}
				else
				{
					ft_putstr("ls: ");
					ft_putstr(v[i]);
					ft_putendl(" No such file or directory");
					exit(0);
				}
				i++;
			}
		}
		while (files)
		{
			if (opendir(files->name))
			{
				printf("IT IS DIR: %s\n", files->name);
				r_dir_handle(&dirs, files->name);
			}
			files = files->previous;
		}
		// files_lst_printer(files);
		printf("%d %d %d\n", flags['l'], flags['a'], flags['R']);
	}

	return (0);
}
