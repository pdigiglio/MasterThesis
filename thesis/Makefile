#
# Easy Makefile to compile main.tex
#

.PHONY: clean distclean dist help

LaTeX=latexmk
# Check if latexmk is installed
isNotInstalled = $(shell which $(LaTeX) 2> /dev/null; echo $$?)
ifeq ($(isNotInstalled),1)
$(info WARNING >> $(LaTeX) is not installed, using latex)
endif

LaTeX=latex
# Check if latexmk is installed
isNotInstalled = $(shell which $(LaTeX) 2> /dev/null; echo $$?)
ifeq ($(isNotInstalled),1)
$(error ERROR >> $(LaTeX) is not installed, exiting)
endif

# default format is -pdf
ifndef format
format=pdf
else
# TODO implement a stop
#ifneq($(format),dvi)
#@echo "a"
#endif
endif

OPTIONS=-$(format) -shell-escape

MAIN=main
$(MAIN): %: %.tex
	@echo "`tput bold`$(LaTeX)`tput sgr0`"\
		"`tput setaf 1`$(OPTIONS)`tput sgr0`"\
		"`tput setaf 2`$<`tput sgr0`"
	@$(LaTeX) $(OPTIONS) $<

clean:
	@echo "`tput bold`rm`tput sgr0`"\
		"`tput setaf 1`--recursive --force --verbose`tput sgr0`"\
		"`tput setaf 2`*.log *.out *.aux *.fls *.fdb_latexmk`tput sgr0`"
	@rm --recursive --force --verbose *.log *.out *.aux *.fls *.ind *.ilg *.fdb_latexmk

distclean: clean
	@echo "`tput bold`rm`tput sgr0`"\
		"`tput setaf 1`--recursive --force --verbose`tput sgr0`"\
		"`tput setaf 2`*.pdf *.dvi`tput sgr0`"
	@rm --recursive --force --verbose *.pdf *.dvi

thisFolder = $(shell basename $$(pwd))
now        = $(shell date "+%G-%m-%d_at_%H-%M-%S")
dist: distclean
	@cd ..; tar -cvzf $(thisFolder)_of_$(now).tar.gz --exclude-vcs $(thisFolder)/

#	echo $(thisFolder) at $(now)

help:
	@echo -e "`tput setaf 1`>> Options available`tput sgr0`\n"\
		"`tput bold`make`tput sgr0`           "\
		"Builds `tput setaf 2`\"$(MAIN).tex\"`tput sgr0` trying to use latexmk (if it's not installed, uses latex)\n"\
		"`tput bold`make help`tput sgr0`      "\
		"Prints this help\n"\
		"`tput bold`make clean`tput sgr0`     "\
		"Removes `tput setaf 2`*.log *.out *.aux *.fls *.fdb_latexmk`tput sgr0` files\n" \
		"`tput bold`make distclean`tput sgr0` "\
		"Calls `tput bold`clean`tput sgr0` and removes `tput setaf 2`*.pdf *.dvi`tput sgr0` files\n" \
		"`tput bold`make dist`tput sgr0`      "\
		"Calls `tput bold`distclean`tput sgr0` and creates a `tput setaf 2`.tar.gz`tput sgr0` archive of source files in ../\n" \
