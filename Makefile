# Nom du programme
NAME = cub3D

# Compilateur et flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3

# Dossiers
SRCDIR = src
OBJDIR = obj
INCDIR = include
LIBDIR = libft

# Fichiers source
SRCS = $(addprefix $(SRCDIR)/, \
	cub3d.c \
	drawing.c \
	free.c \
	header_parsing.c \
	input.c \
	load_textures_paths.c \
	map_parsing.c \
	parsing_2.c \
	parsing_utils_2.c \
	parsing_utils.c \
	parsing.c \
	raycasting.c \
	render_frame.c \
	rgb_handling.c \
	utils.c \
)

OBJS = $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))

DEPS = $(OBJS:.o=.d)

# Librairies
LIBFT = $(LIBDIR)/libft.a
MLX = minilibx/libmlx.a
MLX_FLAGS = -Lminilibx -lmlx -lXext -lX11 -lm -lz

PASTEL_BLUE     := \033[0;38;2;130;135;206m
PRUSSIAN_BLUE   := \033[0;38;2;28;49;68m
JASPER           := \033[0;38;2;213;87;59m
OLIVINE           := \033[0;38;2;154;184;122m


define ascii_art
	@printf "\033[0;38;2;213;87;59m"; \
	cat logo.txt; \
	printf "\e[0;39m"
endef

# Règles
all: $(NAME) 

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@{ $(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME); } || $(call ascii_art)

-include $(DEPS)
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I$(INCDIR) -c -MMD $< -o $@

$(LIBFT):
	@make -s -C $(LIBDIR)

$(MLX):
	@make -s -C minilibx > /dev/null 2>&1

clean:
	@make -s -C $(LIBDIR) clean
	@make -s -C minilibx clean
	rm -rf $(OBJDIR)

fclean: clean
	@make -s -C $(LIBDIR) fclean
	rm -f $(NAME)

re: fclean all

bonus:
	@$(MAKE) BONUS=1 all



.PHONY: all clean fclean re bonus
