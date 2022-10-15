/**********************************************************************
 * GL Demo
 * Just a simple program to demonstrate how to create an Open GL window,
 * draw something on the window, and accept simple user input
 **********************************************************************/

#include "point.h"
#include "uiInteract.h"
#include "uiDraw.h"
#include "ground.h"
//#include "angle.cpp"
#include "physicsEquations.cpp"
#include "LunarModule.cpp"
#include <list>
using namespace std;
LunarModule ship;     // holds the speed, altitude, and fuel of the ship
list<Point> starsList;
//MathFun math;


/*************************************************************************
 * Demo
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Demo
{
public:
    Demo(const Point& ptUpperRight) :
        angle(0.0),
        ptStar(ptUpperRight.getX() - 20.0, ptUpperRight.getY() - 20.0),
        ptLM(ptUpperRight.getX() / 2.0, 350),
        ground(ptUpperRight)
        
        {

            phase = random(0, 255);
            for (int i = 0; i <= 50; i++)
            {
                starsList.push_back(Point(random(0, 400), random(0, 400)));
            }
        }
    
    // this is just for test purposes.  Don't make member variables public!
    Point ptLM;           // location of the LM on the screen
    Point ptUpperRight;   // size of the screen
    double angle;         // angle the LM is pointing
    unsigned char phase;  // phase of the star's blinking
    Ground ground;
    Point ptStar;
    
    

    /*
    * list<Point> starsList;
    void generateStars() {
        for (int i = 0; i < 50; i++)
        {
            int xPos = random(0, 255);
            int yPos = random(0, 255);
            Point* star = new Point(ptUpperRight.getX() - xPos, ptUpperRight.getY() - yPos);
            starsList.push_back(*star);
        }
    }*/
};

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* pUI, void* p)
{
    ogstream gout;
    //MathFuntions mf;
    //Angle angleObject;
    //LunarModule ship;     // holds the speed, altitude, and fuel of the ship
    // the first step is to cast the void pointer into a game object. This
    // is the first step of every single callback function in OpenGL. 
    Demo* pDemo = (Demo*)p;


 // move the ship around
    if (pUI->isRight() and pDemo->ptLM.getX() < 390.0 and pDemo->ground.hitGround(Point(pDemo->ptLM.getX(), pDemo->ptLM.getY()), 10) == false and ship.getFuel() > 0)
        //pDemo->angle -= 0.1;
        pDemo->ptLM.setX(pDemo->ptLM.getX() + 1.0);
    if (pUI->isLeft() and pDemo->ptLM.getX() > 10.0 and pDemo->ground.hitGround(Point(pDemo->ptLM.getX(), pDemo->ptLM.getY()), 10) == false and ship.getFuel() > 0)
        //pDemo->angle += 0.1;
        pDemo->ptLM.setX(pDemo->ptLM.getX() - 1.0);
    if (pUI->isUp() and pDemo->ground.hitGround(Point(pDemo->ptLM.getX(), pDemo->ptLM.getY()), 10) == false and ship.getFuel() > 0)
        pDemo->ptLM.addY(-2.0);
    if (pUI->isDown() and ship.getFuel() > 0)
        pDemo->ptLM.addY(2.0);

    // move because of gravity
    if (pDemo->ground.hitGround(Point(pDemo->ptLM.getX(), pDemo->ptLM.getY()), 10) == false)
        pDemo->ptLM.setY(pDemo->ptLM.getY() - 1);
    
    // set last acceleration
    if (pUI->isRight() and pDemo->ptLM.getX() < 390.0 and pDemo->ground.hitGround(Point(pDemo->ptLM.getX(), pDemo->ptLM.getY()), 10) == false and ship.getFuel() > 0)
        //pDemo->angle -= 0.1;
        ship.setLastAcceleration(1.0);
    if (pUI->isLeft() and pDemo->ptLM.getX() > 10.0 and pDemo->ground.hitGround(Point(pDemo->ptLM.getX(), pDemo->ptLM.getY()), 10) == false and ship.getFuel() > 0)
        //pDemo->angle += 0.1;
        ship.setLastAcceleration(1.0);
    if (pUI->isUp() and pDemo->ground.hitGround(Point(pDemo->ptLM.getX(), pDemo->ptLM.getY()), 10) == false and ship.getFuel() > 0)
        ship.setLastAcceleration(2.0);
    if (pUI->isDown() and ship.getFuel() > 0)
        ship.setLastAcceleration(2.0);

    // move because of gravity
    if (pDemo->ground.hitGround(Point(pDemo->ptLM.getX(), pDemo->ptLM.getY()), 10) == false)
        ship.setLastAcceleration(1.0);

    if (pUI->isRight() and ship.getFuel() > 0)
        ship.setFuel(ship.getFuel() - 1);
    if (pUI->isLeft() and ship.getFuel() > 0)
        ship.updateFuel(-1);
    if (pUI->isUp() and ship.getFuel() > 0)
        ship.updateFuel(-10);
    if (pUI->isDown() and ship.getFuel() > 0)
        ship.updateFuel(-10);

    
        

    if (pUI->isRight())
        ship.updateSpeed(1);
    if (pUI->isLeft())
        ship.updateSpeed(1);
    if (pUI->isUp())
        ship.updateSpeed(10);
    if (pUI->isDown())
        ship.updateSpeed(10);
    


    // draw our little star
    //gout.drawStar(pDemo->ptStar, pDemo->phase++);

    
    // Draw random stars
    
    for (Point star : starsList) {
        gout.drawStar(star, random(0,255));
    }
    
    // draw the ground
    pDemo->ground.draw(gout);

    // draw the lander and its flames
    gout.drawLander(pDemo->ptLM /*position*/, pDemo->angle /*angle*/);
    gout.drawLanderFlames(pDemo->ptLM, pDemo->angle, /*angle*/
        pUI->isDown(), pUI->isLeft(), pUI->isRight());

    // put some text on the screen
    gout.setPosition(Point(30.0, 30.0));
    gout << "Demo (" << (int)pDemo->ptLM.getX() << ", " << (int)pDemo->ptLM.getY() << ")" << "\n";
    /*********************************
    * Getters for ship Info
    *********************************/

    double altitude;
    altitude = pDemo->ground.getElevation(Point(pDemo->ptLM.getX(), pDemo->ptLM.getY()));
    if (ship.getFuel() < 0)
        ship.setFuel(0);
    if (pDemo->ground.getElevation(Point(pDemo->ptLM.getX(), pDemo->ptLM.getY())) < 0 or pDemo->ground.hitGround(Point(pDemo->ptLM.getX(), pDemo->ptLM.getY()), 10) == true)
        altitude = 0;
    // Display the ship Info
    double fuel = ship.getFuel();
    //double altitude = ship.getAltitude();
    double speed = ship.getVelocity();

    

    gout.setPosition(Point(10.0, 350.0));
    gout << "Fuel :" << fuel << " lbs." << "\n";
    gout << "Altitude :" << altitude << " meters" << "\n";
    gout << "Speed :" << speed << " m/s" << "\n";
    
}


/*********************************
 * Main is pretty sparse.  Just initialize
 * my Demo type and call the display engine.
 * That is all!
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ PWSTR pCmdLine,
    _In_ int nCmdShow)
#else // !_WIN32



int main(int argc, char** argv)
#endif // !_WIN32
{
    // Initialize OpenGL
    Point ptUpperRight(400.0, 400.0);
    Interface ui(0, NULL,
        "Open GL Demo",
        ptUpperRight);

    // Initialize the game class
    Demo demo(ptUpperRight);

    //demo.generateStars();

    // set everything into action
    ui.run(callBack, &demo);

    return 0;
}