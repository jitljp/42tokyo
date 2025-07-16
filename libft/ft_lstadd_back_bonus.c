/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeremy <mjeremy@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 10:34:51 by mjeremy           #+#    #+#             */
/*   Updated: 2025/05/03 10:46:01 by mjeremy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Adds the node 'new' at the end of the list.
'lst' is the address of the pointer to the first node.
If the list is empty, 'new' becomes the first node.
Otherwise, the last node's 'next' is set to 'new'.
*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current_node;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	current_node = *lst;
	while (current_node->next != NULL)
		current_node = current_node->next;
	current_node->next = new;
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

void	print_list(t_list *head)
{
	while (head != NULL)
	{
		printf("%d\n", *(int *)(head->content));
		head = head->next;
	}
}

int	main(void)
{
	t_list	*head;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	int		a;
	int		b;
	int		c;

	a = 10;
	b = 20;
	c = 30;

	node1 = ft_lstnew(&a);
	node2 = ft_lstnew(&b);
	node3 = ft_lstnew(&c);

	head = node1;
	node1->next = node2;

	printf("Before ft_lstadd_back:\n");
	print_list(head);

	ft_lstadd_back(&head, node3);

	printf("After ft_lstadd_back:\n");
	print_list(head);

	return (0);
}
*/
