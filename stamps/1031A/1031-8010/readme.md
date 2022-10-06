# 1031A Assembly Manual

This repository contains the source files used to build document number 1031-8010, the 1031A Assembly manual.

The document is written using reStructuredText, and built using Sphinx (http://www.sphinx-doc.org/en/master/) to generate a PDF via LaTeX.

Build Instructions for Macintosh 10.15
======================================

Installing Sphinx
-----------------

1. Install xcode from the Macintosh App Store
2. From the Mac Terminal, run `xcode-select --install` to install the xcode Command Line Tools
3. From the Mac Finder, run the xcode application to accept the license
4. Download macports from https://www.macports.org/install.php
5. From the Mac Finder, run the macports Installer application
6. From the Mac Terminal, run `sudo port install py36-sphinx` to install sphinx
7. From the Mac Terminal, run `sudo port select --set python python36` to set python 3.6 as default
8. From the Mac Terminal, run `sudo port select --set sphinx py36-sphinx` to set python 3.6 as the default for Sphinx
9. From the Mac Terminal, run `sudo port install py36-sphinxcontrib-bibtex` to install the bibtex bibliography extension to sphinx

The following additional packages may be required:

* `sudo port install py36-sphinxcontrib-qthelp`
* `sudo port install py36-sphinxcontrib-serializinghtml`
* `sudo port install py36-sphinxcontrib-htmlhelp`
* `sudo port install py36-sphinxcontrib-jsmath`
* `sudo port install py36-sphinxcontrib-devhelp`
* `sudo port install py36-sphinxcontrib-applehelp`

Installing LaTeX
----------------

9. From the Mac Terminal, run `sudo port install texlive-latex` to install latex
10. From the Mac Terminal, run `sudo port install texlive-xetex` to install xelatex
11. From the Mac Terminal, run `sudo port install latexmk` to install latexmk
12. From the Mac Terminal, run `sudo port install texlive` to install texlive
13. From the Mac Terminal, run `sudo port install texlive-latex-extra` to install texlive extras

Building the Document
---------------------

14. Download the .zip archive of this repository
15. From the Mac Terminal, in the 1031A-master directory, cd into the docs/assembly directory
16. Run `make latexpdf` to build the document
16. Run `open _build/latex/1031-8010.pdf` to open the newly built PDF
