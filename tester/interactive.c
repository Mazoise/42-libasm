/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <mchardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 13:47:52 by mchardin          #+#    #+#             */
/*   Updated: 2020/01/30 15:45:53 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int interactive_mode()
{
	int x = 0;
	char str1[100];
	char str2[100];
	char str1b[100];
	char str2b[100];
	int	a;
	int b;
	ssize_t ret1;
	ssize_t ret2;
	int fd;
	char	*str3;
	char	*str3b;

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
		if (x == 1) //strlen
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
		else if (x == 2) //strcpy
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
		else if (x == 3) //strcmp
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
		else if (x == 4) //write
		{
			printf("Type fd, string and nb : ");
			if (scanf("%d %s %d", &a, str1, &b) != 3)
			{
				printf("Error : Wrong input\n");
				printf("Exiting tester\n");
				return (0);
			}
			printf("write    :\n");
			ret1 = write(a, str1, b);
			printf("\nreturn = %zd\n", ret1);
			printf("ft_write :\n");
			ret2 = ft_write(a, str1, b);
			printf("\nreturn = %zd\n", ret2);
		}
		else if (x == 5) //read
		{
			if ((fd = open("read_test.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXO)) < 0)
				return (0);
			printf("Type fd, string and nb (fd %d created) : ", fd);
			if (scanf("%d %s %d", &a, str1, &b) != 3)
			{
				printf("Error : Wrong input\n");
				printf("Exiting tester\n");
				return (0);
			}
			if (a == fd)
			{
				write (fd, str1, strlen(str1));
				close(fd);
				if ((fd = open("read_test.txt", O_RDONLY)) < 0)
					return (0);
				ret1 = read(fd, str2, b);
				str2[b] = 0;
				printf("\nread    : %s / return = %zd\n", str2, ret1);
				close(fd);
				if ((fd = open("read_test.txt", O_RDONLY)) < 0)
					return (0);
				ret2 = ft_read(fd, str2b, b);
				str2b[b] = 0;
				printf("\nft_read : %s / return = %zd\n", str2b, ret2);
			}
			else
			{
				ret1 = read(a, str2, b);
				str2[b] = 0;
				printf("\nread    : %s / return = %zd\n", str2, ret1);
				ret2 = ft_read(a, str2b, b);
				str2b[b] = 0;
				printf("\nft_read : %s / return = %zd\n", str2b, ret2);
			}
				close(fd);
		}
		else if (x == 6) //strdup
		{
			printf("Type string : ");
			if (scanf("%s", str1) != 1)
			{
				printf("Error : Wrong input\n");
				printf("Exiting tester\n");
				return (0);
			}
			str3 = strdup(str1);
			str3b = strdup(str1);
			printf("strdup    : %s, %p\n", str3, &str3);
			printf("ft_strdup : %s, %p\n", str3b, &str3b);
			str1[0] = (str1[0] == 'Z'? 'A' : 'Z');
			printf("After modif of arg string :\n%s\n%s\n", str3, str3b);
			free(str3);
			free(str3b);
		}
		else if (x == 7) //exit
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
	return (1);
}
