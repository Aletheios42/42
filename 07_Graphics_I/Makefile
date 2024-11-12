# Subprojects in 07_Graphics_I
SUBPROJECTS = Fdf Fractol So_long

# Default target to clean all subprojects
.PHONY: all fclean $(SUBPROJECTS)

all: fclean

# Clean rule to call make fclean in each subproject
fclean: $(SUBPROJECTS)
	@echo "All subprojects in 07_Graphics_I have been cleaned."

# Rule to call fclean in each subproject directory
$(SUBPROJECTS):
	@echo "Cleaning $@..."
	@$(MAKE) -C $@ fclean

