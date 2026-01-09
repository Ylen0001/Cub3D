# Compiler et options
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -fPIE
AR = ar
ARFLAGS = rc
RM = rm -f

# Dossier des fichiers objets
OBJ_DIR = obj
# Dossier des fichiers sources
SRC_DIR = .

# Nom de la bibliothèque
NAME = libft.a

# Liste des fichiers source
SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
      ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
      ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
      ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
      ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
      ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
      ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
      get_next_line.c get_next_line_utils.c \
      ft_printf_char.c ft_printf_hex.c ft_printf_int.c ft_printf_str.c \
      ft_putchar_count.c ft_putstr_count.c ft_printf.c \
      ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
      ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c \
      ft_lstnew_bonus.c ft_lstmap_bonus.c ft_lstsize_bonus.c \
      ft_strcmp.c

# Liste des fichiers objets
OBJ = $(SRC:.c=.o)

# Règle par défaut
all: ascii_art $(NAME)

DEF_COLOR		:= \033[0;39m
GRAY			:= \033[0;90m
RED				:= \033[0;91m
GREEN			:= \033[0;92m
LIGHT_GREEN     := \033[0;32m
YELLOW			:= \033[0;93m
BLUE			:= \033[0;94m
MAGENTA			:= \033[0;95m
CYAN			:= \033[0;96m
LIGHT_CYAN      := \033[0;36m
WHITE			:= \033[0;97m
BRIGHT_YELLOW   := \033[1;33m
LIGHT_YELLOW    := \033[0;33m
NAVY_BLUE       := \033[0;34m
STEEL_BLUE      := \033[0;38;2;94;99;153m
PASTEL_BLUE     := \033[0;38;2;130;135;206m
RESET			:= \033[0m

# Affichage de l'ASCII art en jaune

# Compilation de la bibliothèque
$(NAME): $(OBJ)
	@echo "$(GRAY)"
	@echo "Création de la bibliothèque $@"
	@$(AR) $(ARFLAGS) $@ $^
	@echo "$(STEEL_BLUE)Bibliothèque $@ créée avec succès.$(RESET)"

ascii_art:
	@echo ""
	@printf "$(PASTEL_BLUE)" # Code couleur ANSI pour le jaune
	@cat libft.txt
	@printf "\033[0m" # Réinitialise la couleur
	@echo ""

# Compilation des fichiers objets
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(GRAY)\rCompilation en cours...$(RESET) "

# Nettoyage des fichiers objets
clean:
	@echo "$(GRAY)Suppression des fichiers objets..."
	@$(RM) $(OBJ)
	@echo "Fichiers objets supprimés."

# Nettoyage complet
fclean: clean
	@echo "Suppression de la bibliothèque libft.a..."
	@$(RM) $(NAME)
	@echo "$(STEEL_BLUE)Bibliothèque libft.a supprimée.$(RESET)"

# Règle pour recompilation
re: fclean all

.PHONY: all clean fclean re
