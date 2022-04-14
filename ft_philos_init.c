/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philos_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgummy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:58:36 by sgummy            #+#    #+#             */
/*   Updated: 2022/01/15 15:58:38 by sgummy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_philos_init(t_data	*data, int i, t_struct *arg, char **argv)
{
	data[i].time_to_die = (long long)ft_atoi(argv[2]);
	data[i].time_to_eat = (long long)ft_atoi(argv[3]);
	data[i].time_to_sleep = (long long)ft_atoi(argv[4]);
	if (data[i].time_to_die <= 0 || data[i].time_to_eat <= 0 \
		|| data[i].time_to_sleep <= 0)
	{
		printf("Error: not valid arguments\n");
		return (1);
	}
	data[i].meal = 0;
	data[i].index = i + 1;
	data[i].right_fork = i;
	if (i == arg->num_of_philos - 1)
		data[i].left_fork = 0;
	else
		data[i].left_fork = i + 1;
	data[i].philo = arg;
	return (0);
}
