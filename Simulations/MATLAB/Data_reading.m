% Define the serial port and baud rate (use the correct COM port)
arduinoPort = 'COM11'; % Replace with your Arduino's COM port
baudRate = 9600;

% Create a serialport object
arduino = serialport(arduinoPort, baudRate);

% Set up the terminator (Arduino sends a newline at the end of each line)
configureTerminator(arduino, "LF");

% Parameters for real-time data collection
numSamples = 1000; % Total number of samples to store (adjust based on your needs)
data = zeros(numSamples, 3); % Preallocate [Time(s), Roll(deg), PWM(V)]
index = 1; % Index for storing data

disp('Reading data from Arduino... Press Ctrl+C to stop.');

% Save continuously during the loop
try
    while true
        line = readline(arduino);
        values = str2double(strsplit(line, ','));
        if numel(values) == 3
            data(index, :) = values;
            fprintf('Time: %.3f s, Roll: %.3f deg, PWM: %.3f V\n', values(1), values(2), values(3));
            index = index + 1;
            if index > numSamples
                index = 1;
            end
            % Save continuously to avoid data loss
            writematrix(values, 'arduino_data.csv', 'WriteMode', 'append');
        end
    end
catch
    disp('Stopped reading data.');
end

% Final save after the loop
writematrix(data, 'arduino_data_full.csv');  % Save the complete array
