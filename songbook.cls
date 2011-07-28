\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{songbook}

\DeclareOption{a4paper}
    {\PassOptionsToPackage{a4paper}{geometry}}
\DeclareOption{a5paper}
    {\PassOptionsToPackage{a5paper}{geometry}}
\DeclareOption{b5paper}
    {\PassOptionsToPackage{b5paper}{geometry}}
\DeclareOption{letterpaper}
    {\PassOptionsToPackage{letterpaper}{geometry}}
\DeclareOption{legalpaper}
    {\PassOptionsToPackage{legalpaper}{geometry}}
\DeclareOption{executivepaper}
    {\PassOptionsToPackage{executivepaper}{geometry}}
\DeclareOption{landscape}
    {\PassOptionsToPackage{landscape}{geometry}}

\ExecuteOptions{a4paper}
\ProcessOptions\relax

%\RequirePackage[hscale=0.79, vscale=.93, vcentering=true]{geometry}
\RequirePackage[hscale=0.76, vscale=.905, vcentering=true]{geometry}
\RequirePackage{environ}
\RequirePackage{calc}
\RequirePackage[absolute]{textpos}
\RequirePackage{gchords}
\RequirePackage{needspace}
\RequirePackage{xstring}
\RequirePackage{graphicx}
\RequirePackage{multicol}

\renewcommand{\normalsize}{\fontsize{11pt}{1.15em}\selectfont}
\DeclareMathSizes{11}{9}{9}{9}
%\DeclareMathSizes{11}{10}{10}{10}

\newcommand{\titlefont}{\fontsize{14.4pt}{17pt}\fontseries{bx}\selectfont}
\newcommand{\authorfont}{\fontsize{12pt}{15pt}\fontseries{m}\fontshape{it}\selectfont}
\newcommand{\songfont}{\normalsize\fontseries{m}\selectfont}

