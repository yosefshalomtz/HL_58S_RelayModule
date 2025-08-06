#include "HL_58S_RelayModule8Channel.hpp"

HL_58S_RelayModule8Channel::HL_58S_RelayModule8Channel()
{
    // initialization:
    gpio_config_t io_conf = {};
    io_conf.pin_bit_mask = (1ULL << GPIO_NUM_0);
    io_conf.mode = GPIO_MODE_OUTPUT;
    io_conf.pull_up_en = GPIO_PULLUP_DISABLE;
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    io_conf.intr_type = GPIO_INTR_DISABLE;

    for (int index = 0; index < 8; index++)
    {
        io_conf.pin_bit_mask = (1ULL << gpio_outputs[index]);
        gpio_config(&io_conf);
        gpio_set_level(static_cast<gpio_num_t>(gpio_outputs[index]), 1);
    }
}

HL_58S_RelayModule8Channel &HL_58S_RelayModule8Channel::getInstance()
{
    static HL_58S_RelayModule8Channel instance;
    return instance;
}

// operations:
void HL_58S_RelayModule8Channel::on(int channel)
{
    if (channel < 1 || channel > 8)
        return;
    gpio_set_level(static_cast<gpio_num_t>(gpio_outputs[channel - 1]), 0);
}

void HL_58S_RelayModule8Channel::off(int channel)
{
    if (channel < 1 || channel > 8)
        return;
    gpio_set_level(static_cast<gpio_num_t>(gpio_outputs[channel - 1]), 1);
}

bool HL_58S_RelayModule8Channel::status(int channel)
{
    if (channel < 1 || channel > 8)
        return false;
    return gpio_get_level(static_cast<gpio_num_t>(gpio_outputs[channel - 1])) == 0;
}

void HL_58S_RelayModule8Channel::allOn()
{
    for (int i = 1; i < 9; i++)
        on(i);
}

void HL_58S_RelayModule8Channel::allOff()
{
    for (int i = 1; i < 9; i++)
        off(i);
}
