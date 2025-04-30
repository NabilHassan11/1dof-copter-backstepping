% Parameters
R = 0.5;      % Resistance (Ohms)
L = 0.001;    % Inductance (H)
Ke = 0.01;    % Back-EMF constant (V-s/rad)
Kt = 0.01;    % Torque constant (Nm/A)
J = 0.01;     % Rotor inertia (kg-m^2)
B = 0.001;    % Damping coefficient (Nm-s/rad)
TL = 0.1;     % Load torque (Nm)

% State-space matrices
A = [-R/L, -Ke/L;
      Kt/J, -B/J];

B = [1/L;
     0];

D = [0;
     -1/J];

C = [0, 1];   % Output is angular velocity

% Input vector (Voltage and Load Torque)
u = 48;       % Input voltage (V)

% Create state-space system
sys = ss(A, [B, D], C, 0);

% Time vector
t = 0:0.001:1; % 1-second simulation

% Input signals
V = 48 * ones(size(t));  % Constant voltage input
load_torque = TL * ones(size(t)); % Constant load torque

% Combine inputs
inputs = [V; load_torque]';

% Initial conditions [Current; Angular Velocity]
x0 = [0; 0];

% Simulate the system
[y, t_out, x] = lsim(sys, inputs, t, x0);

% Plot results
figure;
subplot(2,1,1);
plot(t_out, x(:,1)); % Current (I)
xlabel('Time (s)');
ylabel('Current (A)');
title('Phase Current');

subplot(2,1,2);
plot(t_out, x(:,2)); % Angular velocity (omega)
xlabel('Time (s)');
ylabel('Angular Velocity (rad/s)');
title('Angular Velocity');
