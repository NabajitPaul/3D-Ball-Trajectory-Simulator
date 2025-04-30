#include <GL/glut.h>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// Ball parameters
float x = -4.0f, y = 1.5f, z = 0.0f; // Initial position of the ball in 3D space
float vx = 0.12f, vy = 0.32f, vz = 0.0f; // Initial velocities in x, y, z directions
float gravity = -0.02f; // Acceleration due to gravity (negative for downward pull)
float damping = 0.7f; // Energy loss factor on each bounce

// Ground level
const float groundLevel = 0.0f; // Height of the ground (y = 0)

// Timer for frame updates
int delay = 16; // Delay in milliseconds (~60 FPS)

// Store trajectory points
vector<pair<float, float>> trajectoryPoints; // To store the (x, y) coordinates of the ball's trajectory

// Camera variables
float cameraAngle = 1.0f; // Camera rotation angle around the Y-axis (in radians)
float cameraRadius = 18.0f; // Camera radius (distance from the center of the scene)
float cameraHeight = 6.0f; // Camera height on the Y-axis

// Function to draw the ball
void drawBall() {
glPushMatrix(); // Save the current transformation state
glColor3f(1.0f, 0.0f, 0.0f); // Set ball color to red
glTranslatef(x, y, z); // Translate to the ball's position
glutSolidSphere(0.15, 30, 30); // Draw a sphere with radius 0.1
glPopMatrix(); // Restore the previous transformation state
}

// Function to draw the ground
void drawSmoothGround() {
glPushMatrix(); // Save the current transformation state
glColor3f(0.1f, 0.4f, 0.0f); // Set ground color to green

// Draw smooth ground using a grid of quads
float gridSize = 0.5f; // Size of each grid square
glBegin(GL_QUADS); // Begin drawing quads
for (float gx = -4.7f; gx < 4.7f; gx += gridSize) { // Loop through x-coordinates
for (float gz = -1.5f; gz < 1.5f; gz += gridSize) { // Loop through z-coordinates
glVertex3f(gx, groundLevel, gz); // Bottom-left vertex
glVertex3f(gx + gridSize, groundLevel, gz); // Bottom-right vertex
glVertex3f(gx + gridSize, groundLevel, gz + gridSize); // Top-right vertex
glVertex3f(gx, groundLevel, gz + gridSize); // Top-left vertex
}
}
glEnd(); // End drawing quads
glPopMatrix(); // Restore the previous transformation state
}

// Function to draw the trajectory of the ball
void drawTrajectory() {
if (trajectoryPoints.size() < 2) return; // If fewer than 2 points, no trajectory to draw

glColor3f(1.0f, 1.0f, 0.0f); // Set trajectory color to yellow
glLineWidth(3.5f); // Set line width for the trajectory
glBegin(GL_LINE_STRIP); // Begin drawing a continuous line
for (auto& point : trajectoryPoints) { // Loop through each stored point
glVertex3f(point.first, point.second, 0.0f); // Draw point in 3D space
}
glEnd(); // End drawing the line
}

// Function to apply camera rotation around the ball in a 360-degree orbit
void applyCameraRotation() {
// Calculate the camera's position based on an angle around the Y-axis
float cameraX = cameraRadius * cos(cameraAngle); // X position based on angle
float cameraZ = cameraRadius * sin(cameraAngle); // Z position based on angle

// Set the camera to look at the center (the ball's position)
glLoadIdentity(); // Reset the model-view matrix
gluLookAt(cameraX, cameraHeight, cameraZ, // Camera position
x, y, z, // Look-at point (ball's position)
0.0f, 1.0f, 0.0f); // Up direction (Y-axis)
}

// Main display function
void display() {
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the color and depth buffers

applyCameraRotation(); // Apply camera rotation

drawSmoothGround(); // Draw the ground
drawTrajectory(); // Draw the trajectory of the ball
drawBall(); // Draw the ball

glutSwapBuffers(); // Swap buffers to display the rendered frame
}

// Update function called periodically
void update(int value) {

x += vx; // Update x-position using velocity
y += vy; // Update y-position using velocity
z += vz; // Update z-position (not used here)

vy += gravity; // Apply gravity to y-velocity

trajectoryPoints.emplace_back(x, y); // Add the current position to the trajectory

// Check for collision with the ground
if (y <= groundLevel + 0.1f && vx > 0) { // If the ball hits the ground
y = groundLevel + 0.1f; // Adjust position to prevent sinking
vy = -vy * damping; // Reverse and reduce y-velocity due to bounce

if (fabs(vy) < 0.01f) { // If bounce is negligible
vy = 0.0f; // Stop vertical motion
}
}

// Stop the ball after it reaches a certain x-position
if (x >= 5.0f) { // If the ball reaches the batsman
vx = vy = vz = 0.0f; // Stop all motion
}

glutPostRedisplay(); // Request a redraw
glutTimerFunc(delay, update, 0); // Schedule the next update

cameraAngle += 0.005f; // Increment the camera angle for the next frame (continuous rotation)
if (cameraAngle > 2 * M_PI) cameraAngle -= 2 * M_PI; // Keep the angle between 0 and 360 degrees
}

// Keyboard input function for camera control
void keyboard(unsigned char key, int x, int y) {
switch (key) {
case 'w': // Zoom in
cameraRadius -= 0.5f;
if (cameraRadius < 5.0f) cameraRadius = 5.0f; // Limit zoom
break;
case 's': // Zoom out

cameraRadius += 0.5f;
if (cameraRadius > 20.0f) cameraRadius = 20.0f; // Limit zoom
break;
case 'r': // Reset the simulation
x = -4.0f; y = 1.5f; vx = 0.12f; vy = 0.32f;
trajectoryPoints.clear();
break;
default:
break;
}
glutPostRedisplay(); // Redraw after camera movement or reset
}

// Initialization function
void init() {
glClearColor(0.5f, 0.5f, 0.5f, 1.0f); // Set background color to black
glEnable(GL_DEPTH_TEST); // Enable depth testing
glMatrixMode(GL_PROJECTION); // Set matrix mode to projection
glLoadIdentity(); // Reset the projection matrix
gluPerspective(45.0, 1.0, 1.0, 50.0); // Set perspective projection
glMatrixMode(GL_MODELVIEW); // Switch back to model-view matrix
}

// Main function
int main(int argc, char** argv) {
cout << "Enter the x-coordinate where the ball should bounce(e.g.,between 2.0 and 5.0 for better bounce): ";
float bounceX; // Take user input for bounce location
cin >> bounceX;

// Calculate velocity to hit the bounce point
float distanceToBounce = bounceX - x; // Distance from initial x to bounceX
vx = distanceToBounce / 40.0f; // Adjust velocity to reach bounce point

glutInit(&argc, argv); // Initialize GLUT
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Enable double buffering and depth
glutInitWindowSize(800, 600); // Set window size
glutCreateWindow("3D Ball Trajectory with Camera Rotation"); // Create window

init(); // Call initialization function

glutDisplayFunc(display); // Set display callback
glutKeyboardFunc(keyboard); // Register keyboard input callback
glutTimerFunc(delay, update, 0); // Set timer callback

glutMainLoop(); // Enter GLUT event processing loop
return 0; // Return 0 on successful execution
}