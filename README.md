# Monitor de Dispositivos Embebidos Qt

Pequeño proyecto en C++/Qt que simula un dispositivo embebido y muestra su telemetría a través de una HMI de escritorio.

## Características

- Generación periódica de telemetría con QTimer
- Sensores simulados: temperatura, voltaje y RPM
- Lógica de detección de fallos
- Gestión asíncrona de eventos con señales y ranuras Qt
- Actualizaciones de la interfaz de usuario en tiempo real mediante widgets Qt
- Registro de eventos con marcas de tiempo

## Arquitectura

- **Dispositivo**

Simula la lógica del firmware embebido. Genera telemetría y detecta estados de fallo.

- **Telemetría**

Estructura de datos simple que representa las mediciones del sistema.

- **Ventana Principal**
Capa HMI. Muestra valores, estado del sistema y registros de eventos.

La capa de interfaz de usuario está completamente desacoplada de la lógica del dispositivo.

## Tecnologías

- C++
- Qt 6 (Widgets)
- CMake
- Señales y ranuras
- QTimer

## Captura de pantalla

<img width="801" height="493" alt="image" src="https://github.com/user-attachments/assets/9e8f795e-b94b-48ad-825d-cbdf8c7e808d" />
