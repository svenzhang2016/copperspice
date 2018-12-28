/***********************************************************************
*
* Copyright (c) 2012-2018 Barbara Geller
* Copyright (c) 2012-2018 Ansel Sermersheim
* Copyright (c) 2012-2016 Digia Plc and/or its subsidiary(-ies).
* Copyright (c) 2008-2012 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
*
* This file is part of CopperSpice.
*
* CopperSpice is free software. You can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public License
* version 2.1 as published by the Free Software Foundation.
*
* CopperSpice is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*
* <http://www.gnu.org/licenses/>.
*
***********************************************************************/

#include <qplatform_integrationfactory_p.h>
#include <qplatform_integrationplugin.h>
#include <qfactoryloader_p.h>
#include <qmutex.h>
#include <qdir.h>

#include <qguiapplication.h>
#include <qdebug.h>

Q_GLOBAL_STATIC_WITH_ARGS(QFactoryLoader, loader,
    (QPlatformIntegrationFactoryInterface_iid, QLatin1String("/platforms"), Qt::CaseInsensitive))

Q_GLOBAL_STATIC_WITH_ARGS(QFactoryLoader, directLoader,
                  (QPlatformIntegrationFactoryInterface_iid, QLatin1String(""), Qt::CaseInsensitive))

static inline QPlatformIntegration *loadIntegration(QFactoryLoader *loader, const QString &key,
                  const QStringList &parameters, int &argc, char ** argv)
{
    const int index = loader->indexOf(key);

    if (index != -1) {
        if (QPlatformIntegrationPlugin *factory = qobject_cast<QPlatformIntegrationPlugin *>(loader->instance(index)))
            if (QPlatformIntegration *result = factory->create(key, parameters, argc, argv))
                return result;
    }
    return 0;
}

QPlatformIntegration *QPlatformIntegrationFactory::create(const QString &platform,
                  const QStringList &paramList, int &argc, char **argv, const QString &platformPluginPath)
{
    // Try loading the plugin from platformPluginPath first:

    if (! platformPluginPath.isEmpty()) {
        QCoreApplication::addLibraryPath(platformPluginPath);
        if (QPlatformIntegration *ret = loadIntegration(directLoader(), platform, paramList, argc, argv))
            return ret;
    }

    if (QPlatformIntegration *ret = loadIntegration(loader(), platform, paramList, argc, argv))
        return ret;

    return 0;
}

QStringList QPlatformIntegrationFactory::keys(const QString &platformPluginPath)
{
    QStringList list;

    if (!platformPluginPath.isEmpty()) {
        QCoreApplication::addLibraryPath(platformPluginPath);
        list = directLoader()->keyMap().values();

        if (!list.isEmpty()) {
            const QString postFix = QString(" (from ") + QDir::toNativeSeparators(platformPluginPath) + ')';
            const QStringList::iterator end = list.end();

            for (QStringList::iterator it = list.begin(); it != end; ++it)
                (*it).append(postFix);
        }
    }

    list.append(loader()->keyMap().values());

    return list;
}
