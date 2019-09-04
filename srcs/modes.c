/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_prac.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 06:28:59 by jhouston          #+#    #+#             */
/*   Updated: 2019/09/04 06:36:11 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../lib_ls.h"

void	putperms(int mode)
{
	int *num;
	int i;

	i = 0;
	num = (octarr(cDtO(mode)));
	while (i < 5)
	{
		ft_putnbr(num[i]);
		i++;
	}
	ft_putchar('\t');
}

void			putmodes(char *path)
{
	register struct passwd	*pwd;
	register uid_t			user;
	register mode_t			mode;
	struct stat				buff;
	struct timespec			time;
	char					*time2;
	int						links;
	int						size;

	stat(path, &buff);
	mode = buff.st_mode;
	links = buff.st_nlink;
	time = buff.st_mtimespec;
	size = buff.st_size;
	user = geteuid();
	pwd = getpwuid(user);
//	putperms(mode);
	ft_putnbr_t(links);
	ft_putstr_t(pwd->pw_name);
	ft_putnbr_t(size);
	time2 = ctime(&time.tv_sec);
	ft_putstr_t(ft_strcreturn(time2, '\n', 0));
}

