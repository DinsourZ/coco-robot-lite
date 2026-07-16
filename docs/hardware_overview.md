# Hardware overview

## Conceptual parts

- An ESP32-S3 development board
- A data-capable USB cable
- Optional PCA9685 16-channel PWM board
- Optional small hobby servo
- A current-limited external servo supply suitable for that servo
- Jumper wires and a stable bench surface

## Example assumptions

The sample source uses GPIO 8 for SDA and GPIO 9 for SCL as visible placeholders. Development boards differ, so verify their pinout and edit the example before building. The PCA9685 sample uses the board's common default I2C address and one output channel.

## Power boundary

Do not power a servo from a development board's logic rail. Use an appropriate external servo supply, connect grounds as required by the chosen boards, and confirm polarity before applying power. Keep a physical power disconnect within reach.

## Mechanical boundary

Begin with the servo horn and robot linkages removed. A small bench sweep can still pinch fingers or damage a mechanism when connected to unknown geometry. The sample's limited range is not a substitute for physical limits, supervision, or a risk assessment.
