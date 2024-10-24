# Hospital Management System

This project is a simple console-based application to manage a hospital's patient queue system, categorized by specializations. It allows adding new patients, printing all patients, and retrieving the next patient in line.

## Features

- **Add New Patient**: Add a patient to a specific specialization with a regular or urgent status.
- **Print All Patients**: Display all patients currently in the queue, categorized by specialization.
- **Get Next Patient**: Retrieve and remove the next patient in line for a specific specialization.

## Usage

### Run the Application

1. Compile the code using a C++ compiler.
2. Run the executable to start the console application.

### Choose an Option

1. Add a new patient by entering the specialization, patient's name, and status (0 for regular, 1 for urgent).
2. Print all patients, displaying each specialization's queue.
3. Get the next patient for a specified specialization.
4. Exit the application.

## Code Structure

- **menu()**: Displays the menu and handles user input for choices.
- **shift_right()**: Shifts patients to the right to accommodate an urgent patient.
- **shift_left()**: Shifts patients to the left after a patient is attended.
- **add_patient()**: Adds a new patient to the queue.
- **print_patient()**: Prints patients of a specific specialization.
- **print_all_patients()**: Prints all patients across all specializations.
- **get_nxt_patient()**: Retrieves the next patient for a specialization.
- **hospital_system()**: Main loop to handle user interaction.
- **main()**: Entry point of the application.

