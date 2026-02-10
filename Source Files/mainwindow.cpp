#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(&m_device, &Device::telemetryUpdated,
            this, &MainWindow::onTelemetryUpdated);

    connect(&m_device, &Device::faultDetected,
            this, &MainWindow::onFaultDetected);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    ui->logTextEdit->append("Device started");
    m_device.start();
}

void MainWindow::on_stopButton_clicked()
{
    ui->logTextEdit->append("Device stopped");
    m_device.stop();
}

void MainWindow::onTelemetryUpdated(const Telemetry &data)
{
    ui->tempLabel->setText(QString::number(data.temperature, 'f', 1) + " °C");
    ui->voltLabel->setText(QString::number(data.voltage, 'f', 2) + " V");
    ui->rpmLabel->setText(QString::number(data.rpm));

    if (data.systemOk) {
        ui->statusLabel->setText("OK");
        ui->statusLabel->setStyleSheet("color: green;");
    } else {
        ui->statusLabel->setText("FAULT");
        ui->statusLabel->setStyleSheet("color: red;");
    }
}

void MainWindow::onFaultDetected(const QString &message)
{
    QString timestamp = QDateTime::currentDateTime().toString("hh:mm:ss");
    ui->logTextEdit->append("[" + timestamp + "] " + message);
}
