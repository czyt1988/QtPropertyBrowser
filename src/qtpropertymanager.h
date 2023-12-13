// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QTPROPERTYMANAGER_H
#define QTPROPERTYMANAGER_H

#include "qtpropertybrowser.h"
#include "qtpropertybrowserglobal.h"
QT_BEGIN_NAMESPACE

class QDate;
class QTime;
class QDateTime;
class QLocale;
#if QT_VERSION_MAJOR >= 6
class QRegularExpression;
#else
class QRegExp;
#endif
class QT_QTPROPERTYBROWSER_EXPORT QtGroupPropertyManager : public QtAbstractPropertyManager
{
    Q_OBJECT
public:
    QtGroupPropertyManager(QObject* parent = 0);
    ~QtGroupPropertyManager();

protected:
    bool hasValue(const QtProperty* property) const override;

    void initializeProperty(QtProperty* property) override;
    void uninitializeProperty(QtProperty* property) override;
};

class QtIntPropertyManagerPrivate;

class QT_QTPROPERTYBROWSER_EXPORT QtIntPropertyManager : public QtAbstractPropertyManager
{
    Q_OBJECT
public:
    QtIntPropertyManager(QObject* parent = 0);
    ~QtIntPropertyManager();

    int value(const QtProperty* property) const;
    int minimum(const QtProperty* property) const;
    int maximum(const QtProperty* property) const;
    int singleStep(const QtProperty* property) const;

public Q_SLOTS:
    void setValue(QtProperty* property, int val);
    void setMinimum(QtProperty* property, int minVal);
    void setMaximum(QtProperty* property, int maxVal);
    void setRange(QtProperty* property, int minVal, int maxVal);
    void setSingleStep(QtProperty* property, int step);
Q_SIGNALS:
    void valueChanged(QtProperty* property, int val);
    void rangeChanged(QtProperty* property, int minVal, int maxVal);
    void singleStepChanged(QtProperty* property, int step);

protected:
    QString valueText(const QtProperty* property) const override;
    void initializeProperty(QtProperty* property) override;
    void uninitializeProperty(QtProperty* property) override;

private:
    QScopedPointer< QtIntPropertyManagerPrivate > d_ptr;
    Q_DECLARE_PRIVATE(QtIntPropertyManager)
    Q_DISABLE_COPY_MOVE(QtIntPropertyManager)
};

class QtBoolPropertyManagerPrivate;

class QT_QTPROPERTYBROWSER_EXPORT QtBoolPropertyManager : public QtAbstractPropertyManager
{
    Q_OBJECT
public:
    QtBoolPropertyManager(QObject* parent = 0);
    ~QtBoolPropertyManager();

    bool value(const QtProperty* property) const;

public Q_SLOTS:
    void setValue(QtProperty* property, bool val);
Q_SIGNALS:
    void valueChanged(QtProperty* property, bool val);

protected:
    QString valueText(const QtProperty* property) const override;
    QIcon valueIcon(const QtProperty* property) const override;
    void initializeProperty(QtProperty* property) override;
    void uninitializeProperty(QtProperty* property) override;

private:
    QScopedPointer< QtBoolPropertyManagerPrivate > d_ptr;
    Q_DECLARE_PRIVATE(QtBoolPropertyManager)
    Q_DISABLE_COPY_MOVE(QtBoolPropertyManager)
};

class QtDoublePropertyManagerPrivate;

class QT_QTPROPERTYBROWSER_EXPORT QtDoublePropertyManager : public QtAbstractPropertyManager
{
    Q_OBJECT
public:
    QtDoublePropertyManager(QObject* parent = 0);
    ~QtDoublePropertyManager();

