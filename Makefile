# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 10:17:46 by rmonnier          #+#    #+#              #
#    Updated: 2016/12/07 16:32:11 by rmonnier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_NAME		=		ft_printf.c\
							ftpf_convert_characters.c\
							ftpf_convert_signed.c\
							ftpf_convert_unsigned.c\
							ftpf_get_format_specifications.c\
							ft_itoa_base_lld.c\
							ft_itoa_base_llu.c\
							ft_unicode_encoder.c\
							ft_unicode_encoder_string.c\
							ftpf_get_raw_data.c\
							ftpf_get_specifiers.c\
							ftpf_process_characters.c\
							ftpf_process_data.c\
							ftpf_process_signed.c\
							ftpf_process_unsigned.c\
							ftpf_tools.c\
							ftpf_is_functions.c
SRCS_PATH		=		srcs/
SRCS			=		$(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJ_NAME		=		$(SRCS_NAME:.c=.o)
OBJ_PATH		=		obj/
OBJ				=		$(addprefix $(OBJ_PATH), $(OBJ_NAME))
NAME			=		libftprintf.a
FLAG			=		-Wall -Werror -Wextra
INC				=		./includes/


all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p obj
	gcc -c $(FLAGS) -I $(INC) $< -o $@

clean:
	make -C libft/ fclean
	/bin/rm -rf $(OBJ)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all
