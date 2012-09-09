#include "SongParser.hpp"

#include <boost/spirit/include/qi.hpp>

using namespace boost::spirit;

class SongGrammar : qi::grammar<Lexer::Tokens::iterator>
{
public:
    typedef qi::rule<Lexer::Tokens::iterator> Rule;

    SongGrammar();

private:
    Rule line_(Rule line_content);
    Rule token_(SongParser::TokenID token);

    Rule song_;
    Rule song_line_;
    Rule words_;
    Rule title_;
    Rule chords_;
    Rule single_chords_;
    Rule new_section_;
    Rule lyrics_;
    Rule section_name_;
};

SongGrammar::SongGrammar():
    SongGrammar::base_type(song_)
{
    song_ =
        line_(title_)
        >> +song_line_
        ;

    title_ =
        token_(SongParser::TOK_WORD)
        >> token_(SongParser::TOK_SPACE)
        >> token_(SongParser::TOK_LEFT_BRACKET)
        >> token_(SongParser::TOK_WORD)
        >> token_(SongParser::TOK_RIGHT_BRACKET)
        ;

    song_line_ =
        line_(single_chords_)
        | ( -line_(chords_) >> line_(new_section_ | lyrics_) )
        ;

    single_chords_ =
        token_(SongParser::TOK_COLON) >> token_(SongParser::TOK_COLON)
        >> words_
        ;

    chords_ =
        token_(SongParser::TOK_COLON)
        >> words_
        ;

    new_section_ =
        -section_name_
        >> token_(SongParser::TOK_DOT)
        >> lyrics_
        ;

    lyrics_ =
        words_
        ;

    words_ =
        +( +token_(SongParser::TOK_SPACE) >> token_(SongParser::TOK_WORD) )
        >> *token_(SongParser::TOK_SPACE)
        ;

    section_name_ =
        token_(SongParser::TOK_REFRAIN) | token_(SongParser::TOK_RECITATION) | token_(SongParser::TOK_WORD)
        -( token_(SongParser::TOK_SPACE) >> token_(SongParser::TOK_NUMBER) )
        ;
}

SongGrammar::Rule SongGrammar::line_(SongGrammar::Rule line_content)
{
    Rule rule =
        line_content << token_(SongParser::TOK_EOL)
        << *( *token_(SongParser::TOK_SPACE) >> token_(SongParser::TOK_EOL) )
        ;

    return rule;
}

SongGrammar::Rule SongGrammar::token_(SongParser::TokenID token)
{
    return qi::char_(token);
}

SongParser::SongParser()
{
    lexer_.addRule(" ", TOK_SPACE);
    lexer_.addRule("\\.", TOK_DOT);
    lexer_.addRule("\\(", TOK_LEFT_BRACKET);
    lexer_.addRule("\\)", TOK_RIGHT_BRACKET);
    lexer_.addRule(":", TOK_COLON);
    lexer_.addRule("[0-9]+", TOK_NUMBER);
    lexer_.addRule("Capo", TOK_CAPO);
    lexer_.addRule("Rec", TOK_RECITATION);
    lexer_.addRule("Ref", TOK_REFRAIN);
    lexer_.addRule("\\n", TOK_EOL);
    lexer_.addRule("[^ \\t\\n\\r\\(\\)\\.:0-9]+", TOK_WORD);
}

void SongParser::parse(const QString& text)
{
    Lexer::Tokens tokens = lexer_.tokenize(text);

    SongGrammar grammar;

    Lexer::Tokens::iterator begin = tokens.begin();
    Lexer::Tokens::iterator end = tokens.end();
    bool result = qi::parse(begin, end, grammar);
    std::cout << result << std::endl;
}
