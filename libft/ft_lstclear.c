/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:56:04 by ylai              #+#    #+#             */
/*   Updated: 2024/05/25 11:21:12 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*cur;

	if (del == NULL)
		return ;
	if (lst && *lst)
	{
		cur = *lst;
		while (cur)
		{
			temp = cur;
			cur = cur->next;
			ft_lstdelone(*lst, del);
		}
		*lst = NULL;
	}
}
