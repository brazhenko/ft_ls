/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:33:06 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/01/19 01:05:54 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int c, char **v)
{
	t_flags *flags = malloc(sizeof(t_flags));
	int last_flag = parser(c, v, flags);
	printf("%d\n\n", last_flag);
	printf("%d\n%d\n%d\n%d\n",
			flags->a,
			flags->l,
			flags->rec,
			flags->t);

	if (last_flag == c || last_flag + 1 == c)
	{
		if (flags->rec)
			ls_files_r(".");
		else
			ls_dir(opendir("."), ".");
	}
	else
	{
		while (last_flag < c)
		{
				
		}
	}
	
	// ls_files_r(argv[1]);
	return (0);
}
