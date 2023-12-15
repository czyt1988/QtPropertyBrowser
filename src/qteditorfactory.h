// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QTEDITORFACTORY_H
#define QTEDITORFACTORY_H

#include "qtpropertymanager.h"
#include "qtpropertybrowserglobal.h"
QT_BEGIN_NAMESPACE

class QRegularExpression;

class QtSpinBoxFactoryPrivate;

class QT_QTPROPERTYBROWSER_EXPORT QtSpinBoxFactory : public QtAbstractEditorFactory< QtIntPropertyManager >
{
    Q_OBJECT
public:
    QtSpinBoxFactory(QObject* parent = 0);
    ~QtSpinBoxFactory();

protected:
    void connectPropertyManager(QtIntPropertyManager* manager) override;
    QWidget* createEditor(QtIntPropertyManager* manager, QtProperty* property, QWidget* parent) override;
    void disconnectPropertyManager(QtIntPropertyManager* manager) override;

private:
    QScopedPointer< QtSpinBoxFactoryPrivate > d_ptr;
    Q_DECLARE_PRIVATE(QtSpinBoxFactory)
    Q_DISABLE_COPY_MOVE(QtSpinBoxFactory)
#if QT_VERSION_MAJOR == 5
    Q_PRIVATE_SLOT(d_func(), void slotPropertyChanged(QtProperty *, int))
    Q_PRIVATE_SLOT(d_func(), void slotRangeChanged(QtProperty *, int, int))
    Q_PRIVATE_SLOT(d_func(), void slotSingleStepChanged(QtProperty *, int))
    Q_PRIVATE_SLOT(d_func(), void slotSetValue(int))
    Q_PRIVATE_SLOT(d_func(), void slotEditorDestroyed(QObject *))
#endif
};

class QtSliderFactoryPrivate;

class QT_QTPROPERTYBROWSER_EXPORT QtSliderFactory : public QtAbstractEditorFactory< QtIntPropertyManager >
{
    Q_OBJECT
public:
    QtSliderFactory(QObject* parent = 0);
    ~QtSliderFactory();

protected:
    void connectPropertyManager(QtIntPropertyManager* manager) override;
    QWidget* createEditor(QtIntPropertyManager* manager, QtProperty* property, QWidget* parent) override;
    void disconnectPropertyManager(QtIntPropertyManager* manager) override;

private:
    QScopedPointer< QtSliderFactoryPrivate > d_ptr;
    Q_DECLARE_PRIVATE(QtSliderFactory)
    Q_DISABLE_COPY_MOVE(QtSliderFactory)
#if QT_VERSION_MAJOR == 5
    Q_PRIVATE_SLOT(d_func(), void slotPropertyChanged(QtProperty *, int))
    Q_PRIVATE_SLOT(d_func(), void slotRangeChanged(QtProperty *, int, int))
    Q_PRIVATE_SLOT(d_func(), void slotSingleStepChanged(QtProperty *, int))
    Q_PRIVATE_SLOT(d_func(), void slotSetValue(int))
    Q_PRIVATE_SLOT(d_func(), void slotEditorDestroyed(QObject *))
#endif
};

class QtScrollBarFactoryPrivate;

class QT_QTPROPERTYBROWSER_EXPORT QtScrollBarFactory : public QtAbstractEditorFactory< QtIntPropertyManager >
{
    Q_OBJECT
public:
    QtScrollBarFactory(QObject* parent = 0);
    ~QtScrollBarFactory();

protected:
    void connectPropertyManager(QtIntPropertyManager* manager) override;
    QWidget* createEditor(QtIntPropertyManager* manager, QtProperty* property, QWidget* parent) override;
    void disconnectPropertyManager(QtIntPropertyManager* manager) override;

private:
    QScopedPointer< QtScrollBarFactoryPrivate > d_ptr;
    Q_DECLARE_PRIVATE(QtScrollBarFactory)
    Q_DISABLE_COPY_MOVE(QtScrollBarFactory)
#if QT_VERSION_MAJOR == 5
    Q_PRIVATE_SLOT(d_func(), void slotPropertyChanged(QtProperty *, int))
    Q_PRIVATE_SLOT(d_func(), void slotRangeChanged(QtProperty *, int, int))
    Q_PRIVATE_SLOT(d_func(), void slotSingleStepChanged(QtProperty *, int))
    Q_PRIVATE_SLOT(d_func(), void slotSetValue(int))
    Q_PRIVATE_SLOT(d_func(), void slotEditorDestroyed(QObject *))
#endif
};

