% Parameters
a_p = 2;          % Plant parameter
a_m = 3; b_m = 2; % Reference model parameters
delta_y = 22;      % Adaptation gain for ay
delta_r = 11;      % Adaptation gain for ar
r = @(t) sin(t);  % Reference input

% Time span
tspan = [0, 10];

% Initial conditions [y, ym, ay_hat, ar_hat]
y0 = [0; 0; 0; 0];

% Differential equations
odefun = @(t, y) [
    -a_p*y(1) + y(3)*y(1) + y(4)*r(t);                  % Plant output y
    -a_m*y(2) + b_m*r(t);                              % Reference model ym
    -delta_y*y(1)*(y(1) - y(2));                       % Adaptive law for ay
    -delta_r*r(t)*(y(1) - y(2))                        % Adaptive law for ar
];

% Solve the ODE
[t, sol] = ode45(odefun, tspan, y0);

% Extract solutions
y = sol(:, 1);    % Plant output
ym = sol(:, 2);   % Reference model output
ay_hat = sol(:, 3); % Adaptive gain ay
ar_hat = sol(:, 4); % Adaptive gain ar

% Plot results
figure;
subplot(3, 1, 1); plot(t, y, t, ym, '--'); legend('y', 'ym'); title('Output Tracking');
subplot(3, 1, 2); plot(t, ay_hat); title('Adaptive Gain \hat{a}_y');
subplot(3, 1, 3); plot(t, ar_hat); title('Adaptive Gain \hat{a}_r');
