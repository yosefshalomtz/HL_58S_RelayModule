#pragma once
/**
 * @brief Implementation of the HL-58S 8-Channel Relay Module class for the ESP32.
 * Tested on ESP-IDF version 5.4.
 *
 * This code assumes a physical connection map as follows:
 * ESP32 Pin   -> Relay Module Pin
 * VIN (5V)    -> JD-VCC
 * GND         -> GND
 * 3V3         -> VCC
 * GPIO23      -> IN1
 * GPIO22      -> IN2
 * GPIO21      -> IN3
 * GPIO19      -> IN4
 * GPIO18      -> IN5
 * GPIO17      -> IN6
 * GPIO16      -> IN7
 * GPIO4       -> IN8
 *
 * Important: Before using the relay, ensure that VCC is not connected
 * to JD-VCC by default. If a jumper is present, carefully remove it.
 *
 * Usage:
 *   - Call `getInstance()` to obtain the singleton instance.
 *   - Use `on()`, `off()`, and `status()` to control individual channels.
 *
 * Found a bug or have a suggestion? Contact me: yosefshalomtz@gmail.com
 * Author: Yosef Shalom Tzuberi
 * License: MIT
 * Have fun!
 */

#include "driver/gpio.h"

class HL_58S_RelayModule8Channel
{
private:
    static constexpr int gpio_outputs[] = {23, 22, 21, 19, 18, 17, 16, 4};
    HL_58S_RelayModule8Channel();

public:
    static HL_58S_RelayModule8Channel &getInstance();
    HL_58S_RelayModule8Channel(const HL_58S_RelayModule8Channel &) = delete;
    HL_58S_RelayModule8Channel &operator=(const HL_58S_RelayModule8Channel &) = delete;

    // operations:
    void on(int channel);

    void off(int channel);

    bool status(int channel);

    void allOn();

    void allOff();
};