    double value(const QtProperty* property) const;
    double minimum(const QtProperty* property) const;
    double maximum(const QtProperty* property) const;
    double singleStep(const QtProperty* property) const;
    int decimals(const QtProperty* property) const;

public Q_SLOTS:
    void setValue(QtProperty* property, double val);
    void setMinimum(QtProperty* property, double minVal);
    void setMaximum(QtProperty* property, double maxVal);
    void setRange(QtProperty* property, double minVal, double maxVal);
    void setSingleStep(QtProperty* property, double step);
    void setDecimals(QtProperty* property, int prec);
Q_SIGNALS:
    void valueChanged(QtProperty* property, double val);
    void rangeChanged(QtProperty* property, double minVal, double maxVal);
    void singleStepChanged(QtProperty* property, double step);
    void decimalsChanged(QtProperty* property, int prec);

protected:
    QString valueText(const QtProperty* property) const override;
    void initializeProperty(QtProperty* property) override;
    void uninitializeProperty(QtProperty* property) override;

private:
    QScopedPointer< QtDoublePropertyManagerPrivate > d_ptr;
    Q_DECLARE_PRIVATE(QtDoublePropertyManager)
    Q_DISABLE_COPY_MOVE(QtDoublePropertyManager)
};

class QtStringPropertyManagerPrivate;

class QT_QTPROPERTYBROWSER_EXPORT QtStringPropertyManager : public QtAbstractPropertyManager
{
    Q_OBJECT
public:
    QtStringPropertyManager(QObject* parent = 0);
    ~QtStringPropertyManager();

    QString value(const QtProperty* property) const;
#if QT_VERSION_MAJOR >= 6
    QRegularExpression regExp(const QtProperty* property) const;
#else
    QRegExp regExp(const QtProperty* property) const;
#endif

public Q_SLOTS:
    void setValue(QtProperty* property, const QString& val);
#if QT_VERSION_MAJOR >= 6
    void setRegExp(QtProperty* property, const QRegularExpression& regExp);
#else
    void setRegExp(QtProperty* property, const QRegExp& regExp);
#endif
Q_SIGNALS:
    void valueChanged(QtProperty* property, const QString& val);
#if QT_VERSION_MAJOR >= 6
    void regExpChanged(QtProperty* property, const QRegularExpression& regExp);
#else
    void regExpChanged(QtProperty* property, const QRegExp& regExp);
#endif
protected:
    QString valueText(const QtProperty* property) const override;
    void initializeProperty(QtProperty* property) override;
    void uninitializeProperty(QtProperty* property) override;

private:
    QScopedPointer< QtStringPropertyManagerPrivate > d_ptr;
    Q_DECLARE_PRIVATE(QtStringPropertyManager)
    Q_DISABLE_COPY_MOVE(QtStringPropertyManager)
};

class QtDatePropertyManagerPrivate;

class QT_QTPROPERTYBROWSER_EXPORT QtDatePropertyManager : public QtAbstractPropertyManager
{
    Q_OBJECT
public:
    QtDatePropertyManager(QObject* parent = 0);
    ~QtDatePropertyManager();

    QDate value(const QtProperty* property) const;
    QDate minimum(const QtProperty* property) const;
    QDate maximum(const QtProperty* property) const;

public Q_SLOTS:
#if QT_VERSION_MAJOR >= 6
    void setValue(QtProperty* property, QDate val);
    void setMinimum(QtProperty* property, QDate minVal);
    void setMaximum(QtProperty* property, QDate maxVal);
    void setRange(QtProperty* property, QDate minVal, QDate maxVal);
Q_SIGNALS:
    void valueChanged(QtProperty* property, QDate val);
    void rangeChanged(QtProperty* property, QDate minVal, QDate maxVal);
#else
    void setValue(QtProperty* property, const QDate& val);
    void setMinimum(QtProperty* property, const QDate& minVal);
    void setMaximum(QtProperty* property, const QDate& maxVal);
    void setRange(QtProperty* property, const QDate& minVal, const QDate& maxVal);
Q_SIGNALS:
    void valueChanged(QtProperty* property, const QDate& val);
    void rangeChanged(QtProperty* property, const QDate& minVal, const QDate& maxVal);
#endif

protected:
    QString valueText(const QtProperty* property) const override;
    void initializeProperty(QtProperty* property) override;
    void uninitializeProperty(QtProperty* property) override;

private:
    QScopedPointer< QtDatePropertyManagerPrivate > d_ptr;
    Q_DECLARE_PRIVATE(QtDatePropertyManager)
    Q_DISABLE_COPY_MOVE(QtDatePropertyManager)
};

