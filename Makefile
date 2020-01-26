
SRCS = ft_strlen.s ft_strcpy.s ft_strcmp.s

TEST_SRC= main.c

OBJS = $(SRCS:.s=.o)

TEST_OBJS = $(TEST_SRC:.c=.o)

.s.o:
		nasm -fmacho64 $<

.c.o:
		gcc $(CFLAGS) -c $<

CFLAGS = -Wall -Werror -Wextra

AR = ar rc

RM = rm -f

NAME = libasm.a

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)

all:		$(NAME)

test:		$(NAME) $(TEST_OBJS)
			$(CC) $(TEST_OBJS) ./$(NAME) -o run

clean:		
			$(RM) $(OBJS)
			$(RM) $(TEST_OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all