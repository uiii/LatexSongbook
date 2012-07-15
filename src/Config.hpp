#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <QString>
#include <QSettings>

class Config
{
public:
    Config(int argc, char* argv[]);

    const QString& selfAppPath();

    template<typename Type>
    Type value(const QString& key);

    template<typename Type>
    void setValue(const QString& key, const Type& value);

private:
    QString selfAppPath_;
    QSettings settings_;
};

template< typename Type >
Type Config::value(const QString& key)
{
    return settings_.value(key).value<Type>();
}

template< typename Type >
void Config::setValue(const QString& key, const Type& value)
{
    settings_.setValue(key, QVariant::fromValue(value));
    settings_.sync();
}

#endif // CONFIG_HPP
