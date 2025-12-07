#include <graphics.h>
#include <iostream>
#include <math.h>
using namespace std;
#define pi 3.14

struct Smoke
{
    int x, y, radius;
    int dx;
};

const int MAX_SMOKE = 40;
Smoke smokes[MAX_SMOKE];
int smokeIndex = 0;

void addSmoke(int x, int y)
{
    smokes[smokeIndex].x = x + rand() % 10 - 3;
    smokes[smokeIndex].y = y;
    smokes[smokeIndex].radius = rand() % 5 + 20;
    smokes[smokeIndex].dx = rand() % 3 - 1;
    smokeIndex = (smokeIndex + 1) % MAX_SMOKE;
}

void drawSmoke()
{
    setcolor(WHITE);
    for (int i = 0; i < MAX_SMOKE; i++)
    {
        if (smokes[i].radius > 0)
        {
            setfillstyle(SOLID_FILL, WHITE);
            fillellipse(smokes[i].x, smokes[i].y, smokes[i].radius, smokes[i].radius);
            smokes[i].y -= 1;
            smokes[i].x += smokes[i].dx;
            smokes[i].radius -= 1;
        }
    }
    setcolor(BLACK);
}

void trainStructre(int startX, int startY, int p_eyes)
{
    int width = 150;
    int height = 100;
    int depth = 30;

    // Front Face
    int frontface[] =
        {
            startX, startY,
            startX + width, startY,
            startX + width, startY + height,
            startX, startY + height,
            startX, startY
        };
    setfillstyle(SOLID_FILL, RED);
    fillpoly(5, frontface);

    // Top Face
    int topFace[] =
        {
            startX, startY,
            startX + depth, startY - depth,
            startX + width + depth, startY - depth,
            startX + width, startY,
            startX, startY};
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    fillpoly(5, topFace);

    // Window of the train
    setfillstyle(SOLID_FILL, LIGHTCYAN);
    bar(startX + 10, startY + 10, startX + 70, startY + 50);
    setcolor(BROWN);
    rectangle(startX + 10, startY + 10, startX + 70, startY + 50);
    setcolor(BLACK);

    // People on the train
    setfillstyle(SOLID_FILL, LIGHTRED);
    fillellipse(startX + 40, startY + 30, 11, 11);
    setfillstyle(SOLID_FILL, MAGENTA);
    bar(startX + 29.5, startY + 41, startX + 50, startY + 51);
    setfillstyle(SOLID_FILL, WHITE);
    ellipse(startX + 40, startY + 32, 240, 300, 4, 4);

    if ((p_eyes % 100) <= 50)
    {
        arc(startX + 36, startY + 27, 0, 180, 2);
        arc(startX + 44, startY + 27, 0, 180, 2);
    }
    else
    {
        fillellipse(startX + 36, startY + 27, 3, 4);
        fillellipse(startX + 44, startY + 27, 3, 4);
        setfillstyle(SOLID_FILL, BLACK);
        fillellipse(startX + 36, startY + 28, 1.5, 2);
        fillellipse(startX + 44, startY + 28, 1.5, 2);
    }

    // Hair of the people
    for (int i = 180; i <= 360; i++)
    {
        float angle = i * (pi / 180);
        float hairLength = 5 + rand() % 2;
        line((startX + 40) + (11 * cos(angle)), (startY + 30) + (11 * sin(angle)), (startX + 40) + (11 + hairLength) * cos(angle), (startY + 30) + (11 + hairLength) * sin(angle));
    }
}

