/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgummy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:57:38 by sgummy            #+#    #+#             */
/*   Updated: 2022/01/15 15:57:42 by sgummy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(char *str)
{
	int		res;
	int		minus;

	res = 0;
	minus = 1;
	while ((*str != 0) && (((*str >= 9) && (*str <= 13)) || (*str == 32)))
		str++;
	if ((*str == '-') || (*str == '+'))
	{
		if (*str == '-')
			minus = -1;
		str++;
	}
	while ((*str != 0) && ((*str >= 48) && (*str <= 57)))
	{
		res = res * 10 + (*str - 48);
		str++;
	}
	return (res * minus);
}
