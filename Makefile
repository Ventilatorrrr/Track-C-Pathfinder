NAME	=	pathfinder

CFLG	=	-std=c11 $(addprefix -W, all extra error pedantic) -g

SRC_DIR	= src
INC_DIR	= inc
OBJ_DIR	= obj

INC_FILES = $(wildcard $(INC_DIR)/*.h)
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC_FILES:%.c=%.o)))

LMX_DIR	= libmx
LMX_A := $(LMX_DIR)/libmx.a
LMX_INC := $(LMX_DIR)/inc

all: install

install: $(LMX_A) $(NAME)

$(NAME): $(OBJ_FILES)
	@clang $(CFLG) $(OBJ_FILES) -L$(LMX_DIR) -lmx -o $@
	@printf "\033[32;1mBuild complete:\033[0m $(NAME)\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_FILES)
	@clang $(CFLG) -c $< -o $@ -I$(INC_DIR) -I$(LMX_INC)
	@printf "\033[36;1mCompiled:\033[0m $<\n"

$(OBJ_FILES): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir -p $@
	@printf "\033[33;1mDirectory created:\033[0m $(OBJ_DIR)\n"

$(LMX_A):
	@make -sC $(LMX_DIR)

clean:
	@if [ -d "$(OBJ_DIR)" ]; then rm -rf $(OBJ_DIR); \
	printf "\033[31;1m$(OBJ_DIR) deleted in $(NAME)\033[0m\n"; fi

uninstall:
	@make -sC $(LMX_DIR) $@
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)
	@printf "\033[31;1mUninstalled:\033[0m $(NAME) and $(OBJ_DIR)\n"

reinstall: uninstall all

