/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_files_R.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:25:50 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/01/17 22:51:42 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ls_files_r(char *name)
{
	DIR				*cur_dir;
	struct dirent	*file;

	cur_dir = opendir(name);

	while ((file = readdir(cur_dir)))
	{
		printf("%s\n", file->d_name);
		if (file->d_type == 4 && file->d_name[0] != '.')
		{
			printf("\n\n%s\n", ft_strjoin(ft_strjoin(name, "/"), file->d_name));
			ls_files_r(ft_strjoin(ft_strjoin(name, "/"), file->d_name));
		}
	}
	return (1);
}
