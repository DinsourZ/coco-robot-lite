export type HealthItem = {
  label: string;
  value: string;
  detail: string;
  level: "good" | "idle";
};

export const sampleTelemetry = {
  deviceId: "demo-coco-001",
  mode: "Demo",
  connection: "Simulated",
  updatedLabel: "Sample frame · T+42s",
  robotStatus: [
    {
      label: "System state",
      value: "Ready",
      detail: "Local demo fixture loaded",
      accent: "mint",
    },
    {
      label: "Motion",
      value: "Stationary",
      detail: "Hardware output disabled",
      accent: "blue",
    },
    {
      label: "Connection",
      value: "Simulated",
      detail: "No robot service attached",
      accent: "amber",
    },
  ],
  metrics: [
    { label: "Battery", value: "82%", progress: 82, hint: "fake charge level" },
    { label: "Board temp", value: "36.4°C", progress: 48, hint: "fake thermal sample" },
    { label: "Signal quality", value: "91%", progress: 91, hint: "simulated link" },
    { label: "Loop rate", value: "20 Hz", progress: 68, hint: "display fixture" },
  ],
  deviceHealth: [
    {
      label: "ESP32-S3 concept board",
      value: "Simulated OK",
      detail: "Learning profile",
      level: "good",
    },
    {
      label: "I2C learning bus",
      value: "Simulated OK",
      detail: "Two fixture peripherals",
      level: "good",
    },
    {
      label: "Motion output",
      value: "Disabled",
      detail: "Safe demo default",
      level: "idle",
    },
  ] satisfies HealthItem[],
};
