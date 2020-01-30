/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <mchardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 18:27:30 by mchardin          #+#    #+#             */
/*   Updated: 2020/01/30 20:04:26 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void	atoib()
{
	printf("\nATOI BASE :\n");
	printf("1010101010101111101, base 2                           : %d\n", ft_atoi_base("  +-+-1010101010101111101", "01"));
	printf("-0234, base 10                                        : %d\n", ft_atoi_base("-0234", "0123456789"));
	printf("(all whitespaces)+--+-56ff12ufjlesklkjflke, base hexa : %d\n", ft_atoi_base("     \t\r\f\n\v+--+-56ff12ufjlesklkjflke", "0123456789abcdef"));
	printf("Error, should return 0 (Nothing to conv)              : %d\n", ft_atoi_base("balalaa", "la"));
	printf("Error, should return 0 (same char in base)            : %d\n", ft_atoi_base("alalaa", "lal"));
	printf("Error, should return 0 (- in base)                    : %d\n", ft_atoi_base("101", "-01"));
	printf("Error, should return 0 (+ in base)                    : %d\n", ft_atoi_base("alalaa", "la+"));
}

void	mandatory()
{
	printf("\nSTRLEN :\n");
	printf("\"\" : %lu, \"Coucou\" : %lu, \"Les\" : %lu, \"gens\" : %lu, \"[]\" : %lu\n", ft_strlen(""), ft_strlen("Coucou"), ft_strlen("Les"), ft_strlen("gens"), ft_strlen("[]"));
	printf("\"\" : %lu, \"Coucou\" : %lu, \"Les\" : %lu, \"gens\" : %lu, \"[]\" : %lu\n", strlen(""), strlen("Coucou"), strlen("Les"), strlen("gens"), strlen("[]"));
	printf("\nSTRCMP :\n");
	printf("\"\", \"Coucou\" : %d, \"les\", \"gens\" : %d, \"[]\", \"[]\" : %d\n", ft_strcmp("" ,"Coucou"), ft_strcmp("les", "gens"), ft_strcmp("[]", "[]"));
	printf("\"\", \"Coucou\" : %d, \"les\", \"gens\" : %d, \"[]\", \"[]\" : %d\n", strcmp("" ,"Coucou"), strcmp("les", "gens"), strcmp("[]", "[]"));
	printf("\nSTRDUP :\n");
	char *str = ft_strdup("");
	char *str2 = ft_strdup("Coucou");
	char *str3 = strdup("");
	char *str4 = strdup("Coucou");
	printf("\"\" : %s, \"Coucou\" : %s\n", str, str2);
	printf("\"\" : %s, \"Coucou\" : %s\n", str3, str4);
	free(str);
	free(str2);
	free(str3);
	free(str4);
	char 	str5[] = "AAAAAAAAAAAAAAA";
	char 	str6[] = "AAAAAAAAAAAAAAA";
	char 	str7[] = "BBBB";
	char 	str8[] = "BBBB";
	char 	str9[] = "A";
	char 	str10[] = "A";
	printf("\nSTRCPY :\n");
	printf("\"AAAAAAAAAAAAAAA\", \"Coucou\" : %s, \"BBBB\", \"gens\" : %s, \"A\", \"\" : %s\n", ft_strcpy(str6 ,"Coucou"), ft_strcpy(str8, "gens"), ft_strcpy(str10, ""));
	printf("\"AAAAAAAAAAAAAAA\", \"Coucou\" : %s, \"BBBB\", \"gens\" : %s, \"A\", \"\" : %s\n", strcpy(str5 ,"Coucou"), strcpy(str7, "gens"), strcpy(str9, ""));
	printf("\nWRITE :\n");
	printf("\nReturn : %zd\n", ft_write(1, "AAAAAAAAAAAABBBBBBBBBBBBBBBBBB", 31));
	printf("\nReturn : %zd\n", write(1, "AAAAAAAAAAAABBBBBBBBBBBBBBBBBB", 31));
	printf("\nReturn : %zd\n", ft_write(1, "", 0));
	printf("\nReturn : %zd\n", write(1, "", 0));
	printf("\nREAD :\n");
	int fd;
	if ((fd = open("ft_read.s", O_RDONLY)) < 0)
		return ;
	ssize_t ret1 = ft_read(fd, str6, 15);
	str6[15] = 0;
	close(fd);
	if ((fd = open("ft_read.s", O_RDONLY)) < 0)
		return ;
	ssize_t ret2 = read(fd, str5, 15);
	str5[15] = 0;
	close(fd);
	printf("%s\nRet = %zd\n", str6, ret1);
	printf("%s\nRet = %zd\n", str5, ret2);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("\nAdd argument :\n");
		printf("\t-\"mandatory\"   for mandatory fonctions (strlen, strcmp, strdup, strcpy, write, read)\n");
		printf("\t-\"lists\"       for chained lists (list_push_front, list_remove_if, list_size, list_sort)\n");
		printf("\t-\"atoib\"       for atoi_base\n");
		printf("\t-\"interactive\" for interactive mode (warning, beta version)\n\n");
	}
	else if (!(strcmp(argv[1], "mandatory")))
		mandatory();
	else if (!(strcmp(argv[1], "lists")))
		lists();
	else if (!(strcmp(argv[1], "atoib")))
		atoib();
	else if (!(strcmp(argv[1], "interactive")))
		interactive_mode();
	else
		printf("\nWrong argument\n"); 
	return (0);
}