// Train Engine
void trainEngine(int startX, int startY)
{
    int width = 150;
    int height = 100;
    int depth = 30;

    // Front Face
    int frontface[] =
        {
            startX, startY,
            startX + width, startY,
            startX + width, startY + height,
            startX, startY + height,
            startX, startY};
    setfillstyle(SOLID_FILL, RED);
    fillpoly(5, frontface);

    // Top Face
    int topFace[] =
        {
            startX, startY,
            startX + depth, startY - depth,
            startX + width + depth, startY - depth,
            startX + width, startY,
            startX, startY};
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    fillpoly(5, topFace);

    // Chimney structure
    int chimney_FrontFace[] =
        {
            startX + 90, startY - 15,
            startX + 90, startY - 50,
            startX + 110, startY - 50,
            startX + 110, startY - 15,
            startX + 90, startY - 15};
    setfillstyle(SOLID_FILL, BLUE);
    fillpoly(5, chimney_FrontFace);

    int chimney_TopFace[] =
        {
            startX + 90, startY - 50,
            startX + 100, startY - 60,
            startX + 120, startY - 60,
            startX + 110, startY - 50,
            startX + 90, startY - 50};
    setfillstyle(SOLID_FILL, COLOR(80,140,100));
    fillpoly(5, chimney_TopFace);

    int chimney_RightFace[] =
        {
            startX + 110, startY - 50,
            startX + 120, startY - 60,
            startX + 120, startY - 25,
            startX + 110, startY - 15,
            startX + 110, startY - 50};
    setfillstyle(SOLID_FILL, BLUE);
    fillpoly(5, chimney_RightFace);

    // Right Face
    int rightFace[] =
        {
            startX + width, startY,
            startX + width + depth, startY - depth,
            startX + width + depth, startY + height - depth,
            startX + width, startY + height, startX + width, startY};
    setfillstyle(SOLID_FILL, RED);
    fillpoly(5, rightFace);

    // Window of the front
    int window[] =
        {
            startX + width, startY,
            startX + width + depth, startY - depth,
            startX + width + depth, startY + height / 2 - depth,
            startX + width, startY + height / 2,
            startX + width, startY};
    setfillstyle(SOLID_FILL, LIGHTCYAN);
    fillpoly(5, window);

    // Designer strips on the train
    setfillstyle(SOLID_FILL, WHITE);
    bar(startX, startY + 40, startX + width, startY + 50);
    bar(startX, startY + 60, startX + width, startY + 70);
}

// Wheels of the train
void wheels(int startX, float angle)
{
    // Outer Radius
    setfillstyle(SOLID_FILL, BLACK);
    fillellipse(startX + 10, 415, 15, 15);
    fillellipse(startX + 90, 415, 15, 15);
    // Inner Radius
    setfillstyle(SOLID_FILL, WHITE);
    fillellipse(startX + 10, 415, 12, 12);
    fillellipse(startX + 90, 415, 12, 12);

    for (int i = 1; i <= 15; i++)
    {
        float theta = angle + (24 * i * (pi / 180));
        line(startX + 10, 415, startX + 10 + 12 * cos(theta), 415 + 12 * sin(theta));
        line(startX + 90, 415, startX + 90 + 12 * cos(theta), 415 + 12 * sin(theta));
    }
}

// Wheel of the back side
void wheels_backside(int startX, float angle)
{
    setfillstyle(SOLID_FILL, BLACK);
    fillellipse(startX, 385, 15, 15);
    setfillstyle(SOLID_FILL, WHITE);
    fillellipse(startX, 385, 12, 12);

    for (int i = 1; i <= 15; i++)
    {
        float theta = angle + (24 * i * (pi / 180));
        line(startX, 385, startX + 12 * cos(theta), 385 + 12 * sin(theta));
    }
}

// Mountains behind the train
void mountains()
{
    int mountain1[] = {200, 300, 325, 40, 450, 300, 200, 300};
    int mountain2[] = {350, 300, 500, 20, 650, 300, 350, 300};
    int mountain3[] = {50, 300, 175, 5, 300, 300, 50, 300};
    int mountain4[] = {650, 300, 800, 10, 950, 300, 650, 300};
    int mountain5[] = {500, 300, 625, 30, 770, 300, 500, 300};
    setfillstyle(SOLID_FILL, COLOR(119,150,105));
    fillpoly(4, mountain1);
    fillpoly(4, mountain2);
    fillpoly(4, mountain3);
    fillpoly(4, mountain4);
    fillpoly(4, mountain5);
}

