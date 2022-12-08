/*************************************************************
 * 1. Name:
 *      Jacob Fisher, Phil, Joseph
 * 2. Assignment Name:
 *      Lab 08: M777 Howitzer
 * 3. Assignment Description:
 *      Simulate firing the M777 howitzer 15mm artillery piece
 * 4. What was the hardest part? Be as specific as possible.
 *      Figuring out the given code in order to change it and get the Howitzer to perform as required.
 * 5. How long did it take for you to complete the assignment?
 *      Roughly 6 - 8 hours.
 *****************************************************************/

#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "ground.h"     // for GROUND
#include "pos.h"   // for POSITION
#include "test.h"
#include "mathFunctions.h"


using namespace std;

/*************************************************************************
 * Demo
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Demo
{
public:
    Demo(Position ptUpperRight) :
        ptUpperRight(ptUpperRight),
        ground(ptUpperRight),
        time(0.0),
        angle(0.0)
    {
        // Set the horizontal position of the howitzer. This should be random.
        ptHowitzer.setPixelsX(Position(ptUpperRight).getPixelsX() / 2.0);

        // Generate the ground and set the vertical position of the howitzer.
        ground.reset(ptHowitzer);

        // Get the target position
        targetPosition = ground.getTarget();

        // This is to make the bullet travel across the screen. Notice how there are 
        // 20 pixels, each with a different age. This gives the appearance
        // of a trail that fades off in the distance.
        for (int i = 0; i < 20; i++)
        {
            //projectilePath[i].setPixelsX((double)i * 2.0); // Original
            projectilePath[i].setPixelsX(Position(ptUpperRight).getPixelsX() / 2.0);
            //projectilePath[i].setPixelsY(ptUpperRight.getPixelsY() / 1.5); // Original
            projectilePath[i].setPixelsY(ptHowitzer.getPixelsY());
        }
    }

    Ground ground;                 // the ground
    Position  projectilePath[20];  // path of the projectile
    Position  ptHowitzer;          // location of the howitzer
    Position  ptUpperRight;        // size of the screen
    Position targetPosition;
    int targetsHit = 0;
    bool status = true;
    double angle;                  // angle of the howitzer 
    double time;                   // amount of time since the last firing
    bool fired = false;
    double firedAngle;
};
double findInterpolation(Demo* pDemo) {
    /*
    double dragCoefficientTable(double mach);
	double densityTable(double altitude);
	double soundTable(double altitude);
	double gravityTable(double altitude);
    */
    mathFunctions mf;
    /*
    map<double, double> dragTableData = mf.dragCoefficientTable();
    map<double, double> densityTableData = mf.densityTable();
    map<double, double> soundTableData = mf.soundTable();
    map<double, double> gravityTableData = mf.gravityTable();
    */
    double altitude = pDemo->projectilePath->getMetersY();
    
    double movement = NULL;
    
    return movement;
}

