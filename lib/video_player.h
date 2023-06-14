#ifndef VIDEOPLAYER_HH
#define VIDEOPLAYER_HH


#include <QtMultimediaWidgets/QVideoWidget>
#include <QtNetwork/QNetworkDatagram>
#include <QtNetwork/QUdpSocket>
#include <QtWidgets/QWidget>
#include <QBuffer>
#include <QByteArray>
#include <QFile>
#include <QLabel>
#include <QMainWindow>
#include <QMediaPlayer>
#include <QObject>
#include <QPushButton>
#include <QSlider>
#include <QTemporaryFile>
#include <QThread>
#include <QTime>
#include <QUrl>
#include <QVBoxLayout>
class video_player : public QWidget
{
    Q_OBJECT

public:
    video_player(QWidget* parent = nullptr, QString videoFile = "");
    ~video_player();
    void playvideo();
    void stopvideo();

    // public slots:
    //     void data_read(QByteArray videoBuffer);

private:
    QMediaPlayer* player;
    QString d_videoFile;
    bool d_downloading = true;
    qint64 d_position = 0;
};

#endif // VIDEOPLAYER_HH

#ifndef VIDEOSIGNAL_HH
#define VIDEOSIGNAL_HH

class video_player_signal : public QObject
{
    Q_OBJECT

public:
    video_player_signal() {}
    ~video_player_signal() {}

signals:
    void data_send(QByteArray videoBuffer);
};

#endif // VIDEOSIGNAL_HH
