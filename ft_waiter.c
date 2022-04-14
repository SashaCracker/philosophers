/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_waiter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgummy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:58:45 by sgummy            #+#    #+#             */
/*   Updated: 2022/01/15 15:58:47 by sgummy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_death(t_data *ph_data, int i)
{
	pthread_mutex_lock(&ph_data->philo->write);
	ph_data->philo->out = 1;
	printf("%lld %d died\n", (current_timestamp() - \
	ph_data->philo->start_time), ph_data[i].index);
	return (1);
}

void	ft_waiter(void *data)
{
	int			i;
	t_data		*ph_data;
	int			done;
	int			go_out;

	ph_data = (t_data *)data;
	go_out = 0;
	while (go_out != 1)
	{
		done = 0;
		i = 0;
		while (go_out != 1 && i < ph_data->philo->num_of_philos && \
		ph_data->philo->out != 1)
		{
			if (current_timestamp() - ph_data[i].start - \
			ph_data->time_to_die >= 0)
				go_out = ft_death(ph_data, i);
			done = done + ph_data[i].meal;
			i++;
		}
		if (go_out != 1 && ph_data->philo->num_of_meals != -1 && \
		done / ph_data->philo->num_of_philos >= ph_data->philo->num_of_meals)
			break ;
	}
}
