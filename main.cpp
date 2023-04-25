#include "ComplexPlane.h"
#include <iostream>

// Create an enum class 
enum class State {
    CALCULATING,
    DISPLAYING
};

int main() {
    // Get the desktop resolution
    const unsigned int width = VideoMode::getDesktopMode().width;
    const unsigned int height = VideoMode::getDesktopMode().height;


    // Calculate the aspect ratio of the monitor
    float aspectRatio = static_cast<float>(height) / static_cast<float>(width);

    // Construct the window
    RenderWindow window(VideoMode(width, height), "Mandelbrot Set", Style::Fullscreen);


    // Construct an object of type ComplexPlane
//	ComplexPlane plane(16.0f / 9.0f);
    ComplexPlane plane(aspectRatio);

    // Create a Font Object
    Font font;
    if (!font.loadFromFile("Orbitron.ttf")) {
        cout << "Font failed to load" << endl;
    }

    // Create a Text Object
    Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(Color::White);
    text.setPosition(10, 10);

    // Construct Vertex Array
    VertexArray vertexArray(Points, width * height);

    // Initialize to CALCULATING
    State state = State::CALCULATING;

    // ****Begin main Loop****
    while (window.isOpen()) {
        // Handle Input Segment
        Event event;
        while (window.pollEvent(event)) {
            // Handle event to close the window
            // Check if Escape key is pressed
            if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape)) {
                window.close();
            }

            // Handle event when mouse button is pressed
            if (event.type == Event::MouseButtonPressed) {
                // Use mapPixelToCoords to find the Vector2f coord in ComplexPlane
                // View that corresponds to the mouse click
                Vector2f worldPos = window.mapPixelToCoords(Mouse::getPosition(window), plane.getView());

                if (event.mouseButton.button == Mouse::Right) {
                    // Right click will zoomOut and setCenter of the ComplexPlane object
//                    plane.setMouseLocation(worldPos);
                    plane.setCenter(worldPos);
                    plane.zoomOut();
                    state = State::CALCULATING;
                } else if (event.mouseButton.button == Mouse::Left) {
                    // Left click will zoomIn and setCenter of the ComplexPlane object
//                    plane.setMouseLocation(worldPos);
                    plane.setCenter(worldPos);
                    plane.zoomIn();
                    state = State::CALCULATING;
                }
            }

            // Handel event when mouse is moved
            if (event.type == Event::MouseMoved) {
                // mapPixelToCoords can find the Vector2f coordinates in the ComplexPlane view
                // that corresponds to the mouse location
                Vector2f worldPos = window.mapPixelToCoords(Mouse::getPosition(window), plane.getView());

                // setMouseLocation to store the coordinate
                plane.setMouseLocation(worldPos);
            }
        }

        // ****Update Scene Segment****
        if (state == State::CALCULATING) {
            int pixelWidth = static_cast<int>(width);
            int pixelHeight = static_cast<int>(height);


            for (int i = 0; i < pixelHeight; i++) {
                for (int j = 0; j < pixelWidth; j++) {

                    // Set the position of the vertex to the pixel coordinates
                    vertexArray[j + i * pixelWidth].position = {(float) j, (float) i};

                    // Map the pixel coordinated to the corresponding coordinates in the complex plane
                    Vector2f coords = window.mapPixelToCoords({j, i}, plane.getView());

                    // Get the number of iterations for the current complex coordinate
                    int numIterations = plane.countIterations(coords);

                    // Get the RGB color for the number of iterations
                    Uint8 r, g, b;
                    plane.iterationsToRGB(numIterations, r, g, b);

                    // set the color of the vertex to the RGB color
                    vertexArray[j + i * pixelWidth].color = {r, g, b};
                }
            }

            // set the state to DISPLAYING
            state = State::DISPLAYING;
        }

        // Update the text on the screen
        plane.loadText(text);
        // ****Draw Scene Segment****
        window.clear();
        window.draw(vertexArray);
        window.draw(text);
        window.display();
    }

    return 0;
}