class QtTimePropertyManagerPrivate;

class QT_QTPROPERTYBROWSER_EXPORT QtTimePropertyManager : public QtAbstractPropertyManager
{
    Q_OBJECT
public:
    QtTimePropertyManager(QObject* parent = 0);
    ~QtTimePropertyManager();

    QTime value(const QtProperty* property) const;
#if QT_VERSION_MAJOR >= 6
public Q_SLOTS:
    void setValue(QtProperty* property, QTime val);
Q_SIGNALS:
    void valueChanged(QtProperty* property, QTime val);
#else
public Q_SLOTS:
    void setValue(QtProperty* property, const QTime& val);
Q_SIGNALS:
    void valueChanged(QtProperty* property, const QTime& val);
#endif
protected:
    QString valueText(const QtProperty* property) const override;
    void initializeProperty(QtProperty* property) override;
    void uninitializeProperty(QtProperty* property) override;

private:
    QScopedPointer< QtTimePropertyManagerPrivate > d_ptr;
    Q_DECLARE_PRIVATE(QtTimePropertyManager)
    Q_DISABLE_COPY_MOVE(QtTimePropertyManager)
};

class QtDateTimePropertyManagerPrivate;

class QT_QTPROPERTYBROWSER_EXPORT QtDateTimePropertyManager : public QtAbstractPropertyManager
{
    Q_OBJECT
public:
    QtDateTimePropertyManager(QObject* parent = 0);
    ~QtDateTimePropertyManager();

    QDateTime value(const QtProperty* property) const;

public Q_SLOTS:
    void setValue(QtProperty* property, const QDateTime& val);
Q_SIGNALS:
    void valueChanged(QtProperty* property, const QDateTime& val);

protected:
    QString valueText(const QtProperty* property) const override;
    void initializeProperty(QtProperty* property) override;
    void uninitializeProperty(QtProperty* property) override;

private:
    QScopedPointer< QtDateTimePropertyManagerPrivate > d_ptr;
    Q_DECLARE_PRIVATE(QtDateTimePropertyManager)
    Q_DISABLE_COPY_MOVE(QtDateTimePropertyManager)
};

class QtKeySequencePropertyManagerPrivate;

class QT_QTPROPERTYBROWSER_EXPORT QtKeySequencePropertyManager : public QtAbstractPropertyManager
{
    Q_OBJECT
public:
    QtKeySequencePropertyManager(QObject* parent = 0);
    ~QtKeySequencePropertyManager();

    QKeySequence value(const QtProperty* property) const;

public Q_SLOTS:
    void setValue(QtProperty* property, const QKeySequence& val);
Q_SIGNALS:
    void valueChanged(QtProperty* property, const QKeySequence& val);

protected:
    QString valueText(const QtProperty* property) const override;
    void initializeProperty(QtProperty* property) override;
    void uninitializeProperty(QtProperty* property) override;

private:
    QScopedPointer< QtKeySequencePropertyManagerPrivate > d_ptr;
    Q_DECLARE_PRIVATE(QtKeySequencePropertyManager)
    Q_DISABLE_COPY_MOVE(QtKeySequencePropertyManager)
};

class QtCharPropertyManagerPrivate;

class QT_QTPROPERTYBROWSER_EXPORT QtCharPropertyManager : public QtAbstractPropertyManager
{
    Q_OBJECT
public:
    QtCharPropertyManager(QObject* parent = 0);
    ~QtCharPropertyManager();

    QChar value(const QtProperty* property) const;

public Q_SLOTS:
    void setValue(QtProperty* property, const QChar& val);
Q_SIGNALS:
    void valueChanged(QtProperty* property, const QChar& val);

protected:
    QString valueText(const QtProperty* property) const override;
    void initializeProperty(QtProperty* property) override;
    void uninitializeProperty(QtProperty* property) override;

private:
    QScopedPointer< QtCharPropertyManagerPrivate > d_ptr;
    Q_DECLARE_PRIVATE(QtCharPropertyManager)
    Q_DISABLE_COPY_MOVE(QtCharPropertyManager)
};

