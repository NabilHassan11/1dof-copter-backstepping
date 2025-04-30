% MATLAB Script for System Identification of a 1-DOF Copter System

% Load data
filename = 'filtered.csv'; % Ensure this file is saved in the same directory
opts = detectImportOptions(filename);
data = readtable(filename, opts);

% Extract columns
Time = data.Time;
Angle = data.Angle;
PWM_Voltage = data.PWM_Voltage;

% Plot raw data
figure;
subplot(3, 1, 1);
plot(Time, Angle);
title('Angle vs Time');
xlabel('Time (s)');
ylabel('Angle (degrees)');

subplot(3, 1, 2);
plot(Time, PWM_Voltage);
title('PWM Voltage vs Time');
xlabel('Time (s)');
ylabel('PWM Voltage (V)');

% Apply a low-pass filter to smooth the data
fs = 1 / mean(diff(Time)); % Sampling frequency
fc = 0.1 * fs; % Cutoff frequency (10% of Nyquist frequency, adjust as needed)
if fc / (fs / 2) >= 1 || fc / (fs / 2) <= 0
    error('Invalid cutoff frequency. Adjust the fc value.');
end
[b, a] = butter(2, fc / (fs / 2));
Angle_filtered = filtfilt(b, a, Angle);
PWM_Voltage_filtered = filtfilt(b, a, PWM_Voltage);

subplot(3, 1, 3);
plot(Time, Angle_filtered);
title('Filtered Angle vs Time');
xlabel('Time (s)');
ylabel('Angle (degrees)');

% Save filtered data to a new CSV file
filtered_table = table(Time, Angle_filtered, PWM_Voltage_filtered, ...
    'VariableNames', {'Time', 'Angle', 'PWM_Voltage'});
writetable(filtered_table, 'filtered_data_processed.csv');

% Resample data to ensure uniform sampling
uniform_time = linspace(Time(1), Time(end), numel(Time)); 
Angle_resampled = interp1(Time, Angle_filtered, uniform_time, 'linear');
PWM_Voltage_resampled = interp1(Time, PWM_Voltage_filtered, uniform_time, 'linear');

% Create iddata object with resampled data
sys_id_data = iddata(Angle_filtered, PWM_Voltage_filtered, 'SamplingInstants', Time);


% Automated model selection
max_poles = 5; % Maximum number of poles to test
max_zeros = 3; % Maximum number of zeros to test
best_fit = -Inf; % Initialize best fit
best_model = []; % Store the best model

for poles = 1:max_poles
    for zeros = 0:max_zeros
        try
            % Estimate transfer function
            model_order = [poles zeros];
            sys_tf_temp = tfest(sys_id_data, model_order);

            % Validate model
            [~, fit, ~] = compare(sys_id_data, sys_tf_temp);

            % Update best model if fit improves
            if fit > best_fit
                best_fit = fit;
                best_model = sys_tf_temp;
            end
        catch
            % Ignore models that fail to converge
        end
    end
end

% Display the best model
disp('Best Identified Transfer Function:');
disp(best_model);

% Validate the best model
figure;
compare(sys_id_data, best_model);
title('Best Model Validation');
