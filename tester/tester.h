#ifndef	TESTER_H
# define TESTER_H

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

int			interactive_mode();
void 		lists();
size_t		ft_strlen(const char*);
char		*ft_strdup(const char*);
char		*ft_strcpy(char*, const char*);
int			ft_strcmp(char*, char*);
ssize_t 	ft_write(int, char*, size_t);
ssize_t 	ft_read(int, char*, size_t);
int			ft_atoi_base(char *str, char *base);
void 		ft_list_push_front(t_list **begin_list, void *data);
int 		ft_list_size(t_list *begin_list);
void 		ft_list_sort(t_list **begin_list, int (*cmp)()); // VOID PAS INT
void 		ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));

#endif