// Sun
void sun(int blink)
{
    // Body of the sun
    setfillstyle(SOLID_FILL, YELLOW);
    fillellipse(1075, 70, 45, 45);

    if ((blink % 100) <= 50)
    {
        // Sun eyes closed
        arc(1056, 60, 20, 160, 8);
        arc(1094, 60, 20, 160, 8);

        // Smile of the sun, mouth open
        ellipse(1075, 80, 180, 360, 22, 20);
        line(1053, 80, 1097, 80);
        arc(1075, 100, 20, 160, 15);
        setfillstyle(SOLID_FILL, WHITE);
        floodfill(1075, 84, BLACK);
        setfillstyle(SOLID_FILL, RED);
        floodfill(1075, 98, BLACK);
    }

    else
    {
        // Sun eyes open
        setfillstyle(SOLID_FILL, WHITE);
        fillellipse(1056, 55, 7, 9);
        setfillstyle(SOLID_FILL, BLACK);
        fillellipse(1056, 55, 4, 5);
        setfillstyle(SOLID_FILL, WHITE);
        fillellipse(1094, 55, 7, 9);
        setfillstyle(SOLID_FILL, BLACK);
        fillellipse(1094, 55, 4, 5);

        // Smile of the sun, mouth close
        ellipse(1075, 75, 210, 330, 22, 20);
    }

    // Rays of the sun
    for (int i = 1; i <= 60; i++)
    {
        setcolor(YELLOW);
        float angle = 6 * i * (pi / 180);
        float rayLength = 80 + rand() % 15;
        line(1075 + 40 * cos(angle), 70 + 40 * sin(angle), 1075 + rayLength * cos(angle), 70 + rayLength * sin(angle));
    }
}

const int NUM_BIRDS = 5;

struct Bird
{
    int x, y;
    int direction;
};

Bird birds[NUM_BIRDS];

// Birds
void _birds(int blink)
{
    setcolor(BLACK);
    for (int i = 0; i < NUM_BIRDS; i++)
    {
        Bird &b = birds[i];
        if (blink % 20 < 10)
        {
            arc(b.x + 20, b.y, 0, 90, 10);
            arc(b.x + 40, b.y, 90, 180, 10);
            arc(b.x + 40, b.y + 20, 0, 90, 10);
            arc(b.x + 60, b.y + 20, 90, 180, 10);
        }
        else
        {
            ellipse(b.x + 21, b.y, 20, 160, 8, 4);
            ellipse(b.x + 38, b.y, 20, 160, 8, 4);
            ellipse(b.x + 42, b.y + 20, 20, 160, 8, 4);
            ellipse(b.x + 58, b.y + 20, 20, 160, 8, 4);
        }
        b.x += b.direction * 2;
        if (b.direction == 1 && b.x > 900)
        {
            b.direction = -1;
        }
        else if (b.direction == -1 && b.x < -100)
        {
            b.direction = 1;
            b.y = 25 + rand() % 40;
        }
    }
}
// Drawing grass
void grass()
{
    setfillstyle(SOLID_FILL, COLOR(180, 252, 100));
    bar(0, 300, 1210, 690);
}

// Structring the railway track
void railwayTrack()
{
    setfillstyle(SOLID_FILL, BLACK);
    bar(0, 400, 1210, 395);
    bar(0, 430, 1210, 435);

    setfillstyle(SOLID_FILL, DARKGRAY);
    for (int x = 0; x < 1300; x += 15)
    {
        int rect[] = {x, 430, x + 15, 400, x + 20, 400, x + 5, 430, x + 0, 430};
        fillpoly(5, rect);
    }
}

