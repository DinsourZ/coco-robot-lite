# Safe-motion placeholder

This example illustrates the default state for a motion-oriented learning project: no actuator driver is initialized, no motion GPIO is configured, and the application remains idle while printing a periodic demo message.

It is not an emergency-stop system, watchdog, health agent, or production safety implementation. Its only purpose is to make the public demo's no-motion starting point explicit.

## Run

Keep actuators unpowered, then use a normal ESP-IDF workflow:

```bash
idf.py set-target esp32s3
idf.py build
idf.py flash monitor
```
