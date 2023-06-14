#include "video_player.h"
// #include "ui_video_player.h"
#include <QMessageBox>

video_player::video_player(QWidget* parent, QString videoFile)
    : QWidget(parent), d_videoFile(videoFile)

{
    qInfo() << d_videoFile;

    QVideoWidget* videoWidget = new QVideoWidget(this);
    QSlider* timeSlider = new QSlider(Qt::Horizontal, this);
    QLabel* durationLabel = new QLabel(this);
    QLabel* playedTimeLabel = new QLabel(this);
    QPushButton* start_button = new QPushButton("Play", this);
    QPushButton* stop_button = new QPushButton("Stop", this);

    QHBoxLayout* buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(start_button);
    buttonLayout->addWidget(stop_button);

    QHBoxLayout* sliderLayout = new QHBoxLayout;
    sliderLayout->addWidget(playedTimeLabel);
    sliderLayout->addWidget(timeSlider);
    sliderLayout->addWidget(durationLabel);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(videoWidget);
    layout->addItem(sliderLayout);
    layout->addItem(buttonLayout);
    setLayout(layout);

    player = new QMediaPlayer;
    player->setVideoOutput(videoWidget);
    player->setMedia(QUrl::fromLocalFile(d_videoFile));

    connect(start_button, &QPushButton::clicked, this, &video_player::playvideo);
    connect(stop_button, &QPushButton::clicked, this, &video_player::stopvideo);
    // connect(timeSlider, &QSlider::sliderMoved, player, &QMediaPlayer::setPosition);

    connect(player, &QMediaPlayer::positionChanged, [=](qint64 position) {
        timeSlider->setValue(position);
        if (d_position < position) {
            d_position = position;
        }
        QString playedTime = QTime(0, 0).addMSecs(position).toString("mm:ss");
        playedTimeLabel->setText(playedTime);
    });

    connect(player, &QMediaPlayer::durationChanged, [=](qint64 duration) {
        timeSlider->setRange(0, duration);
        QString totalDuration = QTime(0, 0).addMSecs(duration).toString("mm:ss");
        durationLabel->setText(totalDuration);
    });

    connect(timeSlider, &QSlider::sliderMoved, [this](int position) {
        player->setPosition(position);
    });

    connect(
        player, &QMediaPlayer::mediaStatusChanged, [](QMediaPlayer::MediaStatus status) {
            if (status == QMediaPlayer::NoMedia || status == QMediaPlayer::InvalidMedia) {
                QString warningMessage = "Stream contains no data.";
                QMessageBox::warning(nullptr, "Warning", warningMessage);
            }
        });

    connect(player,
            &QMediaPlayer::mediaStatusChanged,
            [this](QMediaPlayer::MediaStatus status) {
                if (status == QMediaPlayer::NoMedia ||
                    status == QMediaPlayer::InvalidMedia) {
                    QString warningMessage = "Stream contains no data.";
                    QMessageBox::warning(nullptr, "Warning", warningMessage);
                } else if (status == QMediaPlayer::EndOfMedia && d_downloading) {
                    qint64 currentPosition = player->position();
                    qint64 duration = player->duration();
                    qInfo() << "Current position:" << currentPosition;
                    qInfo() << "Media duration:" << duration;
                    if (currentPosition < duration) {
                        currentPosition = duration;
                    }
                    if (d_position < currentPosition) {
                        d_position = currentPosition;
                    }
                    player->setMedia(QUrl::fromLocalFile(d_videoFile));
                    player->setPosition(d_position);
                    player->play();
                }
            });
}

video_player::~video_player()
{
    // delete ui;
}

// void data_read(QByteArray videoBuffer)
// {
//     // qInfo() << "data_read";
// }

void video_player::playvideo()
{
    player->setMedia(QUrl::fromLocalFile(d_videoFile));
    qInfo() << "pressed";
    player->setPosition(d_position);
    player->play();
}

void video_player::stopvideo()
{
    if (d_position < player->position()) {
        d_position = player->position();
    }
    player->stop();
}
