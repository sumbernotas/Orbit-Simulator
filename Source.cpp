#include <SFML/Graphics.hpp>
#include <math.h>
#include <cmath>
#include <iostream>
#include <time.h>

using namespace std;

double attractionX(int selfPosX, int selfPosY, int otherPosX, int otherPosY, double g, double selfMass, double otherMass);
double attractionY(int selfPosX, int selfPosY, int otherPosX, int otherPosY, double g, double selfMass, double otherMass);



// declares constant variables
const int screenWidth = sf::VideoMode::getDesktopMode().width;
const int screenHeight = sf::VideoMode::getDesktopMode().height;
const double AU = (149.6e6 * 1000);        // 1 astronomical unit converted from kilometers to meters
const double gravityConst = 6.67428e-11;
const double scale = (80 / AU);             // 1 astronomical unit representing an amount of pixels
const int timestep = 3600 * 24;            // represents one full earth day

class Planet {
    private:
        int originX = 0;
        int originY = 0;

        double posX = 0;
        double posY = 0;

    public:
        string name = " ";

        int velX = 0;
        int velY = 0;
        int width = 0;
        int height = 0;

        float radius = 0.0f;

        double mass = 0.0;
        double distanceToSun = 0.0;

        bool isSun = false; 

        void setOriginX(int w) {
            originX = w / 2;
        }

        int getOriginX() {
            return originX;
        }

        void setOriginY(int h) {
            originY = h / 2;
        }

        int getOriginY() {
            return originY;
        }

        void setPosX(double x) {
            posX = x * scale + (screenWidth / 2);
        }

        double getPosX() {
            return posX;
        }

        void setPosY(double y) {
            posY = y * scale + (screenHeight / 2);
        }

        double getPosY() {
            return posY;
        }
};

double attractionX(int selfPosX, int selfPosY, int otherPosX, int otherPosY, double g, double selfMass, double otherMass) {
    int other_x = otherPosX;
    int other_y = otherPosY;
    int distance_x = other_x - selfPosX;
    int distance_y = other_y - selfPosY;
    int distance = sqrt(pow(distance_x, 2) + pow(distance_y, 2));

    double force = g * selfMass * otherMass / pow(distance, 2);
    double theta = atan2(distance_y, distance_x);
    double force_x = cos(theta) * force;

    return force_x;
}

double attractionY(int selfPosX, int selfPosY, int otherPosX, int otherPosY, double g, double selfMass, double otherMass) {
    int other_x = otherPosX;
    int other_y = otherPosY;
    int distance_x = other_x - selfPosX;
    int distance_y = other_y - selfPosY;
    int distance = sqrt(pow(distance_x, 2) + pow(distance_y, 2));

    double force = g * selfMass * otherMass / pow(distance, 2);
    double theta = atan2(distance_y, distance_x);
    double force_y = sin(theta) * force;

    return force_y;
}

