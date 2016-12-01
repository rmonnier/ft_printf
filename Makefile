# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 10:17:46 by rmonnier          #+#    #+#              #
#    Updated: 2016/11/25 13:43:26 by rmonnier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_NAME		=		ft_printf.c\
							characters_conv.c\
							format_specifications_parser.c\
							ft_itoa_base_lld.c\
							ft_itoa_base_llu.c\
							ft_unicode_encoder.c\
							get_raw_data.c\
							get_specifiers.c\
							process_data.c\
							signed_conv.c\
							unsigned_conv.c\
							tools.c
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
