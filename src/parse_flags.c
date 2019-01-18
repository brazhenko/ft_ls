/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 22:43:21 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/01/18 23:15:40 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	nuller(t_flags *flags)
{
	flags->l = 0;
	flags->rec = 0;
	flags->a = 0;
	flags->r = 0;
	flags->t = 0;
	flags->u = 0;
	flags->f = 0;
	flags->g = 0;
	flags->d = 0;
}

static void	switcher(t_flags *flags, char c)
{
	flags->l = (c == 'l') ? 1 : flags->l;
	flags->rec = (c == 'R') ? 1 : flags->rec;
	flags->a = (c == 'a') ? 1 : flags->a;
	flags->r = (c == 'r') ? 1 : flags->r;
	flags->t = (c == 't') ? 1 : flags->t;
	flags->u = (c == 'u') ? 1 : flags->u;
	flags->f = (c == 'f') ? 1 : flags->f;
	flags->g = (c == 'g') ? 1 : flags->g;
	flags->d = (c == 'd') ? 1 : flags->d;
}

int			parser(int argc, char **argv, t_flags *flags)
{
	int i;
	int j;

	nuller(flags);
	i = 1;
	if (i >= argc)
		return (1);
	while (i < argc)
	{
		if (argv[i][0] == '-')
		{
			j = 1;
			if (argv[i][j] == '\0')
				return (i - 1);
			while (argv[i][j])
			{
				switcher(flags, argv[i][j]);	
				j++;
			}
		}
		else
			return (i - 1);
		i++;
	}
	return (i - 1);
}

// int		main(int argc, char **argv)
// {
// 	t_flags *flags;

// 	flags = (t_flags *)malloc(sizeof(t_flags));
// 	printf("ret = %d\n", parser(argc, argv, flags));
// 	printf("l = %d\n", flags->l);
// 	printf("R = %d\n", flags->rec);
// 	printf("a = %d\n", flags->a);
// 	printf("r = %d\n", flags->r);
// 	printf("t = %d\n", flags->t);
// 	printf("u = %d\n", flags->u);
// 	printf("f = %d\n", flags->f);
// 	printf("g = %d\n", flags->g);
// 	printf("d = %d\n", flags->d);

// 	return (0);
// }
