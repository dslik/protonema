#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import codecs
from string import Template

# -- CUSTOMIZE THIS BLOCK ---------------------------------------------

# General information about the project.
copyright = '2023, David Slik'
author = 'David Slik'
doc_category = '1620'
doc_number = '8201'

# The short X.Y version.
version = '1.0-draft.1'

# The full version, including alpha/beta/rc tags.
release = '1.0.0-draft.1'

latex_logo = 'images/1620A.jpg'

# -- END CUSTOMIZE BLOCK -------------------------------------------------

licensetext = codecs.open('./template/license.md', encoding='utf-8').read() + codecs.open('revisions.tex', encoding='utf-8').read()

extensions = ['sphinx.ext.autodoc',
              'sphinx.ext.todo',
              'sphinx.ext.coverage']
latex_table_style = []
source_suffix = ['.rst', '.md', '.txt']
master_doc = 'template/index'
language = 'en'
exclude_patterns = [ 'readme.md', 'template/license.md']
pygments_style = 'sphinx'
todo_include_todos = True
numfig = True

# -- Options for LaTeX output ---------------------------------------------

latex_documents = [
    (master_doc, '1620-8201.tex', '1620A assembly instructions',
     'DRAFT', 'manual'),
]

latex_contents = r'''
    \licensepage
    \tableofcontents
    \clearpage
    \listoffigures
    \clearpage
    \listoftables
    \clearpage
    \pagenumbering{arabic}
'''

latex_defns = Template(r'''
    \def\licensepage{
        \pagestyle{normal}
        ${licensetext}
        \clearpage
    }
''')

latex_maketitle = r'''
    \begin{titlepage}
        \begingroup % for PDF information dictionary
           \def\endgraf{ }\def\and{\& }%
           \pdfstringdefDisableCommands{\def\\{, }}% overwrite hyperref setup
           \hypersetup{pdfauthor={\constauthor}, pdftitle={\constdoctitle}}%
        \endgroup
        \begin{tikzpicture}[remember picture, overlay]
          \draw[line width = 2pt] ($(current page.north west) + (0.5in,-0.5in)$) rectangle ($(current page.south east) + (-0.5in,0.5in)$);
        \end{tikzpicture}
        \begin{center}
            {\Huge \constprojtitle }\par
            \vspace{10pt}
            {\Large \constdoctitle }\par
            \vspace{20pt}
            \sphinxlogo
            \vspace{20pt}
            {\Large Document control number: \constdocid }\par
            \vspace{10pt}
            {\Large Document revision: \version }\par
            \vspace{10pt}
            {\Large Document date: \constdate }\par
            \vspace{20pt}
        \end{center}
        \begin{flushleft}
            {\normalsize
                ABSTRACT: This document provides instructions on how to assemble and test a \constprojnumfull\ \constprojtitle. A complete bill of materials is included as an annex. 
            }\par
            {\normalsize
               Suggestions and corrections should be directed to \url{http://www.github.com/dslik/protonema/issues}
            }\par
            {\large
               Serial number:\quad\quad\quad\quad\quad\quad\quad\quad Assembly date:\quad\quad\quad\quad\quad\quad\quad\quad Assembled by:
            }\par
        \end{flushleft}
        \setcounter{footnote}{0}
        \let\thanks\relax\let\maketitle\relax
    \end{titlepage}
    \setcounter{page}{1}
    \pagenumbering{roman}
'''