// Rain creation
void rain()
{
    setcolor(BLUE);
    int a = 5 + rand() % 3;
    for (int x = 10; x <= 1210; x += 5)
    {
        int y = rand() % 690;
        line(x, y, x, y + a);
    }
    setcolor(BLACK);
}

// Drawing trees
void trees()
{
    for (int x = 0; x < 1300; x = x + 150)
    {
        // Bark of the tree
        setfillstyle(SOLID_FILL, COLOR(150, 75, 20));
        bar(x + 60, 280, x + 90, 360);

        // Leaves
        setcolor(COLOR(0,64,0));
        setfillstyle(SOLID_FILL, COLOR(0,64,0));
        fillellipse(x + 75 + rand() % 2 - rand() % 2, 260, 30, 35);
        fillellipse(x + 45 + rand() % 2 - rand() % 2, 250, 30, 35);
        fillellipse(x + 60 + rand() % 2 - rand() % 2, 220, 30, 35);
        fillellipse(x + 90 + rand() % 2 - rand() % 2, 210, 30, 35);
        fillellipse(x + 105 + rand() % 2 - rand() % 2, 250, 30, 35);
        setcolor(BLACK);
    }

    // Trees on the mountains
    for (int i = -20; i <= 20; i += 20)
    {
        setfillstyle(SOLID_FILL, COLOR(150, 75, 0));
        bar(315 + i, 110 + i, 330 + i, 150 + i);
        setcolor(COLOR(0,64,0));
        setfillstyle(SOLID_FILL, COLOR(0,64,0));
        fillellipse(322.5 + i + rand() % 2 - rand() % 2, 105 + i, 15, 17);
        fillellipse(308 + i + rand() % 2 - rand() % 2, 98 + i, 15, 17);
        fillellipse(314 + i + rand() % 2 - rand() % 2, 84 + i, 15, 17);
        fillellipse(329 + i + rand() % 2 - rand() % 2, 80 + i, 15, 17);
        fillellipse(335 + i + rand() % 2 - rand() % 2, 99 + i, 15, 17);
    }
    for (int i = -20; i <= 20; i += 20)
    {
        setfillstyle(SOLID_FILL, COLOR(150, 75, 0));
        bar(470 + i, 120 + i, 485 + i, 160 + i);
        setfillstyle(SOLID_FILL, COLOR(0,64,0));
        fillellipse(477.5 + i + rand() % 2 - rand() % 2, 115 + i, 15, 17);
        fillellipse(463 + i + rand() % 2 - rand() % 2, 108 + i, 15, 17);
        fillellipse(469 + i + rand() % 2 - rand() % 2, 94 + i, 15, 17);
        fillellipse(483 + i + rand() % 2 - rand() % 2, 90 + i, 15, 17);
        fillellipse(489 + i + rand() % 2 - rand() % 2, 109 + i, 15, 17);
    }

    setfillstyle(SOLID_FILL, COLOR(150, 80, 0));
    bar(610, 80, 625, 120);
    setfillstyle(SOLID_FILL, COLOR(0,64,0));
    fillellipse(617.5 + rand() % 2 - rand() % 2, 77, 15, 17);
    fillellipse(603 + rand() % 2 - rand() % 2, 70, 15, 17);
    fillellipse(609 + rand() % 2 - rand() % 2, 54, 15, 17);
    fillellipse(623 + rand() % 2 - rand() % 2, 56, 15, 17);
    fillellipse(629 + rand() % 2 - rand() % 2, 74, 15, 17);

    setfillstyle(SOLID_FILL, COLOR(150, 75, 0));
    bar(800, 110, 815, 150);
    setfillstyle(SOLID_FILL, COLOR(0,64,0));
    fillellipse(807.5 + rand() % 2 - rand() % 2, 105, 15, 17);
    fillellipse(793 + rand() % 2 - rand() % 2, 98, 15, 17);
    fillellipse(799 + rand() % 2 - rand() % 2, 84, 15, 17);
    fillellipse(813 + rand() % 2 - rand() % 2, 80, 15, 17);
    fillellipse(819 + rand() % 2 - rand() % 2, 99, 15, 17);

    setfillstyle(SOLID_FILL, COLOR(150, 75, 0));
    bar(150, 70, 165, 110);
    setfillstyle(SOLID_FILL, COLOR(0,64,0));
    fillellipse(157.5 + rand() % 2 - rand() % 2, 65, 15, 17);
    fillellipse(143 + rand() % 2 - rand() % 2, 58, 15, 17);
    fillellipse(149 + rand() % 2 - rand() % 2, 44, 15, 17);
    fillellipse(163 + rand() % 2 - rand() % 2, 40, 15, 17);
    fillellipse(169 + rand() % 2 - rand() % 2, 59, 15, 17);
}

