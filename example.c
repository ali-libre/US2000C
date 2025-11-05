#define SHTDN_CMD						"shut\n"
#define POWER_CMD						"pwr\n"
#define SOHLT_CMD   				    "soh\n"

main(){

    HAL_UART_Transmit_DMA(&huart4,(uint8_t*)CMD , sizeof(POWER_CMD));
    HAL_UART_Receive_DMA(&huart4, (uint8_t*)POWER, 2493);
    BATTERY_VOLTAGE = parse_power_field(POWER, 174, 5);
    BATTERY_CURRENT = parse_power_field(POWER, 181, 5);
    BATTERY_TEMPRATURE = parse_power_field(POWER, 188, 5);
    Battery_Precent = parse_power_field_int(POWER, 259, 2);

    memcpy(CMD, (char*)SOHLT_CMD, sizeof(SOHLT_CMD));
    HAL_UART_Transmit_DMA(&huart4,(uint8_t*)CMD , sizeof(SOHLT_CMD));
    HAL_UART_Receive_DMA(&huart4, (uint8_t*)SOH, 801);


    memcpy(CMD, (char*)SHTDN_CMD, sizeof(SHTDN_CMD));
    HAL_UART_Transmit_DMA(&huart4,(uint8_t*)CMD , sizeof(SHTDN_CMD));
}

static float parse_power_field(const char *power, int start, int lenght)
{
    char tmp[6] = {0};
    for (int k = 0; k < lenght; ++k) {
        tmp[k] = power[start + k];
    }
    return ((float)atoi(tmp)) / 1000.0f;
}
static int parse_power_field_int(const char *power, int start, int lenght)
{
    char tmp[6] = {0};
    for (int k = 0; k < lenght; ++k) {
        tmp[k] = power[start + k];
    }
    return ((float)atoi(tmp));
}
