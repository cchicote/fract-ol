# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchicote <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 17:08:35 by cchicote          #+#    #+#              #
#    Updated: 2016/01/08 15:50:27 by cchicote         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCDIR = ./srcobj/

SRCS = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memalloc.c ft_memccpy.c ft_memcpy.c ft_memchr.c ft_memcmp.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_striter.c ft_striteri.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strcat.c ft_strncmp.c ft_strncpy.c ft_strnew.c ft_strnstr.c ft_strstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_itoa.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strtrim.c ft_strjoin.c ft_strsplit.c ft_strlcat.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_isupper.c ft_islower.c ft_swap.c ft_isblank.c ft_isspace.c ft_putnbrendl.c get_next_line.c

SRC = $(addprefix $(SRCDIR), $(SRCS))

OBJ = 	$(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\n"
	@echo "\033[33;36mLLL       OOO   BBBBBBBB  FFFFFFFFFF  TTTTTTTTTT"
	@echo "LLL       OOO   BB    BB  FF              TT"
	@echo "LLL             BB    BB  FF              TT"
	@echo "LLL       III   BBBBBBB   FFFFFF          TT"
	@echo "LLL       III   BB    B   FF              TT"
	@echo "LLL       III   BB     B  FF              TT"
	@echo "LLLLLLLL  III   BB    BB  FF              TT"
	@echo "LLLLLLLL  III   BBBBBBB   FF              TT"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[33;32mNOTICE pour afficher la liste des commandes : make help"

help:
	@echo "\033[33;40;1mGuide :"
	@echo "Pour compiler la bibliotheque (deja fait avec "make all" ou "make")"
	@echo "\tmake all"
	@echo "\nPour n'effacer que les fichier .o"
	@echo "\tmake clean"
	@echo "\nPour effacer les fichiers crees par le makefile"
	@echo "\tmake fclean"
	@echo "\nPour effacer puis recompiler"
	@echo "\tmake re"
	@echo "\nPour check la norme"
	@echo "\tmake norme"

$%.o: %.c
	@gcc -Wall -Werror -Wextra -c $(SRC)

norme:
	@norminette $(SRC)

swag:
	@echo "\033[33;33m                                                                     ";
	@echo "      *******         ***** *    **   ***            **              * ***      ";
	@echo "    *       ***    ******  *  *****    ***        *****            *  ****  *   ";
	@echo "   *         **   **   *  *     *****   ***      *  ***           *  *  ****    ";
	@echo "   **        *   *    *  **     * **      **        ***          *  **   **     ";
	@echo "    ***              *  ***     *         **       *  **        *  ***          ";
	@echo "   ** ***           **   **     *         **       *  **       **   **          ";
	@echo "    *** ***         **   **     *         **      *    **      **   **   ***    ";
	@echo "      *** ***       **   **     *         **      *    **      **   **  ****  * ";
	@echo "        *** ***     **   **     *         **     *      **     **   ** *  ****  ";
	@echo "          ** ***    **   **     *         **     *********     **   ***    **   ";
	@echo "           ** **     **  **     *         **    *        **     **  **     *    ";
	@echo "            * *       ** *      *         *     *        **      ** *      *    ";
	@echo "  ***        *         ***      ***      *     *****      **      ***     *     ";
	@echo " *  *********           ******** ********     *   ****    ** *     *******      ";
	@echo "*     *****               ****     ****      *     **      **        ***        ";
	@echo "*                                            *                                  ";
	@echo " **                                           **                                ";

money:
	@echo "\033[33;32m	        ";
	@echo "	       .       		";
	@echo "	       E       		";
	@echo "	    .x+E:..    		";	
	@echo "	  u8~  E  \'b.  		";
	@echo "	 t8E   E d888> 		";
	@echo "	 88N.  E'8888~ 		";
	@echo "	 88888b&.\'\"\"\'  	";
	@echo "	 '88888888e.   		";
	@echo "	   \"*8888888N  		";
	@echo "	  uu. ^8*8888E 		";
	@echo "	 @888L E \'\"88E 	";
	@echo "	'8888~ E   98~ 		";
	@echo "	 \'*.  E  .*\"  	";
	@echo "	   \'~=R=~\'    	";
	@echo "	       E			";
	@echo "	       .			";

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
