/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgummy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:06:30 by sgummy            #+#    #+#             */
/*   Updated: 2022/01/15 16:06:32 by sgummy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <string.h>
# include <stdio.h>

typedef struct s_struct
{
	int				num_of_philos;
	int				num_of_meals;
	long long		start_time;
	long long		life_time;
	int				out;
	pthread_t		*trd;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;
}		t_struct;

typedef struct s_data
{
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	int				meal;
	int				index;
	long long		start;
	int				right_fork;
	int				left_fork;
	t_struct		*philo;

}		t_data;

int			ft_atoi(char *str);
long long	current_timestamp(void);
int			ft_pars_args(char **argv, t_struct *arg);
int			ft_philos_init(t_data	*data, int i, t_struct *arg, char **argv);
void		ft_philo(t_struct *arg, t_data *data);
void		ft_waiter(void *data);
void		ft_free_trd_mtx_malloc(t_data *data);

#endif
