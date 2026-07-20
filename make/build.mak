export LD_LIBRARY_PATH := $(BUILD_DIR)
GCC_FLAGS := -O1 -fPIC -L$(BUILD_DIR) -I.

include $(filter-out make/%,$(wildcard */build.mak))

$(BUILD_DIR)/obj/%.c.o: %.c
	$(info > Compiling $@)
	mkdir -p $(@D)
	gcc $(GCC_FLAGS) -c $< -o $@

.DEFAULT_GOAL := build
.PHONY: build
build: $(BUILD_TARGETS)