class QtCheckBoxFactoryPrivate;

class QT_QTPROPERTYBROWSER_EXPORT QtCheckBoxFactory : public QtAbstractEditorFactory< QtBoolPropertyManager >
{
    Q_OBJECT
public:
    QtCheckBoxFactory(QObject* parent = 0);
    ~QtCheckBoxFactory();

protected:
    void connectPropertyManager(QtBoolPropertyManager* manager) override;
    QWidget* createEditor(QtBoolPropertyManager* manager, QtProperty* property, QWidget* parent) override;
    void disconnectPropertyManager(QtBoolPropertyManager* manager) override;

private:
    QScopedPointer< QtCheckBoxFactoryPrivate > d_ptr;
    Q_DECLARE_PRIVATE(QtCheckBoxFactory)
    Q_DISABLE_COPY_MOVE(QtCheckBoxFactory)
#if QT_VERSION_MAJOR == 5
    Q_PRIVATE_SLOT(d_func(), void slotPropertyChanged(QtProperty *, bool))
    Q_PRIVATE_SLOT(d_func(), void slotSetValue(bool))
    Q_PRIVATE_SLOT(d_func(), void slotEditorDestroyed(QObject *))
#endif
};

class QtDoubleSpinBoxFactoryPrivate;

class QT_QTPROPERTYBROWSER_EXPORT QtDoubleSpinBoxFactory : public QtAbstractEditorFactory< QtDoublePropertyManager >
{
    Q_OBJECT
public:
    QtDoubleSpinBoxFactory(QObject* parent = 0);
    ~QtDoubleSpinBoxFactory();

protected:
    void connectPropertyManager(QtDoublePropertyManager* manager) override;
    QWidget* createEditor(QtDoublePropertyManager* manager, QtProperty* property, QWidget* parent) override;
    void disconnectPropertyManager(QtDoublePropertyManager* manager) override;

private:
    QScopedPointer< QtDoubleSpinBoxFactoryPrivate > d_ptr;
    Q_DECLARE_PRIVATE(QtDoubleSpinBoxFactory)
    Q_DISABLE_COPY_MOVE(QtDoubleSpinBoxFactory)
#if QT_VERSION_MAJOR == 5
    Q_PRIVATE_SLOT(d_func(), void slotPropertyChanged(QtProperty *, double))
    Q_PRIVATE_SLOT(d_func(), void slotRangeChanged(QtProperty *, double, double))
    Q_PRIVATE_SLOT(d_func(), void slotSingleStepChanged(QtProperty *, double))
    Q_PRIVATE_SLOT(d_func(), void slotDecimalsChanged(QtProperty *, int))
    Q_PRIVATE_SLOT(d_func(), void slotSetValue(double))
    Q_PRIVATE_SLOT(d_func(), void slotEditorDestroyed(QObject *))
#endif
};

class QtLineEditFactoryPrivate;

class QT_QTPROPERTYBROWSER_EXPORT QtLineEditFactory : public QtAbstractEditorFactory< QtStringPropertyManager >
{
    Q_OBJECT
public:
    QtLineEditFactory(QObject* parent = 0);
    ~QtLineEditFactory();

protected:
    void connectPropertyManager(QtStringPropertyManager* manager) override;
    QWidget* createEditor(QtStringPropertyManager* manager, QtProperty* property, QWidget* parent) override;
    void disconnectPropertyManager(QtStringPropertyManager* manager) override;

private:
    QScopedPointer< QtLineEditFactoryPrivate > d_ptr;
    Q_DECLARE_PRIVATE(QtLineEditFactory)
    Q_DISABLE_COPY_MOVE(QtLineEditFactory)
#if QT_VERSION_MAJOR == 5
    Q_PRIVATE_SLOT(d_func(), void slotPropertyChanged(QtProperty *, const QString &))
    Q_PRIVATE_SLOT(d_func(), void slotRegExpChanged(QtProperty *, const QRegExp &))
    Q_PRIVATE_SLOT(d_func(), void slotSetValue(const QString &))
    Q_PRIVATE_SLOT(d_func(), void slotEditorDestroyed(QObject *))
#endif
};

