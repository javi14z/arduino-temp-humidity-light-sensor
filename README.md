# Arduino: Sensor de Temperatura, Humedad, Luz, Calidad del Aire y Velocidad del Viento

Actividad 1 de la asignatura Equipos e Instrumentación del Máster Universitario en Ingeniería de Telecomunicación de la UNIR.
El proyecto consiste en el desarrollo de una estación de monitoreo ambiental básica utilizando una placa Keyestudio Plus.
Utiliza una pantalla LCD con interfaz I2C para mostrar la temperatura, humedad, nivel de luz ambiental, calidad del aire y velocidad del viento, permitiendo cambiar la información visualizada mediante un botón físico.

---

## 🔧 Componentes

- Arduino keyestudio Plus
- Sensor DHT11 (temperatura y humedad)
- Fotorresistor (LDR)
- Resistencia de 10kΩ (divisor de tensión)
- Pantalla LCD 16x2 con interfaz I2C
- Botón
- 2 potenciómetros
- Protoboard y cables de conexión
- Servomotor

---

## 🛠️ Montaje

### Diagrama de conexiones

| Componente | Pin Arduino |
|------------|-------------|
| DHT11      | D7          |
| LDR        | A3          |
| POT1       | A0          |
| POT2       | A1          |
| Botón      | D4 (con `INPUT_PULLUP`) |
| LCD I2C    | SDA: A4, SCL: A5 |
| Servomotor | A9 |


> ⚠️ El LDR se conecta formando un divisor de tensión con una resistencia de 10kΩ a GND.

### Esquema visual

A continuación, se muestra el diagrama de conexiones de esta práctica:

![Diagrama de conexiones](img/diagram.png)

---

## 📋 Funcionamiento

- Al iniciar, se muestra en pantalla la **temperatura y humedad** medidas por el sensor DHT11.
- Al pulsar el botón, la pantalla muestra el **nivel de luz ambiental**, basado en la lectura analógica del LDR normalizada a una escala de 0 a 100.
- Al pulsar el botón nuevamente, la pantalla muestra la **calidad del aire**, basada en la simulación que logramos con el potenciómetro.
- Al pulsar el botón nuevamente, la pantalla muestra la **velocidad del viento**, basada en la simulación que logramos con el potenciómetro.
- Cada nueva pulsación cambia entre estas pantallas.

Mejoras actividad 2:

- Optimización para evitar parpadeo (solo se actualiza si alguna variable mostrada en la pantalla cambia).
- Relación entre voltaje del LDR y luxes ajustada según las fórmulas vistas en clase. 
- Añadido un servomotor que abre/cierra automáticamente una compuerta según el rango de temperatura (10–25 °C).

---

### Simulación en Wokwi

Haz clic en el siguiente [enlace](https://wokwi.com/projects/430940779169492993) para acceder a la simulación del circuito en la plataforma Wokwi.

   
---

### Demostración en vídeo

Puedes ver una demostración del funcionamiento del circuito físico haciendo clic en este [enlace](demo_video.mp4).

> ⚠️ En la simulación de Wokwi se han utilizado dos potenciómetros para representar los sensores de velocidad del viento y calidad del aire. Debido a la falta de componentes físicos durante el desarrollo, estos sensores no han podido ser implementados en el prototipo real. Los potenciómetros permiten ajustar manualmente los valores de entrada y comprobar el funcionamiento del sistema.
>
>- Potenciómetro 1 (A0): Simula sensor de calidad del aire
>- Potenciómetro 2 (A1): Simula sensor de velocidad del viento

> ⚠️ No se han añadido las mejoras de la actividad 2 en el vídeo, solo en la simulación de Wokwi.

---

## 💾 Código fuente

El código utilizado en esta práctica se encuentra en la carpeta [code](/code/code.ino).  
El archivo `.ino` está comentado para facilitar su comprensión.
