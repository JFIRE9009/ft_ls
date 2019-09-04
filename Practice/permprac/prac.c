/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prac.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 06:30:58 by jhouston          #+#    #+#             */
/*   Updated: 2019/08/27 07:29:15 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pwd.h>
#include <sys/types.h>
#include <uuid/uuid.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	register struct passwd	*pwd;
	register uid_t user;

	user = geteuid();
	pwd = getpwuid(user);
	printf("%s", pwd->pw_gecos);
}
