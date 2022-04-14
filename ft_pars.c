/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgummy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:58:17 by sgummy            #+#    #+#             */
/*   Updated: 2022/01/15 15:58:19 by sgummy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_wrong_arg(t_struct *arg)
{
	if (arg->num_of_philos <= 0 || arg->life_time <= 0)
	{
		printf("Error: not valid arguments\n");
		return (1);
	}
	return (0);
}

static int	ft_num_of_meals(char **argv, t_struct *arg)
{
	if (argv[5] != NULL)
	{
		arg->num_of_meals = ft_atoi(argv[5]);
		if (arg->num_of_meals <= 0)
		{
			printf("Error: not valid arguments\n");
			return (1);
		}
	}
	else
		arg->num_of_meals = -1;
	return (0);
}

static int	ft_thrds(t_struct *arg)
{
	arg->trd = malloc(sizeof (pthread_t) * arg->num_of_philos);
	if (!arg->trd)
	{
		printf("Malloc error\n");
		return (1);
	}
	return (0);
}

static int	ft_forks(t_struct *arg)
{
	int		i;

	arg->forks = malloc(sizeof (pthread_mutex_t) * arg->num_of_philos);
	if (!arg->forks)
	{
		printf("Malloc error\n");
		return (1);
	}
	i = 0;
	while (i < arg->num_of_philos)
	{
		pthread_mutex_init(&arg->forks[i], NULL);
		i++;
	}
	return (0);
}

int	ft_pars_args(char **argv, t_struct *arg)
{
	arg->num_of_philos = ft_atoi(argv[1]);
	arg->life_time = (long long)ft_atoi(argv[2]);
	if (ft_wrong_arg(arg) == 1)
		return (1);
	if (ft_num_of_meals(argv, arg) == 1)
		return (1);
	if (ft_thrds(arg) == 1)
		return (1);
	if (ft_forks(arg) == 1)
		return (1);
	arg->out = 0;
	pthread_mutex_init(&arg->write, NULL);
	return (0);
}
