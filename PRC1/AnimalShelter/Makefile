PN=animal_shelter

CFLAGS=-Wall -Werror -Iproduct -I../Unity -Itest

#add your own other c files here
SHARED=	product/administration.c  
	                         
TEST=$(SHARED) \
             test/Unity/unity.c 

all: 
	gcc $(CFLAGS) product/$(PN).c $(SHARED) -o $(PN) 

adminTest:
	gcc $(CFLAGS) test/administration_test.c $(TEST) -o administrationTest 
   
clean:
	rm -rf administrationTest $(PN) 

valgrind: 
	valgrind ./$(PN)



.PHONY: clean test valgrind
