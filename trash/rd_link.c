/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rd_link.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 16:06:08 by lreznak-          #+#    #+#             */
/*   Updated: 2018/12/25 16:22:42 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#define BUFF_SIZE 2

int						main(void)
{
	char	*buf;
	ssize_t n = readlink("./file", buf, BUFF_SIZE);
	printf("%s\n%zd\n", buf, n);
}
