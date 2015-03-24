#include "xlsxdocument.h"
#include "typedeclare.h"

#include <QXlsx/xlsxdocument.h>

#include <QScriptEngine>
#include <QDebug>
#include <QImage>

using namespace QXlsx;

XlsxDocument::XlsxDocument(QObject *parent)
{
    m_document = new Document(parent);
}

XlsxDocument::XlsxDocument(const QString &name, QObject *parent)
{
    m_document = new Document(name, parent);
}

XlsxDocument::XlsxDocument(QIODevice *device, QObject *parent) : QObject(parent)
{
    m_document = new Document(device, parent);
}

XlsxDocument::~XlsxDocument()
{
    qDebug() << "delete XlsxDocument.";
    delete m_document;
}

QScriptValue XlsxDocument::cellAt() const
{
    const int n = argumentCount();
    Cell* cell = nullptr;
    if (n == 2 && argument(0).isNumber() && argument(1).isNumber()) {
        int row = argument(0).toInt32();
        int col = argument(1).toInt32();
        cell = m_document->cellAt(row, col);
    } else if (n == 1 && argument(0).isString()) {
        cell = m_document->cellAt(argument(0).toString());
    }

    return cell ? engine()->toScriptValue(cell) : engine()->undefinedValue();
}

bool XlsxDocument::copySheet(const QString &srcName, const QString &distName)
{
    return m_document->copySheet(srcName, distName);
}

bool XlsxDocument::deleteSheet(const QString &name)
{
    return m_document->deleteSheet(name);
}

bool XlsxDocument::insertSheet(int index, const QString &name, SheetType type)
{
    return m_document->insertSheet(index, name, (QXlsx::AbstractSheet::SheetType)type);
}

bool XlsxDocument::renameSheet(const QString &oldName, const QString &newName)
{
    return m_document->renameSheet(oldName, newName);
}

bool XlsxDocument::moveSheet(const QString &srcName, int distIndex)
{
    return m_document->moveSheet(srcName, distIndex);
}

QString XlsxDocument::documentProperty(const QString &key) const
{
    return m_document->documentProperty(key);
}

QStringList XlsxDocument::documentPropertyNames() const
{
    return m_document->documentPropertyNames();
}

bool XlsxDocument::addSheet(const QString &name, XlsxDocument::SheetType type)
{
    return m_document->addSheet(name, AbstractSheet::SheetType(type));
}

bool XlsxDocument::save() const
{
    return m_document->save();
}

bool XlsxDocument::saveAs(const QString &name) const
{
    return m_document->saveAs(name);
}

bool XlsxDocument::write()
{
    const int n = argumentCount();
    QXlsx::Format f;
    if (n >= 3 && argument(0).isNumber() && argument(1).isNumber()) {
        int row = argument(0).toInt32();
        int col = argument(1).toInt32();
        if (n == 4)
            f = qscriptvalue_cast<QXlsx::Format>(argument(3));
        return m_document->write(row, col, argument(2).toVariant(), f);
    } else if (n >= 2 && argument(0).isString()) {
        if (n == 3)
            f = qscriptvalue_cast<QXlsx::Format>(argument(2));
        return m_document->write(argument(0).toString(), argument(1).toVariant(), f);
    }
    return false;
}

QVariant XlsxDocument::read() const
{
    const int n = argumentCount();
    if (n == 2 && argument(0).isNumber() && argument(1).isNumber()) {
        int row = argument(0).toInt32();
        int col = argument(1).toInt32();
        return m_document->read(row, col);
    } else if (n == 1 && argument(0).isString()) {
        return m_document->read(argument(0).toString());
    }
    return engine()->undefinedValue().toVariant();
}

bool XlsxDocument::selectSheet(const QString &name)
{
    return m_document->selectSheet(name);
}

void XlsxDocument::setDocumentProperty(const QString &key, const QString &property)
{
    m_document->setDocumentProperty(key, property);
}

QScriptValue XlsxDocument::worksheet(const QString &sheetName) const
{
    QXlsx::Worksheet* ws = dynamic_cast<QXlsx::Worksheet*>(m_document->sheet(sheetName));
    return ws ? engine()->toScriptValue(ws) : engine()->nullValue();
}

