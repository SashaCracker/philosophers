/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgummy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:55:56 by sgummy            #+#    #+#             */
/*   Updated: 2022/01/15 15:56:05 by sgummy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_one_philosopher(t_struct *arg)
{
	if (arg->num_of_philos == 1)
	{
		pthread_mutex_lock(&arg->write);
		printf("%d %d has taken a fork\n%d %d is thinking\n", 0, 1, 0, 1);
		usleep(arg->life_time);
		printf("%lld %d died\n", arg->life_time, 1);
		return (0);
	}
	return (1);
}

static int	ft_mistake(int argc)
{
	if (argc < 5 || argc > 6)
	{
		printf("Error: wrong number of arguments\n");
		return (1);
	}
	return (0);
}

static int	ft_maloc(t_data *data)
{
	if (!data)
	{
		printf("Malloc error\n");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_struct		arg;
	t_data			*data;
	int				i;

	if (ft_mistake(argc) == 1)
		return (1);
	if (ft_pars_args(argv, &arg) == 1)
		return (1);
	if (ft_one_philosopher(&arg) == 0)
		return (0);
	data = malloc(sizeof (t_data) * arg.num_of_philos);
	if (ft_maloc(data) == 1)
		return (1);
	i = 0;
	while (i < arg.num_of_philos)
	{
		if (ft_philos_init(data, i, &arg, argv) == 1)
			return (1);
		i++;
	}
	ft_philo(&arg, data);
	ft_waiter(data);
	usleep(10000);
	ft_free_trd_mtx_malloc(data);
	return (0);
}
