/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 08:39:51 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/02/05 08:40:07 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			prt_st(char *str, int n)
{
	int i;

	i = n - ft_strlen(str);
	while (i > 0)
	{
		printf("%s", " ");
		i--;
	}
	printf(" %s", str);
}

void			printf_len_post_str(char *str, int n)
{
	int i;

	i = n - ft_strlen(str);
	printf("%s ", str);
	while (i > 0)
	{
		printf("%s", " ");
		i--;
	}
}

void			printf_len_llnum(long long int num, int n)
{
	int i;

	i = n - ft_strlen(ft_itoa(num));
	while (i > 0)
	{
		printf("%s", " ");
		i--;
	}
	printf(" %lld", num);
}

void			printf_len_hu_num(unsigned short int num, int n)
{
	int i;

	i = n - ft_strlen(ft_itoa(num));
	while (i > 0)
	{
		printf("%s", " ");
		i--;
	}
	printf(" %hu", num);
}
