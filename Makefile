NAME = so_long

CCF = cc -Wall -Wextra -Werror

MLX_INCLUDE = -I/usr/include -Imlx_linux -O3

MLX_LIB = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -O3

RED := \033[0;31m
GREEN := \033[0;32m
YELLOW := \033[33;1m
RESET := \033[0m
CLEAR := \033[K
RETURN := \r
BOLD_PURPLE := \033[35;1m
BOLD_UNDER_GREEN := \033[32;1;4m
BOLD_GREEN := \033[32;1m

S = Source_Code
S_EF=$(S)/External_Functions
S_ERF=$(S)/Error_Functions
S_CF=$(S)/Check_Functions
S_BF=$(S)/Build_Functions
S_OF=$(S)/Other_Functions

FILES=	$(S)/so_long.c $(S_BF)/build_map.c $(S_BF)/build_mlx_images.c $(S_BF)/build_mlx_win.c \
		$(S_CF)/check_arg.c $(S_CF)/check_path2exit.c $(S_CF)/check_pce_ch.c $(S_CF)/check_rectangle.c $(S_CF)/check_walls.c $(S_CF)/check_path2collec.c  $(S_CF)/check_xpm.c \
		$(S_ERF)/err_map_R0.c $(S_ERF)/err_map_R1.c $(S_ERF)/err_map_R2.c \
		$(S_EF)/ft_nstrlen.c $(S_EF)/ft_printf.c $(S_EF)/ft_strchr.c $(S_EF)/ft_strcmp.c $(S_EF)/ft_strrchr.c $(S_EF)/Func_I.c $(S_EF)/Func_II.c $(S_EF)/get_next_line_utils.c $(S_EF)/get_next_line.c $(S_EF)/ft_itoa.c $(S_EF)/ft_strdupp.c \
		$(S_OF)/handle_input.c $(S_OF)/handle_loop_input.c $(S_OF)/shutdown.c

OBJ = 	$(FILES:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
		@echo -n "$(RETURN)$(CLEAR)"
		@echo  -n "$(RETURN)$(BOLD_GREEN)Building the program... $(RESET)$(CLEAR)"
		@sleep 0.63
		@echo  "$(RETURN)$(BOLD_GREEN)Finishing up...$(RESET)$(CLEAR)"
		@sleep 0.60
		@$(CCF) $^ $(MLX_LIB) -o $@
		@echo  "\t$(BOLD_UNDER_GREEN)>>>>>>>YOUR PROGRAM IS READY<<<<<<<$(RESET)"

%.o:%.c
		@echo -n "$(RETURN)$(YELLOW)Compiling:  $(notdir $<)....$(CLEAR)$(RESET)"
		@$(CCF)  -c $< -o $@
		@sleep 0.08
	
clean:
		@echo  -n "$(YELLOW)Cleaning up...$(RESET)$(CLEAR)$(RETURN)"
		@sleep 0.60
		@rm -f $(OBJ)

fclean: clean
		@echo "$(YELLOW)Cleaning up the program...$(RESET)"
		@sleep 0.60
		@rm -f $(NAME)

re: fclean all

map1: all
		@echo "$(YELLOW)running the program...$(RESET)"
		@sleep 0.55
		@./so_long Maps/dust2.ber

map2: all
		@echo "$(YELLOW)running the program...$(RESET)"
		@sleep 0.55
		@./so_long Maps/marley.ber

norm:
		@norminette