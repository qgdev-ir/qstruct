QSTRUCT_INSTALL_HEADERS = $(call INSTALL_HEADER_RESOLVER,qstruct)

$(INSTALL_DIR)/usr/lib/libqstruct.so: $(BUILD_DIR)/libqstruct.so
	$(info > Installing $@)
	install -Dm755 $< $@

INSTALL_TARGETS += \
		$(INSTALL_DIR)/usr/lib/libqstruct.so \
		$(call INSTALL_HEADER_TO_TARGET,qstruct,$(QSTRUCT_INSTALL_HEADERS))

