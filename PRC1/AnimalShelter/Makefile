PN=animal_shelter
BINDIR=bin

CFLAGS=-Wall -Werror -Iproduct -I../Unity -Itest

SHARED=product/administration.c
TEST=$(SHARED) ../Unity/unity.c

all: $(BINDIR) $(BINDIR)/$(PN)

$(BINDIR):
	mkdir -p $(BINDIR)

$(BINDIR)/$(PN): product/$(PN).c $(SHARED)
	gcc $(CFLAGS) $^ -o $@ 

adminTest: $(BINDIR) $(BINDIR)/administrationTest

$(BINDIR)/administrationTest: test/administration_test.c $(TEST)
	gcc $(CFLAGS) $^ -o $@ 

clean:
	rm -rf $(BINDIR)/*

valgrind: $(BINDIR)/$(PN)
	valgrind ./$(BINDIR)/$(PN)

.PHONY: clean adminTest valgrind
