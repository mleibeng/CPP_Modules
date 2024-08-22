NAME		:= serialize
CC			:= c++
CFLAGS		:= -Wall -Wextra -Werror -g -std=c++98

SRCS		:= main.cpp Serializer.cpp
OBJS		:= $(SRCS:.cpp=.o)

COLOR_RESET			=	\033[0m
COLOR_CYAN			=	\033[36m
COLOR_GREEN			=	\033[32m
COLOR_RED			=	\033[31m

all: $(NAME)

%.o: %.cpp
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME):   $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)
	@echo "$(COLOR_GREEN)Compilation for $(NAME) complete$(COLOR_RESET)"

compile_message:
	@echo "$(COLOR_CYAN)Beginning compilation for: $(NAME)$(COLOR_RESET)"

clean:
	@echo "$(COLOR_CYAN)Cleaning compiled files$(COLOR_RESET)"
	@rm -rf $(OBJS)
	@echo "$(COLOR_GREEN)Cleanup completed.$(COLOR_RESET)"

fclean: clean
	@echo "$(COLOR_CYAN)Full compiled clean initiated$(COLOR_RESET)"
	@rm -rf $(NAME)
	@echo "$(COLOR_GREEN)Full-Clean completed.$(COLOR_RESET)"

re: fclean all

.PHONY: all clean fclean re
