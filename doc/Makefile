#
# Makefile
#

.PHONY: html uml

help:
	@echo "make [doxygen|uml|grip]"

doxygen:
	doxygen

uml:
	java -jar ~/Downloads/plantuml.jar ./uml/*.uml

grip:
	grip KLUELOGIC_ERGODOX.md
