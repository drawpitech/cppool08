##
## EPITECH PROJECT, 2024
## ppool06
## File description:
## Makefile
##

CXX := g++ -std=c++20
CXXFLAGS := -W -Wall -Wextra -Wunused -Wpedantic
CXXFLAGS += -Wundef -Wshadow -Wcast-align
CXXFLAGS += -Wcast-qual -Wunreachable-code
CXXFLAGS += -U_FORTIFY_SOURCE
CXXFLAGS += -iquote ./.
CXXFLAGS += -lcriterion --coverage -g3
LDFLAGS :=

NAME := unit_tests
NAME_ASAN := unit_tests_asan

VPATH := .
SRC := ex00/Droid.cpp

VPATH += tests
SRC += test_ex00.cpp

BUILD_DIR := .build
OBJ := $(SRC:%.cpp=$(BUILD_DIR)/normal/%.o)
ASAN_OBJ := $(SRC:%.cpp=$(BUILD_DIR)/asan/%.o)

DEPS_FLAGS := -MMD -MP
DEPS := $(OBJ:.o=.d)
ASAN_DEPS := $(TEST_OBJ:.o=.d)

all: $(NAME)

# UNIT TESTS
$(BUILD_DIR)/normal/%.o: %.cpp
	@ mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(DEPS_FLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

tests_run: $(NAME)
	@-./$<

.PHONY: $(NAME) tests_run

# ASAN
$(BUILD_DIR)/asan/%.o: %.cpp
	@ mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(DEPS_FLAGS) -o $@ -c $<

$(NAME_ASAN): $(ASAN_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

tests_run_asan: $(NAME_ASAN)
	@-./$<

.PHONY: $(NAME_ASAN) tests_run_asan

re: fclean
	$(MAKE)

.PHONY: re

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ:.o=.gcno)
	$(RM) $(OBJ:.o=.gcda)

fclean: clean
	$(RM) -r $(BUILD_DIR)
	$(RM) $(NAME)

.PHONY: clean fclean

cov: GCOVR_FLAGS := --exclude bonus/
cov: GCOVR_FLAGS += --exclude tests/
cov:
	@ gcovr $(GCOVR_FLAGS)
	@ gcovr $(GCOVR_FLAGS) --branches

