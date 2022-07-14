NAME = cub3D

CC = cc

FLAGS = -Wall -Werror -Wextra -g
# FLAGS = -Wall -Werror -Wextra  -fsanitize=address -g

LIBRARIES =  -lft -L$(LIBFT_DIRECTORY) -lmlx -lm -L$(MINILIBX_DIRECTORY) -framework OpenGL -framework AppKit

LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./libft/
LIBFT_HEADERS = $(LIBFT_DIRECTORY)

MINILIBX = $(MINILIBX_DIRECTORY)libmlx.a
MINILIBX_DIRECTORY = ./minilibx_macos/
MINILIBX_HEADERS = $(MINILIBX_DIRECTORY)

HEADER = cub3d.h $(GNL_D)/get_next_line.h $(ANLS_MAP_D)/analyse_map.h
HEADERS_DIRECTORY = .

GNL_S = get_next_line.c get_next_line_utils.c
GNL_D = gnl/

ANLS_MAP_S = copy_map_to_array.c check_format_map.c init_array_map.c init_texture_struct.c get_color_image_texture.c write_textures_to_struct.c \
				check_game_map.c trim_game_map.c checker_function.c check_utils.c ft_isspace.c

ANLS_MAP_D = analyse_map/

KEY_C_S = init_control_key.c key_control.c mouse_control.c
KEY_C_D = key_control/

DIR_SRC = $(OBJS_DIR)$(GNL_D) $(OBJS_DIR)$(ANLS_MAP_D) $(OBJS_DIR)$(KEY_C_D)

SOURCES_S = main.c\
			$(addprefix gnl/, $(GNL_S)) \
			$(addprefix analyse_map/, $(ANLS_MAP_S)) \
			$(addprefix key_control/, $(KEY_C_S)) \
			handling_errors.c\
			init_player.c\
			game.c init_imgs.c paint_engine.c raycast_utils.c raycast.c draw_minimap.c

OBJS = $(SOURCES_S:%.c=%.o)
OBJS_DIR = objs/
OBJECTS	= $(addprefix $(OBJS_DIR), $(OBJS))

GREEN = \033[0;32m
RED = \033[0;31m
CROSS = \033[9m
MARK = \033[7m
RESET = \033[0m

.PHONY: all clean fclean re bonus clno

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT) $(MINILIBX)
	@$(CC) $(FLAGS) $(INCLUDES)  $(LIBRARIES) $(OBJECTS) -o $(NAME)
	@echo "\n$(MARK) $(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(MARK) $(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(OBJS_DIR)%.o : %.c $(HEADER)
	@mkdir -p $(OBJS_DIR)
	@mkdir -p  $(DIR_SRC)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT): $(LIBFT_DIRECTORY)/*.c $(LIBFT_DIRECTORY)/*.h
	@echo "$(NAME): $(GREEN)Creating $(LIBFT)...$(RESET)"
	@$(MAKE) -sC $(LIBFT_DIRECTORY)

$(MINILIBX):
	@echo "$(NAME): $(GREEN)Creating $(MINILIBX)...$(RESET)"
	@$(MAKE) -C $(MINILIBX_DIRECTORY)

clean:
	@$(MAKE) -C $(LIBFT_DIRECTORY) clean
	@$(MAKE) -C $(MINILIBX_DIRECTORY) clean
	@rm -rf $(OBJECTS) $(OBJS_DIR)
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) -sC $(LIBFT_DIRECTORY) fclean
	@echo "$(CROSS) $(NAME) : $(RED)$(NAME) and $(BONUS_NAME) was deleted$(RESET)"

re: fclean all