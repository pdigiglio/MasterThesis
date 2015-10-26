#
# Easy Makefile to compile main.tex
#

.PHONY: clean distclean

LaTeX=latexmk
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

#	@$(LaTeX) $(OPTIONS) $<

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