class QtEnumPropertyManager;
class QtLocalePropertyManagerPrivate;

class QT_QTPROPERTYBROWSER_EXPORT QtLocalePropertyManager : public QtAbstractPropertyManager
{
    Q_OBJECT
public:
    QtLocalePropertyManager(QObject* parent = 0);
    ~QtLocalePropertyManager();

    QtEnumPropertyManager* subEnumPropertyManager() const;

    QLocale value(const QtProperty* property) const;

public Q_SLOTS:
    void setValue(QtProperty* property, const QLocale& val);
Q_SIGNALS:
    void valueChanged(QtProperty* property, const QLocale& val);

protected:
    QString valueText(const QtProperty* property) const override;
    void initializeProperty(QtProperty* property) override;
    void uninitializeProperty(QtProperty* property) override;

private:
    QScopedPointer< QtLocalePropertyManagerPrivate > d_ptr;
    Q_DECLARE_PRIVATE(QtLocalePropertyManager)
    Q_DISABLE_COPY_MOVE(QtLocalePropertyManager)
};

class QtPointPropertyManagerPrivate;

class QT_QTPROPERTYBROWSER_EXPORT QtPointPropertyManager : public QtAbstractPropertyManager
{
    Q_OBJECT
public:
    QtPointPropertyManager(QObject* parent = 0);
    ~QtPointPropertyManager();

    QtIntPropertyManager* subIntPropertyManager() const;

    QPoint value(const QtProperty* property) const;

public Q_SLOTS:
    void setValue(QtProperty* property, const QPoint& val);
Q_SIGNALS:
    void valueChanged(QtProperty* property, const QPoint& val);

protected:
    QString valueText(const QtProperty* property) const override;
    void initializeProperty(QtProperty* property) override;
    void uninitializeProperty(QtProperty* property) override;

private:
    QScopedPointer< QtPointPropertyManagerPrivate > d_ptr;
    Q_DECLARE_PRIVATE(QtPointPropertyManager)
    Q_DISABLE_COPY_MOVE(QtPointPropertyManager)
};

class QtPointFPropertyManagerPrivate;

class QT_QTPROPERTYBROWSER_EXPORT QtPointFPropertyManager : public QtAbstractPropertyManager
{
    Q_OBJECT
public:
    QtPointFPropertyManager(QObject* parent = 0);
    ~QtPointFPropertyManager();

    QtDoublePropertyManager* subDoublePropertyManager() const;

    QPointF value(const QtProperty* property) const;
    int decimals(const QtProperty* property) const;

public Q_SLOTS:
    void setValue(QtProperty* property, const QPointF& val);
    void setDecimals(QtProperty* property, int prec);
Q_SIGNALS:
    void valueChanged(QtProperty* property, const QPointF& val);
    void decimalsChanged(QtProperty* property, int prec);

protected:
    QString valueText(const QtProperty* property) const override;
    void initializeProperty(QtProperty* property) override;
    void uninitializeProperty(QtProperty* property) override;

private:
    QScopedPointer< QtPointFPropertyManagerPrivate > d_ptr;
    Q_DECLARE_PRIVATE(QtPointFPropertyManager)
    Q_DISABLE_COPY_MOVE(QtPointFPropertyManager)
};

class QtSizePropertyManagerPrivate;

class QT_QTPROPERTYBROWSER_EXPORT QtSizePropertyManager : public QtAbstractPropertyManager
{
    Q_OBJECT
public:
    QtSizePropertyManager(QObject* parent = 0);
    ~QtSizePropertyManager();

    QtIntPropertyManager* subIntPropertyManager() const;

