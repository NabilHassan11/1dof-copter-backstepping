clear;
clc;

% Motor Parameters
param.m_motor = 52e-3;                % Mass of motor [kg]
param.r_propeller = 0.15;             % Propeller radius [m]
param.Jm = (1/2) * param.m_motor * param.r_propeller^2; % Motor's moment of inertia
Voltage = 0;

% % Control Gains
% k1 = 2;
% k2 = 2;
% k3 = 2;
% k4 = 2;

% Electrical Parameters
param.R = 0.09;          % Resistance (Ohms)
param.L = 50e-6;         % Inductance (H)
param.Ke = 0.00434;      % Back-EMF constant (V-s/rad)
param.Kt = 0.00434;      % Torque constant (Nm/A)
param.B = 0.001;         % Damping coefficient (Nm-s/rad)

% System Parameters
param.m_rod = 0.198;                   % Mass of the rod [kg]
param.l = 0.3;                         % Length of the rod [m]
param.J_rod = param.m_rod * param.l^2; % Rod's moment of inertia
param.m = param.m_rod + param.m_motor; % Total mass
param.J = param.J_rod + param.Jm;      % Total inertia
param.g = 9.81;                        % Gravitational acceleration [m/s^2]

% Thrust Force Parameters
param.C_t = 1.732;       % Thrust coefficient
param.P = 1.225;         % Air density (kg/m^3)
param.r = 0.15;          % Radius of Propeller (m)
param.pitch = 0.1143;    % Pitch of Propeller (m)

% Air Speed Proportionality Constant
param.K = param.pitch / (2 * pi);  % Proportionality constant dependent on the propeller

% Thrust Force (T) Relation to Rotor Speed (w)
% T = 1/2 * Ct * pi * P * r^2 * v^2 where v = K * w
param.K_telda = 0.1;

% Define nonlinear state-space dynamics
nonlinear_dynamics = @(t, x, w) [
    x(2);
    (param.l * (0.5 * param.C_t * pi * param.P * param.r^2 * param.K^2 * w^2) ...
     - param.l * (0.5 * param.m_rod + param.m_motor) * param.g * sin(x(1))) / param.J
];

% Time vector
tspan = [0 10];

% Initial conditions
x0 = [pi/2;pi/2;pi/2;0];  % Starting at a small angle with zero angular velocity

% Input rotor speed (w), defined as a function of time
w_func = @(t) 0;  % Example: constant rotor speed input over time (rad/s)

% Simulate using ODE solver
[t, x] = ode45(@(t, x) nonlinear_dynamics(t, x, w_func(t)), tspan, x0);

% Plot results
figure;
subplot(2, 1, 1);
plot(t, x(:, 1), 'LineWidth', 1.5);
ylabel('\theta (rad)');
title('Rod Angular Position');
grid on;

subplot(2, 1, 2);
plot(t, x(:, 2), 'LineWidth', 1.5);
ylabel('\dot{\theta} (rad/s)');
xlabel('Time (s)');
title('Rod Angular Velocity');
grid on;
