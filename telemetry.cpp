#ifndef TELEMETRY_H
#define TELEMETRY_H

struct Telemetry
{
    float temperature;
    float voltage;
    int rpm;
    bool systemOk;
};

#endif // TELEMETRY_H