    QSize value(const QtProperty* property) const;
    QSize minimum(const QtProperty* property) const;
    QSize maximum(const QtProperty* property) const;

public Q_SLOTS:
    void setValue(QtProperty* property, const QSize& val);
    void setMinimum(QtProperty* property, const QSize& minVal);
    void setMaximum(QtProperty* property, const QSize& maxVal);
    void setRange(QtProperty* property, const QSize& minVal, const QSize& maxVal);
Q_SIGNALS:
    void valueChanged(QtProperty* property, const QSize& val);
    void rangeChanged(QtProperty* property, const QSize& minVal, const QSize& maxVal);

protected:
    QString valueText(const QtProperty* property) const override;
    void initializeProperty(QtProperty* property) override;
    void uninitializeProperty(QtProperty* property) override;

private:
    QScopedPointer< QtSizePropertyManagerPrivate > d_ptr;
    Q_DECLARE_PRIVATE(QtSizePropertyManager)
    Q_DISABLE_COPY_MOVE(QtSizePropertyManager)
};

class QtSizeFPropertyManagerPrivate;

class QT_QTPROPERTYBROWSER_EXPORT QtSizeFPropertyManager : public QtAbstractPropertyManager
{
    Q_OBJECT
public:
    QtSizeFPropertyManager(QObject* parent = 0);
    ~QtSizeFPropertyManager();

    QtDoublePropertyManager* subDoublePropertyManager() const;

    QSizeF value(const QtProperty* property) const;
    QSizeF minimum(const QtProperty* property) const;
    QSizeF maximum(const QtProperty* property) const;
    int decimals(const QtProperty* property) const;

public Q_SLOTS:
    void setValue(QtProperty* property, const QSizeF& val);
    void setMinimum(QtProperty* property, const QSizeF& minVal);
    void setMaximum(QtProperty* property, const QSizeF& maxVal);
    void setRange(QtProperty* property, const QSizeF& minVal, const QSizeF& maxVal);
    void setDecimals(QtProperty* property, int prec);
Q_SIGNALS:
    void valueChanged(QtProperty* property, const QSizeF& val);
    void rangeChanged(QtProperty* property, const QSizeF& minVal, const QSizeF& maxVal);
    void decimalsChanged(QtProperty* property, int prec);

protected:
    QString valueText(const QtProperty* property) const override;
    void initializeProperty(QtProperty* property) override;
    void uninitializeProperty(QtProperty* property) override;

private:
    QScopedPointer< QtSizeFPropertyManagerPrivate > d_ptr;
    Q_DECLARE_PRIVATE(QtSizeFPropertyManager)
    Q_DISABLE_COPY_MOVE(QtSizeFPropertyManager)
};

class QtRectPropertyManagerPrivate;

class QT_QTPROPERTYBROWSER_EXPORT QtRectPropertyManager : public QtAbstractPropertyManager
{
    Q_OBJECT
public:
    QtRectPropertyManager(QObject* parent = 0);
    ~QtRectPropertyManager();

    QtIntPropertyManager* subIntPropertyManager() const;

    QRect value(const QtProperty* property) const;
    QRect constraint(const QtProperty* property) const;

public Q_SLOTS:
    void setValue(QtProperty* property, const QRect& val);
    void setConstraint(QtProperty* property, const QRect& constraint);
Q_SIGNALS:
    void valueChanged(QtProperty* property, const QRect& val);
    void constraintChanged(QtProperty* property, const QRect& constraint);

protected:
    QString valueText(const QtProperty* property) const override;
    void initializeProperty(QtProperty* property) override;
    void uninitializeProperty(QtProperty* property) override;

private:
    QScopedPointer< QtRectPropertyManagerPrivate > d_ptr;
    Q_DECLARE_PRIVATE(QtRectPropertyManager)
    Q_DISABLE_COPY_MOVE(QtRectPropertyManager)
};

class QtRectFPropertyManagerPrivate;

class QT_QTPROPERTYBROWSER_EXPORT QtRectFPropertyManager : public QtAbstractPropertyManager
{
    Q_OBJECT
public:
    QtRectFPropertyManager(QObject* parent = 0);
    ~QtRectFPropertyManager();

    QtDoublePropertyManager* subDoublePropertyManager() const;