latex_elements = {
    'preamble': r'''
        \newcommand{\constprojnum}{\text{1620}} 
        \newcommand{\constprojnumfull}{\text{\constprojnum A}}
        \newcommand{\constprojtitle}{\text{ALU Trainer}}
        \newcommand{\constdocnum}{\text{8201}}
        \newcommand{\constdocid}{\text{\constprojnum -\constdocnum}}
        \newcommand{\constdoctitle}{\text{Assembly Instructions}}
        \newcommand{\constauthor}{\text{David Slik}}
        \newcommand{\constyear}{\text{2023}}
        \newcommand{\constmonth}{\text{09}}
        \newcommand{\constday}{\text{30}}
        \newcommand{\constdate}{\text{\constyear -\constmonth -\constday}}
        \newcommand{\constreleasetype}{\text{DRAFT}}

        \usepackage{array}
        \setlength\extrarowheight{4pt}

        \usepackage{graphbox}

        % Make table headers lightgray
        \usepackage{colortbl}
        \protected\def\sphinxstyletheadfamily {\cellcolor{lightgray}\sffamily}

        % Change Latex's Part/Chapter/Appendix to Part/Section/Annex
        \addto\captionsenglish{\renewcommand{\partname}{Part~}}
        \addto\captionsenglish{\renewcommand{\chaptername}{Section~}}
        \addto\captionsenglish{\renewcommand{\appendixname}{Annex~}}
        \addto\captionsenglish{\renewcommand{\figurename}{Fig.\enspace}} 
        \usepackage{chngcntr}
        \counterwithout{figure}{chapter}
        \counterwithout{table}{chapter}

        % Change the tables of content/figure/table
        \usepackage{tocloft}
        \setlength{\cftchapnumwidth}{18pt}
        \setlength{\cftsecnumwidth}{24pt}
        \setlength{\cftsubsecnumwidth}{28pt}

        \message{figure}
        \newlength{\myfiglen}
        \renewcommand{\cftfigpresnum}{\figurename}
          \renewcommand{\cftfigaftersnum}{:}
          \settowidth{\myfiglen}{\cftfigpresnum\cftfigaftersnum}
          \addtolength{\cftfignumwidth}{\myfiglen}
        \message{table}
        \newlength{\mytablen}
        \renewcommand{\cfttabpresnum}{\tablename}
          \renewcommand{\cfttabaftersnum}{:}
          \settowidth{\mytablen}{\cfttabpresnum\cfttabaftersnum}
          \addtolength{\cfttabnumwidth}{\mytablen}
        \message{chapter}
        \newlength{\mychaplen}
        \renewcommand{\cftchappresnum}{\chaptername}
          \renewcommand{\cftchapaftersnum}{:}
          \settowidth{\mychaplen}{\cftchappresnum\cftchapaftersnum}
          \addtolength{\cftchapnumwidth}{\mychaplen}

        % Clear pages before new Part
        \usepackage{titlesec}
        \newcommand{\sectionbreak}{\clearpage}

        \usepackage{tikz}
        \usetikzlibrary{calc}

        % Change the page headers
        \makeatletter
        \fancypagestyle{normal}{
            \fancyhf{}
            \fancyhead[LE,LO]{{\py@HeaderFamily \constdocid \ \constdoctitle \ \version}}
            \fancyhead[RE,RO]{{\py@HeaderFamily Public / Controlled}}
            \fancyfoot[LE,LO]{{\py@HeaderFamily Copyright \copyright \ \constyear}}
            \fancyfoot[CE,CO]{{\py@HeaderFamily \constreleasetype}}
            \fancyfoot[RE,RO]{{\py@HeaderFamily\thepage}}
            \renewcommand{\headrulewidth}{0.4pt}
            \renewcommand{\footrulewidth}{0.4pt}
            }
        \fancypagestyle{plain}{
            \fancyhf{}
            \fancyhead[LE,LO]{{\py@HeaderFamily \constdocid \ \constdoctitle \ \version}}
            \fancyhead[RE,RO]{{\py@HeaderFamily Public / Controlled}}
            \fancyfoot[LE,LO]{{\py@HeaderFamily Copyright \copyright \ \constyear}}
            \fancyfoot[CE,CO]{{\py@HeaderFamily \constreleasetype}}
            \fancyfoot[RE,RO]{{\py@HeaderFamily\thepage}}
            \renewcommand{\headrulewidth}{0.4pt}
            \renewcommand{\footrulewidth}{0.4pt}
            }
        \makeatother

        % Create linenumers
        %\usepackage{lineno} 
        %\linenumbers
    ''' + latex_defns.substitute(licensetext=licensetext),   

    'papersize': 'a4paper',
    'fncychap': '',
    'pointsize': '10pt',
    'inputenc': '',
    'utf8extra': '',
    'printindex': '',

    'fontpkg': r'''
        % Set fonts
        \usepackage{fontspec}
        \setsansfont{Arial}
        \setmainfont{Arial}
        \setmonofont{Courier New}

        \DeclareSymbolFont{letters}{OML}{ztmcm}{m}{it}
        \DeclareSymbolFontAlphabet{\mathnormal}{letters}

        % Adjust font size
        \usepackage{scrextend}
        \changefontsizes[10pt]{9pt}
        \usepackage{enumitem}
    ''',

    'tableofcontents': latex_contents,
    'sphinxsetup': 'verbatimhintsturnover=true, VerbatimColor={rgb}{1,1,1}',
    'extraclassoptions': 'openany',
    'releasename': 'Version',
    'maketitle': latex_maketitle,
}

latex_engine = 'xelatex'
latex_use_xindy = False
latex_toplevel_sectioning = 'part'
