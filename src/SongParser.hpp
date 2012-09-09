#ifndef SONGPARSER_HPP
#define SONGPARSER_HPP

#include "Lexer.hpp"

class SongParser
{
public:
    enum TokenID
    {
        TOK_SPACE,
        TOK_DOT,
        TOK_LEFT_BRACKET,
        TOK_RIGHT_BRACKET,
        TOK_COLON,
        TOK_NUMBER,
        TOK_CAPO,
        TOK_RECITATION,
        TOK_REFRAIN,
        TOK_WORD,
        TOK_EOL
    };

    SongParser();

    void parse(const QString& text);

private:
    Lexer lexer_;
};

#endif // SONGPARSER_HPP
