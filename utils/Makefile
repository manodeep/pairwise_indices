include ../common.mk
SRC   := cosmology_params.c gridlink.c gridlink_mocks.c progressbar.c set_cosmo_dist.c utils.c
OBJS  := $(SRC:.c=.o)
INCL  := avx_calls.h cellarray.h cellarray_mocks.h cosmology_params.h defs.h function_precision.h gridlink.h gridlink_mocks.h \
         progressbar.h set_cosmo_dist.h set_cosmology.h sglib.h utils.h

all: $(OBJS) Makefile ../common.mk ../theory.options ../mocks.options

%.o: %.c $(INCL) ../theory.options ../common.mk ../mocks.options Makefile
	$(CC) $(CFLAGS) -c $< -o $@

set_cosmo_dist.o: set_cosmo_dist.c $(INCL) ../mocks.options 
	$(CC) $(CFLAGS) $(GSL_CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

clena: clean
celan: celan


