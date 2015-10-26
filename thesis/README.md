`MasterThesis/thesis`
=====================

That's where the LaTeX source code for the thesis will be.

 * `data` contains data and tables which will be included in `main.tex`.
 The directory is "shared" meaning that in `../src` there is a link to it; nevertheless the "true" folder is here so that the `.tar.gz` archive obtained via `make dist` compiles properly.

Makefile
--------
`./Makefile` requires `latexmk` to be installed.
	Run `make help` for more information about the options available.
