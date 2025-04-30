clear;
clc;


% Define symbolic variables
syms theta theta_dot F m_motor r_propeller J_motor m_rod l_rod J_rod J_total g c real

% Define parameters and equations
J_motor = (1/2) * m_motor * r_propeller^2; % Motor's moment of inertia
J_rod = m_rod * l_rod^2;                  % Rod's moment of inertia
J_total = J_motor + J_rod;                % Total inertia

% Define state variables
x1 = theta;         % State 1: angular position (theta)
x2 = theta_dot;     % State 2: angular velocity (theta_dot)

% Nonlinear state-space equations
dx1_dt = x2; % dx1/dt = x2
dx2_dt = (l_rod * F - l_rod * (m_rod + m_motor) * g * sin(x1)) / sym('J_total'); % dx2/dt

% Display equations
disp('Nonlinear state-space equations:');
fprintf('dx1/dt = x2\n');
fprintf('dx2/dt = (l_rod * F - l_rod * (m_rod + m_motor) * g * sin(x1)) / J_total\n');

% Create symbolic vector for states
state_vector = [x1; x2];
state_dot_vector = [dx1_dt; dx2_dt];

% Display state-space representation in matrix form
disp('State-space representation:');
disp('dx/dt = f(x, u)');
disp('f(x, u):');
disp(state_dot_vector);
