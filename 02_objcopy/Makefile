OBJCOPY=objcopy
# Not work on MacOS ...
OUT_ARCH=elf64-x86-64

a.out: main_objcopy.c example_string.txt.o example_binary.png.o
	$(CC) -o $@ $^

example_string.txt.o: ../example_string.txt
	$(OBJCOPY) -I binary -O $(OUT_ARCH) $< $@

example_binary.png.o: ../example_binary.png
	$(OBJCOPY) -I binary -O $(OUT_ARCH) $< $@

.PHONY: clean
clean:
	-rm -rf a.out *.o
