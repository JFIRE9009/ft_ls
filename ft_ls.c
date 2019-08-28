/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_prac.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 06:28:59 by jhouston          #+#    #+#             */
/*   Updated: 2019/08/28 07:31:47 by jhouston         ###   ########.fr       */
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

struct			mine {
	char		*data;
	struct mine	*next;
};

void			putmodes(char *path)
{
	register struct passwd	*pwd;
	register uid_t			user;
	struct	stat			buff;
	int						links;
	struct timespec			time;
	char					*time2;
	int						size;

	stat(path, &buff);
	links = buff.st_nlink;
	time = buff.st_mtimespec;
	size = buff.st_size;
	user = geteuid();
	pwd = getpwuid(user);
	ft_putnbr(links);
	ft_putchar('\t');
	ft_putstr(pwd->pw_name);
	ft_putchar('\t');
	ft_putnbr(size);
	ft_putchar('\t');
	time2 = ctime(&time.tv_sec);
	ft_putstr(ft_strcreturn(time2, '\n', 0));
	ft_putchar('\t');
}

void	l_flag(DIR *dir, struct mine loop, struct dirent *had)
{
	while ((had = readdir(dir)) != NULL)
	{
		loop.data = had->d_name;
		if (loop.data[0] != '.')
		{
			ft_putstr("-");
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
		{
			ft_putstr(had->d_name);
			ft_putchar('\t');
		}
		no_flags(dir, loop, had);
	}
}

void	a_flags(DIR *dir, struct mine loop, struct dirent *had)
{
	while ((had = readdir(dir)) != NULL)
	{
		loop.data = had->d_name;
		ft_putstr(loop.data);
		ft_putchar('\t');
	}
}

int		main(int argc, char **argv)
{
	struct dirent	*dir;
	struct mine		pole;
	DIR				*asd;

	(void)argc;
	pole.data = NULL;
	dir = NULL;
	asd = opendir(".");
	if (argv[1] == NULL)
		no_flags(asd, pole, dir);
	else if (ft_strcmp(argv[1], "-a") == 0)
			a_flags(asd, pole, dir);
	else if (ft_strcmp(argv[1], "-l") == 0)
			l_flag(asd, pole, dir);
	else if (ft_strcmp(argv[1], "-R") == 0)
			R_flag(asd, pole, dir, 0);
	closedir(asd);
	return (0);
}
