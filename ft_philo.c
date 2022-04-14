/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgummy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:58:29 by sgummy            #+#    #+#             */
/*   Updated: 2022/01/15 15:58:31 by sgummy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	ft_usleep(long long time_exit)
{
	long long	result;

	result = current_timestamp() + time_exit;
	while (current_timestamp() < result)
		usleep(100);
}

static void	ft_print(t_data *ph_data, char *str)
{
	pthread_mutex_lock(&ph_data->philo->write);
	printf("%lld %d %s\n", \
	(current_timestamp() - ph_data->philo->start_time), ph_data->index, str);
	pthread_mutex_unlock(&ph_data->philo->write);
}

static void	ft_eat(t_data *ph_data)
{
	pthread_mutex_lock(&ph_data->philo->forks[ph_data->right_fork]);
	ft_print(ph_data, "has taken a fork");
	pthread_mutex_lock(&ph_data->philo->forks[ph_data->left_fork]);
	if (ph_data->philo->out == 1)
		return ;
	ph_data->start = current_timestamp();
	ft_print(ph_data, "has taken a fork");
	ft_print(ph_data, "is eating");
	ft_usleep(ph_data->time_to_eat);
	ph_data->meal++;
	pthread_mutex_unlock(&ph_data->philo->forks[ph_data->left_fork]);
	pthread_mutex_unlock(&ph_data->philo->forks[ph_data->right_fork]);
	ft_print(ph_data, "is sleeping");
	usleep(ph_data->time_to_sleep * 1000);
	ft_print(ph_data, "is thinking");
}

static void	*ft_dining(void *data)
{
	t_data	*ph_data;

	ph_data = (t_data *)data;
	if ((ph_data->index) % 2 != 0)
		usleep(ph_data->time_to_eat / 2 * 1000);
	while (ph_data->philo->out != 1)
		ft_eat(ph_data);
	return (NULL);
}

void	ft_philo(t_struct *arg, t_data *data)
{
	int	i;

	i = 0;
	arg->start_time = current_timestamp();
	while (i < arg->num_of_philos)
	{
		data[i].start = current_timestamp();
		pthread_create(&arg->trd[i], NULL, ft_dining, &data[i]);
		i++;
	}
}
