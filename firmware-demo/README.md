# Firmware demos

These independent ESP32-S3 examples are small, public teaching exercises. They are not production robot firmware and have no browser, cloud, enrollment, remote-command, health-agent, or deployment integration.

## Recommended order

1. `safe_motion_placeholder` — confirm a no-output starting point.
2. `esp32s3_i2c_scanner` — inspect a supervised local I2C lab bus.
3. `pca9685_servo_sweep_demo` — optionally move one disconnected hobby servo through a deliberately narrow range.

## Build model

Each directory is a standalone minimal ESP-IDF project. With a maintained ESP-IDF environment available:

```bash
cd firmware-demo/safe_motion_placeholder
idf.py set-target esp32s3
idf.py build
idf.py flash monitor
```

Review the source and board pinout before building. Build artifacts and local configuration are ignored and must remain uncommitted.

## Safety boundary

Use a current-limited bench setup, remove mechanical loads, check polarity, and keep a physical power disconnect accessible. The examples contain neither a safety-rated stop mechanism nor complete fault handling. Do not incorporate them into a production or unattended robot.
