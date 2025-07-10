#include "pch.h"

void setInjectorPins() {
	engineConfiguration->injectionPins[0] = Gpio::B15;
	engineConfiguration->injectionPins[1] = Gpio::B14;
	engineConfiguration->injectionPins[2] = Gpio::B12;
	engineConfiguration->injectionPins[3] = Gpio::B13;
	engineConfiguration->injectionPins[4] = Gpio::A8;
	engineConfiguration->injectionPins[5] = Gpio::E7;
	engineConfiguration->injectionPins[6] = Gpio::E13;
	engineConfiguration->injectionPins[7] = Gpio::E10;
}

void setIgnitionPins() {
	engineConfiguration->ignitionPins[0] = Gpio::E2;
	engineConfiguration->ignitionPins[1] = Gpio::E3;
	engineConfiguration->ignitionPins[2] = Gpio::C13;
	engineConfiguration->ignitionPins[3] = Gpio::E6;
	engineConfiguration->ignitionPins[4] = Gpio::E4;
	engineConfiguration->ignitionPins[5] = Gpio::E5;
	engineConfiguration->ignitionPins[6] = Gpio::E0;
	engineConfiguration->ignitionPins[7] = Gpio::B9;
}

void setEtbConfig() {
	// VNH7070 driver
	// This chip has four control pins:
	// DIR1 - open direction of the motor
	// DIR2 - open direction of the motor
	// PWM - pwm control (enable high, coast low)
	// DIS - disables motor (enable low)

	// Throttle #1
	// PWM pin
	engineConfiguration->etbIo[0].controlPin = Gpio::B11;
	// DIR1 pin
	engineConfiguration->etbIo[0].directionPin1 = Gpio::E15;
	// DIR2 pin
	engineConfiguration->etbIo[0].directionPin2 = Gpio::B10;
	// Disable pin
	engineConfiguration->etbIo[0].disablePin = Gpio::C9;

	// Throttle #2
	// PWM pin
	engineConfiguration->etbIo[1].controlPin = Gpio::Unassigned;
	// DIR1 pin
	engineConfiguration->etbIo[1].directionPin1 = Gpio::Unassigned;
	// DIR2 pin
	engineConfiguration->etbIo[1].directionPin2 = Gpio::Unassigned;
	// Disable pin
	engineConfiguration->etbIo[1].disablePin = Gpio::Unassigned;

	// we only have pwm/dir, no dira/dirb
	engineConfiguration->etb_use_two_wires = false;
}

void setupVbatt() {
	// 910R high side/470R low side = 1.54 ratio divider
	engineConfiguration->analogInputDividerCoefficient = 1.54f;
	
	// 3.9k high side/ 1k low side
	engineConfiguration->vbattDividerCoeff = (7.15 + 1) / 1; 

	// Battery sense on PA4
	engineConfiguration->vbattAdcChannel = EFI_ADC_4;

	engineConfiguration->adcVcc = 3.3f;
}

void setStepperConfig() {
	engineConfiguration->idle.stepperDirectionPin = Gpio::Unassigned;
	engineConfiguration->idle.stepperStepPin = Gpio::Unassigned;
	engineConfiguration->stepperEnablePin = Gpio::Unassigned;
}

Gpio getCommsLedPin() {
	return Gpio::Unassigned;
}

Gpio getRunningLedPin() {
	return Gpio::Unassigned;
}

Gpio getWarningLedPin() {
	return Gpio::Unassigned;
}

void setBoardConfigOverrides() {
	setupVbatt();

	engineConfiguration->clt.config.bias_resistor = 2490;
	engineConfiguration->iat.config.bias_resistor = 2490;

	//CAN 1 bus overwrites
	engineConfiguration->canRxPin = Gpio::D0;
	engineConfiguration->canTxPin = Gpio::D1;

	//CAN 2 bus overwrites
	engineConfiguration->can2RxPin = Gpio::Unassigned;
	engineConfiguration->can2TxPin = Gpio::Unassigned;
}

// board-specific configuration setup
void setBoardDefaultConfiguration(void) {
	setInjectorPins();
	setIgnitionPins();
	setEtbConfig();
	setStepperConfig();

	engineConfiguration->isSdCardEnabled = true;

	engineConfiguration->triggerInputPins[0] = Gpio::D3;
	engineConfiguration->triggerInputPins[1] = Gpio::Unassigned;
	// MAP on PA3
	engineConfiguration->map.sensor.hwChannel = EFI_ADC_3;
	// CLT on PA1
	engineConfiguration->clt.adcChannel = EFI_ADC_1;
	// IAT on PA0
	engineConfiguration->iat.adcChannel = EFI_ADC_0;

	engineConfiguration->spi1mosiPin = Gpio::B5;
	engineConfiguration->spi1misoPin = Gpio::B4;
	engineConfiguration->spi1sckPin = Gpio::B3;
	engineConfiguration->spi2mosiPin = Gpio::Unassigned;
	engineConfiguration->spi2misoPin = Gpio::Unassigned;
	engineConfiguration->spi2sckPin = Gpio::Unassigned;
	engineConfiguration->spi3mosiPin = Gpio::C12;
	engineConfiguration->spi3misoPin = Gpio::C11;
	engineConfiguration->spi3sckPin = Gpio::C10;
	engineConfiguration->is_enabled_spi_1 = true;
	engineConfiguration->is_enabled_spi_2 = false;
	engineConfiguration->is_enabled_spi_3 = true;
}
