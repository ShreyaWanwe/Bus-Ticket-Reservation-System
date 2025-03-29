# Bus Ticket Reservation System 

The **Bus Ticket Reservation System** is a comprehensive C language project aimed at automating the process of booking and managing bus tickets. This project provides an efficient and user-friendly interface for passengers to view available buses, book seats, check booking status, and cancel reservations.

## Key Features

### 1️⃣ Bus List Display  
- Users can view a list of available buses with their names and corresponding numbers, making it easy to choose a bus for their journey.

### 2️⃣ Ticket Booking  
- Allows users to book tickets by entering the desired bus number and the number of seats they want to reserve.  
- Captures the passenger names and assigns them specific seat numbers.

### 3️⃣ Booking Status Check  
- Users can check the status of a particular bus to see which seats are booked and which are still available.

### 4️⃣ Cancellation  
- Provides an option to cancel a booking, releasing the reserved seats back to the pool of available seats and refunding the booking amount.

### 5️⃣ User Authentication  
- Implements a basic login system to ensure that only authorized users can access the reservation system.  
- Includes user registration and password reset functionality.


## Concepts Used  

This project uses various key concepts in C programming:

###  1. File Handling  
- **Reading from Files:** Reads seat availability and passenger details.  
- **Writing to Files:** Updates reservation details and cancellations.  
- Functions used: `fopen()`, `fgets()`, `fputs()`, `fclose()`.

###  2. Arrays  
- **Character Arrays:** Stores bus names and passenger names.  
- **Integer Arrays:** Stores seat numbers and other numeric data.

###  3. Control Structures  
- **Loops:** `do-while`, `while`, and `for` loops for menu display, data entry, and reading information.  
- **Conditional Statements:** `if`, `else if`, and `switch` statements for handling user choices.

###  4. Strings  
- **Concatenation:** Uses `strcat()` to create messages.  
- **Comparison:** Uses `strcmp()` for authentication.  

###  5. Functions  
- **Modular Programming:** Functions such as `bus()`, `booking()`, `cancel()`, `status()`, and `login()` are used to improve readability and maintainability.  


## Added Features  

✅ **Ticket Generation**:  
- A `generate_ticket()` function was added to automatically generate and print a ticket after booking.

✅ **Enhanced UI**:  
- **Window and Aisle Labelling:** Seats are labeled to distinguish window and aisle seats.  
- **Front and Back Indication:** The bus seating arrangement includes directional indicators.


##  Installation & Usage  

### 1. Compile the Program  
Use any C compiler such as GCC (MinGW for Windows) to compile the program:  
```sh
gcc bus_reservation.c -o bus_reservation
```
### 2. Run the Program
```sh
./bus_reservation
```
### 3. Follow the Menu
Select an option from the menu to view buses, book tickets, check status, cancel a booking, or exit.

## Future Enhancements
⭐ Graphical Interface using GTK or a web-based system.</br>
⭐ Database Integration to replace file handling.</br>
⭐ Online Booking Portal for real-world application.