void fireProjectile(Demo* pDemo) {
    /*
     // Constant moving across the top of the screen
    // move the projectile across the screen
    for (int i = 0; i < 20; i++)
    {
        // this bullet is moving left at 1 pixel per frame
        double x = pDemo->projectilePath[i].getPixelsX(); // Gets x value of last position
        double y = pDemo->projectilePath[i].getPixelsY(); // get y value of last position
        x -= 1.0; // Change x by -1, move left 1
        y -= 1.0; // change y value by -1
        if (x < 0) // If projectile reaches end of the screen, move it back to the beginning.
            x = pDemo->ptUpperRight.getPixelsX();
        pDemo->projectilePath[i].setPixelsY(y);
        pDemo->projectilePath[i].setPixelsX(x);
    }*/
    for (int i = 0; i < 20; i++)
    {
        double x = pDemo->projectilePath[i].getPixelsX(); // Gets x value of last position
        double y = pDemo->projectilePath[i].getPixelsY(); // get y value of last position
        if (pDemo->time < 3.0) {
            //cout << pDemo->time << endl; Display time
            y += (3 - pDemo->time);
        }
        else {
            y -= (pDemo->time - 3);
        }

        // Right side aim
        // 0 .2 .4 .6 .8 1.0 1.2 1.4 
        if (pDemo->firedAngle <= 0.2 and pDemo->firedAngle > 0) {
            x += 0.8;
        }
        else if (pDemo->firedAngle <= 0.4 and pDemo->firedAngle > 0.2) {
            x += 1.0;
        }
        else if (pDemo->firedAngle <= 0.6 and pDemo->firedAngle > 0.4) {
            x += 1.5;
        }
        else if (pDemo->firedAngle <= 0.8 and pDemo->firedAngle > 0.6) {
            x += 2.5;
        }
        else if (pDemo->firedAngle <= 1.0 and pDemo->firedAngle > 0.8) {
            x += 3.0;
        }
        else if (pDemo->firedAngle <= 1.2 and pDemo->firedAngle > 1.0) {
            x += 3.5;
        }
        else if (pDemo->firedAngle <= 1.4 and pDemo->firedAngle > 1.2) {
            x += 4.0;
        }
        else if (pDemo->firedAngle > 1.4) {
            x += 2;
        }
        else if (pDemo->firedAngle >= -0.2 and pDemo->firedAngle < 0) { // Left side aim
            x -= 0.8;
        }
        else if (pDemo->firedAngle >= -0.4 and pDemo->firedAngle < -0.2) {
            x -= 1.0;
        }
        else if (pDemo->firedAngle >= -0.6 and pDemo->firedAngle < -0.4) {
            x -= 1.5;
        }
        else if (pDemo->firedAngle >= -0.8 and pDemo->firedAngle < -0.6) {
            x -= 2.5;
        }
        else if (pDemo->firedAngle >= -1.0 and pDemo->firedAngle < -0.8) {
            x -= 3.0;
        }
        else if (pDemo->firedAngle >= -1.2 and pDemo->firedAngle < -1.0) {
            x -= 3.5;
        }
        else if (pDemo->firedAngle >= -1.4 and pDemo->firedAngle < -1.2) {
            x -= 4.0;
        }
        else if (pDemo->firedAngle < -1.4) {
            x -= 2;
        }
        
        if (x < 0) { // If projectile reaches left end of the screen, move it back to the beginning.
            x = pDemo->ptUpperRight.getPixelsX();
        }
        else if (x > pDemo->ptUpperRight.getPixelsX()) { // If projectile reaches right end of the screen, move it back to the beginning.
            x = 0;
        }
        pDemo->projectilePath[i].setPixelsY(y);
        pDemo->projectilePath[i].setPixelsX(x);

    }
}
void projectileReset(Demo* pDemo) {
    for (int i = 0; i < 20; i++)
    {
        //projectilePath[i].setPixelsX((double)i * 2.0); // Original
        pDemo->projectilePath[i].setPixelsX(Position(pDemo->ptUpperRight).getPixelsX() / 2.0);
        //projectilePath[i].setPixelsY(ptUpperRight.getPixelsY() / 1.5); // Original
        pDemo->projectilePath[i].setPixelsY(pDemo->ptHowitzer.getPixelsY());
    }
    pDemo->fired = false;
}

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* pUI, void* p)
{
    // the first step is to cast the void pointer into a game object. This
    // is the first step of every single callback function in OpenGL. 
    Demo* pDemo = (Demo*)p;

    //
    // accept input
    //

    // move a large amount
    if (pUI->isRight())
        pDemo->angle += 0.025;
    if (pUI->isLeft())
        pDemo->angle -= 0.025;

    // move by a little
    if (pUI->isUp())
        pDemo->angle += (pDemo->angle >= 0 ? -0.002 : 0.002);
    if (pUI->isDown())
        pDemo->angle += (pDemo->angle >= 0 ? 0.002 : -0.002);
    //cout << pDemo->projectilePath[0] << endl; // Display projectile Position
    // fire that gun
    //cout << pDemo->angle << endl; // Check angle
    if (pUI->isSpace() and pDemo->status == true) {
        //pDemo->projectilePath[0].setPixelsY(pDemo->ptHowitzer.getPixelsY());
        //pDemo->projectilePath[0].setPixelsX(pDemo->ptHowitzer.getPixelsX());
        pDemo->time = 0.0;
        pDemo->fired = true;
        pDemo->firedAngle = pDemo->angle;
    }
    if (pDemo->fired) {
        fireProjectile(pDemo);
        pDemo->status = false;
        pDemo->time += 0.03;
    }
    
    
    //
    // draw everything
    //

    ogstream gout(Position(10.0, pDemo->ptUpperRight.getPixelsY() - 20.0));

    // draw the ground first
    pDemo->ground.draw(gout);

    // draw the howitzer
    gout.drawHowitzer(pDemo->ptHowitzer, pDemo->angle, pDemo->time);

    // draw the projectile
    // TODO: Projectile reset when ground is hit //////////////////////////////////////////////////////////////////////////////////////////////////////
    for (int i = 0; i < 20; i++) {
        cout << "Ground: " << pDemo->ground.getElevationMeters(pDemo->projectilePath[i]) << endl;
        //cout << "Projectile: " << pDemo->projectilePath[i].getPixelsY() << endl;
        if (pDemo->ground.getElevationMeters(pDemo->projectilePath[i]) >= pDemo->projectilePath[i].getMetersY()) {
            projectileReset(pDemo);
            pDemo->status = true;
            
        }
        if (pDemo->ground.getElevationMeters(pDemo->projectilePath[i]) <= pDemo->projectilePath[i].getMetersY()) {
            gout.drawProjectile(pDemo->projectilePath[i], 0.5 * (double)i);
            
        }
        // Makes projectile reset at target or cannon depending on which is lower.
        /*
        //cout << pDemo->projectilePath[i].getPixelsY() << endl; Show y position
        if (pDemo->targetPosition.getPixelsY() - 1 <= pDemo->ptHowitzer.getPixelsY() - 1) {
            if (pDemo->projectilePath[i].getPixelsY() > pDemo->targetPosition.getPixelsY() - 1)
                gout.drawProjectile(pDemo->projectilePath[i], 0.5 * (double)i);
            if (pDemo->projectilePath[i].getPixelsY() < pDemo->targetPosition.getPixelsY() - 1) {
                projectileReset(pDemo);
                pDemo->status = true;
            }
        }
        else {
            if (pDemo->projectilePath[i].getPixelsY() > pDemo->ptHowitzer.getPixelsY() - 1)
                gout.drawProjectile(pDemo->projectilePath[i], 0.5 * (double)i);
            if (pDemo->projectilePath[i].getPixelsY() < pDemo->ptHowitzer.getPixelsY() - 1) {
                projectileReset(pDemo);
                pDemo->status = true;
            }
        }*/
        
            
        
    }

    
    // Check for collision
    for (int i = 0; i < 20; i++) {
        if (pDemo->projectilePath[i].getPixelsY() < pDemo->targetPosition.getPixelsY() + 15 and pDemo->projectilePath[i].getPixelsY() > pDemo->targetPosition.getPixelsY() - 15) {
            if (pDemo->projectilePath[i].getPixelsX() < pDemo->targetPosition.getPixelsX() + 15 and pDemo->projectilePath[i].getPixelsX() > pDemo->targetPosition.getPixelsX() - 15)
            {
                pDemo->targetsHit += 1;
                pDemo->ground.reset(pDemo->ptHowitzer);
                pDemo->targetPosition = pDemo->ground.getTarget();
                break;
            }
            break;
        }
    }
    string readyToFire;
    if (pDemo->status == true) {
        readyToFire = "Ready";
    }
    else {
        readyToFire = "Not Ready";
    }


    // draw some text on the screen
    gout.setf(ios::fixed | ios::showpoint);
    gout.precision(1);
    gout << "Time since the bullet was fired: " << pDemo->time << "s\n" 
        << "Projectile Altitude: " << pDemo->projectilePath[1].getPixelsY() << "\n"
        << "Howitzer Angle: " << pDemo->angle << "\n\n"
        << "Targets Hit: " << pDemo->targetsHit << "\n"
        << "Ready To Fire: " << readyToFire << "\n";
}

double Position::metersFromPixels = 40.0;



/*********************************
 * Initialize the simulation and set it in motion
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
    // Unit Tests
    testRunner();

    // Initialize OpenGL
    Position ptUpperRight;
    ptUpperRight.setPixelsX(700.0);
    ptUpperRight.setPixelsY(500.0);
    Position().setZoom(40.0 /* 42 meters equals 1 pixel */);
    Interface ui(0, NULL,
        "Demo",   /* name on the window */
        ptUpperRight);

    // Initialize the demo
    Demo demo(ptUpperRight);

    // set everything into action
    ui.run(callBack, &demo);

    


    return 0;
}
