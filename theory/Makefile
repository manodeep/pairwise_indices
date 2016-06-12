include ../theory.options ../common.mk

ifneq ($(COMPILE_PYTHON_EXT), 0)
  PYTHON_DIR := python_bindings
else
  PYTHON_DIR := 
  $(warning $(ccmagenta) Not compiling C extensions for theory. Either python or numpy not available $(ccreset))
endif


DIRS:= theory 
BUILDDIRS := $(DIRS:%=build-%)
BUILDDIRS += build-examples
LIBDIRS   := $(DIRS:%=lib-%)
INSTALLDIRS := $(DIRS:%=install-%)
CLEANDIRS := $(DIRS:%=clean-%)

all: $(BUILDDIRS) ../common.mk ../theory.options Makefile logbins | dirs
dirs:  | ../lib ../bin ../include
../lib ../bin ../include: 
	mkdir -p $@

$(DIRS): $(BUILDDIRS)
$(BUILDDIRS):
	$(MAKE) -C $(@:build-%=%)

build-examples:$(LIBDIRS)

install: $(INSTALLDIRS) all
$(INSTALLDIRS):
	$(MAKE) -C $(@:install-%=%) install

lib: $(LIBDIRS) all
$(LIBDIRS):
	$(MAKE) -C $(@:lib-%=%) lib

clean: $(CLEANDIRS)
	$(RM) logbins $(OBJS1)

$(CLEANDIRS):
	$(MAKE) -C $(@:clean-%=%) clean

distclean: $(CLEANDIRS)
	$(RM) ../bin/logbins
	$(MAKE) -C $(@:clean-%=%) distclean


.PHONY: $(DIRS)
.PHONY: $(BUILDDIRS)
.PHONY: $(INSTALLDIRS)
.PHONY: $(LIBDIRS)
.PHONY: $(CLEANDIRS)
.PHONY: all install clean test

all: $(targets) $(PYTHON_DIR) logbins

OBJS1= logbins.o ../utils/utils.o 
logbins: $(OBJS1)  | dirs 
	$(CC) $(OBJS1) $(CLINK) -o $@
../bin/%: %
	cp -p $< $@

%.o: %.c Makefile ../common.mk ../theory.options
	$(CC) $(CFLAGS) -c $< -o $@ 


.PHONY: clean celna clena celan $(targets) libs install tests distclean realclean distclena realclena

### Must create the libraries first before making the examples.
examples: examples/run_correlations 

## Not a phony target
examples/run_correlations: libs
	$(MAKE) -C examples

test: tests
tests:  
	$(MAKE) -C tests

