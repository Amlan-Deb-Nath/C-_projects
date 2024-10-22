#include <iostream>
#include <cmath>
#include <cstring>
#include <chrono>
#include <thread>
#include <windows.h>

const int screen_width = 100;
const int screen_height = 32;
const float pi = 3.14159265359f;
const int donut_radius = 10;
const int tube_radius = 4;
const float theta_spacing = 0.07f;
const float phi_spacing = 0.02f;

int main() {
    // Declare the screen buffer
    char buffer[screen_width * screen_height];
    float z_buffer[screen_width * screen_height];
    std::memset(buffer, ' ', screen_width * screen_height); // Clear the screen
    float A = 0, B = 0; // Rotation angles

    while (true) {
        // Initialize buffers
        std::memset(buffer, ' ', screen_width * screen_height);
        std::memset(z_buffer, 0, sizeof(z_buffer));

        for (float theta = 0; theta < 2 * pi; theta += theta_spacing) {
            for (float phi = 0; phi < 2 * pi; phi += phi_spacing) {
                // Calculate coordinates in 3D space
                float cos_A = std::cos(A), sin_A = std::sin(A);
                float cos_B = std::cos(B), sin_B = std::sin(B);
                float cos_theta = std::cos(theta), sin_theta = std::sin(theta);
                float cos_phi = std::cos(phi), sin_phi = std::sin(phi);

                float circle_x = donut_radius + tube_radius * cos_theta;
                float circle_y = tube_radius * sin_theta;

                // Calculate 3D position
                float x = circle_x * (cos_B * cos_phi + sin_A * sin_B * sin_phi) - circle_y * cos_A * sin_B;
                float y = circle_x * (sin_B * cos_phi - sin_A * cos_B * sin_phi) + circle_y * cos_A * cos_B;
                float z = cos_A * circle_x * sin_phi + circle_y * sin_A + 15; // Shift donut out of view
                float ooz = 1 / z; // Depth

                // Calculate projection
                int xp = static_cast<int>(screen_width / 2 + 30 * ooz * x);
                int yp = static_cast<int>(screen_height / 2 - 15 * ooz * y);

                // Calculate luminance
                float L = cos_phi * cos_theta * sin_B - cos_A * cos_theta * sin_phi - sin_A * sin_theta + cos_B * (cos_A * sin_theta - cos_theta * sin_phi);

                // Choose ASCII character for luminance
                if (L > 0) {
                    int idx = xp + screen_width * yp;
                    if (idx >= 0 && idx < screen_width * screen_height) {
                        if (ooz > z_buffer[idx]) {
                            z_buffer[idx] = ooz;
                            buffer[idx] = ".,-~:;=!*#$@"[int(L * 8)];
                        }
                    }
                }
            }
        }

        // Display the frame
        std::cout << "\x1b[H"; // Reset cursor position
        for (int i = 0; i < screen_width * screen_height; i++) {
            std::cout << (i % screen_width ? buffer[i] : '\n');
        }

        // Update rotation angles
        A += 0.04f;
        B += 0.02f;

        // Control frame rate
        Sleep(50);
        
    }

    return 0;
}