SRCDIR = src
BUILDDIR = build
ENTRY = splitfile.c
PACKAGENAME = splitfile
CC := $(shell command -v clang 2> /dev/null || \
	  command -v gcc 2> /dev/null || \
      echo cc)

.DEFAULT_GOAL = build
.PHONY = build install uninstall

build:
	@mkdir -p $(BUILDDIR)
	$(CC) -o $(BUILDDIR)/$(PACKAGENAME) $(SRCDIR)/$(ENTRY)
	@echo "Installed splitfile package to /usr/loca/bin/splitfile"


install: build
	@cp $(BUILDDIR)/$(PACKAGENAME) /usr/local/bin/$(PACKAGENAME)
	@rm -r $(BUILDDIR)


uninstall:
	@if [ -f /usr/local/bin/$(PACKAGENAME) ]; then rm /usr/local/bin/$(PACKAGENAME) && echo "Uninstalled package"; else echo "Nothing to uninstall"; fi
