# Minimal makefile for Sphinx documentation
SPHINXOPTS    = 
SPHINXBUILD   = sphinx-build
SPHINXPROJ    = capabilities_selection
SOURCEDIR     = .
BUILDDIR      = _build

latex:
	@$(SPHINXBUILD) -M latexpdf "$(SOURCEDIR)" "$(BUILDDIR)" $(SPHINXOPTS) $(O)

.PHONY: latex Makefile

# Catch-all target: route all unknown targets to Sphinx using the new
# "make mode" option.  $(O) is meant as a shortcut for $(SPHINXOPTS).
%: Makefile
	@$(SPHINXBUILD) -M $@ "$(SOURCEDIR)" "$(BUILDDIR)" $(SPHINXOPTS) $(O)
