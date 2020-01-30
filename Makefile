
SRCS			= ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s

BONUS_SRCS		= ft_atoi_base.s ft_is_in_base.s ft_is_whitespace.s ft_list_push_front.s ft_list_size.s ft_list_sort.s ft_list_remove_if.s

TEST_SRC		= ./tester/interactive.c ./tester/lists.c ./tester/main.c

OBJS			= $(SRCS:.s=.o)

BONUS_OBJS		= $(BONUS_SRCS:.s=.o)

TEST_OBJS		= $(TEST_SRC:.c=.o)

AS				= nasm

CC				= gcc

ASFLAGS			= -fmacho64

CFLAGS			= -Wall -Werror -Wextra -I ./tester/

AR				= ar rc

RM				= rm -f

NAME			= libasm.a

$(NAME):		$(OBJS)
				$(AR) $(NAME) $(OBJS)

all:			
				$(MAKE) $(NAME)

test:			$(NAME) $(TEST_OBJS)
				$(CC) $(TEST_OBJS) ./$(NAME) -o run

bonus:			all $(BONUS_OBJS)
				$(AR) $(BONUS_NAME) $(BONUS_OBJS)

clean:
				$(RM) $(OBJS)
				$(RM) $(TEST_OBJS)
				$(RM) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all