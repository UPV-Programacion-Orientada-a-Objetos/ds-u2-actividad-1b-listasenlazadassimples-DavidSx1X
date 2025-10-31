#ifndef SENSOR_PRESION_H
#define SENSOR_PRESION_H

#include "SensorBase.h"
#include "ListaSensor.h"

/**
 * @class SensorPresion
 * @brief Implementación concreta para un sensor de presión (int).
 */
class SensorPresion : public SensorBase {
private:
    ListaSensor<int> historial; // Lista interna de lecturas

public:
    SensorPresion(const char* n);
    virtual ~SensorPresion();

    // Implementación de la interfaz virtual
    virtual void procesarLectura() override;
    virtual void imprimirInfo() const override;
    virtual void agregarLectura(const char* valor) override;
};

#endif // SENSOR_PRESION_H