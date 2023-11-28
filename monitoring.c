/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendes- <mmendes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:06:22 by mmendes-          #+#    #+#             */
/*   Updated: 2023/11/28 19:06:22 by mmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

#define TAKE_FORK_STR "has taken a fork 🍴\n"
#define DROP_FORK_STR "has dropped a fork 🍴\n"
#define EAT_STR "is eating 😋\n"
#define THINK_STR "is thinking 🤔\n"
#define SLEEP_STR "is sleeping 😴\n"
#define DEAD_STR "is dead 😵\n"

void	monitoring(t_philo *philo, t_event_id event_id)
{
	suseconds_t	timestamp;
	const char	*events[6] = {DEAD_STR, EAT_STR, THINK_STR,
		SLEEP_STR, TAKE_FORK_STR, DROP_FORK_STR};

	pthread_mutex_lock(&philo->args->monitoring_mutex);
	if (philo->args->simulation_should_end)
	{
		pthread_mutex_unlock(&philo->args->monitoring_mutex);
		return ;
	}
	timestamp = get_time() - philo->start_time;
	printf("%ld %d %s", timestamp, philo->philo_nbr, events[event_id]);
	pthread_mutex_unlock(&philo->args->monitoring_mutex);
}
