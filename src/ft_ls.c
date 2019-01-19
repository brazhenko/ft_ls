/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:33:06 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/01/19 03:36:09 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int c, char **v)
{
	char			*flags;
	int				last_flag;

	flags = parse_flags(c, v, &last_flag);
	if (last_flag++)
	{
		while (last_flag < c)
		{
			last_flag++;
		}
	}
	else
	{
		if (flags['R'])
			ls_files_r(".");
		else
			ls_dir(opendir("."), ".");
	}
	return (0);
}