void setupBirds()
{
    for (int i = 0; i < NUM_BIRDS; i++)
    {
        birds[i].x = rand() % 1100 + 50;            // random x position between 50 and 1150
        birds[i].y = rand() % 50 + 10;              // random y position between 30 and 80
        birds[i].direction = (rand() % 2) ? 1 : -1; // random direction: either 1 or -1
    }
}

void mountainClouds()
{
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);

    // Cloud above Mountain_1
    for (int i = -50, m = -5; i <= 80 && m <= 5; i += 30, m += 2)
    {
        int y = 30 + m;
        if (y < 30)
            fillellipse(305 + i, y - 2 * m, 30, 20);

        if (y > 30)
            fillellipse(305 + i, y + 2 * m, 30, 20);
    }

    for (int i = -50, m = -5; i <= 80 && m <= 5; i += 30, m += 2)
    {
        int y = 20 + m;
        if (y < 20)
            fillellipse(480 + i, y - 2 * m, 30, 20);

        if (y > 20)
            fillellipse(480 + i, y + 2 * m, 30, 20);
    }

    // Cloud above Mountain_3
    for (int i = -50, m = -5; i <= 80 && m <= 5; i += 30, m += 2)
    {
        int y = 30 + m;
        if (y < 30){
            fillellipse(830 + i, y - 2 * m, 30, 20);
        }
        if (y > 30){
            fillellipse(830 + i, y + 2 * m, 30, 20);
        }
    }
 
    // Cloud above Mountain_5
    for (int i = -50, m = -5; i <= 80 && m <= 5; i += 30, m += 2)
    {
        int y = 25 + m;
        if(y < 25){
            fillellipse(655 + i, y - 2 * m, 30, 20);
            fillellipse(655 + i, y - 3 * m, 30, 20);
        }
        if(y > 25){
            fillellipse(655 + i, y + 2 * m, 30, 20);
            fillellipse(655 + i, y + 3 * m, 30, 20);
        }
    }

    setcolor(BLACK); // Reset color
}

