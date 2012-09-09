#ifndef LEXER_HPP
#define LEXER_HPP

#include <QString>
#include <QRegExp>
#include <QList>

class Lexer
{
public:
    struct Token
    {
        int id;
        QString lexeme;

        operator int() const
        {
            return id;
        }
    };

    typedef QList<Token> Tokens;

    Lexer();

    void addRule(const QString& pattern, int tokenId);
    Tokens tokenize(const QString& text);

private:
    struct Rule
    {
        QRegExp pattern;
        int tokenId;
    };

    typedef QList<Rule> Rules;

    Rules rules_;
};

#endif // LEXER_HPP
