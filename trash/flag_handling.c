/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 17:01:07 by lreznak-          #+#    #+#             */
/*   Updated: 2018/12/26 22:09:51 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int			is_flag(char c)
{
	if (c == 'l' || c == 'R' || c == 'a' || c == 'r' || c == 't')
		return (1);
	return (0);
}

int					parse_flag(char *arg, char **flags)
{
	if (*arg == '-')
	{
		write(1, "HI!\n", 4);
		arg++;
		while (*arg)
		{
			if (is_flag(*arg))
				(*flags)[*arg] = 1;
			else
				print_usage(*arg);
			arg++;
		}
		return (1);
	}
	return (0);
}
