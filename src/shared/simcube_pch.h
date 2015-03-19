/*
 * This is a precompiled header file for use in Xcode / Mac GCC /
 * GCC >= 3.4 / VC to greatly speed the building of SimCube.
 */

#if defined __cplusplus
#include <QtGlobal>

#ifdef Q_OS_WIN
# define _POSIX_
# include <limits.h>
# undef _POSIX_
#endif

#include <QCoreApplication>
#include <QList>
#include <QVariant>
#include <QObject>
#include <QRegExp>
#include <QString>
#include <QStringList>
#include <QTextCodec>
#include <QPointer>
#include <QScopedPointer>
#include <QSharedPointer>
#include <QDebug>

#include <stdlib.h>
#endif
