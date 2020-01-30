/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <mchardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 12:57:40 by mchardin          #+#    #+#             */
/*   Updated: 2020/01/30 14:12:52 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct	s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;

size_t	ft_strlen(const char*);
char	*ft_strcpy(char*, const char*);
int		ft_strcmp(char*, char*);
ssize_t ft_write(int, char*, size_t);
ssize_t ft_read(int, char*, size_t);
// int	ft_atoi_base(char *str, char *base);
void ft_list_push_front(t_list **begin_list, void *data);
int ft_list_size(t_list *begin_list);
void ft_list_sort(t_list **begin_list, int (*cmp)()); // VOID PAS INT
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));

void ft_free_fct(void *str)
{
	printf("%s, Del\n", (char*)str);
	free(str);
}


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

int main()
{
    t_list *l3 = malloc(sizeof(t_list *));
	*l3 = (t_list) { .data = strdup("Yulu"), .next = NULL };
    t_list *l2 = malloc(sizeof(t_list *));
	*l2 = (t_list) { .data = strdup("Yulu"), .next = l3 };
    t_list *l1 = malloc(sizeof(t_list *));
    *l1 = (t_list) { .data = strdup("Yulu"), .next = l2 };
    ft_lstprint(l1, "Initialized");
    printf("Sended ptr %p\n", l1);
    char *el = strdup("Yulu");
    ft_list_push_front(&l1, el);
    ft_lstprint(l1, "Modified");
    printf("Ret is %p\n", l1); 
    printf("Data init ptr is %p and l1->data is %p (%s)\n", el, (char *)l1->data, l1->data);
    printf("Next is %p\n", l1->next);
	printf("Size: %d\n", ft_list_size(l1));
	ft_list_sort(&l1, ft_strcmp);
	ft_lstprint(l1, "Sorted");
	ft_list_remove_if(&l1, "Yulu", ft_strcmp, ft_free_fct);
	ft_lstprint(l1, "Deleted if \"Yulu\"");
	system("leaks run");
	// t_list list;
	// list.next = 0;
	// list.data = 0;

	// printf("%lu, %p, %p, %p\n", sizeof(t_list), &list, &list.data, list.next);
	// printf("%d\n", ft_atoi_base("    	--+--12344'34", "01"));

	// int x = 0;
	// char str1[100];
	// char str2[100];
	// char str1b[100];
	// char str2b[100];
	// int	a;
	// int b;
	// ssize_t ret1;
	// ssize_t ret2;
	// int fd;
	// char	*str3;
	// char	*str3b;

	// while (x != 7)
	// {
	// 	printf("\n---- MENU ----\n\n");
	// 	printf("Choose the function to test :\n");
	// 	printf("1 : atoi base\n");
	// 	// printf("2 : strcpy\n");
	// 	// printf("3 : strcmp\n");
	// 	// printf("4 : write\n");
	// 	// printf("5 : read\n");
	// 	// printf("6 : strdup\n");
	// 	// printf("7 : exit tester\n\n");
	// 	printf("\t>> ");
	// 	if (scanf("%d", &x) != 1)
	// 	{
	// 		printf("Error : Wrong input\n");
	// 		printf("Exiting tester\n");
	// 		return (0);
	// 	}
	// 	if (x == 1) //strlen
	// 	{
	// 		printf("Type string : ");
	// 		if (scanf("%s", str1) != 1)
	// 		{
	// 			printf("Error : Wrong input\n");
	// 			printf("Exiting tester\n");
	// 			return (0);
	// 		}
	// 		printf("strlen    : %lu\n", strlen(str1));
	// 		printf("ft_strlen : %lu\n", ft_strlen(str1));
	// 	}
	// 	else if (x == 2) //strcpy
	// 	{
	// 		printf("Type strings (dest, src): ");
	// 		if (scanf("%s %s", str1, str2) != 2)
	// 		{
	// 			printf("Error : Wrong input\n");
	// 			printf("Exiting tester\n");
	// 			return (0);
	// 		}
	// 		strcpy(str1b, str1);
	// 		strcpy(str2b, str2);
	// 		printf("strcpy    : %s\n", strcpy(str1, str2));
	// 		printf("ft_strcpy : %s\n", ft_strcpy(str1b, str2b));
	// 	}
	// 	else if (x == 3) //strcmp
	// 	{
	// 		printf("Type strings (s1, s2): ");
	// 		if (scanf("%s %s", str1, str2) != 2)
	// 		{
	// 			printf("Error : Wrong input\n");
	// 			printf("Exiting tester\n");
	// 			return (0);
	// 		}
	// 		printf("Reminder : Only the sign matters for the return value\n");
	// 		printf("strcmp    : %d\n", strcmp(str1, str2));
	// 		printf("ft_strcmp : %d\n", ft_strcmp(str1, str2));
	// 	}
	// 	else if (x == 4) //write
	// 	{
	// 		printf("Type fd, string and nb : ");
	// 		if (scanf("%d %s %d", &a, str1, &b) != 3)
	// 		{
	// 			printf("Error : Wrong input\n");
	// 			printf("Exiting tester\n");
	// 			return (0);
	// 		}
	// 		printf("write    :\n");
	// 		ret1 = write(a, str1, b);
	// 		printf("\nreturn = %zd\n", ret1);
	// 		printf("ft_write :\n");
	// 		ret2 = ft_write(a, str1, b);
	// 		printf("\nreturn = %zd\n", ret2);
	// 	}
	// 	else if (x == 5) //read
	// 	{
	// 		if ((fd = open("read_test.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXO)) < 0)
	// 			return (0);
	// 		printf("Type fd, string and nb (fd %d created) : ", fd);
	// 		if (scanf("%d %s %d", &a, str1, &b) != 3)
	// 		{
	// 			printf("Error : Wrong input\n");
	// 			printf("Exiting tester\n");
	// 			return (0);
	// 		}
	// 		if (a == fd)
	// 		{
	// 			write (fd, str1, strlen(str1));
	// 			close(fd);
	// 			if ((fd = open("read_test.txt", O_RDONLY)) < 0)
	// 				return (0);
	// 			ret1 = read(fd, str2, b);
	// 			str2[b] = 0;
	// 			printf("\nread    : %s / return = %zd\n", str2, ret1);
	// 			close(fd);
	// 			if ((fd = open("read_test.txt", O_RDONLY)) < 0)
	// 				return (0);
	// 			ret2 = ft_read(fd, str2b, b);
	// 			str2b[b] = 0;
	// 			printf("\nft_read : %s / return = %zd\n", str2b, ret2);
	// 		}
	// 		else
	// 		{
	// 			ret1 = read(a, str2, b);
	// 			str2[b] = 0;
	// 			printf("\nread    : %s / return = %zd\n", str2, ret1);
	// 			ret2 = ft_read(a, str2b, b);
	// 			str2b[b] = 0;
	// 			printf("\nft_read : %s / return = %zd\n", str2b, ret2);
	// 		}
	// 			close(fd);
	// 	}
	// 	else if (x == 6) //strdup
	// 	{
	// 		printf("Type string : ");
	// 		if (scanf("%s", str1) != 1)
	// 		{
	// 			printf("Error : Wrong input\n");
	// 			printf("Exiting tester\n");
	// 			return (0);
	// 		}
	// 		str3 = strdup(str1);
	// 		str3b = strdup(str1);
	// 		printf("strdup    : %s, %p\n", str3, &str3);
	// 		printf("ft_strdup : %s, %p\n", str3b, &str3b);
	// 		str1[0] = (str1[0] == 'Z'? 'A' : 'Z');
	// 		printf("After modif of arg string :\n%s\n%s\n", str3, str3b);
	// 		free(str3);
	// 		free(str3b);
	// 	}
	// 	else if (x == 7)
	// 	{
	// 		printf("Exiting tester\n");
	// 		return (0);
	// 	}
	// 	else
	// 		printf("Wrong input number, type a number between 1 and 7\n");
	// 	bzero(str1, 100);
	// 	bzero(str2, 100);
	// 	bzero(str1b, 100);
	// 	bzero(str2b, 100);
	// }
}
