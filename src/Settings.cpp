#include "Settings.hpp"

Page::Page(const QString& name):
    name_(name)
{
}

QString Page::name() const
{
    return name_;
}

Settings::Settings(const QString& name, const QIcon &icon):
    name_(name),
    icon_(icon)
{
}

const QString& Settings::name() const
{
    return name_;
}

const QIcon& Settings::icon() const
{
    return icon_;
}

const Settings::Pages &Settings::pages() const
{
    return pages_;
}

void Settings::addPage_(Page* page)
{
    pages_.push_back(page);
}
