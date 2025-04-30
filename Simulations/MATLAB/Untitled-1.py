

import pandas as pd

# Load the provided data file
file_path = 'arduino_data_full.csv'
data = pd.read_csv(file_path)

# Display the first few rows of the dataset to understand its structure
data.head(), data.info()

# Rename the columns for clarity
data.columns = ['Time', 'Angle', 'PWM_Voltage']

# Filter the data to exclude the first 3 seconds
filtered_data = data[data['Time'] >= (data['Time'].min() + 3)]

# Display the first few rows of the filtered dataset to verify
filtered_data.head(), filtered_data.describe()
print(data)

df = pd.DataFrame(data)
df.to_csv("filtered.csv", index=False)