#ifndef TELEMETRY_H
#define TELEMETRY_H

struct Telemetry
{
    double temperature;
    double voltage;
    int rpm;
    bool systemOk;
};

#endif // TELEMETRY_H
