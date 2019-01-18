/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 22:43:21 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/01/19 02:49:07 by lreznak-         ###   ########.fr       */
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
				(*flags)[*arg] = 1;
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

	flags = malloc(sizeof(char) * 128);	
	i = 1;
	while (i < argc)
	{
		parse_flag(argv[i], &flags);
		i++;
	}
	return (flags);
}
