/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 08:08:21 by jhouston          #+#    #+#             */
/*   Updated: 2019/06/24 08:24:53 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;
	t_list	*lstret;

	newlst = f(lst);
	lstret = newlst;
	if (lst == NULL || f == NULL)
		return (NULL);
	else
		while (lst->next != NULL)
		{
			newlst->next = f(lst->next);
			newlst = newlst->next;
			lst = lst->next;
		}
	return (lstret);
}
