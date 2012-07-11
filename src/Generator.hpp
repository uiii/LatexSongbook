#ifndef GENERATOR_HPP
#define GENERATOR_HPP

#include <QString>

#include <boost/spirit/include/qi.hpp>

namespace qi = boost::spirit::qi;

class Generator
{
    typedef std::string::iterator iterator;

    struct SongGrammar : qi::grammar<iterator>
    {
        typedef qi::rule<iterator> Rule;

        SongGrammar();

        Rule word;
        Rule space;

        Rule start;
        Rule title;
        Rule name;
        Rule author;
        Rule text;
    };

public:
    Generator();

    void generateSong(const QString& songText);

private:
    SongGrammar grammar_;
};

#endif // GENERATOR_HPP
