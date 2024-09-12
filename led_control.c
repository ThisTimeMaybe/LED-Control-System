#include <stdio.h>
#include <stdint.h>

// Structure to hold individual LED settings
typedef struct {
    uint8_t state;       // ON (1) / OFF (0)
    uint8_t brightness;  // Brightness level from 0 to 255
    uint32_t color;      // RGB color value
} LEDSettings;

// Structure to hold a group of LEDs and group-level settings
typedef struct {
    LEDSettings singleLED;   // Individual LED settings
    uint8_t groupState;      // Group ON (1) / OFF (0)
    uint8_t groupBrightness; // Group brightness adjustment
} LEDGroup;

// Function to initialize the LED group with default values
void initLEDGroup(LEDGroup *group) {
    group->singleLED.state = 0;  // Turn off the LED
    group->singleLED.brightness = 0;  // Set brightness to minimum (0)
    group->singleLED.color = 0x000000;  // Default color (black)

    group->groupState = 0;  // Group state OFF
    group->groupBrightness = 0;  // Group brightness set to 0
}

// Function to update both individual LED settings and group settings
void updateLEDGroupSettings(LEDGroup *group, uint8_t groupState, uint8_t groupBrightness, 
                            uint8_t state, uint8_t brightness, uint32_t color) {
    group->groupState = groupState;
    group->groupBrightness = groupBrightness;

    group->singleLED.state = state;
    group->singleLED.brightness = brightness;
    group->singleLED.color = color;
}

// Function to display the current LED group and individual LED status
void displayLEDGroupStatus(const LEDGroup *group) {
    // Display individual LED settings
    printf("Individual LED State: %s\n", group->singleLED.state ? "ON" : "OFF");
    printf("Individual LED Brightness: %d\n", group->singleLED.brightness);
    printf("Individual LED Color (RGB): #%06X\n", group->singleLED.color);

    // Display group settings
    printf("Group LED State: %s\n", group->groupState ? "ON" : "OFF");
    printf("Group LED Brightness: %d\n", group->groupBrightness);
}

int main() {
    LEDGroup ledGroup;

    // Initialize the LED group
    initLEDGroup(&ledGroup);

    // Display the default status
    printf("Initial LED Group Status:\n");
    displayLEDGroupStatus(&ledGroup);
    
    // Update the LED group settings
    updateLEDGroupSettings(&ledGroup, 1, 128, 1, 200, 0xFF5733);

    // Display the updated status
    printf("\nUpdated LED Group Status:\n");
    displayLEDGroupStatus(&ledGroup);

    return 0;
}
