/*
 * Copyright 2015 Christian Loose <christian.loose@hamburg.de>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "stylemanager.h"

#include <QMap>



QMap<QString, QString> getMarkdownHighlight()
{
    QMap<QString, QString> map;
    map.insert( "Default", "default" );
    map.insert( "Solarized Light", "solarized-light" );
    map.insert( "Solarized Dark", "solarized-dark" );
    map.insert( "Clearness Dark", "clearness-dark" );
    map.insert( "Byword Dark", "byword-dark" );
    return map;
};

QMap<QString, QString> getCodeHighlight()
{
    QMap<QString, QString> map;
    map.insert("Default", "default"                );
    map.insert("Github", "github"                  );
    map.insert("Solarized Light", "solarized_light");
    map.insert("Solarized Dark", "solarized_dark"  );
    return map;
};

QMap<QString, QString> getPreviewHighlight()
{
    QMap<QString, QString> map;
    map.insert("Default", "qrc:/css/markdown.css"               );
    map.insert("Github", "qrc:/css/github.css"                  );
    map.insert("Solarized Light", "qrc:/css/solarized-light.css");
    map.insert("Solarized Dark", "qrc:/css/solarized-dark.css"  );
    map.insert("Clearness", "qrc:/css/clearness.css"            );
    map.insert("Clearness Dark", "qrc:/css/clearness-dark.css"  );
    map.insert("Byword Dark", "qrc:/css/byword-dark.css"        );
    return map;
};

static const QMap<QString, QString> BUILTIN_MARKDOWN_HIGHLIGHTINGS = getMarkdownHighlight();

static const QMap<QString, QString> BUILTIN_CODE_HIGHLIGHTINGS = getCodeHighlight();
static const QMap<QString, QString> BUILTIN_PREVIEW_STYLESHEETS = getPreviewHighlight();

QMap<QString, QString> StyleManager::customPreviewStylesheets;


void StyleManager::insertCustomPreviewStylesheet(const QString &styleName, const QString &stylePath)
{
    customPreviewStylesheets.insert(styleName, stylePath);
}

QString StyleManager::markdownHighlightingPath(const Theme &theme)
{
    return BUILTIN_MARKDOWN_HIGHLIGHTINGS[theme.markdownHighlighting()];
}

QString StyleManager::codeHighlightingPath(const Theme &theme)
{
    return BUILTIN_CODE_HIGHLIGHTINGS[theme.codeHighlighting()];
}

QString StyleManager::previewStylesheetPath(const Theme &theme)
{
    if (customPreviewStylesheets.contains(theme.previewStylesheet())) {
        return customPreviewStylesheets[theme.previewStylesheet()];
    }

    return BUILTIN_PREVIEW_STYLESHEETS[theme.previewStylesheet()];
}
