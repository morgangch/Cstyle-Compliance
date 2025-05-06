##
## EPITECH PROJECT, 2025
## Workshop-CStyle
## File description:
## Makefile
##

NAME	=	ex_07

SRCS	=	file.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-W -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJS)
	gcc -o $(NAME) $(OBJS) $(CPPFLAGS)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@
	@echo "Compiling $<"

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

test:	$(NAME)
	@echo "Running tests..."
	@./$(NAME) > result.txt
	@echo "Tests completed. Check result.txt for output."
