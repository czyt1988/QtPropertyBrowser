// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QTGROUPBOXPROPERTYBROWSER_H
#define QTGROUPBOXPROPERTYBROWSER_H

#include "qtpropertybrowser.h"
#include "qtpropertybrowserglobal.h"

QT_BEGIN_NAMESPACE

class QtGroupBoxPropertyBrowserPrivate;

class QT_QTPROPERTYBROWSER_EXPORT QtGroupBoxPropertyBrowser : public QtAbstractPropertyBrowser
{
    Q_OBJECT
public:
    QtGroupBoxPropertyBrowser(QWidget* parent = 0);
    ~QtGroupBoxPropertyBrowser();

protected:
    void itemInserted(QtBrowserItem* item, QtBrowserItem* afterItem) override;
    void itemRemoved(QtBrowserItem* item) override;
    void itemChanged(QtBrowserItem* item) override;

private:
    QScopedPointer< QtGroupBoxPropertyBrowserPrivate > d_ptr;
    Q_DECLARE_PRIVATE(QtGroupBoxPropertyBrowser)
    Q_DISABLE_COPY_MOVE(QtGroupBoxPropertyBrowser)
#if QT_VERSION_MAJOR == 5
    Q_PRIVATE_SLOT(d_func(), void slotUpdate())
    Q_PRIVATE_SLOT(d_func(), void slotEditorDestroyed())
#endif
};

QT_END_NAMESPACE

#endif
