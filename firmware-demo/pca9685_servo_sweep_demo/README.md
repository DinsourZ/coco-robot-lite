# PCA9685 limited servo sweep

This supervised bench example configures one PCA9685 channel at 50 Hz and moves a small hobby servo through a narrow sequence. It demonstrates a peripheral concept only; it is not a robot motion controller.

## Placeholder wiring

| ESP32-S3 | PCA9685 |
| --- | --- |
| GPIO 8 | SDA |
| GPIO 9 | SCL |
| GND | GND |

Power the servo rail from a suitable current-limited external supply. Do not power the servo from the controller's logic rail. Verify voltage, polarity, shared ground, and the development board pinout.

## Safe bench sequence

1. Remove the servo horn and every linkage.
2. Keep servo power disconnected while checking wiring.
3. Keep a physical disconnect within reach.
4. Build and monitor the program before applying servo power.
5. Stop immediately at unexpected movement, sound, heat, or odor.

The example performs three narrow sweeps, disables the PWM channel, and then remains idle. Software limits do not establish a safe mechanical range.

## Run

```bash
idf.py set-target esp32s3
idf.py build
idf.py flash monitor
```
