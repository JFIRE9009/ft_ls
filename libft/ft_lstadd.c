/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 08:08:09 by jhouston          #+#    #+#             */
/*   Updated: 2019/07/15 13:32:40 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	new->next = (*alst);
	(*alst) = new;
}

int	main(void)
{
	t_list	*lst;
	t_list	*new;

	new = ft_lstnew("Hey THere", 20);
	ft_lstadd(&lst, new);
//	lst = ft_lstnew(new->content, new->content_size);
	ft_putnbr(lst->content_size);
}
