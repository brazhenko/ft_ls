/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_files.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 18:30:04 by lreznak-          #+#    #+#             */
/*   Updated: 2019/01/04 13:12:42 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


void			ls_files(char *dir)
{
	struct dirent *pDirent;
	DIR *pDir;
	pDir = opendir(dir);
	while ((pDirent = readdir(pDir)) != NULL)
	{
		if (is_visible(pDirent->d_name))
		{
			ft_putstr(pDirent->d_name);
			ft_putstr("    ");
		}
	}
	ft_putstr("\n");
}
