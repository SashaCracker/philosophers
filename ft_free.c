/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgummy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:58:07 by sgummy            #+#    #+#             */
/*   Updated: 2022/01/15 15:58:09 by sgummy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_free_trd_mtx_malloc(t_data *data)
{
	pthread_t		*trd_tmp;
	pthread_mutex_t	*mtx_tmp;
	int				i;

	trd_tmp = data->philo->trd;
	mtx_tmp = data->philo->forks;
	i = 0;
	while (i < data->philo->num_of_philos)
	{
		pthread_mutex_destroy(&data->philo->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->philo->write);
	free(trd_tmp);
	free(mtx_tmp);
	free(data);
}
