/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_prac.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 06:28:59 by jhouston          #+#    #+#             */
/*   Updated: 2019/09/03 14:53:23 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <grp.h>
#include <uuid/uuid.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <time.h>

#define BIT_ACTIVE(FLAGS, BIT) ((FLAGS >> BIT) & 1)
#define	SET_BIT(FLAGS, BIT) (FLAGS |= (1 << BIT))

struct			mine {
	char		*data;
	struct mine	*next;
};

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
/*	if (num[1] == 4)
		ft_putstr("-r");  */
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

void	l_flag(DIR *dir, struct mine loop, struct dirent *had)
{
	while ((had = readdir(dir)) != NULL)
	{
		loop.data = had->d_name;
		if (loop.data[0] != '.')
		{
			putmodes(loop.data);
			ft_putendl(loop.data);
		}
	}
}

void indent_print(int indent)
{
	int i;

	i = 0;
	while (indent >= i)
	{
		ft_putstr(" ");
		i++;
	}
}

void R_flag(DIR *dir, struct mine loop,  struct dirent *entry, int indent)
{
	int i;
	while ((entry = readdir(dir)) != NULL) 
	{
		if (entry->d_type == DT_DIR) 
		{
			char	path[1024];
			i = 0;
			if (ft_strcmp(entry->d_name, ".") == 0 || ft_strcmp(entry->d_name, "..") == 0)
				continue;
			loop.data = entry->d_name;
//			ft_putstr(name);
//			ft_putstr(entry->d_name);
			snprintf(path, sizeof(path), "%s/%s", entry->d_name, entry->d_name);
//			indent_print(indent);
//			ft_putendl(loop.data);
			printf("%*s[%s]\n", indent, "", entry->d_name);
            R_flag(dir, loop, entry, indent);
		}
	   	else 
			printf("%*s%s\t", indent, "", loop.data);
	}
	closedir(dir);
}

void	no_flags(DIR *dir, struct mine loop, struct dirent *had)
{
	if ((had = readdir(dir)) != NULL)
	{
		loop.data = had->d_name;
		if (loop.data[0] != '.')
			ft_putendl(loop.data);
		no_flags(dir, loop, had);
	}
}

void	a_flags(DIR *dir, struct mine loop, struct dirent *had)
{
	if ((had = readdir(dir)) != NULL)
	{
		loop.data = had->d_name;
		ft_putendl(loop.data);
		a_flags(dir, loop, had);
	}
}

int	scan_options(int max, char **flags)
{
	int i;
	int j;
	int check;

	i = 1;
	check = 0;
	while (i < max)
	{
		j = 0;
		if (flags[i][0] == '-')
		{
			if (flags[i][j + 1] != '\0')
			while (flags[i][j])
			{
				SET_BIT(check, (flags[i][j] - 'a'));
				j++;
			}
			else
			{
				ft_putstr("Invalid Flag Input '-'");
				return (0);
			}
		}
		else
		{
			ft_putstr("Invalid Flag Input "); 
			ft_putchar('\'');
			ft_putchar(flags[i][j]);
			ft_putstr("\'\n");
			ft_putstr("Did you mean -");
			ft_putchar(flags[i][j]);
			ft_putchar('?');
			ft_putchar('\n');
			return (0);
		}
		i++;
	}
	return (check);
}

int		main(int argc, char **argv)
{
	struct dirent	*dir;
	struct mine		pole;
	DIR				*folder;
	int				flags;

	pole.data = NULL;
	dir = NULL;
	folder = opendir(".");
	flags = scan_options(argc, argv);
	if (argv[1] == NULL)
		no_flags(folder, pole, dir);
	if (BIT_ACTIVE(flags, ('a' - 'a')))
			a_flags(folder, pole, dir);
	else if (BIT_ACTIVE(flags, ('l' - 'a')))
			l_flag(folder, pole, dir);
	else if (BIT_ACTIVE(flags, ('R' - 'A')))
			R_flag(folder, pole, dir, 0);
	closedir(folder);
	return (0);
}

