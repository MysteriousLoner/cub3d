NAME        := cub3d
CC        := gcc
CFLAGS    := -Wall -Wextra -Werror #-fsanitize=address -g3

SRCS        :=      main.c \
                          libft/ft_memcpy.c \
                          libft/ft_putstr_fd.c \
                          libft/ft_strchr.c \
                          libft/ft_memset.c \
                          libft/ft_itoa.c \
                          libft/ft_strdup.c \
                          libft/ft_lstiter.c \
                          libft/ft_putchar_fd.c \
                          libft/ft_bzero.c \
                          libft/ft_strlcpy.c \
                          libft/ft_lstsize.c \
                          libft/ft_putendl_fd.c \
                          libft/ft_strcmp.c \
                          libft/ft_isprint.c \
                          libft/ft_substr.c \
                          libft/ft_striteri.c \
                          libft/ft_strmapi.c \
                          libft/ft_isalpha.c \
                          libft/ft_putnbr_fd.c \
                          libft/ft_strjoin.c \
                          libft/ft_strlcat.c \
                          libft/ft_isalnum.c \
                          libft/ft_lstclear.c \
                          libft/ft_isdigit.c \
                          libft/ft_lstmap.c \
                          libft/ft_tolower.c \
                          libft/ft_isascii.c \
                          libft/ft_lstnew.c \
                          libft/ft_strrchr.c \
                          libft/ft_lstlast.c \
                          libft/ft_lstdelone.c \
                          libft/ft_strtrim.c \
                          libft/ft_lstadd_back.c \
                          libft/ft_strnstr.c \
                          libft/ft_memmove.c \
                          libft/ft_toupper.c \
                          libft/ft_strlen.c \
                          libft/ft_lstadd_front.c \
                          libft/ft_memcmp.c \
                          libft/ft_strncmp.c \
                          libft/ft_calloc.c \
                          libft/ft_memchr.c \
                          libft/ft_atoi.c \
                          libft/ft_split.c \
                          parsing/mapcheck.c \
                          parsing/map_check_utils.c \
                          parsing/map_check_vassign.c \
                          parsing/map_check2.c \
                          parsing/map_check3.c \
                          movement.c \
                          movement2.c \
                          debug.c \
                          gnl/get_next_line.c \
                          gnl/get_next_line_utils.c \
                          for_real_engine/for_real_engine.c \
                          for_real_engine/engine_utils.c \
                          for_real_engine/raycast_collision.c \
                          for_real_engine/render_background.c \
                          for_real_engine/render_minimap.c \
                          for_real_engine/render_player.c \
                          for_real_engine/raycasting.c \
                          for_real_engine/render_walls.c \
                          misc.c \
                          for_real_engine/texture_init.c \
                          
OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

UNAME		:=	$(shell uname)

ifeq ($(UNAME), Darwin)
$(NAME): ${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			@ $(MAKE) -C mlx all >/dev/null 2>&1
			@ cp ./mlx/libmlx.a .
			$(CC) $(CFLAGS) -g3 -Ofast -o $(NAME) -Imlx $(OBJS) -Lmlx -lmlx -lm -framework OpenGL -framework AppKit
			@echo "$(GREEN)$(NAME) created[0m ✔️"
endif

ifeq ($(UNAME), Linux)
$(NAME): ${OBJS}
			@echo "$(GREEN)Linux compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			@chmod 777 mlx_linux/configure
			@ $(MAKE) -C mlx_linux all
		)	$(CC) $(CFLAGS) -g3 -o $(NAME) $(OBJS -Imlx_linux -Lmlx_linux -lmlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm
			@echo "$(GREEN)$(NAME) created[0m ✔️"
endif

all:		${NAME}

ifeq ($(UNAME), Darwin)
clean:
			@ ${RM} *.o */*.o */*/*.o
			@ rm -rf $(NAME).dSYM >/dev/null 2>&1
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"
endif

ifeq ($(UNAME), Linux)
clean:
			@ ${RM} *.o */*.o */*/*.o
			@ rm -rf $(NAME).dSYM >/dev/null 2>&1
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"
endif


ifeq ($(UNAME), Linux)
fclean:		clean
			@ ${RM} ${NAME}
			@ $(MAKE) -C mlx_linux clean 
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"
endif

ifeq ($(UNAME), Darwin)
fclean:		clean
			@ ${RM} ${NAME}
			@ rm libmlx.a
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"
endif

re:			fclean all

.PHONY:		all clean fclean re


