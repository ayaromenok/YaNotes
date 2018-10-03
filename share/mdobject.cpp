#include "mdobject.h"
#include "../share/share.h"
#include "../3rdparty/hoedown/src/html.h"

MDObject::MDObject(QObject *parent) : QObject(parent)
{
    YN_TIMESTAMP();
}

MDObject::~MDObject()
{
    YN_TIMESTAMP();
}

QString
MDObject::toHtml(QString &strMD)
{
    YN_TIMESTAMP();
    qDebug() << "MD input" << strMD;

    hoedown_renderer *renderer =
                hoedown_html_renderer_new(HOEDOWN_HTML_USE_XHTML, 32);

    hoedown_extensions extensions =
            (hoedown_extensions) ((HOEDOWN_EXT_BLOCK | HOEDOWN_EXT_SPAN |
                                   HOEDOWN_EXT_MATH_EXPLICIT) & ~HOEDOWN_EXT_QUOTE);
    hoedown_document *document = hoedown_document_new(renderer, extensions, 32);


    unsigned char *sequence = (unsigned char *) qstrdup(
                strMD.toUtf8().constData());
    qint64 length = strlen((char *) sequence);

    hoedown_buffer *html = hoedown_buffer_new(length);
    hoedown_document_render(document, html, sequence, length);
    QString strResult = QString::fromUtf8((char *) html->data, html->size);

    qDebug() << "HTML output" << strResult;

    //free
    free(sequence);
    hoedown_buffer_free(html);
    hoedown_document_free(document);
    hoedown_html_renderer_free(renderer);

    return strResult;
}
