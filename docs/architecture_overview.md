# Architecture overview

CoCo Robot Lite contains two deliberately disconnected learning surfaces.

## Browser demo

The React application reads a TypeScript fixture bundled into the page. Components derive cards, meters, and labels from that fixture. There are no fetch calls, socket clients, service-discovery routines, or runtime configuration inputs.

```text
sampleTelemetry.ts -> React components -> browser presentation
```

The control experiment changes presentation state inside the current browser tab only. It cannot reach hardware.

## Firmware examples

Each C file is an independent peripheral exercise rather than a shared robot application. The I2C scanner demonstrates local bus discovery. The PCA9685 example shows a small, bounded bench sweep. The safe-motion placeholder demonstrates a no-output default.

```text
ESP32-S3 -> local I2C bus -> optional teaching peripheral
```

## Deliberate separation

No public-demo component bridges the browser and ESP32-S3. Communication transport, identity, pairing, backend processing, policy enforcement, production safety behavior, and deployment architecture are outside this repository.
