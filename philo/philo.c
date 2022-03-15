/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 21:53:36 by tarchimb          #+#    #+#             */
/*   Updated: 2022/03/15 09:13:21 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

/*
	Main function
*/
int	main(int argc, char **argv)
{
	t_prg	prg;
	int		error;

	if (argc < 5 || argc > 6)
		return (print_stderror(0, "Syntax error"));
	error = parsing(argc, argv, &prg);
	if (error == 0 || error == -1)
	{
		if (error == 0)
			free(prg.philo);
		return (0);
	}
	start_simulation(&prg);
	free(prg.philo);
	return (EXIT_SUCCESS);
}
