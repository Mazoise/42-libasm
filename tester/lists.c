/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <mchardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 12:57:40 by mchardin          #+#    #+#             */
/*   Updated: 2020/01/30 18:31:27 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void	ft_lstprint(t_list *lst, char *cmt)
{
	int i;

	i = 0;
	printf("--- nodes ---\n");
	if (cmt)
		printf("| %s\n", cmt);
	while (lst)
	{
		printf("| %d | \"%s\"\n", i++, lst->data);
		lst = lst->next;
	}
	printf("---------------\n\n");
}

void	lists()
{
    t_list *l3 = malloc(sizeof(t_list *));
	*l3 = (t_list) { .data = strdup("Bravo"), .next = NULL };
    t_list *l2 = malloc(sizeof(t_list *));
	*l2 = (t_list) { .data = strdup("Romeo"), .next = l3 };
    t_list *l1 = malloc(sizeof(t_list *));
    *l1 = (t_list) { .data = strdup("Alpha"), .next = l2 };
    ft_lstprint(l1, "Initialized");
    char *el = strdup("Zulu");
    ft_list_push_front(&l1, el);
    ft_lstprint(l1, "Modified");
	ft_list_sort(&l1, ft_strcmp);
	ft_lstprint(l1, "Sorted");
	printf("Size: %d\n\n", ft_list_size(l1));
	ft_list_remove_if(&l1, "Romeo", ft_strcmp, free);
	ft_lstprint(l1, "Deleted if \"Romeo\"");
	printf("Size: %d\n\n", ft_list_size(l1));
	ft_list_remove_if(&l1, "Alpha", ft_strcmp, free);
	ft_lstprint(l1, "Deleted if \"Alpha\"");
	printf("Size: %d\n\n", ft_list_size(l1));
	ft_list_remove_if(&l1, "Zulu", ft_strcmp, free);
	ft_lstprint(l1, "Deleted if \"Zulu\"");
	printf("Size: %d\n\n", ft_list_size(l1));
	ft_list_remove_if(&l1, "Bravo", ft_strcmp, free);
	ft_lstprint(l1, "Deleted if \"Bravo\"");
	printf("Size: %d\n\n", ft_list_size(l1));
	system("leaks run");
}
