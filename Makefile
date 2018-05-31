# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/09 02:33:20 by lmartin-          #+#    #+#              #
#    Updated: 2018/04/06 14:46:58 by lmartin-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	lem-in

CC			=	/usr/bin/clang
MK			=	/bin/mkdir -p
MV			=	/bin/mv
RM			=	/bin/rm -f

O1			=	\033[0;38;5;166m
O2			=	\033[0;2;38;5;166m
G1			=	\033[0;38;5;82m
G2			=	\033[0;2;38;5;82m
R			=	\033[0m

DINC		=	incs libft/incs
INC			=	$(addsuffix /,$(addprefix -I./,$(DINC)))

DOBJ		=	.objs
DDEP		=	.deps
DSRC		=	srcs

NSRC		=	main.c \
				parser/li_parser.c \
				parser/parse_rooms.c parser/parse_tunnels.c\
				parser/hash.c parser/free_room.c \
				lexer/char_lexer.c lexer/li_lexer.c lexer/word_lexer.c \
				algo/li_algo.c algo/ft_move.c \
				err/fatal_error.c err/syntax_error.c

NOBJ		=	$(NSRC:.c=.o)
NDEP		= 	$(NSRC:.c=.d)

SRC			=	$(addprefix $(DSRC)/,$(NSRC))
OBJ			=	$(addprefix $(DOBJ)/,$(NOBJ))
DEP			=	$(addprefix $(DDEP)/,$(NDEP))

DLIB		=	./libft
LIBS		=	$(DLIB)/libft.a
FLIBS		=	-lft

CFLAGS		=	-Wall -Wextra -Werror
DEPFLGS		=	-MMD -MP -MF $(DDEP)/$*.Td
#ASAN		=	-g3 -fsanitize=address
COMP		=	$(CC) $(CFLAGS) $(INC)
PCOMP		=	$(MV) $(DDEP)/$*.Td $(DDEP)/$*.d && touch $@

DDOBJ		=	$(sort $(dir $(OBJ)))
DDDEP		=	$(sort $(dir $(DEP)))

all: libs $(NAME)

$(NAME): $(LIBS) $(DDOBJ) $(DDDEP) $(OBJ)
	echo ""
	echo "$(O1)Compiling [$(O2)$@$(O1)]$(R)"
	$(COMP) -o $@ -L$(DLIB) $(FLIBS) $(OBJ)
	echo "\033[A\033[K$(G1)Compiled  [$(G2)$@$(G1)]$(R)"

$(DDDEP):
	$(MK) $@
	echo "$(G1)Created dependecies directory [$(G2)$@$(G1)]$(R)"

$(DDOBJ):
	$(MK) $@
	echo "$(G1)Created objects directory [$(G2)$@$(G1)]$(R)"

$(DOBJ)/%.o: $(DSRC)/%.c
$(DOBJ)/%.o: $(DSRC)/%.c $(DDEP)/%.d Makefile | $(DDOBJ) $(DDDEP)
	echo "$(O1)Compiling [$(O2)$(notdir $(basename $@))$(O1)]$(R)"
	$(COMP) $(DEPFLGS) -o $@ -c $<
	echo "\033[A\033[K$(G1)Compiled  [$(G2)$(notdir $(basename $@))$(G1)]$(R)"
	$(PCOMP)

$(DDEP)/%.d:	;
-include $(DEP)

libs:
	make -C $(DLIB)

lclean:
	make -C $(DLIB) clean

bclean:
	$(RM) -r $(DOBJ) $(DDEP)

clean: lclean bclean

lfclean: lclean
		make -C $(DLIB) fclean

bfclean: bclean
	$(RM) $(NAME)

fclean: lfclean bfclean

re: fclean all

.PHONY: all clean bclean lclean fclean bfclean lfclean re
ifndef V
.SILENT:
endif
.PRECIOUS: $(DOBJ)/%.d
