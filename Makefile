CC=gcc
FLAGS=-Wall -ansi -c -ggdb
EXEC=unit-test
SRCS=utest.c mock_display.c test.c \
test_suite_console.c \
test_suite_display.c \
test_suite_screen.c \
test_suite_screen_action.c \
test_suite_value_to_str.c \
test_suite_screen_value.c \
test_suite_screen_option.c \
stack.c console.c display.c screen.c screen_text.c screen_action.c  screen_option.c \
screen_value.c utils.c
OBJS = $(SRCS:.c=.o)
INSTALL_PATH=bin

all: $(EXEC)

test: $(EXEC)
	bin/$(EXEC)

$(EXEC): $(OBJS)
	@mkdir -p $(INSTALL_PATH)
	$(CC) obj/*.o -o $(INSTALL_PATH)/$(EXEC) 

.c.o:
	@echo $<
	@mkdir -p obj
	@$(CC) $(FLAGS) $< -o obj/$*.o

clean:
	@rm -rf obj/*
	@rm -rf bin/*
