/***********************************************************************
*
* Copyright (c) 2012-2020 Barbara Geller
* Copyright (c) 2012-2020 Ansel Sermersheim
*
* Copyright (c) 2015 The Qt Company Ltd.
* Copyright (c) 2012-2016 Digia Plc and/or its subsidiary(-ies).
* Copyright (c) 2008-2012 Nokia Corporation and/or its subsidiary(-ies).
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
* https://www.gnu.org/licenses/
*
***********************************************************************/

#include <qradiodata.h>

#include <qpair.h>
#include <qmediaservice.h>
#include <qradiodatacontrol.h>

#include <qmediaobject_p.h>
#include <qmediaserviceprovider_p.h>

class QRadioDataPrivate
{
    Q_DECLARE_NON_CONST_PUBLIC(QRadioData)

public:
    QRadioDataPrivate();

    QMediaObject *mediaObject;
    QRadioDataControl* control;

    void _q_serviceDestroyed();

    QRadioData *q_ptr;
};

QRadioDataPrivate::QRadioDataPrivate()
    : mediaObject(0), control(0)
{}

void QRadioDataPrivate::_q_serviceDestroyed()
{
    mediaObject = 0;
    control = 0;
}

QRadioData::QRadioData(QMediaObject *mediaObject, QObject *parent)
    : QObject(parent), d_ptr(new QRadioDataPrivate)
{
    Q_D(QRadioData);

    d->q_ptr = this;

    if (mediaObject)
        mediaObject->bind(this);
}

QRadioData::~QRadioData()
{
    Q_D(QRadioData);

    if (d->mediaObject)
        d->mediaObject->unbind(this);

    delete d_ptr;
}

/*!
  \reimp
*/
QMediaObject *QRadioData::mediaObject() const
{
    return d_func()->mediaObject;
}

/*!
  \reimp
*/
bool QRadioData::setMediaObject(QMediaObject *mediaObject)
{
    Q_D(QRadioData);

    if (d->mediaObject) {
        if (d->control) {
            disconnect(d->control, &QRadioDataControl::stationIdChanged,                     this, &QRadioData::stationIdChanged);
            disconnect(d->control, &QRadioDataControl::programTypeChanged,                   this, &QRadioData::programTypeChanged);
            disconnect(d->control, &QRadioDataControl::programTypeNameChanged,               this, &QRadioData::programTypeNameChanged);
            disconnect(d->control, &QRadioDataControl::stationNameChanged,                   this, &QRadioData::stationNameChanged);
            disconnect(d->control, &QRadioDataControl::radioTextChanged,                     this, &QRadioData::radioTextChanged);
            disconnect(d->control, &QRadioDataControl::alternativeFrequenciesEnabledChanged, this, &QRadioData::alternativeFrequenciesEnabledChanged);
            disconnect(d->control, &QRadioDataControl::error,                                this, &QRadioData::error);

            QMediaService *service = d->mediaObject->service();
            service->releaseControl(d->control);
            disconnect(service, &QMediaService::destroyed, this, &QRadioData::_q_serviceDestroyed);
        }
    }

    d->mediaObject = mediaObject;

    if (d->mediaObject) {
        QMediaService *service = mediaObject->service();
        if (service) {
            d->control = qobject_cast<QRadioDataControl*>(service->requestControl(QRadioDataControl_iid));

            if (d->control) {
               connect(d->control, &QRadioDataControl::stationIdChanged,                     this, &QRadioData::stationIdChanged);
               connect(d->control, &QRadioDataControl::programTypeChanged,                   this, &QRadioData::programTypeChanged);
               connect(d->control, &QRadioDataControl::programTypeNameChanged,               this, &QRadioData::programTypeNameChanged);
               connect(d->control, &QRadioDataControl::stationNameChanged,                   this, &QRadioData::stationNameChanged);
               connect(d->control, &QRadioDataControl::radioTextChanged,                     this, &QRadioData::radioTextChanged);
               connect(d->control, &QRadioDataControl::alternativeFrequenciesEnabledChanged, this, &QRadioData::alternativeFrequenciesEnabledChanged);
               connect(d->control, &QRadioDataControl::error,                                this, &QRadioData::error);

               connect(service, &QMediaService::destroyed, this, &QRadioData::_q_serviceDestroyed);

               return true;
            }
        }
    }

    // without QRadioDataControl discard the media object
    d->mediaObject = 0;
    d->control = 0;

    return false;
}

/*!
    Returns the availability of the radio data service.

    A long as there is a media service which provides radio functionality, then the
    \l{QMultimedia::AvailabilityStatus}{availability} will be that
    of the \l{QRadioTuner::availability()}{radio tuner}.
*/
QMultimedia::AvailabilityStatus QRadioData::availability() const
{
    Q_D(const QRadioData);

    if (d->control == 0)
        return QMultimedia::ServiceMissing;

    return d->mediaObject->availability();
}

/*!
    \property QRadioData::stationId
    \brief Current Program Identification

*/

QString QRadioData::stationId() const
{
    Q_D(const QRadioData);

    if (d->control != 0)
        return d->control->stationId();
    return QString();
}

/*!
    \property QRadioData::programType
    \brief Current Program Type

*/

QRadioData::ProgramType QRadioData::programType() const
{
    Q_D(const QRadioData);

    if (d->control != 0)
        return d->control->programType();

    return QRadioData::Undefined;
}

QString QRadioData::programTypeName() const
{
    Q_D(const QRadioData);

    if (d->control != 0)
        return d->control->programTypeName();
    return QString();
}

QString QRadioData::stationName() const
{
    Q_D(const QRadioData);

    if (d->control != 0)
        return d->control->stationName();
    return QString();
}

QString QRadioData::radioText() const
{
    Q_D(const QRadioData);

    if (d->control != 0)
        return d->control->radioText();
    return QString();
}

bool QRadioData::isAlternativeFrequenciesEnabled() const
{
    Q_D(const QRadioData);

    if (d->control != 0)
        return d->control->isAlternativeFrequenciesEnabled();
    return false;
}

void QRadioData::setAlternativeFrequenciesEnabled( bool enabled )
{
    Q_D(const QRadioData);

    if (d->control != 0)
        return d->control->setAlternativeFrequenciesEnabled(enabled);
}

QRadioData::Error QRadioData::error() const
{
    Q_D(const QRadioData);

    if (d->control != 0)
        return d->control->error();

    return QRadioData::ResourceError;
}

QString QRadioData::errorString() const
{
    Q_D(const QRadioData);

    if (d->control != 0)
        return d->control->errorString();

    return QString();
}

void QRadioData::_q_serviceDestroyed()
{
	Q_D(QRadioData);
	d->_q_serviceDestroyed();
}
