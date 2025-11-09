# ============================================================================== #
#                                 CONFIGURATION                                  #
# ============================================================================== #

# 📛 Nom du programme
OUT := ft_malcolm
LIB_NAME := libft

# 📂 Répertoires
SRCS_DIR := srcs/
BUILD_DIR := build/
LIB_DIR := $(LIB_NAME)/
INCLUDE_DIRS := -Iincludes -I$(LIB_DIR)includes

# 📦 Compiler & Flags
CC := cc
CFLAGS := -Wall -Wextra -Werror -g3 -std=gnu11 -D_GNU_SOURCE
CPPFLAGS := -Iincludes 

# 🛠 Utilitaires
MAKE := make
RM := rm -rf

# 📁 Sources & Objets
SRCS := $(addprefix $(SRCS_DIR), \
		ft_malcolm.c \
		\
		core/arp_handler.c \
		core/arp_receiver.c \
		core/arp_sender.c \
		core/arp_service.c \
		core/arp_validator.c \
		\
		domain/mac_address.c \
		domain/ip_address.c \
		\
		domain/arp/arp_parser.c \
		\
		infrastructure/cli/cli_config_parser.c \
		infrastructure/cli/cli_usage.c \
		\
		infrastructure/iface/iface_open.c \
		infrastructure/iface/iface.c \
		\
		infrastructure/log/logger.c \
		\
		infrastructure/net/arp_serializer.c \
		infrastructure/net/arp_printer.c \
		infrastructure/net/mac_parser.c \
		\
		infrastructure/permissions.c \
		\
		infrastructure/signal/signal_handler.c \
		\
		shared/hex_utils.c \
)
OBJS := $(patsubst %.c, $(BUILD_DIR)%.o, $(SRCS))

DEPS := $(OBJS:.o=.d) 

# 📚 Libft
LIB_FILE := $(LIB_DIR)libft.a

# ============================================================================== #
#                               RULES - BUILD FLOW                               #
# ============================================================================== #

# 🎯 Règle principale
all: $(OUT)

# 🧱 Construction de l'exécutable
$(OUT): $(BUILD_DIR) $(LIB_FILE) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIB_FILE) $(INCLUDE_DIRS) -lft -L$(LIB_DIR) -o $(OUT)

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

# 📚 Build libft.a
$(LIB_FILE): $(LIB_DIR)
	$(MAKE) -sC $(LIB_DIR)

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