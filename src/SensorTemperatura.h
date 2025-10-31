#ifndef SENSOR_TEMPERATURA_H
#define SENSOR_TEMPERATURA_H

#include "SensorBase.h"
#include "ListaSensor.h" // Contiene su propia lista genérica

/**
 * @class SensorTemperatura
 * @brief Implementación concreta para un sensor de temperatura (float).
 */
class SensorTemperatura : public SensorBase {
private:
    ListaSensor<float> historial; // Lista interna de lecturas

public:
    SensorTemperatura(const char* n);
    virtual ~SensorTemperatura();

    // Implementación de la interfaz virtual
    virtual void procesarLectura() override;
    virtual void imprimirInfo() const override;
    virtual void agregarLectura(const char* valor) override;
};

#endif // SENSOR_TEMPERATURA_H