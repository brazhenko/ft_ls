/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_dir_handle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 17:36:33 by lreznak-          #+#    #+#             */
/*   Updated: 2019/01/04 18:24:37 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			r_dir_handle(t_file **dirs,	char *dir_name)
{
	struct dirent *pDirent;
	DIR *pDir;
	pDir = opendir(dir_name);
	while ((pDirent = readdir(pDir)) != NULL)
	{
		if (opendir(pDirent->d_name))
		{
			r_dir_handle(dirs, pDirent->d_name);
				//	ft_strjoin(ft_strjoin(dir_name, "/"), pDirent->d_name));
			ft_putendl(pDirent->d_name);
		}
	}

}
