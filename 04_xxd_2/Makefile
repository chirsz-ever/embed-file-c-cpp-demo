XXD=xxd

a.out: main_xxd.o
	$(CC) -o $@ $<

main_xxd.o: example_string.txt.xxd.h example_binary.png.xxd.h

example_string.txt.xxd.h: ../example_string.txt
	$(XXD) -i < $< > $@

example_binary.png.xxd.h: ../example_binary.png
	$(XXD) -i < $< > $@

.PHONY: clean
clean:
	-rm -rf a.out *.o *.xxd.h
