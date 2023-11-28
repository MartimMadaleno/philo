/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendes- <mmendes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:06:18 by mmendes-          #+#    #+#             */
/*   Updated: 2023/11/28 19:06:18 by mmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_args			args;
	pthread_mutex_t	*forks;
	t_philo			*philos;

	if (!valid_args(argc, argv) || !init_args(&args, argv))
		return (EXIT_FAILURE);
	forks = init_forks(&args);
	philos = init_philos(&args, forks);
	if (!launch_threads_and_join(&args, philos, forks))
		return (EXIT_FAILURE);
	destroy(&args, forks, philos);
	return (EXIT_SUCCESS);
}
