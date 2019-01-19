/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 13:42:48 by lreznak-          #+#    #+#             */
/*   Updated: 2019/01/17 12:34:05 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <stdio.h>
#include <time.h>

int			main(void)
{
	struct stat a;
	int n = stat("file", &a);

	printf("%d\n", n);
// 	time_t		current = (((a.st_ctimespec).tv_sec));
// 	printf("%ld\n", (current));
// 	printf("%s\n", (ctime(&current)));
// 	
// 	
// 	
// 	// LSTAT то же самое, только для символьной ссылки
	return (0);
}
