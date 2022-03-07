/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 21:53:36 by tarchimb          #+#    #+#             */
/*   Updated: 2022/03/07 12:29:51 by tarchimb         ###   ########.fr       */
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
		return (printf("Syntax error\n"));
	error = parsing(argc, argv, &prg);
	if (error == 0 || error == -1)
	{
		if (error == 0)
			free(prg.philo);
		return (0);
	}
	if (start_simulation(&prg) == -1)
	{
		print_stderror(-1, "An error occured\n");
		return (0);
	}
	return (EXIT_SUCCESS);
}
