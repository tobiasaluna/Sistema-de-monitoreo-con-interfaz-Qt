#include "device.h"
#include <QRandomGenerator>

Device::Device(QObject *parent)
    : QObject(parent)
{
    connect(&m_timer, &QTimer::timeout,
            this, &Device::updateTelemetry);
}

void Device::start()
{
    m_timer.start(1000); // 1 segundo
}

void Device::stop()
{
    m_timer.stop();
}

void Device::updateTelemetry()
{
    Telemetry data = generateTelemetry();
    evaluateState(data);

    emit telemetryUpdated(data);

    if (!data.systemOk) {
        emit faultDetected("Device entered FAULT state");
    }
}

Telemetry Device::generateTelemetry()
{
    Telemetry t;

    auto rng = QRandomGenerator::global();

    t.temperature = 20.0 + rng->generateDouble() * (90.0 - 20.0);
    t.voltage     = 3.0  + rng->generateDouble() * (4.2  - 3.0);
    t.rpm         = rng->bounded(1000, 5000);

    t.systemOk = (t.temperature < 80.0 && t.voltage > 3.3);

    return t;
}



void Device::evaluateState(Telemetry &data)
{
    data.systemOk = (data.temperature < 80.0f && data.voltage > 3.2f);
}
