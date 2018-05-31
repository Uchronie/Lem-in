# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/09 02:33:20 by lmartin-          #+#    #+#              #
#    Updated: 2017/11/17 21:48:18 by lmartin-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

CC			=	/usr/bin/clang
MK			=	/bin/mkdir -p
MV			=	/bin/mv
RM			=	/bin/rm -f
AC			=	/usr/bin/ar rc
RA			=	/usr/bin/ranlib

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

NSRC		=	put/ft_print_memory.c put/ft_putchar.c put/ft_putendl.c \
				put/ft_putnbr.c put/ft_putstr_fd.c put/ft_putbase.c \
				put/ft_putchar_fd.c put/ft_putendl_fd.c put/ft_putnbr_fd.c \
				put/ft_putstr.c put/ft_putlst.c put/ft_putnstr.c\
				mem/ft_bzero.c mem/ft_memalloc.c mem/ft_memset.c \
				mem/ft_memchr.c mem/ft_memcmp.c mem/ft_memcpy.c \
				mem/ft_memdel.c mem/ft_memmove.c mem/ft_memrealloc.c \
				str/ft_strcat.c str/ft_strcmp.c str/ft_strdup.c \
				str/ft_striteri.c str/ft_strlen.c str/ft_strncat.c \
				str/ft_strnequ.c str/ft_strrchr.c str/ft_strstr.c \
				str/ft_strchr.c str/ft_strcpy.c str/ft_strequ.c \
				str/ft_strjoin.c str/ft_strmap.c str/ft_strncmp.c \
				str/ft_strnew.c str/ft_strrev.c str/ft_strsub.c \
				str/ft_strclr.c str/ft_strdel.c str/ft_striter.c \
				str/ft_strlcat.c str/ft_strmapi.c str/ft_strncpy.c \
				str/ft_strnstr.c str/ft_strsplit.c str/ft_strtrim.c \
				str/ft_strnum.c str/ft_strmatch.c \
				str/ft_strndup.c str/ft_strjoinfree.c str/ft_strcount.c\
				class/ft_isalnum.c class/ft_isalpha.c class/ft_isascii.c \
				class/ft_isdigit.c class/ft_islower.c class/ft_isprint.c \
				class/ft_isupper.c class/ft_tolower.c class/ft_toupper.c \
				convert/ft_atoi.c convert/ft_atoi_base.c convert/ft_itoa.c \
				convert/ft_itoa_base.c \
				lst/ft_lstadd.c lst/ft_lstappend.c lst/ft_lstdel.c \
				lst/ft_lstdelone.c lst/ft_lstiter.c lst/ft_lstmap.c \
				lst/ft_lstnew.c lst/ft_lstfind.c lst/ft_lstremove_if.c \
				lst/ft_lstfree.c lst/ft_lstfree_elem.c lst/ft_lstlen.c \
				lst/ft_lstlast.c lst/ft_lstsort.c lst/ft_lstswap.c \
				lst/ft_lstcpy.c \
				numbers/ft_pow.c \
				tab/ft_tablen.c tab/ft_tabcpy.c tab/ft_tabfree.c\
				get_next_line/get_next_line.c \
				btree/ft_btnode.c btree/ft_btnode_noal.c btree/ft_btfree.c \
				btree/ft_btdensity.c btree/ft_btdepth.c \
				btree/ft_btaddlr.c btree/ft_btaddrl.c \
				ft_printf/pf_conv.c ft_printf/pf_convwc.c ft_printf/pf_getnb.c \
				ft_printf/pf_getnb2.c ft_printf/pf_getptr.c ft_printf/pf_getchr.c \
				ft_printf/pf_getpad.c ft_printf/pf_pads.c ft_printf/pf_readfmt.c \
				ft_printf/pf_readfmt2.c ft_printf/pf_wildcard.c \
				ft_printf/ft_printf.c

NOBJ		=	$(NSRC:.c=.o)
NDEP		= 	$(NSRC:.c=.d)

SRC			=	$(addprefix $(DSRC)/,$(NSRC))
OBJ			=	$(addprefix $(DOBJ)/,$(NOBJ))
DEP			=	$(addprefix $(DDEP)/,$(NDEP))

CFLAGS		=	-Wall -Wextra -Werror
DEPFLGS		=	-MMD -MP -MF $(DDEP)/$*.Td
COMP		=	$(CC) $(CFLAGS) $(INC)
PCOMP		=	$(MV) $(DDEP)/$*.Td $(DDEP)/$*.d && touch $@

DDOBJ		=	$(sort $(DOBJ) $(dir $(OBJ)))
DDDEP		=	$(sort $(DDEP) $(dir $(DEP)))

all: $(NAME)

$(NAME): $(DDOBJ) $(DDDEP) $(OBJ) Makefile
	echo ""
	echo "$(O1)Compiling [$(O2)$@$(O1)]$(R)"
	$(AC) $@ $(OBJ)
	echo "\033[A\033[K$(G1)Compiled  [$(G2)$@$(G1)]$(R)"
	echo "$(O1)Indexing [$(O2)$@$(O1)]$(R)"
	$(RA) $@
	echo "\033[A\033[K$(G1)Indexed  [$(G2)$@$(G1)]$(R)"

$(DDDEP):
	$(MK) $@
	echo "$(G1)Created dependecies directory [$(G2)$@$(G1)]$(R)"

$(DDOBJ):
	$(MK) $@
	echo "$(G1)Created objects directory [$(G2)$@$(G1)]$(R)"

$(DOBJ)/%.o: $(DSRC)/%.c
$(DOBJ)/%.o: $(DSRC)/%.c $(DDEP)/%.d Makefile
	echo "$(O1)Compiling [$(O2)$(notdir $(basename $@))$(O1)]$(R)"
	$(COMP) $(DEPFLGS) -o $@ -c $<
	echo "\033[A\033[K$(G1)Compiled  [$(G2)$(notdir $(basename $@))$(G1)]$(R)"
	$(PCOMP)

$(DDEP)/%.d:	;
-include $(DEP)

clean:
	$(RM) -r $(DOBJ) $(DDEP)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
.PRECIOUS: $(DOBJ)/%.d
ifndef V
.SILENT:
endif
