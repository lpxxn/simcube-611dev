#ifndef TYPEDECLARE
#define TYPEDECLARE

#include <QXlsx/xlsxformat.h>
#include <QXlsx/xlsxcell.h>
#include <QXlsx/xlsxworksheet.h>

Q_DECLARE_METATYPE(QXlsx::Format)
Q_DECLARE_METATYPE(QXlsx::Format*)
Q_DECLARE_METATYPE(QXlsx::Cell*)
Q_DECLARE_METATYPE(QXlsx::Worksheet*)
Q_DECLARE_METATYPE(QXlsx::Format::HorizontalAlignment)

#endif // TYPEDECLARE

