/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeremy <mjeremy@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:40:58 by mjeremy           #+#    #+#             */
/*   Updated: 2025/05/01 16:44:15 by mjeremy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Returns the last node of the list starting from lst.
If the list is empty, returns NULL.
*/
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

/*
#include <stdio.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

int	main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*last;
	int		a;
	int		b;
	int		c;

	a = 10;
	b = 20;
	c = 30;
	node1 = ft_lstnew(&a);
	node2 = ft_lstnew(&b);
	node3 = ft_lstnew(&c);
	node1->next = node2;
	node2->next = node3;
	last = ft_lstlast(node1);
	printf("Last node value: %d\n", *(int *)(last->content));
	free(node1);
	free(node2);
	free(node3);
	return (0);
}
*/
