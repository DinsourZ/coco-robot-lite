import { useState } from "react";
import { sampleTelemetry } from "./sampleTelemetry";

function SignalMark() {
  return (
    <span className="signal-mark" aria-hidden="true">
      <i />
      <i />
      <i />
    </span>
  );
}

function App() {
  const [experimentMessage, setExperimentMessage] = useState(
    "Waiting for a local UI experiment.",
  );

  const runPlaceholder = () => {
    setExperimentMessage(
      "Visual check complete — no command was sent and no hardware was contacted.",
    );
  };

  return (
    <div className="page-shell">
      <header className="topbar">
        <a className="brand" href="#top" aria-label="CoCo Robot Lite home">
          <span className="brand-mark" aria-hidden="true">
            C
          </span>
          <span>
            <strong>CoCo Robot Lite</strong>
            <small>Robotics learning dashboard</small>
          </span>
        </a>

        <div className="demo-pill">
          <span className="pulse-dot" aria-hidden="true" />
          Demo Mode Only
        </div>
      </header>

      <main id="top">
        <section className="hero">
          <div className="eyebrow">ESP32-S3 · ROBOTICS · SAFE SIMULATION</div>
          <div className="hero-grid">
            <div>
              <h1>A friendly window into robot telemetry.</h1>
              <p>
                Explore device state, health, and interface ideas with a polished
                dashboard powered entirely by bundled sample data.
              </p>
            </div>
            <div className="hero-note">
              <SignalMark />
              <div>
                <span>Presentation state</span>
                <strong>{sampleTelemetry.connection} · No hardware link</strong>
              </div>
            </div>
          </div>
        </section>

        <section aria-labelledby="status-title">
          <div className="section-heading">
            <div>
              <span className="section-kicker">Robot overview</span>
              <h2 id="status-title">Status at a glance</h2>
            </div>
            <span className="sample-time">{sampleTelemetry.updatedLabel}</span>
          </div>

          <div className="status-grid">
            {sampleTelemetry.robotStatus.map((item) => (
              <article className="status-card" key={item.label}>
                <div className={`status-icon ${item.accent}`} aria-hidden="true">
                  <span />
                </div>
                <div>
                  <p>{item.label}</p>
                  <h3>{item.value}</h3>
                  <span>{item.detail}</span>
                </div>
              </article>
            ))}
          </div>
        </section>

        <div className="dashboard-grid">
          <section className="panel telemetry-panel" aria-labelledby="telemetry-title">
            <div className="panel-heading">
              <div>
                <span className="section-kicker">Fake telemetry</span>
                <h2 id="telemetry-title">Sample signals</h2>
              </div>
              <span className="fixture-label">Bundled fixture</span>
            </div>

            <div className="metric-list">
              {sampleTelemetry.metrics.map((metric) => (
                <div className="metric" key={metric.label}>
                  <div className="metric-copy">
                    <div>
                      <span>{metric.label}</span>
                      <small>{metric.hint}</small>
                    </div>
                    <strong>{metric.value}</strong>
                  </div>
                  <div className="meter" aria-hidden="true">
                    <span style={{ width: `${metric.progress}%` }} />
                  </div>
                </div>
              ))}
            </div>
          </section>

          <section className="panel" aria-labelledby="health-title">
            <div className="panel-heading">
              <div>
                <span className="section-kicker">Device health</span>
                <h2 id="health-title">Learning setup</h2>
              </div>
            </div>

            <div className="health-list">
              {sampleTelemetry.deviceHealth.map((item) => (
                <div className="health-row" key={item.label}>
                  <span className={`health-dot ${item.level}`} aria-hidden="true" />
                  <div>
                    <strong>{item.label}</strong>
                    <span>{item.detail}</span>
                  </div>
                  <em>{item.value}</em>
                </div>
              ))}
            </div>
          </section>
        </div>

        <section className="experiment" aria-labelledby="experiment-title">
          <div className="experiment-copy">
            <span className="section-kicker">Safe control experiment</span>
            <h2 id="experiment-title">Try the interface, not the robot.</h2>
            <p>
              This button only changes the message in this browser tab. The public
              demo contains no transport or remote-control integration.
            </p>
            <div className="experiment-result" aria-live="polite">
              <span aria-hidden="true">✓</span>
              {experimentMessage}
            </div>
          </div>

          <button type="button" onClick={runPlaceholder}>
            Run visual posture check
            <span aria-hidden="true">→</span>
          </button>
        </section>

        <section className="boundary-note">
          <span aria-hidden="true">i</span>
          <p>
            <strong>Educational boundary:</strong> device identity, production
            safety behavior, remote commands, and private services are outside
            this public demo.
          </p>
        </section>
      </main>

      <footer>
        <span>CoCo Robot Lite · Public educational demo</span>
        <span>{sampleTelemetry.deviceId} · {sampleTelemetry.mode} mode</span>
      </footer>
    </div>
  );
}

export default App;
