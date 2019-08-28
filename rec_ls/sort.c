/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 07:10:50 by jhouston          #+#    #+#             */
/*   Updated: 2019/08/14 09:37:04 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int	main(int argc, char **argv)
{
	char temp[1024];
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) > 0)
			{
				ft_strcpy(temp, argv[i]);
				ft_strcpy(argv[i], argv[j]);
				ft_strcpy(argv[j], temp);
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < argc)
	{
		ft_putendl(argv[i]);
		i++;
	}
}
