#ifndef BUTTOMSTATUSWIDGET_H
#define BUTTOMSTATUSWIDGET_H

#include <QObject>
#include <QWidget>
#include <QHBoxLayout>
#include <QGuiApplication>
#include <QLabel>
#include <QScreen>
#include <QMouseEvent>

class ButtomStatusWidget :public QWidget
{
public:
    ButtomStatusWidget(QWidget* parent =nullptr);

    void moveToBottom();

    void updateInfo(const QString &info);

protected:
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private:
    bool m_draging = false;
    QPoint m_dragoffset;
     QLabel *m_label;
};

#endif // BUTTOMSTATUSWIDGET_H
