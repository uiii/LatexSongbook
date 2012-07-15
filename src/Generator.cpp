#include "Generator.hpp"

#include <QDebug>

#include <string>

Generator::Generator()
{
}

void Generator::generateSong(SongParser& parser)
{
    /*for(int i = 0; i < songText.size(); ++i)
    {
        qDebug() << songText.at(i);
    }
    std::string text = songText.toAscii().data();
    std::string::iterator it = text.begin();
    bool result = qi::parse(it, text.end(), grammar_);
    qDebug() << result;
    qDebug() << text.substr(0, it - text.begin()).c_str();*/
}
