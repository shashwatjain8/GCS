#include "json_zoom.h"
void Zoom::write(QJsonObject &json) const
{
    json[
            ["zoom"] = z;
}

bool Zoom::saveZoom(Zoom::SaveFormat saveFormat) const
{
    QFile saveFile(QStringLiteral("save.json"));

    if (!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open save file.");
        return false;
    }

    QJsonObject zoom;
    write(zonm);
    QJsonDocument saveDoc(zoom);
    saveFile.write(saveDoc.toJson());
    return true;
}
