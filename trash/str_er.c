/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 15:45:26 by lreznak-          #+#    #+#             */
/*   Updated: 2018/12/25 16:01:45 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int					main(void)
{
	printf("%s\n", strerror(0));
	printf("%s\n", strerror(1));
	perror("I am just an error printed to the 2 FD");

	printf("%s\n", strerror(1));
}
