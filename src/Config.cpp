#include "Config.hpp"

Config::Config(int argc, char* argv[]):
    settings_("LatexSongbook", "LatexSongbook")
{
    selfAppPath_ = argv[0];
}

const QString &Config::selfAppPath()
{
    return selfAppPath_;
}
