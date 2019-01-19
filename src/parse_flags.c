/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 22:43:21 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/01/19 03:13:47 by lreznak-         ###   ########.fr       */
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
	if (*arg == '-')
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
		return (0);
	}
	return (1);
}

char				*parse_flags(int argc, char **argv, int *last_flag)
{
	int		i;
	char	*flags;

	flags = malloc(sizeof(char) * 128);	
	i = 1;
	if (i >= argc)
		*last_flag = 0;
	while (i < argc)
	{
		if (parse_flag(argv[i], &flags))
			*last_flag = i - 1;
		i++;
	}
	return (flags);
}
