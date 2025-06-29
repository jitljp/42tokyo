/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeremy <mjeremy@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:03:17 by mjeremy           #+#    #+#             */
/*   Updated: 2025/05/01 16:54:18 by mjeremy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Adds the node ’new’ at the beginning of the list.
'lst' is the address of the pointer to the first node.
'new' becomes the new first node and points to the previous first node.
*/
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
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
	t_list	*head;
	t_list	*node1;
	t_list	*node2;
	int		a;
	int		b;

	a = 10;
	b = 20;
	node1 = ft_lstnew(&a);
	node2 = ft_lstnew(&b);
	head = NULL;

	ft_lstadd_front(&head, node1);
	printf("After adding node1:\n");
	printf("head -> %d\n", *(int *)(head->content));

	ft_lstadd_front(&head, node2);
	printf("After adding node2:\n");
	printf("head -> %d -> %d\n",
		*(int *)(head->content),
		*(int *)(head->next->content));

	free(node1);
	free(node2);
	return (0);
}
*/
