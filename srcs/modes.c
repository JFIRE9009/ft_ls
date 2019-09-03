/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_prac.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 06:28:59 by jhouston          #+#    #+#             */
/*   Updated: 2019/09/03 17:04:38 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../lib_ls.h"

int cDtO(int decimalNumber)
{
    int octalNumber;
	int	i;

	i = 1;
	octalNumber = 0;
    while (decimalNumber != 0)
    {
        octalNumber += (decimalNumber % 8) * i;
        decimalNumber /= 8;
        i *= 10;
    }
    return (octalNumber);
}

int	*octarr(int oct)
{
	int *retarr;
	int i;

	i = ft_intlen(cDtO(oct));
	retarr = (int *)malloc(sizeof(int) * i);
	while (oct >= 1)
	{
		retarr[i] = (oct % 10);
		i--;
		oct /= 10;
	}
	return (retarr);
}

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

