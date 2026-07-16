# Safety notes

This repository is a learning aid, not a certified control or safety system.

## Before powering hardware

- Disconnect wheels, arms, and other moving mechanisms.
- Inspect wiring, polarity, current limits, and shared-ground requirements.
- Place the device on a clear, stable, non-conductive surface.
- Ensure a physical power disconnect is immediately reachable.
- Keep people, pets, and loose objects away from moving parts.

## While testing

- Run one example at a time.
- Begin with the no-motion placeholder.
- Observe I2C discovery before attaching an actuator.
- Supervise all powered motion and stop at unexpected sound, heat, odor, or movement.

## Important limitations

The browser controls do not command hardware. The servo range in the sample is only a software teaching limit and does not establish a safe mechanical envelope. No production emergency-stop, watchdog, health policy, remote command, or failover implementation is included.
