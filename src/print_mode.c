/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 07:59:04 by lreznak-          #+#    #+#             */
/*   Updated: 2019/02/06 02:47:41 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_mode(int mode)
{
	if (S_ISDIR(mode))
		printf("d");
	else if (mode & 1024)
		printf("c");
	else if (mode & 2048)
		printf("b");
	else
		printf("-");
	printf("%c", (mode & 256) ? 'r' : '-');
	printf("%c", (mode & 128) ? 'w' : '-');
	printf("%c", (mode & 64) ? 'x' : '-');
	printf("%c", (mode & 32) ? 'r' : '-');
	printf("%c", (mode & 16) ? 'w' : '-');
	printf("%c", (mode & 8) ? 'x' : '-');
	printf("%c", (mode & 4) ? 'r' : '-');
	printf("%c", (mode & 2) ? 'w' : '-');
	if (mode & 1)
		printf("x");
	else if (mode & 512)
		printf("T");
	else
		printf("-");
}
