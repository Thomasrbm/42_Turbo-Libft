# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: throbert <throbert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+           #
#    Created: 2024/10/22 05:59:42 by throbert          #+#    #+#              #
#    Updated: 2025/03/23 16:49:55 by throbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ===================
# === VARIABLES ===
# ===================

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
OBJ_DIR = objects

# === Manuellement ajouter les fichiers ===
ALLOCS = allocs/free_split.c allocs/free_tab.c allocs/ft_bzero.c allocs/ft_calloc.c \
	allocs/ft_memcpy.c allocs/ft_memmove.c allocs/ft_memset.c allocs/ft_strdup.c \
	allocs/ft_strndup.c allocs/ft_tabdup.c

COMPARERS = comparers/ft_memcmp.c comparers/ft_strncmp.c

CONVERTERS = converters/ft_atoi.c converters/ft_atoi_base.c converters/ft_itoa.c \
	converters/ft_tolower.c converters/ft_toupper.c

IS_DIRS = is_dirs/ft_isalnum.c is_dirs/ft_isalpha.c is_dirs/ft_isascii.c \
	is_dirs/ft_isdigit.c is_dirs/ft_isprint.c is_dirs/ft_isspace.c

ITER_ON_FT = iter_on_ft/ft_striteri.c iter_on_ft/ft_strmapi.c

LISTS = lists/ft_lstadd_back_bonus.c lists/ft_lstadd_front_bonus.c lists/ft_lstclear_bonus.c \
	lists/ft_lstdelone_bonus.c lists/ft_lstiter_bonus.c lists/ft_lstlast_bonus.c \
	lists/ft_lstmap_bonus.c lists/ft_lstnew_bonus.c lists/ft_lstsize_bonus.c

PRINTERS = printers/ft_putchar_fd.c printers/ft_putendl_fd.c printers/ft_putnbr_fd.c \
	printers/ft_putstr_fd.c printers/print_tab.c

SEARCHERS = searchers/ft_memchr.c searchers/ft_strchr.c searchers/ft_strnstr.c \
	searchers/ft_strrchr.c searchers/ft_tabchr.c

SIZERS = sizers/ft_strlen.c sizers/tab_size.c sizers/tablen.c

SORTERS = sorters/sort_alpha_tab.c sorters/sort_str_tab.c

SPLITTERS = splitters/ft_split.c splitters/ft_strjoin.c splitters/ft_strlcat.c \
	splitters/ft_strlcpy.c splitters/ft_strtok.c splitters/ft_strtrim.c splitters/ft_substr.c

# === Tous les fichiers sources ===
SRCS = $(ALLOCS) $(COMPARERS) $(CONVERTERS) $(IS_DIRS) $(ITER_ON_FT) $(LISTS) \
	$(PRINTERS) $(SEARCHERS) $(SIZERS) $(SORTERS) $(SPLITTERS)

# === Création des .o dans objects/ ===
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

# ===================
# === COMMANDES ===
# ===================

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "\033[35m[OK] Compilation terminée : $(NAME)\033[0m"

# Compilation de chaque fichier .c -> .o
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "\033[36m[CC] Compilation : $< -> $@\033[0m"
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des .o
clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
		echo "\033[33m[INFO] Suppression des fichiers objets...\033[0m"; \
		rm -rf $(OBJ_DIR); \
		echo "\033[32m[OK] Nettoyage terminé !\033[0m"; \
	else \
		echo "\033[33m[INFO] Aucun fichier objet à supprimer.\033[0m"; \
	fi

# Nettoyage complet + .a
fclean: clean
	@if [ -f "$(NAME)" ]; then \
		echo "\033[33m[INFO] Suppression de $(NAME)...\033[0m"; \
		rm -f $(NAME); \
		echo "\033[32m[OK] Suppression complète !\033[0m"; \
	else \
		echo "\033[33m[INFO] Aucun fichier à supprimer.\033[0m"; \
	fi

# Recompile tout proprement
re: fclean all

# ===================
# === PHONY ===
# ===================
.PHONY: all clean fclean re
