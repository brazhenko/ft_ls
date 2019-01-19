/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 16:23:01 by lreznak-          #+#    #+#             */
/*   Updated: 2018/12/26 22:09:52 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdio.h>

int				main(void)
{
	time_t		current_time_from_Epoch;
	// printf("%ld\n", time(&current_time_from_Epoch));
	// printf("%ld\n", current_time_from_Epoch);
	current_time_from_Epoch = 1545759801;
	printf("%s", ctime(&current_time_from_Epoch));
}
