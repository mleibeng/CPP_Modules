NAME		:= FragTrap
CC			:= c++
CFLAGS		:= -Wall -Wextra -Werror -g -std=c++98

SRCS		:= main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
OBJS		:= $(SRCS:.cpp=.o)

COLOR_RESET			=	\033[0m
COLOR_CYAN			=	\033[36m
COLOR_GREEN			=	\033[32m
COLOR_RED			=	\033[31m
COLOR_YELLOW 		=	\033[33m

all: check_status $(NAME)

%.o: %.cpp
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	@echo "$(COLOR_CYAN)Compiling $(NAME)...$(COLOR_RESET)"
	@$(CC) $(OBJS) -o $(NAME)
	@echo "$(COLOR_GREEN)Compilation for $(NAME) complete$(COLOR_RESET)"

check_status:
	@if [ -f $(NAME) ] && [ "$(OBJS)" -ot "$(NAME)" ]; then \
		echo "$(COLOR_YELLOW)$(NAME) is already up to date$(COLOR_RESET)"; \
		exit 0; \
	fi

clean:
	@echo "$(COLOR_CYAN)Cleaning compiled files$(COLOR_RESET)"
	@rm -rf $(OBJS)
	@echo "$(COLOR_GREEN)Cleanup completed.$(COLOR_RESET)"

fclean: clean
	@echo "$(COLOR_CYAN)Full compiled clean initiated$(COLOR_RESET)"
	@rm -rf $(NAME)
	@echo "$(COLOR_GREEN)Full-Clean completed.$(COLOR_RESET)"

re: fclean all

.PHONY: all clean fclean re check_status
