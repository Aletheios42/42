# Directories that contain projects with their own Makefile
PROJECTS = 00_Piscine 01_Libft 02_Ft_printf 03_Get_next_line 04_BornToBeRoot \
           05_Proccess 06_Push_Swap 07_Graphics_I 08_Minishell 08_Philo

# Default target to clean everything
.PHONY: all fclean $(PROJECTS)

all: fclean

# fclean rule to recursively call make fclean in each project, if Makefile and rule exist
fclean:
	@for project in $(PROJECTS); do \
		if [ -f $$project/Makefile ]; then \
			if $(MAKE) -C $$project -q fclean >/dev/null 2>&1; then \
				echo "Cleaning $$project..."; \
				$(MAKE) -C $$project fclean; \
			else \
				echo "Skipping $$project: No fclean rule found."; \
			fi \
		else \
			echo "Skipping $$project: No Makefile found."; \
		fi \
	done
	@echo "All projects in 42 have been cleaned."

