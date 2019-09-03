/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 10:20:58 by jhouston          #+#    #+#             */
/*   Updated: 2019/09/02 20:06:59 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#define BIT_ACTIVE(FLAGS, BIT) ((FLAGS >> BIT) & 1) 
#define SET_BIT(FLAGS, BIT) (FLAGS |= (1 << BIT))

int parse_options(int argc, char **argv)
{
	int i;
	int j;
	int flags;

	i = 1;
	flags = 0;
	while (i < argc)
	{
		j = 0;
		if (argv[i][0] == '-')
			while (argv[i][j])
			{
				SET_BIT(flags, (argv[i][j] - 'a'));
				j++;
			}
		i++;
	}
	return (flags);
}

int	main(int argc, char **argv)
{
	int flags;

	flags = parse_options(argc, argv);

	if (BIT_ACTIVE(flags, ('c' - 'a')))
		printf("c is pressed\n");
	else
		printf("isbroken");
}
