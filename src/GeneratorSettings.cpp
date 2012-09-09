#include "GeneratorSettings.hpp"

#include <QObject>

GeneratorSettings::GeneratorSettings():
    Settings(QObject::tr("Generator"), QIcon::fromTheme("document-new"))
{
    Page* page = new Page("Profiles");

    addPage_(page);
}