    QRectF value(const QtProperty* property) const;
    QRectF constraint(const QtProperty* property) const;
    int decimals(const QtProperty* property) const;

public Q_SLOTS:
    void setValue(QtProperty* property, const QRectF& val);
    void setConstraint(QtProperty* property, const QRectF& constraint);
    void setDecimals(QtProperty* property, int prec);
Q_SIGNALS:
    void valueChanged(QtProperty* property, const QRectF& val);
    void constraintChanged(QtProperty* property, const QRectF& constraint);
    void decimalsChanged(QtProperty* property, int prec);

protected:
    QString valueText(const QtProperty* property) const override;
    void initializeProperty(QtProperty* property) override;
    void uninitializeProperty(QtProperty* property) override;

private:
    QScopedPointer< QtRectFPropertyManagerPrivate > d_ptr;
    Q_DECLARE_PRIVATE(QtRectFPropertyManager)
    Q_DISABLE_COPY_MOVE(QtRectFPropertyManager)
};

class QtEnumPropertyManagerPrivate;

class QT_QTPROPERTYBROWSER_EXPORT QtEnumPropertyManager : public QtAbstractPropertyManager
{
    Q_OBJECT
public:
    QtEnumPropertyManager(QObject* parent = 0);
    ~QtEnumPropertyManager();

    int value(const QtProperty* property) const;
    QStringList enumNames(const QtProperty* property) const;
    QMap< int, QIcon > enumIcons(const QtProperty* property) const;

public Q_SLOTS:
    void setValue(QtProperty* property, int val);
    void setEnumNames(QtProperty* property, const QStringList& names);
    void setEnumIcons(QtProperty* property, const QMap< int, QIcon >& icons);
Q_SIGNALS:
    void valueChanged(QtProperty* property, int val);
    void enumNamesChanged(QtProperty* property, const QStringList& names);
    void enumIconsChanged(QtProperty* property, const QMap< int, QIcon >& icons);

protected:
    QString valueText(const QtProperty* property) const override;
    QIcon valueIcon(const QtProperty* property) const override;
    void initializeProperty(QtProperty* property) override;
    void uninitializeProperty(QtProperty* property) override;

private:
    QScopedPointer< QtEnumPropertyManagerPrivate > d_ptr;
    Q_DECLARE_PRIVATE(QtEnumPropertyManager)
    Q_DISABLE_COPY_MOVE(QtEnumPropertyManager)
};

class QtFlagPropertyManagerPrivate;

class QT_QTPROPERTYBROWSER_EXPORT QtFlagPropertyManager : public QtAbstractPropertyManager
{
    Q_OBJECT
public:
    QtFlagPropertyManager(QObject* parent = 0);
    ~QtFlagPropertyManager();

    QtBoolPropertyManager* subBoolPropertyManager() const;

    int value(const QtProperty* property) const;
    QStringList flagNames(const QtProperty* property) const;

public Q_SLOTS:
    void setValue(QtProperty* property, int val);
    void setFlagNames(QtProperty* property, const QStringList& names);
Q_SIGNALS:
    void valueChanged(QtProperty* property, int val);
    void flagNamesChanged(QtProperty* property, const QStringList& names);

protected:
    QString valueText(const QtProperty* property) const override;
    void initializeProperty(QtProperty* property) override;
    void uninitializeProperty(QtProperty* property) override;

private:
    QScopedPointer< QtFlagPropertyManagerPrivate > d_ptr;
    Q_DECLARE_PRIVATE(QtFlagPropertyManager)
    Q_DISABLE_COPY_MOVE(QtFlagPropertyManager)
};

class QtSizePolicyPropertyManagerPrivate;

class QT_QTPROPERTYBROWSER_EXPORT QtSizePolicyPropertyManager : public QtAbstractPropertyManager
{
    Q_OBJECT
public:
    QtSizePolicyPropertyManager(QObject* parent = 0);
    ~QtSizePolicyPropertyManager();

    QtIntPropertyManager* subIntPropertyManager() const;
    QtEnumPropertyManager* subEnumPropertyManager() const;