\newcommand{\songtitle}[1]{{\titlefont #1}}
\newcommand{\songauthor}[1]{{\authorfont #1}}

\newsavebox{\sectionbox}

\newcounter{versecounter}%
\newcounter{diff}%

\newcommand{\sectionContent}[2]{%
    \setcounter{diff}{0}%
    \par\noindent\llap{{\fontsize{10pt}{1.15em}\selectfont\bfseries #1}\hspace{0.6em}}\ignorespaces#2%
}%

\newcommand{\section}[2]{%
    \savebox{\sectionbox}{%
        \begin{minipage}{\textwidth}%
            \sectionContent{#1}{#2}
        \end{minipage}%
    }%

    \begin{needspace}{\dimexpr\ht\sectionbox+\dp\sectionbox}%
        \sectionContent{#1}{#2}
    \end{needspace}%
}%

\newcommand{\Verse}[1]{%
    \section{\arabic{versecounter}.}{#1}%
    \stepcounter{versecounter}%
}%

\newcommand{\Ref}[2][\@null]{%
    \ifx#1\@null%
        \section{Ref.}{#2}%
    \else%
        \section{Ref~#1.}{#2}%
    \fi%
}%

\newcommand{\Rec}[2][\@null]{%
    \ifx#1\@null%
        \section{Rec.}{\itshape #2}%
    \else%
        \section{Rec~#1.}{\itshape #2}%
    \fi%
}%

\newcommand{\Label}[2]{%
    \section{#1.}{#2}%
}%

\newcommand{\NoLabel}[1]{%
    \section{}{#1}%
}%

%\newcommand{\clearChord}[1]{%
%    \StrSubstitute{#1}{ }{\;\:}[\cleared]%
%    %\StrSubstitute{\cleared}{\#}{\sharp}[\cleared]%
%    %\StrSubstitute{\cleared}{&}{\flat}[\cleared]%
%    \cleared%
%}%

\newcommand{\chordMark}[1]{%
    \@ifundefined{chord#1}{%
        \ClassError{songbook}{%
            Unknown chord #1%
        }{%
            Command 'chord#1' is no defined! Please define it.%
        }%
    }{%
        $\mathbf{\csname chord#1\endcsname}$%
    }%
}%

\newcommand{\Chords}[1]{%
    \section{}{%
        \makeatletter%
        \@for\ch:=#1\do{%
            \chordMark{\ch}$\;\:$%
        }%
        \makeatother%
    }%
    %\section{}{$\mathbf{\clearChord{#1}}$}%
}%

\newsavebox{\chordbox}%
\newsavebox{\textbox}%

\newcommand{\spaceletter}{ }%
\newcommand{\leftletter}{ }%
\newcommand{\rightletter}{ }%

\newsavebox{\joinbox}%
\newcounter{join}

\newcounter{repeat}%
\newcommand{\Repeat}[2]{%
    \ifnum\value{repeat} = #1%
        \setcounter{repeat}{0}%
    \else%
        #2%
        \stepcounter{repeat}%
        \Repeat{#1}{#2}%
    \fi%
}%

\newcommand{\n}{%
    \\%
    \setcounter{diff}{0}%
}%

\catcode`\|=13%
\def|#1|#2|{%
    \StrBetween{#1}{(}{)}[\altChord]%
    \StrDel{#1}{(\altChord)}[\mainChord]%
    \IfStrEq{\altChord}{}{%
        \savebox{\chordbox}{\chordMark{\mainChord}}%
    }{%
        \IfStrEq{\mainChord}{}{%
            \savebox{\chordbox}{$($\chordMark{\altChord}$)$}%
        }{%
            \savebox{\chordbox}{\chordMark{\mainChord}$($\chordMark{\altChord}$)$}%
        }%
    }%
    \savebox{\joinbox}{--}%
    \StrLeft{#2}{1}[\rightletter]%
    \savebox{\textbox}{#2}%
    \ifnum\value{diff} > 0%
        \IfStrEq{\leftletter}{\spaceletter}{%
            \hspace{\value{diff}sp}%
        }{%
            \IfStrEq{\rightletter}{\spaceletter}{%
                \hspace{\value{diff}sp}%
            }{%
                \IfStrEq{\rightletter}{}{%
                    \hspace{\value{diff}sp}%
                }{%
                    \setcounter{join}{\value{diff}/\wd\joinbox}%
                    \ifnum\value{join} = 0%
                        \stepcounter{join}%
                    \fi%
                    \Repeat{\value{join}}{--}%
                }%
            }%
        }%
    \fi%
    \raisebox{4.5ex}{%
        \makebox[0em][l]{%
            \raisebox{-2.35ex}[0ex][0ex]{%
                \usebox{\chordbox}%
            }%
        }%
    }%
    \usebox{\textbox}%
    \setcounter{diff}{\wd\chordbox+200000-\wd\textbox}%
    \StrRight{#2}{1}[\leftletter]%
}%

\newcommand{\Instrument}{}

\newcommand{\setInstrument}[1]{%
    \renewcommand{\Instrument}{#1}%
}%

\def\chordsize{1.8mm}
\def\topfretsiz{0.45mm}

\newcommand{\chordDiagram}[1]{%
    %\expandafter \ifx \csname chord#1\endcsname je \else neni \fi%
    \@ifundefined{chord#1Diagram}{%
        \ClassError{songbook}{%
            Unknown chord #1%
        }{%
            Diagram for chord #1 is not defined!%
        }%
    }{%
        %\upchord{\csname chord#1\endcsname}%
        \csname chord#1Diagram\endcsname%
    }%
}%

\newcounter{chordsXPosition}
\newcounter{chordsYPosition}
\setcounter{chordsXPosition}{\paperwidth-700000}
\setcounter{chordsYPosition}{(\paperheight+\textheight)/2}

\newsavebox{\chordDiagramsBox}

\newcommand{\ChordDiagramsToPrint}{}%

\newcommand{\ChordDiagrams}[1]{%
    \renewcommand{\ChordDiagramsToPrint}{#1}%
}%

\newcommand{\PrintChordDiagrams}{%
    \begin{textblock*}{2900000sp}[1,1](\value{chordsXPosition}sp, \value{chordsYPosition}sp)%
        %\noindent%
        %\usebox{\chordDiagramsBox}%
        \setlength{\parskip}{0ex}%
        \noindent%
        \@for\ch:=\ChordDiagramsToPrint\do{%
            \\\chordDiagram{\ch}%
        }%
    \end{textblock*}%

    \savebox{\chordDiagramsBox}{}%
}%

\newcommand{\Dots}{\dots$\;$}

\NewEnviron{song}[2]{%
    \clearpage%
    \setcounter{versecounter}{1}%
    \setlength{\parskip}{2.2ex}%

    \noindent%
    \songtitle{#1}%
    \hfill\songauthor{#2}%
    \vspace{0.5ex}\par%
    \BODY%

    \IfStrEq{\Instrument}{}{}{%
        \begin{textblock*}{.5\paperwidth}[1,1](\paperwidth-1000000sp, \paperheight-1300000sp)%
            \vfill%
            \hfill%
            \includegraphics[width=.5\paperwidth,height=.5\paperheight, keepaspectratio]{\Instrument.png}%
        \end{textblock*}%
    }%

    \PrintChordDiagrams
}%

%\newsavebox{\songbox}

%\NewEnviron{song}[2]{%
%    \clearpage
%    \setcounter{versecounter}{1}
%
    % song title
%    \noindent%
%    \songtitle{#1}%
%    \hfill\songauthor{#2}%
%    \vspace{0.55cm}\par%
%    \BODY
%
    % song text
%    \savebox{\songbox}{%
%        \begin{minipage}{\textwidth}%
%        \songfont
%                \BODY
%        \end{minipage}%
%    }%
%
%    \ifnum\dimexpr\ht\songbox+\dp\songbox > \textheight
%        \begin{multicols}{2}%
%        \noindent
%            \BODY
%        \end{multicols}%
%    \else
%        \noindent
%        \usebox{\songbox}%
%    \fi
%}
