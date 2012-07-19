#include "GeneratorSettings.hpp"

#include <QObject>

GeneratorSettings::GeneratorSettings():
    Settings(QObject::tr("Generator"))
{
    Page* page = new Page("Profiles");

    addPage_(page);
}
