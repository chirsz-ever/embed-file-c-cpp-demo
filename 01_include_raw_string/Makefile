a.out: main_include_raw_string.cpp example_string.txt.raw.h
	$(CXX) -std=c++11 -o $@ $<

example_string.txt.raw.h: ../example_string.txt
	@printf 'R"(' > $@
	@cat $< >> $@
	@printf ')"' >> $@

.PHONY: clean
clean:
	-rm -rf a.out *.raw.h