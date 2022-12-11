# 1031A Assembly Manual

This repository contains the source files used to build document number 1031-8010, the 1031A Assembly manual.

The document is written using reStructuredText, and built using Sphinx (http://www.sphinx-doc.org/en/master/) to generate a PDF via LaTeX.

Build Instructions for MacOS 12.x
=================================

Installing Sphinx
-----------------

1. Install xcode from the Macintosh App Store
2. From the Mac Terminal, run `sudo xcodebuild -license` to install the xcode Command Line Tools
3. Download macports from https://www.macports.org/install.php
4. From the Mac Finder, run the macports Installer application
5. From the Mac Terminal, run `sudo port install py38-sphinx` to install sphinx
6. From the Mac Terminal, run `sudo port select --set python python38` to set python 3.8 as default
7. From the Mac Terminal, run `sudo port select --set python3 python38` to set python 3.8 as default
8. From the Mac Terminal, run `sudo port select --set sphinx py38-sphinx` to set python 3.8 as the default for Sphinx

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
17. Run `open _build/latex/1031-8010.pdf` to open the newly built PDF