class QtDateEditFactoryPrivate;

class QT_QTPROPERTYBROWSER_EXPORT QtDateEditFactory : public QtAbstractEditorFactory< QtDatePropertyManager >
{
    Q_OBJECT
public:
    QtDateEditFactory(QObject* parent = 0);
    ~QtDateEditFactory();

protected:
    void connectPropertyManager(QtDatePropertyManager* manager) override;
    QWidget* createEditor(QtDatePropertyManager* manager, QtProperty* property, QWidget* parent) override;
    void disconnectPropertyManager(QtDatePropertyManager* manager) override;

private:
    QScopedPointer< QtDateEditFactoryPrivate > d_ptr;
    Q_DECLARE_PRIVATE(QtDateEditFactory)
    Q_DISABLE_COPY_MOVE(QtDateEditFactory)
#if QT_VERSION_MAJOR == 5
    Q_PRIVATE_SLOT(d_func(), void slotPropertyChanged(QtProperty *, const QDate &))
    Q_PRIVATE_SLOT(d_func(), void slotRangeChanged(QtProperty *,
                        const QDate &, const QDate &))
    Q_PRIVATE_SLOT(d_func(), void slotSetValue(const QDate &))
    Q_PRIVATE_SLOT(d_func(), void slotEditorDestroyed(QObject *))
#endif
};

class QtTimeEditFactoryPrivate;

class QT_QTPROPERTYBROWSER_EXPORT QtTimeEditFactory : public QtAbstractEditorFactory< QtTimePropertyManager >
{
    Q_OBJECT
public:
    QtTimeEditFactory(QObject* parent = 0);
    ~QtTimeEditFactory();

protected:
    void connectPropertyManager(QtTimePropertyManager* manager) override;
    QWidget* createEditor(QtTimePropertyManager* manager, QtProperty* property, QWidget* parent) override;
    void disconnectPropertyManager(QtTimePropertyManager* manager) override;

private:
    QScopedPointer< QtTimeEditFactoryPrivate > d_ptr;
    Q_DECLARE_PRIVATE(QtTimeEditFactory)
    Q_DISABLE_COPY_MOVE(QtTimeEditFactory)
#if QT_VERSION_MAJOR == 5
    Q_PRIVATE_SLOT(d_func(), void slotPropertyChanged(QtProperty *, const QTime &))
    Q_PRIVATE_SLOT(d_func(), void slotSetValue(const QTime &))
    Q_PRIVATE_SLOT(d_func(), void slotEditorDestroyed(QObject *))
#endif
};

class QtDateTimeEditFactoryPrivate;

class QT_QTPROPERTYBROWSER_EXPORT QtDateTimeEditFactory : public QtAbstractEditorFactory< QtDateTimePropertyManager >
{
    Q_OBJECT
public:
    QtDateTimeEditFactory(QObject* parent = 0);
    ~QtDateTimeEditFactory();

protected:
    void connectPropertyManager(QtDateTimePropertyManager* manager) override;
    QWidget* createEditor(QtDateTimePropertyManager* manager, QtProperty* property, QWidget* parent) override;
    void disconnectPropertyManager(QtDateTimePropertyManager* manager) override;

private:
    QScopedPointer< QtDateTimeEditFactoryPrivate > d_ptr;
    Q_DECLARE_PRIVATE(QtDateTimeEditFactory)
    Q_DISABLE_COPY_MOVE(QtDateTimeEditFactory)
#if QT_VERSION_MAJOR == 5
    Q_PRIVATE_SLOT(d_func(), void slotPropertyChanged(QtProperty *, const QDateTime &))
    Q_PRIVATE_SLOT(d_func(), void slotSetValue(const QDateTime &))
    Q_PRIVATE_SLOT(d_func(), void slotEditorDestroyed(QObject *))
#endif
};

