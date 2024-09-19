NAME = libmx.a
CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

SRCD = src
INCD = inc
OBJD = obj

INC = libmx.h
INCS = $(INCD)/$(INC)

SRC = $(wildcard $(SRCD)/*.c)
OBJS = $(patsubst $(SRCD)/%.c, $(OBJD)/%.o, $(SRC))

all: install

install: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $@ $^
	@printf "\r\33[2K$@\t   \033[32;1mcreated\033[0m\n"

$(OBJD)/%.o: $(SRCD)/%.c $(INCS)
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(INCD)
	@printf "\r\33[2K$(NAME)\t   \033[33;1mcompile \033[0m$(<:$(SRCD)/%.c=%) "

$(OBJD):
	@mkdir -p $@

clean:
	@rm -rf $(OBJD)
	@printf "$(OBJD)\t   \033[31;1mdeleted\033[0m\n"

uninstall: clean
	@rm -rf $(NAME)
	@printf "$(NAME)\t   \033[31;1muninstalled\033[0m\n"

reinstall: uninstall install