    QSizePolicy value(const QtProperty* property) const;

public Q_SLOTS:
    void setValue(QtProperty* property, const QSizePolicy& val);
Q_SIGNALS:
    void valueChanged(QtProperty* property, const QSizePolicy& val);

protected:
    QString valueText(const QtProperty* property) const override;
    void initializeProperty(QtProperty* property) override;
    void uninitializeProperty(QtProperty* property) override;

private:
    QScopedPointer< QtSizePolicyPropertyManagerPrivate > d_ptr;
    Q_DECLARE_PRIVATE(QtSizePolicyPropertyManager)
    Q_DISABLE_COPY_MOVE(QtSizePolicyPropertyManager)
};

class QtFontPropertyManagerPrivate;

class QT_QTPROPERTYBROWSER_EXPORT QtFontPropertyManager : public QtAbstractPropertyManager
{
    Q_OBJECT
public:
    QtFontPropertyManager(QObject* parent = 0);
    ~QtFontPropertyManager();

    QtIntPropertyManager* subIntPropertyManager() const;
    QtEnumPropertyManager* subEnumPropertyManager() const;
    QtBoolPropertyManager* subBoolPropertyManager() const;

    QFont value(const QtProperty* property) const;

public Q_SLOTS:
    void setValue(QtProperty* property, const QFont& val);
Q_SIGNALS:
    void valueChanged(QtProperty* property, const QFont& val);

protected:
    QString valueText(const QtProperty* property) const override;
    QIcon valueIcon(const QtProperty* property) const override;
    void initializeProperty(QtProperty* property) override;
    void uninitializeProperty(QtProperty* property) override;

private:
    QScopedPointer< QtFontPropertyManagerPrivate > d_ptr;
    Q_DECLARE_PRIVATE(QtFontPropertyManager)
    Q_DISABLE_COPY_MOVE(QtFontPropertyManager)
};

class QtColorPropertyManagerPrivate;

class QT_QTPROPERTYBROWSER_EXPORT QtColorPropertyManager : public QtAbstractPropertyManager
{
    Q_OBJECT
public:
    QtColorPropertyManager(QObject* parent = 0);
    ~QtColorPropertyManager();

    QtIntPropertyManager* subIntPropertyManager() const;

    QColor value(const QtProperty* property) const;

public Q_SLOTS:
    void setValue(QtProperty* property, const QColor& val);
Q_SIGNALS:
    void valueChanged(QtProperty* property, const QColor& val);

protected:
    QString valueText(const QtProperty* property) const override;
    QIcon valueIcon(const QtProperty* property) const override;
    void initializeProperty(QtProperty* property) override;
    void uninitializeProperty(QtProperty* property) override;

private:
    QScopedPointer< QtColorPropertyManagerPrivate > d_ptr;
    Q_DECLARE_PRIVATE(QtColorPropertyManager)
    Q_DISABLE_COPY_MOVE(QtColorPropertyManager)
};

class QtCursorPropertyManagerPrivate;

class QT_QTPROPERTYBROWSER_EXPORT QtCursorPropertyManager : public QtAbstractPropertyManager
{
    Q_OBJECT
public:
    QtCursorPropertyManager(QObject* parent = 0);
    ~QtCursorPropertyManager();

#ifndef QT_NO_CURSOR
    QCursor value(const QtProperty* property) const;
#endif

public Q_SLOTS:
    void setValue(QtProperty* property, const QCursor& val);
Q_SIGNALS:
    void valueChanged(QtProperty* property, const QCursor& val);

protected:
    QString valueText(const QtProperty* property) const override;
    QIcon valueIcon(const QtProperty* property) const override;
    void initializeProperty(QtProperty* property) override;
    void uninitializeProperty(QtProperty* property) override;

private:
    QScopedPointer< QtCursorPropertyManagerPrivate > d_ptr;
    Q_DECLARE_PRIVATE(QtCursorPropertyManager)
    Q_DISABLE_COPY_MOVE(QtCursorPropertyManager)
};

QT_END_NAMESPACE

#endif
