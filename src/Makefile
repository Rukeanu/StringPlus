NAME = s21_string.a 
CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
G_OUT = gcovreport

UTILS_SRCS = s21_memcmp.c \
	s21_memchr.c \
	s21_memset.c \
	s21_strlen.c \
	s21_strncat.c \
	s21_strncmp.c \
	s21_strncpy.c \
	s21_memcpy.c \
	s21_strrchr.c \
	s21_strchr.c \
	s21_strpbrk.c \
	s21_strerror.c \
	s21_to_upper.c \
	s21_trim.c \
	s21_to_lower.c \
	s21_strstr.c \
	s21_strcspn.c \
	s21_strtok.c \
	s21_insert.c
SRCS = $(UTILS_SRCS)
GCOV_SRCS = $(UTILS_SRCS)

SPRINTF_SRCS = s21_sprintf.c \
	parse_format.c \
	init_flags.c \
	process_percent.c \
	parse.c \
	process_flags.c \
	process_int.c \
	process_char.c \
	process_float.c \
	process_string.c \
	process_uint.c \
	utils.c
SRCS += $(SPRINTF_SRCS)
GCOV_SRCS += s21_sprintf.c

SSCANF_SRCS = s21_sscanf.c
SRCS += $(SSCANF_SRCS)
GCOV_SRCS += $(SSCANF_SRCS)

HEADERS = s21_string.h

OBJS_DIR = objs
OBJS = $(patsubst %.c, %.o, $(SRCS))
OBJS_PATH = $(addprefix $(OBJS_DIR)/, $(OBJS))
GCOV_OBJS = $(patsubst %.c, %.o, $(GCOV_SRCS))
GCOV_OBJS_PATH = $(addprefix $(OBJS_DIR)/, $(GCOV_OBJS))

DIR_TESTS = unit_tests
SRC_TESTS = unit_tests.c
HEADER_TEST = $(addprefix $(DIR_TESTS)/, unit_tests.h)

SPRINTF_TESTS_DIR = sprintf
DIRS = $(SPRINTF_TESTS_DIR)
SPRINTF_TESTS = s21_sscanf_tests.c \
	s21_sprintf_c_test.c \
	s21_sprintf_d_test.c \
	s21_sprintf_e_test.c \
	s21_sprintf_f_test.c \
	s21_sprintf_g_test.c \
	s21_sprintf_other_test.c \
	s21_sprintf_ouxX_test.c \
	s21_sprintf_s_test.c
SPRINTF_TESTS_PATH = $(addprefix $(SPRINTF_TESTS_DIR)/, $(SPRINTF_TESTS))
SRC_TESTS += $(SPRINTF_TESTS_PATH)

UTILS_TESTS_DIR = utils
DIRS += $(UTILS_TESTS_DIR)
UTILS_TESTS = s21_memchr_test.c \
	s21_memcmp_test.c \
	s21_memcpy_test.c \
	s21_memset_test.c \
	s21_strchr_test.c \
	s21_strcspn_test.c \
	s21_strerror_test.c \
	s21_strlen_test.c \
	s21_strncat_test.c \
	s21_strncmp_test.c \
	s21_strncpy_test.c \
	s21_strpbrk_test.c \
	s21_strrchr_test.c \
	s21_strstr_test.c \
	s21_strtok_test.c \
	s21_to_lower_test.c \
	s21_to_upper_test.c \
	s21_insert_test.c \
	s21_trim_test.c
UTILS_TESTS_PATH = $(addprefix $(UTILS_TESTS_DIR)/, $(UTILS_TESTS))
SRC_TESTS += $(UTILS_TESTS_PATH)

OBJS_TEST_DIR = test_objs
OBJS_TEST = $(patsubst %.c, %.o, $(SRC_TESTS))
OBJS_TEST_PATH = $(addprefix $(OBJS_TEST_DIR)/, $(OBJS_TEST))
CREATES_DIR = $(addprefix $(OBJS_TEST_DIR)/, $(DIRS))

NAME_TEST = s21_string_test

TEST_FLAGS = --coverage

ifeq ($(shell uname -s), Linux)
	TEST_LIBS = $(shell pkg-config --libs --cflags check) -lm
endif
ifeq ($(shell uname -s), Darwin)
	TEST_LIBS = $(shell pkg-config --libs --cflags check)
endif

REPORT_DEL = report

all: $(NAME)

$(NAME): $(OBJS_PATH)
	ar rcs $(NAME) $(OBJS_PATH)

$(OBJS_DIR)/%.o: %.c Makefile $(HEADERS)
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME_TEST): $(OBJS_TEST_PATH)
	$(CC) $(CFLAGS) $(TEST_FLAGS) $(OBJS_TEST_PATH) $(GCOV_OBJS_PATH) $(NAME) $(TEST_LIBS) -o $(NAME_TEST)

$(OBJS_TEST_DIR)/%.o: $(DIR_TESTS)/%.c $(HEADER_TEST)
	mkdir -p $(OBJS_TEST_DIR) $(CREATES_DIR)
	$(CC) $(CFLAGS) $(TEST_FLAGS) -I. -I $(DIR_TESTS) $(TEST_LIBS) -c $< -o $@

test: $(NAME) $(NAME_TEST)
	./$(NAME_TEST)

gcov_report: test
	lcov -t "gcovreport" -o $(G_OUT).info -c --directory .
	genhtml -o report $(G_OUT).info
	
clean:
	rm -rf $(OBJS_DIR) $(NAME)
	rm -rf *.info $(REPORT_DEL)
	rm -rf $(OBJS_TEST_DIR) $(NAME_TEST)
	rm -rf .clang-format

rebuild: clean all

.PHONY: all clean rebuild test gcov_report