class QtKeySequenceEditorFactoryPrivate;

class QT_QTPROPERTYBROWSER_EXPORT QtKeySequenceEditorFactory : public QtAbstractEditorFactory< QtKeySequencePropertyManager >
{
    Q_OBJECT
public:
    QtKeySequenceEditorFactory(QObject* parent = 0);
    ~QtKeySequenceEditorFactory();

protected:
    void connectPropertyManager(QtKeySequencePropertyManager* manager) override;
    QWidget* createEditor(QtKeySequencePropertyManager* manager, QtProperty* property, QWidget* parent) override;
    void disconnectPropertyManager(QtKeySequencePropertyManager* manager) override;

private:
    QScopedPointer< QtKeySequenceEditorFactoryPrivate > d_ptr;
    Q_DECLARE_PRIVATE(QtKeySequenceEditorFactory)
    Q_DISABLE_COPY_MOVE(QtKeySequenceEditorFactory)
#if QT_VERSION_MAJOR == 5
    Q_PRIVATE_SLOT(d_func(), void slotPropertyChanged(QtProperty *, const QKeySequence &))
    Q_PRIVATE_SLOT(d_func(), void slotSetValue(const QKeySequence &))
    Q_PRIVATE_SLOT(d_func(), void slotEditorDestroyed(QObject *))
#endif
};

class QtCharEditorFactoryPrivate;

class QT_QTPROPERTYBROWSER_EXPORT QtCharEditorFactory : public QtAbstractEditorFactory< QtCharPropertyManager >
{
    Q_OBJECT
public:
    QtCharEditorFactory(QObject* parent = 0);
    ~QtCharEditorFactory();

protected:
    void connectPropertyManager(QtCharPropertyManager* manager) override;
    QWidget* createEditor(QtCharPropertyManager* manager, QtProperty* property, QWidget* parent) override;
    void disconnectPropertyManager(QtCharPropertyManager* manager) override;

private:
    QScopedPointer< QtCharEditorFactoryPrivate > d_ptr;
    Q_DECLARE_PRIVATE(QtCharEditorFactory)
    Q_DISABLE_COPY_MOVE(QtCharEditorFactory)
#if QT_VERSION_MAJOR == 5
    Q_PRIVATE_SLOT(d_func(), void slotPropertyChanged(QtProperty *, const QChar &))
    Q_PRIVATE_SLOT(d_func(), void slotSetValue(const QChar &))
    Q_PRIVATE_SLOT(d_func(), void slotEditorDestroyed(QObject *))
#endif
};

class QtEnumEditorFactoryPrivate;

class QT_QTPROPERTYBROWSER_EXPORT QtEnumEditorFactory : public QtAbstractEditorFactory< QtEnumPropertyManager >
{
    Q_OBJECT
public:
    QtEnumEditorFactory(QObject* parent = 0);
    ~QtEnumEditorFactory();

protected:
    void connectPropertyManager(QtEnumPropertyManager* manager) override;
    QWidget* createEditor(QtEnumPropertyManager* manager, QtProperty* property, QWidget* parent) override;
    void disconnectPropertyManager(QtEnumPropertyManager* manager) override;

private:
    QScopedPointer< QtEnumEditorFactoryPrivate > d_ptr;
    Q_DECLARE_PRIVATE(QtEnumEditorFactory)
    Q_DISABLE_COPY_MOVE(QtEnumEditorFactory)
#if QT_VERSION_MAJOR == 5
    Q_PRIVATE_SLOT(d_func(), void slotPropertyChanged(QtProperty *, int))
    Q_PRIVATE_SLOT(d_func(), void slotEnumNamesChanged(QtProperty *,
                        const QStringList &))
    Q_PRIVATE_SLOT(d_func(), void slotEnumIconsChanged(QtProperty *,
                        const QMap<int, QIcon> &))
    Q_PRIVATE_SLOT(d_func(), void slotSetValue(int))
    Q_PRIVATE_SLOT(d_func(), void slotEditorDestroyed(QObject *))
#endif
};

