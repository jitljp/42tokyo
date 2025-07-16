/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeremy <mjeremy@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 10:46:34 by mjeremy           #+#    #+#             */
/*   Updated: 2025/05/09 09:50:31 by mjeremy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Takes a node as a parameter and frees its content using the function 'del'.
Frees the node itself but does NOT free the next node.
'lst' is the node to delete.
'del' is the address of the function used to delete the content.
*/
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

/*
#include <stdio.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	del_int(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*node;
	int		*value;

	value = malloc(sizeof(int));
	if (!value)
		return (1);
	*value = 42;

	node = ft_lstnew(value);

	printf("Before delete: %d\n", *(int *)(node->content));
	ft_lstdelone(node, del_int);

	printf("After delete: node freed\n");
	return (0);
}
*/
