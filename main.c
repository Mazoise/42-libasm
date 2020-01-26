/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <mchardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 13:47:52 by mchardin          #+#    #+#             */
/*   Updated: 2020/01/26 18:49:59 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <strings.h>
size_t	ft_strlen(const char*);
char	*ft_strcpy(char*, const char*);
int		ft_strcmp(char*, char*);

int main()
{
	int x = 0;
	char str1[100];
	char str2[100];
	char str1b[100];
	char str2b[100];

	while (x != 7)
	{
		printf("\n---- MENU ----\n\n");
		printf("Choose the function to test :\n");
		printf("1 : strlen\n");
		printf("2 : strcpy\n");
		printf("3 : strcmp\n");
		printf("4 : write\n");
		printf("5 : read\n");
		printf("6 : strdup\n");
		printf("7 : exit tester\n\n");
		printf("\t>> ");
		if (scanf("%d", &x) != 1)
		{
			printf("Error : Wrong input\n");
			printf("Exiting tester\n");
			return (0);
		}
		if (x == 1)
		{
			printf("Type string : ");
			if (scanf("%s", str1) != 1)
			{
				printf("Error : Wrong input\n");
				printf("Exiting tester\n");
				return (0);
			}
			printf("strlen    : %lu\n", strlen(str1));
			printf("ft_strlen : %lu\n", ft_strlen(str1));
		}
		else if (x == 2)
		{
			printf("Type strings (dest, src): ");
			if (scanf("%s %s", str1, str2) != 2)
			{
				printf("Error : Wrong input\n");
				printf("Exiting tester\n");
				return (0);
			}
			strcpy(str1b, str1);
			strcpy(str2b, str2);
			printf("strcpy    : %s\n", strcpy(str1, str2));
			printf("ft_strcpy : %s\n", ft_strcpy(str1b, str2b));
		}
		else if (x == 3)
		{
			printf("Type strings (s1, s2): ");
			if (scanf("%s %s", str1, str2) != 2)
			{
				printf("Error : Wrong input\n");
				printf("Exiting tester\n");
				return (0);
			}
			printf("Reminder : Only the sign matters for the return value\n");
			printf("strcmp    : %d\n", strcmp(str1, str2));
			printf("ft_strcmp : %d\n", ft_strcmp(str1, str2));
		}
		else if (x == 7)
		{
			printf("Exiting tester\n");
			return (0);
		}
		else
			printf("Wrong input number, type a number between 1 and 7\n");
		bzero(str1, 100);
		bzero(str2, 100);
		bzero(str1b, 100);
		bzero(str2b, 100);
	}
}
