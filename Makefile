NAME	=	bin

CC	:=	gcc
CPP	:=	.c

CFLAGS	+=	-Wall -Wextra

COLOR   :=      \033[01;38;5;31m

WHITE   :=      \033[0;0m

CLEAR   :=      \033[2K

all:    $(NAME)

$(NAME):

clean:
	@rm -f vgcore*
	@rm -f $(NAME)
	@echo -e "$(NAME)\033[01;38;5;222m has been deleted : DONE$(WHITE)"

re:     clean  all

build: re
	@echo -ne "\033[0;33mcompiling $(NAME): \033[0;0m" && \
	gcc $(CFLAGS) -o $(NAME) main.c functions.c $(LDFLAGS) && \
	echo -e "\033[0;32m[OK]\033[0;0m" || \
	echo -e "\033[0;31m[FAILED]\033[0;0m"

build_test: re
	@echo -ne "\033[0;33mcompiling $(NAME): \033[0;0m" && \
	gcc $(CFLAGS) -o $(NAME) main_test.c functions.c -lcriterion && \
	echo -e "\033[0;32m[OK]\033[0;0m" || \
	echo -e "\033[0;31m[FAILED]\033[0;0m"

print-%  : ; @echo $* = $($*)

.PHONY: $(NAME) clean fclean re test
