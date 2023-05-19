# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jduval <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 13:51:31 by jduval            #+#    #+#              #
#    Updated: 2023/05/18 13:02:23 by jduval           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TEST		:=	$(shell find unitest -name '*.c')
TEST_OBJS	:=	$(TEST:%.c=$(OBJ_DIR)/%.o)

ARCHIVE		:=	unitest/
RUNNER		:=	unitest/test

$(ARCHIVE): $(OBJS)
	ar rcs $(ARCHIVE) $(OBJS)

$(TEST_OBJS): CPPFLAGS+= -I unitest/

$(TEST_OBJS): CFLAGS = -Wall -Wextra -ggdb3

$(RUNNER): $(LIBS_TARGET) $(ARCHIVE) $(TEST_OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(TEST_OBJS) $(ARCHIVE) $(LDLIBS) -o $(RUNNER)

clear:
	rm -rf $(ARCHIVE)
.PHONY: clear

rclean:
	rm -rf test/test
.PHONY: rclean

test: clear fclean rclean $(RUNNER)
.PHONY: test

run:
	cd unitest/ && greatest_parallel ./test
.PHONY: run

v:
	cd unitest/ && greatest_parallel -v ./test
.PHONY: v

gdb:
	cd unitest/ && gdb -args ./test
.PHONY: gdb
