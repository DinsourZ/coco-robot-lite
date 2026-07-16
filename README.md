# CoCo Robot Lite

> An AI-assisted robotics and IoT learning demo that connects ESP32-S3 hardware concepts with a safe web dashboard for telemetry, device status, and control experiments.

## Project overview

CoCo Robot Lite is a small, presentation-ready learning project for exploring how a browser dashboard can represent a robot's state while an ESP32-S3 demonstrates basic peripheral concepts. The repository is deliberately self-contained: the dashboard uses local fixtures, and the firmware examples are isolated teaching samples.

This is a public educational demo. Production security internals, real device pairing, authentication logic, deployment secrets, real device tokens, full control protocols, and private backend systems are intentionally excluded.

## Inspiration

Robotics projects are easier to learn when hardware, telemetry, interface design, and safety can be examined separately. CoCo Robot Lite turns those boundaries into an approachable demo that can be shown without exposing a real robot or its infrastructure.

## What it does

- Presents simulated robot status, telemetry, and device health in a clean dashboard.
- Labels every interactive control as a non-operational experiment.
- Demonstrates ESP32-S3 I2C discovery and a deliberately limited PCA9685 servo sweep.
- Provides a no-motion firmware placeholder for testing an application's safe default state.

## Architecture

```text
Local fixture data
        |
        v
React + TypeScript dashboard       ESP32-S3 teaching examples
(browser-only demo state)          (local peripheral exercises)

No network bridge exists between the two sides in this public demo.
```

See [docs/architecture_overview.md](docs/architecture_overview.md) and [docs/public_private_boundary.md](docs/public_private_boundary.md) for the design and disclosure boundary.

## Built with

- React, TypeScript, and Vite
- HTML and CSS
- ESP-IDF-style C examples for ESP32-S3
- PCA9685 as an optional learning peripheral

## Hardware concept

The conceptual lab setup uses an ESP32-S3 development board, an optional PCA9685 board, and a small hobby servo powered from a suitable external supply. The web demo does not connect to this hardware. Read [docs/hardware_overview.md](docs/hardware_overview.md) before wiring anything.

## Web demo

The web demo shows robot status cards, fake telemetry, simulated device health, and a safe-control placeholder. A persistent **Demo Mode Only** label makes its scope visible. It contains no networking client and loads its display values from `web-demo/src/sampleTelemetry.ts`.

## Firmware demo

The firmware folder contains three independent educational examples:

1. An ESP32-S3 I2C bus scanner.
2. A limited PCA9685 servo sweep for a supervised bench setup.
3. A safe-motion placeholder that initializes no motor outputs and causes no motion.

These samples are not a robot firmware stack and do not implement remote control, device enrollment, safety-agent internals, or cloud communication.

## Safety notes

- Test with wheels, arms, and linkages removed or physically restrained.
- Use an appropriate external supply for servos and share ground with the controller.
- Keep an accessible physical power disconnect.
- Treat the UI controls as visual prototypes only.
- Review [docs/safety_notes.md](docs/safety_notes.md) before using the firmware examples.

## What is intentionally not included

- Production firmware or complete motion-control behavior
- Real device pairing or identity material
- Authentication or authorization implementation
- Private backend services, databases, or operational telemetry
- Network addresses, deployment configuration, or infrastructure automation
- Production health-agent behavior, emergency-stop chains, or policy engines
- Any material copied from a private Git history

## How to run the web demo

Use a maintained Node.js release, then run:

```bash
cd web-demo
npm install
npm run dev
```

Open the local address printed by Vite. The page remains a local, fixture-driven visualization and does not contact a robot service.

To make a static build:

```bash
npm run build
```

## How to use the firmware examples

Each example folder has its own README with wiring assumptions and guardrails. Create a fresh ESP-IDF project, copy only the selected `main/main.c` into it, select an ESP32-S3 target, review the placeholder GPIO assignments, and build with your normal local ESP-IDF workflow. Do not reuse a production project's configuration.

Start with `safe_motion_placeholder`, continue with the I2C scanner, and use the servo demo only on a supervised, low-energy bench setup.

## Hackathon submission notes

- The web dashboard is the recommended live demo because it is deterministic and hardware-independent.
- Screenshots or recordings should keep the **Demo Mode Only** label visible.
- Describe the firmware as limited educational samples, not a production controller.
- Architecture claims should match the explicit public/private boundary in this repository.
- Add project media under `assets/` only after confirming that it contains no private screens, identifiers, or operational data.

## License

Released under the MIT License. See [LICENSE](LICENSE).
