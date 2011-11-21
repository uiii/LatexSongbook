\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{songbook}

\newcommand\@ptsize{9}

\DeclareOption{a4paper}{
    \PassOptionsToPackage{a4paper}{geometry}
    \renewcommand\@ptsize{12}   
}
\DeclareOption{a5paper}{
    \PassOptionsToPackage{a5paper}{geometry}
    \renewcommand\@ptsize{11}
}
\DeclareOption{b5paper}{
    \PassOptionsToPackage{b5paper}{geometry}
    \renewcommand\@ptsize{11}   
}
\DeclareOption{letterpaper}{
    \PassOptionsToPackage{letterpaper}{geometry}
    \renewcommand\@ptsize{12}   
}
\DeclareOption{legalpaper}{
    \PassOptionsToPackage{legalpaper}{geometry}
    \renewcommand\@ptsize{12}   
}
\DeclareOption{executivepaper}{
    \PassOptionsToPackage{executivepaper}{geometry}
    \renewcommand\@ptsize{12}   
}
\DeclareOption{landscape}{
    \PassOptionsToPackage{landscape}{geometry}
    \renewcommand\@ptsize{12}   
}

\DeclareOption{9pt}
    {\renewcommand\@ptsize{9}}
\DeclareOption{10pt}
    {\renewcommand\@ptsize{10}}
\DeclareOption{11pt}
    {\renewcommand\@ptsize{11}}
\DeclareOption{12pt}
    {\renewcommand\@ptsize{12}}
\DeclareOption{14pt}
    {\renewcommand\@ptsize{14}}

\ExecuteOptions{a4paper, 12pt}
\ProcessOptions\relax

\input{fontsize\@ptsize.clo}

%\RequirePackage[hscale=0.76, vscale=.905, vcentering=true, showframe]{geometry}
\RequirePackage[hscale=0.76, vscale=.905, vcentering=true]{geometry}
\RequirePackage{environ}
\RequirePackage{calc}
%\RequirePackage[absolute, showboxes]{textpos}
\RequirePackage[absolute]{textpos}
\RequirePackage{gchords}
\RequirePackage{needspace}
\RequirePackage{xstring}
\RequirePackage{graphicx}
\RequirePackage{multicol}

%\renewcommand{\normalsize}{\fontsize{11pt}{1.15em}\selectfont}
\renewcommand{\normalsize}{\normalfontsize\selectfont}
\DeclareMathSizes{\basefontsize}{\chordfontsize}{9}{9}
%\DeclareMathSizes{11}{10}{10}{10}

\newcommand{\titlefont}{\titlefontsize\fontseries{bx}\selectfont}
\newcommand{\authorfont}{\authorfontsize\fontseries{m}\fontshape{it}\selectfont}
\newcommand{\songfont}{\normalsize\fontseries{m}\selectfont}

