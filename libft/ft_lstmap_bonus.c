/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahansal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 04:24:04 by mahansal          #+#    #+#             */
/*   Updated: 2022/10/27 03:06:36 by mahansal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*tmp1;
	t_list	*tmp2;

	if (!lst)
		return (0);
	head = ft_lstnew(f(lst->content));
	if (!head)
		return (0);
	tmp1 = lst->next;
	while (tmp1)
	{
		tmp2 = ft_lstnew(f(tmp1->content));
		if (!tmp2)
		{
			ft_lstclear(&head, del);
		}
		ft_lstadd_back(&head, tmp2);
		tmp1 = tmp1->next;
	}
	return (head);
}
