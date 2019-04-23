DIRS = $(shell find . -maxdepth 10 -type d)
OUT = $(foreach dir,$(DIRS),$(wildcard $(dir)/*.out))

rmout:
	rm -rf $(OUT)