void drawChild(int startX,float angleDeg)
{
    // Hair of the child
    setfillstyle(SOLID_FILL, COLOR(150,75,20));
    int hair[] = {startX + 37, 506, startX + 37, 480, startX + 67 , 480, startX + 62, 490, startX + 62, 506, startX + 37, 506};
    // startX + 42, 484, startX + 51, 480, startX + 58, 484, startX + 62, 480,
    fillpoly(5, hair);
     
    // Face of the child
    setfillstyle(SOLID_FILL, LIGHTRED);
    bar(startX + 46, 515, startX + 52, 520);
    rectangle(startX + 46, 515, startX + 52, 520);
    fillellipse(startX + 50, 502, 14, 15);
    ellipse(startX + 50, 502, 0, 360, 14, 15);

    // Smile of the child
    arc(startX + 64, 502, 220, 270, 5);
    arc(startX + 62, 502, 210, 270, 9);
    
    // Legs of the child
    float angle = angleDeg * pi /180;
    int lx[4] = {0,10,10,0};
    int ly[4] = {0, 0, 35, 35};
    int lx_1[4] = {0,10,10,0};
    int ly_1[4] = {0, 0, 35, 35};
    int points_1[10];
    int points_2[10];
    for(int i = 0; i<= 4; i++)
    {
        float xRot = lx[i] * cos(angle) - ly[i] * sin(angle);
        float yRot = lx[i] * sin(angle) + ly[i] * cos(angle);
                                                                        
        float xRot_1 = lx_1[i] * cos(-angle) - ly_1[i] * sin(-angle);
        float yRot_1 = lx_1[i] * sin(-angle) + ly_1[i] * cos(-angle);

        points_1[2 * i] = startX + 44 + xRot;
        points_1[2 * i + 1] = 565 + yRot;

        points_2[2 * i] = startX + 44 + xRot_1;
        points_2[2 * i + 1] = 565 + yRot_1;
    }

    points_1[8] = points_1[0];
    points_1[9] = points_1[1];

    points_2[8] = points_2[0];
    points_2[9] = points_2[1];

    setfillstyle(SOLID_FILL, COLOR(160, 125, 130));
    fillpoly(5, points_2);
    setfillstyle(SOLID_FILL, COLOR(160, 125, 130));
    fillpoly(5, points_1);
    
    // Hand holding umbrella
    // setfillstyle(SOLID_FILL, LIGHTRED);
    // bar(startX + 41, 525 , startX + 75, 535);
    // rectangle(startX + 41, 525 , startX + 75, 535);

    // Umbrella
    

    // Torso
    setfillstyle(SOLID_FILL, RED);
    bar(startX + 41, 520,startX + 57, 570);
    rectangle(startX + 41, 520, startX + 57, 570);

    // Hands of the child
    int px[4] = {0,10,10,0};
    int py[4] = {0, 0, 35, 35};
    int points[10];

    for(int i = 0; i<= 4; i++)
    {
        float xRot = px[i] * cos(angle) - py[i] * sin(angle);
        float yRot = px[i] * sin(angle) + py[i] * cos(angle);

        points[2 * i] = startX + 44 + xRot;
        points[2 * i + 1] = 525 + yRot;
    }    

    points[8] = points[0];
    points[9] = points[1];

    setfillstyle(SOLID_FILL, LIGHTRED);
    fillpoly(5, points);

    // Eyes of the child
    setfillstyle(SOLID_FILL, WHITE);
    fillellipse(startX + 57, 498, 3, 4);
    setfillstyle(SOLID_FILL, BLACK);
    fillellipse(startX + 57, 498, 1, 2);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    initwindow(1210, 690);
    setupBirds();
    int page = 0;
    int blink = 0;
    float angle = 0;
    int direction = 1;
    for (int x = -500, x1 = 0, x2 = 0;; x+=2, x1+=1, x2+=2 )
    {
        setactivepage(page);
        setvisualpage(1 - page);
        setfillstyle(SOLID_FILL, COLOR(55, 95, 115));
        clearviewport();
        bar(0, 0, 1210, 690);
        grass();
        setcolor(BLACK);
        mountains();
        railwayTrack();
        trees();
        rain();
        mountainClouds();
        _birds(x2 - 20);
        wheels_backside(x + 480, angle);
        trainStructre(x + 0, 300, blink);
        trainStructre(x + 155, 300, blink + 30);
        trainEngine(x + 310, 300);
        wheels(x + 37.5, angle);
        wheels(x + 150 + 37.5, angle);
        wheels(x + 310 + 37.5, angle);
        angle += 0.01;
        if (blink % 3 == 0)
        {
            addSmoke(x + 320 + 100, 300 - 65);
        }
        drawSmoke();
        drawChild(x1 - 100, angle);
        angle += direction;
        if (angle > 30 || angle < -30)
        direction *= -1;
        sun(blink);
        blink++;
        // rocks();
        delay(5);
        page = 1 - page;
        if (x > 1300)
        {
            x = -500;
        }
    }
    getch();
    closegraph();
    return 0;
}