\newcommand{\songtitle}[1]{{\titlefont #1}}
\newcommand{\songauthor}[1]{{\authorfont #1}}

\newsavebox{\sectionbox}

\newcounter{versecounter}%
\newcounter{diff}%

\newcommand{\sectionContent}[2]{%
    \setcounter{diff}{0}%
    \par\noindent\llap{{\sectionfontsize\selectfont\bfseries #1}\hspace{0.6em}}\ignorespaces#2%
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

\newcommand{\chordMark}[2][0]{%
    \@ifundefined{chord#2}{%
        \ClassError{songbook}{%
            Unknown chord #2%
        }{%
            Command 'chord#2' is no defined! Please define it.%
        }%
    }{%
        \if0#1%
            $\mathbf{\csname chord#2\endcsname}$%
        \else%
            $\scriptstyle\mathbf{\csname chord#2\endcsname}$%
        \fi%
    }%
}%

\input{chords}

\newcommand{\Chords}[1]{%
    \section{}{%
        \makeatletter%
        \@for\ch:=#1\do{%
            \chordMark{\ch}$\;\:$%
        }%
        \makeatother%
    }%
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

\newcommand{\instrumentImage}{}

\newcommand{\setInstrument}[1]{%
    \input{#1}
}%

\def\chordsize{1.8mm}
%\def\chordsize{2.4mm}
\def\topfretsiz{0.45mm}

\newcommand{\chordDiagramError}{0}%

\newcommand{\reportUnknownChordDiagrams}{%
    \renewcommand{\chordDiagramError}{1}%
}%

\newcommand{\dontReportUnknownChordDiagrams}{%
    \renewcommand{\chordDiagramError}{0}%
}%

\newcommand{\chordDiagram}[1]{%
    %\expandafter \ifx \csname chord#1\endcsname je \else neni \fi%
    \@ifundefined{chord#1Diagram}{%
        \if\chordDiagramError1%
            \ClassError{songbook}{%
                Unknown diagram of #1 chord%
            }{%
                Diagram for chord #1 is not defined!%
            }%
        \fi%
    }{%
        %\upchord{\csname chord#1\endcsname}%
        \csname chord#1Diagram\endcsname%
    }%
}%

%\newcounter{chordsXPosition}
\newcounter{chordsYPosition}
%\setcounter{chordsXPosition}{\paperwidth-700000}
\setcounter{chordsYPosition}{(\paperheight+\textheight)/2}

\newsavebox{\chordDiagramsBox}

\newcommand{\ChordDiagramsToPrint}{}%

\newcommand{\ChordDiagrams}[1]{%
    \renewcommand{\ChordDiagramsToPrint}{#1}%
}%

\newsavebox{\currentChord}

\newcommand{\nothing}{}

\newcounter{chordsHeight}%
\newcounter{chordsCount}%
\newcounter{chordsTotalCount}%
\newcounter{breakCount}%
\newcounter{loopCount}%
\newcounter{shift}%
\newcounter{stopChord}%
\newcounter{overHeight}%
\newcommand{\chordsMaxHeight}{\dimexpr\textheight-0cm}%
\newcommand{\PrintChordDiagrams}{%
    \setcounter{chordsHeight}{0}
    \setcounter{chordsTotalCount}{0}
    \@for\ch:=\ChordDiagramsToPrint\do{%
        \savebox{\currentChord}{\chordDiagram{\ch}}%
        \addtocounter{chordsHeight}{\ht\currentChord}%
        \stepcounter{chordsTotalCount}%
    }%
    \ifnum\value{chordsHeight}>\chordsMaxHeight%
        \setcounter{overHeight}{\value{chordsHeight}-\chordsMaxHeight}%
    \else%
        \setcounter{overHeight}{0}%
    \fi%
    \newcommand{\leftChords}{%
        \setcounter{chordsCount}{0}%
        \setcounter{chordsHeight}{0}%
        \setcounter{stopChord}{0}%
        %\setcounter{breakCount}{\value{chordsTotalCount}-10}
        %\setcounter{loopCount}{1}%
        \@for\ch:=\ChordDiagramsToPrint\do{%
            \savebox{\currentChord}{\chordDiagram{\ch}}%
            \addtocounter{chordsHeight}{\ht\currentChord}%
            %\ifnum\value{loopCount}<\value{breakCount}%
            \ifnum\value{stopChord}=0%
                \ifnum\value{chordsHeight}<\value{overHeight}%
                    %\\\chordDiagram{\ch}%
                    \\\usebox{\currentChord}%
                    \stepcounter{chordsCount}%
                \else%
                    \ifnum\value{overHeight}>0
                        \\\usebox{\currentChord}%
                        \stepcounter{chordsCount}%
                        \stepcounter{stopChord}%
                    \fi
                \fi%
            \fi
            %\stepcounter{loopCount}%
        }%
    }%
    \newcommand{\rightChords}{%
        \setcounter{breakCount}{\value{chordsTotalCount}-\value{chordsCount}}%
        \setcounter{loopCount}{1}%
        \@for\ch:=\ChordDiagramsToPrint\do{%
            %\ifnum\value{loopCount}>\value{breakCount}%
            \ifnum\value{loopCount}>\value{chordsCount}%
                \if\chordDiagram{\ch}\nothing
                \else
                    \\\chordDiagram{\ch}%
                \fi
            \fi%
            \stepcounter{loopCount}%
        }%
    }%
    \savebox{\currentChord}{\chordDiagram{C}}%%%%%
    \setcounter{shift}{\wd\currentChord}%
    %\ifnum\value{chordsTotalCount}>11\setcounter{shift}{2600000}\fi%
    %\begin{textblock*}{2900000sp}[1,1](\value{chordsXPosition}sp-\value{shift}sp, \value{chordsYPosition}sp)%
    \begin{textblock*}{\wd\currentChord}[1,1](.964\paperwidth-\value{shift}sp, \value{chordsYPosition}sp)%
        %\noindent%
        %\usebox{\chordDiagramsBox}%
        \setlength{\parskip}{0ex}%
        \noindent%
        \leftChords%
%        \@for\ch:=\ChordDiagramsToPrint\do{%
%            \\\chordDiagram{\ch}%
%        }%
    \end{textblock*}%

    %\begin{textblock*}{2900000sp}[1,1](\value{chordsXPosition}sp, \value{chordsYPosition}sp)%
    \begin{textblock*}{\wd\currentChord}[1,1](.964\paperwidth, \value{chordsYPosition}sp)%
        %\noindent%
        %\usebox{\chordDiagramsBox}%
        \setlength{\parskip}{0ex}%
        \noindent%
        \rightChords%
%        \@for\ch:=\ChordDiagramsToPrint\do{%
%            \\\chordDiagram{\ch}%
%        }%
    \end{textblock*}%

    %\savebox{\chordDiagramsBox}{}%
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

    \IfStrEq{\instrumentImage}{}{}{%
        %\begin{textblock*}{.5\paperwidth}[1,1](\paperwidth-1000000sp, \paperheight-1300000sp)%
        \begin{textblock*}{.5\paperwidth}[1,1](.965\paperwidth, .967\paperheight)%
            \vfill%
            \hfill%
            \includegraphics[width=.5\paperwidth,height=.5\paperheight, keepaspectratio]{\instrumentImage}%
        \end{textblock*}%
    }%

    \PrintChordDiagrams
}%

\newcommand{\currentLetter}{}
\newcommand{\bynameindexitem}[2]{%
    \StrLeft{#1}{1}[\letter]%
    \IfStrEq{\currentLetter}{\letter}{%
        #1%
    }{%
        \par\noindent{\bfseries \letter}\StrDel[1]{#1}{\letter}%
    }%
    \dotfill {\itshape #2}\\%
    \StrLeft{#1}{1}[\currentLetter]%
}%

\newcommand{\currentAuthor}{}
\newcommand{\byauthorindexitem}[2]{%
    \IfStrEq{\currentAuthor}{#1}{}{%
        \par\noindent{\bfseries #1} %
    }%
    \hspace*{0pt}\dotfill #2\\%
    \renewcommand{\currentAuthor}{#1}
}%

\newcommand{\songindexhead}[1]{%
    \clearpage%
    \indexfontsize\selectfont%
    \newgeometry{hscale=.9, vscale=.9, vcentering=true, hcentering=true}%
    \noindent%
    {\titlefont #1%
    \vspace{1em}}%
    \setlength{\columnsep}{4ex}%
}%

\NewEnviron{songindexbyname}[1]{%
    \songindexhead{#1}%
    \begin{multicols*}{2}%
    \BODY
    \end{multicols*}%
}%

\NewEnviron{songindexbyauthor}[1]{%
    \songindexhead{#1}%
    \begin{multicols*}{2}%
    \BODY
    \end{multicols*}%
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
