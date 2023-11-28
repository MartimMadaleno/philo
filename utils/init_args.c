/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendes- <mmendes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:05:50 by mmendes-          #+#    #+#             */
/*   Updated: 2023/11/28 19:05:50 by mmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

#define AGR_0_ERR "nbr_of_philosophers and must_eat_times must be bigger than 0"

bool	init_args(t_args *args, char **argv)
{
	args->nbr_of_philo = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	args->must_eat_times = -1;
	if (argv[5])
		args->must_eat_times = ft_atoi(argv[5]);
	if (args->nbr_of_philo == 0 || args->must_eat_times == 0)
	{
		panic(NULL, NULL, NULL, AGR_0_ERR);
		return (false);
	}
	if (pthread_mutex_init(&args->monitoring_mutex, NULL) != 0)
	{
		panic(NULL, NULL, NULL, MUTEX_INIT_ERR);
		return (false);
	}
	args->simulation_should_end = false;
	return (true);
}
