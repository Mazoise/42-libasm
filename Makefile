
SRCS = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s  ft_atoi_base.s ft_is_in_base.s ft_is_whitespace.s ft_list_push_front.s ft_list_size.s ft_list_sort.s ft_list_remove_if.s

TEST_SRC= main.c

BONUS_SRC= bonus.c

OBJS = $(SRCS:.s=.o)

TEST_OBJS = $(TEST_SRC:.c=.o)

BONUS_OBJS = $(BONUS_SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra
ASFLAGS = -fmacho64
AS = nasm
CC = gcc

AR = ar rc

RM = rm -f

NAME = libasm.a

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)

all:		$(NAME)

test:		$(NAME) $(TEST_OBJS)
			$(CC) $(TEST_OBJS) ./$(NAME) -o run

bonus:		$(NAME) $(BONUS_OBJS)
			$(CC) $(BONUS_OBJS) ./$(NAME) -o run

clean:		
			$(RM) $(OBJS)
			$(RM) $(TEST_OBJS)
			$(RM) $(BONUS_OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all