class QtCursorEditorFactoryPrivate;

class QT_QTPROPERTYBROWSER_EXPORT QtCursorEditorFactory : public QtAbstractEditorFactory< QtCursorPropertyManager >
{
    Q_OBJECT
public:
    QtCursorEditorFactory(QObject* parent = 0);
    ~QtCursorEditorFactory();

protected:
    void connectPropertyManager(QtCursorPropertyManager* manager) override;
    QWidget* createEditor(QtCursorPropertyManager* manager, QtProperty* property, QWidget* parent) override;
    void disconnectPropertyManager(QtCursorPropertyManager* manager) override;

private:
    QScopedPointer< QtCursorEditorFactoryPrivate > d_ptr;
    Q_DECLARE_PRIVATE(QtCursorEditorFactory)
    Q_DISABLE_COPY_MOVE(QtCursorEditorFactory)
#if QT_VERSION_MAJOR == 5
    Q_PRIVATE_SLOT(d_func(), void slotPropertyChanged(QtProperty *, const QCursor &))
    Q_PRIVATE_SLOT(d_func(), void slotEnumChanged(QtProperty *, int))
    Q_PRIVATE_SLOT(d_func(), void slotEditorDestroyed(QObject *))
#endif
};

class QtColorEditorFactoryPrivate;

class QT_QTPROPERTYBROWSER_EXPORT QtColorEditorFactory : public QtAbstractEditorFactory< QtColorPropertyManager >
{
    Q_OBJECT
public:
    QtColorEditorFactory(QObject* parent = 0);
    ~QtColorEditorFactory();

protected:
    void connectPropertyManager(QtColorPropertyManager* manager) override;
    QWidget* createEditor(QtColorPropertyManager* manager, QtProperty* property, QWidget* parent) override;
    void disconnectPropertyManager(QtColorPropertyManager* manager) override;

private:
    QScopedPointer< QtColorEditorFactoryPrivate > d_ptr;
    Q_DECLARE_PRIVATE(QtColorEditorFactory)
    Q_DISABLE_COPY_MOVE(QtColorEditorFactory)
#if QT_VERSION_MAJOR == 5
    Q_PRIVATE_SLOT(d_func(), void slotPropertyChanged(QtProperty *, const QColor &))
    Q_PRIVATE_SLOT(d_func(), void slotEditorDestroyed(QObject *))
    Q_PRIVATE_SLOT(d_func(), void slotSetValue(const QColor &))
#endif
};

class QtFontEditorFactoryPrivate;

class QT_QTPROPERTYBROWSER_EXPORT QtFontEditorFactory : public QtAbstractEditorFactory< QtFontPropertyManager >
{
    Q_OBJECT
public:
    QtFontEditorFactory(QObject* parent = 0);
    ~QtFontEditorFactory();

protected:
    void connectPropertyManager(QtFontPropertyManager* manager) override;
    QWidget* createEditor(QtFontPropertyManager* manager, QtProperty* property, QWidget* parent) override;
    void disconnectPropertyManager(QtFontPropertyManager* manager) override;

private:
    QScopedPointer< QtFontEditorFactoryPrivate > d_ptr;
    Q_DECLARE_PRIVATE(QtFontEditorFactory)
    Q_DISABLE_COPY_MOVE(QtFontEditorFactory)
#if QT_VERSION_MAJOR == 5
    Q_PRIVATE_SLOT(d_func(), void slotPropertyChanged(QtProperty *, const QFont &))
    Q_PRIVATE_SLOT(d_func(), void slotEditorDestroyed(QObject *))
    Q_PRIVATE_SLOT(d_func(), void slotSetValue(const QFont &))
#endif
};

QT_END_NAMESPACE

#endif
