/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceliboz <maxenceliboz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:27:00 by mliboz            #+#    #+#             */
/*   Updated: 2022/01/08 10:03:38 by maxencelibo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(const char *s)
{
	int		count;

	count = 0;
	if (!s)
		return (0);
	while (s[count] != 0)
		count++;
	return (count);
}
