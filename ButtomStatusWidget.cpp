#include "ButtomStatusWidget.h"

ButtomStatusWidget::ButtomStatusWidget(QWidget *parent)
{

    setWindowFlags(Qt::Tool | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_TranslucentBackground, false);

    resize(400, 40);

    m_label = new QLabel("系统运行中...", this);
    m_label->setAlignment(Qt::AlignCenter);
    m_label->setAttribute(Qt::WA_TransparentForMouseEvents);

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setContentsMargins(10, 0, 10, 0);
    layout->addWidget(m_label);

    setStyleSheet(
                "background-color:#ffffff;"
                "color:black;"
                "font-size:14px;"
                );

    moveToBottom();
    //transparent
}

void ButtomStatusWidget::moveToBottom()
{
    QRect screen = QGuiApplication::primaryScreen()->availableGeometry();
    move((screen.width() - width()) / 2,
         screen.height() - height() - 2);
}

void ButtomStatusWidget::updateInfo(const QString &info)
{
    m_label->setText(info);
}

void ButtomStatusWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (m_draging && (event->buttons() & Qt::LeftButton))
    {
        move(event->globalPos() - m_dragoffset);
         event->accept();
    }
}

void ButtomStatusWidget::mouseReleaseEvent(QMouseEvent *event)
{
    m_draging = false;
    event->accept();
}

void ButtomStatusWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_draging = true;
        m_dragoffset = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
}
