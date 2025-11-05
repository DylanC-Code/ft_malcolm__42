# ============================================================================== #
#                                 CONFIGURATION                                  #
# ============================================================================== #

# 📛 Nom du programme
OUT := ft_malcolm

# 📂 Répertoires
SRCS_DIR := srcs/
BUILD_DIR := build/
INCLUDE_DIRS := -Iincludes

# 📦 Compiler & Flags
CC := cc
CFLAGS := -Wall -Wextra -Werror -g3
CPPFLAGS := -Iincludes

# 🛠 Utilitaires
MAKE := make
RM := rm -rf

# 📁 Sources & Objets
SRCS := $(addprefix $(SRCS_DIR), \
		main.c \
)
OBJS := $(patsubst %.c, $(BUILD_DIR)%.o, $(SRCS))

DEPS := $(OBJS:.o=.d) 


# ============================================================================== #
#                               RULES - BUILD FLOW                               #
# ============================================================================== #

# 🎯 Règle principale
all: $(OUT)

# 🧱 Construction de l'exécutable
$(OUT): $(BUILD_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(OUT)

# 🔨 Compilation des .c vers .o
$(BUILD_DIR)%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -MMD -MP $(INCLUDE_DIRS) -c $< -o $@


# ============================================================================== #
#                            DIRECTORY & LIBRARY SETUP                           #
# ============================================================================== #

# 📁 Création du dossier de build
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# ============================================================================== #
#                                   CLEAN RULES                                  #
# ============================================================================== #

clean:
	$(RM) $(BUILD_DIR)

fclean: clean
	$(RM) $(OUT)

re: fclean all

# ============================================================================== #
#                                  PHONY & DEPS                                  #
# ============================================================================== #

# 📌 Cibles qui ne sont pas des fichiers
.PHONY: all clean fclean re

# 📎 Inclusion des dépendances générées automatiquement
-include $(DEPS)