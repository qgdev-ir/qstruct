QSTRUCT_OBJS := $(patsubst %,$(BUILD_DIR)/obj/%.o,$(call RESOLVE_SOURCES,qstruct,.c))

$(BUILD_DIR)/libqstruct.so: $(QSTRUCT_OBJS)
	$(info > Linking $@)
	gcc $(GCC_FLAGS) --shared $(QSTRUCT_OBJS) -o $@
BUILD_TARGETS += $(BUILD_DIR)/libqstruct.so

