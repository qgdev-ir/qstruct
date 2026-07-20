INSTALL_HEADER_RESOLVER = $(filter-out %.internal.h,$(call RESOLVE_SOURCES,$1,.h))
INSTALL_HEADER_TO_TARGET = $(patsubst %,$(INSTALL_DIR)/usr/include/%,$2)

include $(filter-out make/%,$(wildcard */install.mak))

$(INSTALL_DIR)/usr/include/%.h: %.h
	$(info > Installing $@)
	install -Dm644 $< $@

.PHONY: install
install: $(INSTALL_TARGETS)

.PHONY: uninstall
uninstall:
	$(info ! Uninstalling)
	rm -fr $(INSTALL_TARGETS)

