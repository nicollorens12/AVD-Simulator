OPTIONS := -O2 -Wall -Wno-sign-compare -Wno-unused-parameter

EXE_NAME = programa

BIN_PATH     = bin/
BUILD_PATH   = build/
DEP_PATH     = dep/
INCLUDE_PATH = include/
SRC_PATH     = src/

################################################################################

# get project files
ALL_CPP := $(shell find $(SRC_PATH) -type f -name "*.cc")
ALL_H := $(shell find $(INCLUDE_PATH) -type f -name "*.h")
ALL_O := $(subst $(SRC_PATH),$(BUILD_PATH),$(subst .cc,.o,$(ALL_CPP)))
ALL_D := $(subst $(SRC_PATH),$(DEP_PATH),$(subst .cc,.d,$(ALL_CPP)))


all: $(BIN_PATH)$(EXE_NAME)

#linking
$(BIN_PATH)$(EXE_NAME): $(ALL_O)
	@echo ' -> linking'
	@g++ $(OPTIONS) -o $@ $(ALL_O)
	@echo Finished!

# generic build rule
$(BUILD_PATH)%.o: $(SRC_PATH)%.cc
	@echo ' -> building:' $<
	@g++ $(OPTIONS) -c $< -o $@ -I$(INCLUDE_PATH) -MMD -MF  $(subst $(BUILD_PATH),$(DEP_PATH),$(@:.o=.d))


.PHONY: clean count init build_and_run

build_and_run:
	make
	./bin/programa ./dicts/words.txt 10 10 42

init:
	mkdir bin build dep

clean:
	@echo Removed files: $(ALL_D) $(ALL_O) $(BIN_PATH)$(EXE_NAME)
	@rm $(ALL_D) $(ALL_O) $(BIN_PATH)$(EXE_NAME)

count:
	@echo ' lines words characters'
	@wc $(ALL_CPP) $(ALL_H) | tail -1

-include $(ALL_D)