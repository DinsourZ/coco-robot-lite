# ESP32-S3 I2C scanner

This example probes the normal 7-bit I2C address range and prints any responding addresses to the serial monitor. It is intended for a small, supervised teaching bus.

## Placeholder wiring

| Signal | Example GPIO |
| --- | ---: |
| SDA | 8 |
| SCL | 9 |

Verify the selected development board's pinout and voltage before use. The example enables internal pull-ups for convenience, but a real bus may require appropriate external pull-ups.

## Run

```bash
idf.py set-target esp32s3
idf.py build
idf.py flash monitor
```

Disconnect actuators while scanning. Discovery only shows that a device acknowledged an address; it does not identify or validate that device.
