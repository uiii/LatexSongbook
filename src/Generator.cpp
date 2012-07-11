#include "Generator.hpp"

#include <QDebug>

#include <string>

Generator::SongGrammar::SongGrammar():
    SongGrammar::base_type(start)
{
    word = qi::char_("a-zA-Zěščřžýáíé");
    space = qi::char_(' ');

    name = word % space;
    author = word % space;
    title = *space >> name >> *space >> '(' >> author >> ')';
    text = *qi::char_;
    start = title >> qi::eol >> text;
}

Generator::Generator()
{
}

void Generator::generateSong(const QString &songText)
{
    std::string text = songText.toAscii().data();
    bool result = qi::parse(text.begin(), text.end(), grammar_);
    qDebug() << result;
}