QStringList XlsxDocument::sheetNames() const
{
    return m_document->sheetNames();
}

QScriptValue XlsxDocument::rowCount() const
{
    return m_document->dimension().lastRow();

}

QScriptValue XlsxDocument::columnCount() const
{
    return m_document->dimension().lastColumn();
}

QScriptValue XlsxDocument::currentWorksheet() const
{
    QXlsx::Worksheet* ws = m_document->currentWorksheet();
    return ws ? engine()->toScriptValue(ws) : engine()->nullValue();
}

bool XlsxDocument::mergeCells(const QString &range, const Format &format)
{
    return m_document->mergeCells(CellRange(range), format);
}

bool XlsxDocument::unmergeCells(const QString &range)
{
    return m_document->unmergeCells(CellRange(range));
}

bool XlsxDocument::insertImage(int row, int col, const QString &imgPath)
{
    QImage img(imgPath);

    return m_document->insertImage(row, col, img);
}

bool XlsxDocument::insertImage(int row, int col, const QImage &img)
{
    return m_document->insertImage(row, col, img);
}

bool XlsxDocument::setColumnWidth(int column, double width)
{
    return m_document->setColumnWidth(column, width);
}

bool XlsxDocument::setColumnWidth(int colFirst, int colLast, double width)
{
    return m_document->setColumnWidth(colFirst, colLast, width);
}

bool XlsxDocument::setColumnFormat(int column, const Format &format)
{
    return m_document->setColumnFormat(column, format);
}

bool XlsxDocument::setColumnFormat(int colFirst, int colLast, const Format &format)
{
    return m_document->setColumnFormat(colFirst, colLast, format);
}

bool XlsxDocument::setColumnHidden(int column, bool hidden)
{
    return m_document->setColumnHidden(column, hidden);
}

bool XlsxDocument::setColumnHidden(int colFirst, int colLast, bool hidden)
{
    return m_document->setColumnHidden(colFirst, colLast, hidden);
}

double XlsxDocument::columnWidth(int column)
{
    return m_document->columnWidth(column);
}

QScriptValue XlsxDocument::columnFormat(int column)
{
    return engine()->toScriptValue(m_document->columnFormat(column));
}

bool XlsxDocument::isColumnHidden(int column)
{
    return m_document->isColumnHidden(column);
}

bool XlsxDocument::setRowHeight(int row, double height)
{
    return m_document->setRowHeight(row, height);
}

bool XlsxDocument::setRowFormat(int row, const Format &format)
{
    return m_document->setRowFormat(row, format);
}

bool XlsxDocument::setRowHidden(int row, bool hidden)
{
    return m_document->setRowHidden(row, hidden);
}

bool XlsxDocument::setRowHeight(int rowFirst, int rowLast, double height)
{
    return m_document->setRowHeight(rowFirst, rowLast, height);
}

bool XlsxDocument::setRowFormat(int rowFirst, int rowLast, const Format &format)
{
    return m_document->setRowFormat(rowFirst, rowLast, format);
}

bool XlsxDocument::setRowHidden(int rowFirst, int rowLast, bool hidden)
{
    return m_document->setRowHeight(rowFirst, rowLast, hidden);
}

double XlsxDocument::rowHeight(int row)
{
    return m_document->rowHeight(row);
}

QScriptValue XlsxDocument::rowFormat(int row)
{
    return engine()->toScriptValue(m_document->rowFormat(row));
}

bool XlsxDocument::isRowHidden(int row)
{
    return m_document->isRowHidden(row);
}

bool XlsxDocument::groupRows(int rowFirst, int rowLast, bool collapsed)
{
    return m_document->groupRows(rowFirst, rowLast, collapsed);
}

bool XlsxDocument::groupColumns(int colFirst, int colLast, bool collapsed)
{
    return m_document->groupColumns(colFirst, colLast, collapsed);
}

//QScriptValue XlsxDocument::cellAt(int row, int col) const
//{
//    if (Worksheet *sheet = m_document->currentWorksheet())
//        return engine()->toScriptValue(sheet->cellAt(row, col));
//    return engine()->nullValue();
//}

bool XlsxDocument::defineName(const QString &name, const QString &formula, const QString &comment, const QString &scope)
{
    return m_document->defineName(name, formula, comment, scope);
}









