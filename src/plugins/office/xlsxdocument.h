#ifndef XLSXDOCUMENT_H
#define XLSXDOCUMENT_H

#include <QXlsx/xlsxformat.h>

#include <QVariant>
#include <QScriptValue>
#include <QScriptable>

namespace QXlsx {
    class Document;
}

class QIODevice;

class XlsxDocument : public QObject, public QScriptable
{
    Q_OBJECT
    Q_ENUMS(SheetType)
public:
    enum SheetType {
        WorkSheet,
        ChartSheet,
        DialogSheet,
        MacroSheet
    };

    XlsxDocument(QObject *parent = nullptr);
    explicit XlsxDocument(const QString& name, QObject *parent = nullptr);
    explicit XlsxDocument(QIODevice* device, QObject *parent = nullptr);
    ~XlsxDocument();

    //bool addConditionalFormatting(const ConditionalFormatting &cf);
    //bool addDataValidation(const DataValidation &validation);
    Q_INVOKABLE bool addSheet(const QString &name = QString(), SheetType type = WorkSheet);
    Q_INVOKABLE QScriptValue cellAt() const;

    Q_INVOKABLE bool copySheet(const QString& srcName, const QString& distName);

    Q_INVOKABLE bool deleteSheet(const QString & name);

    //begin---
    Q_INVOKABLE bool insertSheet(int index, const QString &name = QString(), SheetType type = WorkSheet);
    Q_INVOKABLE bool renameSheet(const QString &oldName, const QString &newName);
    Q_INVOKABLE bool moveSheet(const QString &srcName, int distIndex);
    //end---
    Q_INVOKABLE QString documentProperty(const QString& key) const;
    Q_INVOKABLE QStringList	documentPropertyNames() const;

    Q_INVOKABLE QVariant read() const;

    Q_INVOKABLE bool save() const;
    Q_INVOKABLE bool saveAs(const QString & name) const;
    Q_INVOKABLE bool selectSheet(const QString& name);
    Q_INVOKABLE void setDocumentProperty(const QString& key, const QString& property);
    Q_INVOKABLE QStringList sheetNames() const;
    Q_INVOKABLE QScriptValue worksheet(const QString& sheetName) const;
    Q_INVOKABLE bool write();



    Q_INVOKABLE QScriptValue rowCount() const;
    Q_INVOKABLE QScriptValue columnCount() const;
    Q_INVOKABLE QScriptValue currentWorksheet() const;
    Q_INVOKABLE bool mergeCells(const QString &range, const QXlsx::Format &format = QXlsx::Format());
    Q_INVOKABLE bool unmergeCells(const QString &range);
    Q_INVOKABLE bool insertImage(int row, int col, const QString &imgPath);
    Q_INVOKABLE bool insertImage(int row, int col, const QImage &img);

    //begin--
    Q_INVOKABLE bool setColumnWidth(int column, double width);
    Q_INVOKABLE bool setColumnWidth(int colFirst, int colLast, double width);

    Q_INVOKABLE bool setColumnFormat(int column, const QXlsx::Format &format);
    Q_INVOKABLE bool setColumnFormat(int colFirst, int colLast, const QXlsx::Format &format);

    Q_INVOKABLE bool setColumnHidden(int column, bool hidden);
    Q_INVOKABLE bool setColumnHidden(int colFirst, int colLast, bool hidden);

    Q_INVOKABLE double columnWidth(int column);
    Q_INVOKABLE QScriptValue columnFormat(int column);
    Q_INVOKABLE bool isColumnHidden(int column);

    Q_INVOKABLE bool setRowHeight(int row, double height);
    Q_INVOKABLE bool setRowFormat(int row, const QXlsx::Format &format);
    Q_INVOKABLE bool setRowHidden(int row, bool hidden);
    Q_INVOKABLE bool setRowHeight(int rowFirst, int rowLast, double height);
    Q_INVOKABLE bool setRowFormat(int rowFirst, int rowLast, const QXlsx::Format &format);
    Q_INVOKABLE bool setRowHidden(int rowFirst, int rowLast, bool hidden);

    Q_INVOKABLE double rowHeight(int row);
    Q_INVOKABLE QScriptValue rowFormat(int row);
    Q_INVOKABLE bool isRowHidden(int row);

    Q_INVOKABLE bool groupRows(int rowFirst, int rowLast, bool collapsed = true);
    Q_INVOKABLE bool groupColumns(int colFirst, int colLast, bool collapsed = true);

    //Q_INVOKABLE QScriptValue cellAt(int row, int col) const;
    Q_INVOKABLE bool defineName(const QString &name, const QString &formula, const QString &comment=QString(), const QString &scope=QString());
    // end----


private:
    QXlsx::Document* m_document;
};

#endif // XLSXDOCUMENT_H
