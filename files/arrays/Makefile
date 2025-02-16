C_FILES = $(shell find -type f -name '*.c' -printf ' %P')
O_FILES = $(patsubst %.c, %.o, $(C_FILES))

.PHONY: all
all: $(O_FILES)
	@echo $(C_FILES)
	@echo $(O_FILES)
	gcc -o test $(O_FILES)
	./test

%.o: %.c %.h
	gcc -c -o $@ $(patsubst %.o, %.c, $@)

clean:
	rm -f *.o
	rm -f */*.o
	rm -f test