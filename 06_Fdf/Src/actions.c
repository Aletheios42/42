#include "../Inc/automaton.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

// Global variables for demonstration purposes (modify as needed)
int current_height = 0;      // Changed from current_value to current_height
int current_color = 0;       // Changed from current_hex_color to current_color

// Function to handle height
void handle_height(void) {
  printf("Handling height...\n");
  char input[] = "123"; // Example input, should come from a real source
  current_height = atoi(input); // Convert input string to an integer
  printf("Parsed height: %d\n", current_height);
}

// Function to handle color
void handle_color(void) {
  printf("Handling color...\n");
  char input[] = "0xFF5733"; // Example hex input, should come from a real source
  sscanf(input, "%x", &current_color); // Convert input string to hexadecimal
  printf("Parsed color: #%06X\n", current_color); // Print the color
}

// Function to handle space
void handle_space(void) {
  printf("Handling space...\n");
  // Logic to handle spaces
}

// Function to handle newline
void handle_newline(void) {
  printf("Handling newline...\n");
  // Logic to handle newline
}

// Function to handle end of file
void handle_eof(void) {
  printf("Handling end of file...\n");
  // Logic to handle EOF
}

// Function to handle errors
void handle_error(void) {
  printf("Handling error...\n");
  // Logic to handle errors
}

// Function to handle comma
void handle_comma(void) {
  printf("Handling comma...\n");
  // Logic to handle commas
}

