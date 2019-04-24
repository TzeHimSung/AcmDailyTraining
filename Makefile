DIRS = $(shell find . -maxdepth 10 -type d)
OUT = $(foreach dir,$(DIRS),$(wildcard $(dir)/*.out))
STD = $(foreach dir,$(DIRS),$(wildcard $(dir)/*_std.cpp))

cl:
	rm -rf $(OUT) $(STD)