int main()
{
    clock_t time;
    time = clock();

    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Orbit Simulator");
    window.setVerticalSyncEnabled(true);
    
    // creates and sets values of members for sun of class Planet
    Planet sun;
    sun.name = "Sun";
    sun.width = 25;
    sun.height = 25;
    sun.setPosX(0);
    sun.setPosY(0);
    sun.radius = 12.5;
    sun.mass = 1.98892 * pow(10, 30);
    sun.isSun = true;

    // creates the shape for the sun
    sf::CircleShape staticSun(sun.width, sun.height);
    sf::Vector2f staticSunPosition(sun.getPosX(), sun.getPosY());
    staticSun.setPosition(staticSunPosition);
    staticSun.setRadius(sun.radius);
    staticSun.setFillColor(sf::Color(255, 255, 0));

    // creates and sets values of members for mercury of class Planet
    Planet mercury;
    mercury.name = "Mercury";
    mercury.width = 15;
    mercury.height = 15;
    mercury.setPosX(0.387 * AU);
    mercury.setPosY(0);
    mercury.radius = 7.5;
    mercury.mass = 3.30 * pow(10, 23);

    // creates the shape for mercury
    sf::CircleShape planetMercury(mercury.width, mercury.height);
    sf::Vector2f planetMercuryPosition(mercury.getPosX(), mercury.getPosY());
    planetMercury.setPosition(planetMercuryPosition);
    planetMercury.setRadius(mercury.radius);
    planetMercury.setFillColor(sf::Color(100, 92, 133));

    // creates and set values of members for venus of class Planet
    Planet venus;
    venus.name = "Venus";
    venus.width = 20;
    venus.height = 20;
    venus.setPosX(0.723 * AU);
    venus.setPosY(0);
    venus.radius = 10;
    venus.mass = 4.8685 * pow(10, 24);

    // creats the shape for venus
    sf::CircleShape planetVenus(venus.width, venus.height);
    sf::Vector2f planetVenusPosition(venus.getPosX(), venus.getPosY());
    planetVenus.setPosition(planetVenusPosition);
    planetVenus.setRadius(venus.radius);
    planetVenus.setFillColor(sf::Color(196, 101, 17));

    // creates and sets values of members for earth of class Planet
    Planet earth;
    earth.name = "Earth";
    earth.width = 30;
    earth.height = 30;
    earth.setPosX(-1 * AU);
    earth.setPosY(0);
    earth.radius = 15;
    earth.mass = 5.9742 * pow(10, 24);

    // creates the shape for earth
    sf::CircleShape planetEarth(earth.width, earth.height);
    sf::Vector2f planetEarthPosition(earth.getPosX(), earth.getPosY());
    planetEarth.setPosition(planetEarthPosition);
    planetEarth.setRadius(earth.radius);
    planetEarth.setFillColor(sf::Color(84, 102, 110));

    // creates and sets values of members for mars of class Planet
    Planet mars;
    mars.name = "Mars";
    mars.width = 20;
    mars.height = 20;
    mars.setPosX(-1.524 * AU);
    mars.setPosY(0);
    mars.radius = 10;
    mars.mass = 6.39 * pow(10, 23);

    // creates the shape for mars
    sf::CircleShape planetMars(mars.width, mars.height);
    sf::Vector2f planetMarsPosition(mars.getPosX(), mars.getPosY());
    planetMars.setPosition(planetMarsPosition);
    planetMars.setRadius(mars.radius);
    planetMars.setFillColor(sf::Color(195, 102, 95));

    // creates and set values of members for jupiter of class Planet
    Planet jupiter;
    jupiter.name = "Jupiter";
    jupiter.width = 50;
    jupiter.height = 50;
    jupiter.setPosX(5.2 * AU);
    jupiter.setPosY(0);
    jupiter.radius = 25;
    jupiter.mass = 1.89813 * pow(10, 27);

    // creates shape for jupiter
    sf::CircleShape planetJupiter(jupiter.width, jupiter.height);
    sf::Vector2f planetJupiterPosition(jupiter.getPosX(), jupiter.getPosY());
    planetJupiter.setPosition(planetJupiterPosition);
    planetJupiter.setRadius(jupiter.radius);
    planetJupiter.setFillColor(sf::Color(162, 151, 143));

    // creates and set values of members for saturn of class Planet
    Planet saturn;
    saturn.name = "Saturn";
    saturn.width = 45;
    saturn.height = 45;
    saturn.setPosX(-9.5 * AU);
    saturn.setPosY(0);
    saturn.radius = 22.5;
    saturn.mass = 5.683 * pow(10, 26);

    // creates shape for saturn
    sf::CircleShape planetSaturn(saturn.width, saturn.height);
    sf::Vector2f planetSaturnPosition(saturn.getPosX(), saturn.getPosY());
    planetSaturn.setPosition(planetSaturnPosition);
    planetSaturn.setRadius(saturn.radius);
    planetSaturn.setFillColor(sf::Color(248, 223, 182));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(staticSun);
        window.draw(planetMercury);
        window.draw(planetVenus);
        window.draw(planetEarth);
        window.draw(planetMars);
        window.draw(planetJupiter);
        window.draw(planetSaturn);
        window.display();
    }

    return 0;
}