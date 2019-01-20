/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 03:26:03 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/01/19 05:44:55 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			print_usage(char c)
{
	write(1, "ls: illegal option -- ",22);
	write(1, &c, 1);
	write(1, "\nusage: ls [-Ra] [file ...]\n", 28);
	exit(0);
}

static int			is_flag(char c)
{
	if (c == 'l' || c == 'R' || c == 'a' || c == 'r' ||  c == 't' || c == 'u' || c == 'f' || c == 'g' || c == 'd')
		return (1);
	return (0);
}

static	int			parse_flag(char *arg, char **flags)
{
	if (*arg == '-' && *(arg + 1))
	{
		arg++;
		while (*arg)
		{
			if (is_flag(*arg))
				(*flags)[((int)*arg)] = 1;
			else
				print_usage(*arg);
			arg++;
		}
		return (1);
	}
	return (0);
}


char				*parse_flags(int argc, char **argv, int *last_flag)
{
	int		i;
	char	*flags;

	i = 1;
	flags = malloc(sizeof(char) * 128);
	ft_memset((void *)flags, 0, 128);
	*last_flag = 0;
	while (i < argc)
	{
		if (!parse_flag(argv[i], &flags))
			return (flags);
		*last_flag = i;
		i++;
	}
	return (flags);
}
