#include "Lexer.hpp"

Lexer::Lexer()
{
}

void Lexer::addRule(const QString& pattern, int tokenId)
{
    Rule rule = { QRegExp(pattern), tokenId };
    rules_.push_back(rule);
}

Lexer::Tokens Lexer::tokenize(const QString& text)
{
    Tokens tokens;

    int pos = 0;
    while(pos != text.size())
    {
        Rules::iterator ruleIt = rules_.begin();
        while(ruleIt != rules_.end() && ruleIt->pattern.indexIn(text, pos) != pos)
        {
            ++ruleIt;
        }

        if(ruleIt == rules_.end())
        {
            throw; // TODO error
        }
        else
        {
            Token token = { ruleIt->tokenId, ruleIt->pattern.cap(0) };
            tokens.push_back(token);

            pos += ruleIt->pattern.matchedLength();
        }
    }

    return tokens;
}
