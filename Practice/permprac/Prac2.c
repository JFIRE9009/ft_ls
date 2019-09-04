/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Prac2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 07:23:17 by jhouston          #+#    #+#             */
/*   Updated: 2019/08/27 07:29:48 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <stdio.h>

int	main(void)
{
	char *file = "../libft";
	struct stat buff;

	stat(file, &buff);
	int size = buff.st_nlink;

	printf("%d", size);
}
