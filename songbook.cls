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

\RequirePackage[hscale=0.75, vscale=.9, vcentering=true]{geometry}
\RequirePackage{environ}
\RequirePackage{graphics}
\RequirePackage{calc}
\RequirePackage[absolute, showboxes]{textpos}
\RequirePackage{gchords}
\RequirePackage{needspace}
\RequirePackage{xstring}

\renewcommand{\normalsize}{\fontsize{9pt}{10pt}\selectfont}
\DeclareMathSizes{9}{8}{8}{8}

\newcommand{\titlefont}{\fontsize{14.4pt}{17pt}\fontseries{bx}\selectfont}
\newcommand{\authorfont}{\fontsize{12pt}{15pt}\fontseries{m}\fontshape{it}\selectfont}
\newcommand{\songfont}{\normalsize\fontseries{m}\selectfont}

\newcommand{\songtitle}[1]{{\titlefont #1}}
\newcommand{\songauthor}[1]{{\authorfont #1}}

\newsavebox{\sectionbox}

\newcommand{\section}[2]{%
    \savebox{\sectionbox}{%
        \begin{minipage}{\textwidth}%
            \par\noindent\llap{{\bfseries #1}\hspace{0.6em}}\ignorespaces#2%
        \end{minipage}%
    }%

    \begin{needspace}{\dimexpr\ht\sectionbox+\dp\sectionbox}%
        \usebox{\sectionbox}%
    \end{needspace}%
}%

\newcounter{versecounter}

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

\newcommand{\clearChord}[1]{%
    \StrSubstitute{#1}{ }{\;\:}[\cleared]%
    %\StrSubstitute{\cleared}{\#}{\sharp}[\cleared]%
    %\StrSubstitute{\cleared}{&}{\flat}[\cleared]%
    \cleared%
}%

\newcommand{\Chords}[1]{%
    \section{}{$\mathbf{\clearChord{#1}}$}%
}%

\catcode`\|=13
%\def|#1|{%
%    \raisebox{4.5ex}{%
%        \makebox[0em][l]{%
%            \raisebox{-2.5ex}[0ex][0ex]{%
%                $\mathbf{#1}$%
%            }%
%        }%
%    }%
%}%

\newsavebox{\chordbox}%
\newsavebox{\textbox}%
\newcounter{diff}%
\setcounter{diff}{0}%

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

\def|#1|#2|{%
    \savebox{\joinbox}{--}%
    \StrLeft{#2}{1}[\rightletter]%
    \savebox{\chordbox}{$\mathbf{\clearChord{#1}}$}%
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
            \raisebox{-2.5ex}[0ex][0ex]{%
                \usebox{\chordbox}%
            }%
        }%
    }%
    \usebox{\textbox}%
    \setcounter{diff}{\wd\chordbox+200000-\wd\textbox}%
    \StrRight{#2}{1}[\leftletter]%
    %\renewcommand{\leftletter}{\StrRight{#2}{1}}%
}%

\newcommand{\n}{%
    \\%
    \setcounter{diff}{0}%
}%

\NewEnviron{song}[2]{%
    \clearpage%
    \setcounter{versecounter}{1}%
    \setcounter{diff}{0}%
    \setlength{\parskip}{2.4ex}%

    \noindent%
    \songtitle{#1}%
    \hfill\songauthor{#2}%
    \vspace{1.5ex}\par%
    \BODY%
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
