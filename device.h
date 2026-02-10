#ifndef DEVICE_H
#define DEVICE_H

#include <QObject>
#include <QTimer>
#include "telemetry.h"

class Device : public QObject
{
    Q_OBJECT

public:
    explicit Device(QObject *parent = nullptr);

    void start();
    void stop();

signals:
    void telemetryUpdated(const Telemetry& data);
    void faultDetected(const QString& message);

private slots:
    void updateTelemetry();

private:
    Telemetry generateTelemetry();
    void evaluateState(Telemetry& data);

    QTimer m_timer;
};

#endif // DEVICE_H
