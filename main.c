#include "raylib.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
int main()
{
	int iaMode = 0;
   int screenWidth = 1080;
int screenHeight = 1020;
    int currentPage = 0;
    InitWindow(screenWidth, screenHeight, "Scientific Calculator");
    Rectangle arithmeticBtn  = {20,140,290,55};
Rectangle scientificBtn = {20,205,290,55};
Rectangle trigonometryBtn = {20,270,290,55};
Rectangle interestBtn = {20,335,290,55};
Rectangle historyBtn = {20,400,290,55};
Rectangle exitBtn = {20,465,290,55};
Rectangle homeBtn = {20,530,290,55};
Rectangle addBtn = {380,320,70,50};
Rectangle powerBtn = {380,320,100,50};
Rectangle sqrtBtn = {500,320,100,50};
Rectangle factorialBtn = {620,320,100,50};
Rectangle gcdBtn = {380,390,100,50};
Rectangle lcmBtn = {500,390,100,50};
Rectangle clearSciBtn = {740,390,70,50};
Rectangle subBtn = {470,320,70,50};
Rectangle mulBtn = {560,320,70,50};
Rectangle divBtn = {650,320,70,50};
Rectangle clearBtn = {740,320,70,50};
Rectangle sinBtn = {380,260,100,50};
Rectangle cosBtn = {500,260,100,50};
Rectangle tanBtn = {620,260,100,50};
Rectangle asinBtn = {380,330,100,50};
Rectangle acosBtn = {500,330,100,50};
Rectangle atanBtn = {620,330,100,50};
Rectangle clearTrigBtn = {740,330,70,50};
Rectangle siBtn = {380, 400, 180, 50};
Rectangle ciBtn = {580, 400, 180, 50};
Rectangle rectangleBtn = {380,470,120,50};
Rectangle squareBtn    = {520,470,100,50};
Rectangle circleBtn    = {640,470,100,50};
Rectangle triangleBtn  = {760,470,120,50};
Rectangle clearIABtn = {780, 400, 60, 50};
char resultText[32] = "";
char history[20][100];
int historyCount = 0;
Rectangle resultBox = {380,440,420,50};
Rectangle thirdBox = {380,340,500,50};
char thirdNumber[32] = "";
int thirdLength = 0;
bool thirdActive = false;
Rectangle firstBox  = {380, 120, 500, 50};// Arithmetic Page Input Boxes
Rectangle secondBox = {380, 230, 500, 50};
    SetTargetFPS(60);
    char firstNumber[32] = "";
    char secondNumber[32] = "";
    int firstLength = 0;
    int secondLength = 0;
    bool firstActive = false;
    bool secondActive = false;
    while (!WindowShouldClose())
    {
    	if (IsKeyPressed(KEY_F11))
{
    ToggleFullscreen();

    screenWidth = GetScreenWidth();
    screenHeight = GetScreenHeight();
}
    	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
{
    if (currentPage == 1 || currentPage == 2 || currentPage == 3)
    {
        firstActive = CheckCollisionPointRec(GetMousePosition(), firstBox);
        secondActive = CheckCollisionPointRec(GetMousePosition(), secondBox);
    }
    else if (currentPage == 4)
    {
        firstActive = CheckCollisionPointRec(GetMousePosition(), firstBox);
        secondActive = CheckCollisionPointRec(GetMousePosition(), secondBox);
        thirdActive = CheckCollisionPointRec(GetMousePosition(), thirdBox);
    }
}
int key = GetCharPressed();
while (key > 0)
{
    if ((key >= '0' && key <= '9') || key == '.' || key == '-')
    {
        if (firstActive && firstLength < 31)
        {
            firstNumber[firstLength] = (char)key;
            firstLength++;
            firstNumber[firstLength] = '\0';
        }
        if (secondActive && secondLength < 31)
        {
            secondNumber[secondLength] = (char)key;
            secondLength++;
            secondNumber[secondLength] = '\0';
        }
        if (thirdActive && thirdLength < 31)
   {
    thirdNumber[thirdLength] = (char)key;
    thirdLength++;
    thirdNumber[thirdLength] = '\0';
   } 
    }
    key = GetCharPressed();
}
if (IsKeyPressed(KEY_BACKSPACE))
{
    if (firstActive && firstLength > 0)
    {
        firstLength--;
        firstNumber[firstLength] = '\0';
    }
    if (secondActive && secondLength > 0)
    {
        secondLength--;
        secondNumber[secondLength] = '\0';
    }
    if (thirdActive && thirdLength > 0)
{
    thirdLength--;
    thirdNumber[thirdLength] = '\0';
}
}
time_t now = time(NULL);
struct tm *t = localtime(&now);
char currentTime[20];
char currentDate[20];
sprintf(currentTime,"%02d:%02d:%02d",t->tm_hour,t->tm_min,t->tm_sec);
sprintf(currentDate,"%02d/%02d/%04d",t->tm_mday,t->tm_mon + 1,t->tm_year + 1900);
ClearBackground(DARKGRAY);
BeginDrawing();
ClearBackground(DARKGRAY);
DrawRectangle(0,0,340,screenHeight,BLACK);// Left Sidebar
DrawRectangle(0,screenHeight-40,screenWidth,40,BLACK);// Bottom Footer
DrawRectangle(1450,12,340,50,BLACK);// Clock
DrawRectangleLines(1450,12,340,50,GREEN);
DrawText(currentTime,1475,20,32,GREEN);
DrawText(currentDate,1615,26,18,WHITE);
DrawText("Scientific Calculator v1.0",20,screenHeight-30,18,WHITE);// Footer Text
DrawText("Raylib | C++",430,screenHeight-30,18,GREEN);
DrawText("F11 : Fullscreen",screenWidth-220,screenHeight-30,18,WHITE);
DrawText("SCIENTIFIC",40,30,38,WHITE);// Sidebar Title
DrawText("CALCULATOR",40,75,38,GREEN);
        Color arithmeticColor=DARKGRAY;
        Color scientificColor=DARKGRAY;
        Color trigonometryColor=DARKGRAY;
        Color interestColor=DARKGRAY;
        Color historyColor=DARKGRAY;
        Color exitColor=DARKGRAY;
if (CheckCollisionPointRec(GetMousePosition(), arithmeticBtn))//Arithmatic
{
    arithmeticColor = GRAY;
}
DrawRectangleRec(arithmeticBtn, arithmeticColor);
DrawRectangleLinesEx(arithmeticBtn,2,GREEN);
       DrawText("Arithmetic",60,156,24,WHITE);
       if (CheckCollisionPointRec(GetMousePosition(), scientificBtn)) // Scientific Button
{
    scientificColor = GRAY;
}
DrawRectangleRec(scientificBtn, scientificColor);
DrawRectangleLinesEx(scientificBtn,2,GREEN);
       DrawText("Scientific", 45, 221, 22, WHITE);
       if (CheckCollisionPointRec(GetMousePosition(), trigonometryBtn))// Trigonometry Button
{
    trigonometryColor = GRAY;
}
DrawRectangleRec(trigonometryBtn, trigonometryColor);
DrawRectangleLinesEx(trigonometryBtn,2,GREEN);
       DrawText("Trigonometry", 45, 286, 22, WHITE);
      if (CheckCollisionPointRec(GetMousePosition(), interestBtn))// Interest & Area Button
{
    interestColor = GRAY;
}
DrawRectangleRec(interestBtn, interestColor);
DrawRectangleLinesEx(interestBtn,2,GREEN);
      DrawText("Interest & Area", 45, 351, 22, WHITE);
      if (CheckCollisionPointRec(GetMousePosition(), historyBtn))  // History Button
{
    historyColor = GRAY;
}
DrawRectangleRec(historyBtn, historyColor);
DrawRectangleLinesEx(historyBtn,2,GREEN);
DrawText("History", 45, 416, 22, WHITE);
     if (CheckCollisionPointRec(GetMousePosition(), exitBtn))// Exit Button
{
    exitColor = GRAY;
}
Color homeColor = DARKGRAY;
if (CheckCollisionPointRec(GetMousePosition(), homeBtn))
    homeColor = GRAY;
DrawRectangleRec(homeBtn, homeColor);
DrawRectangleLinesEx(homeBtn, 2, GREEN);
DrawText("Home", 45,546, 22, WHITE);
DrawRectangleRec(exitBtn, exitColor);
DrawRectangleLinesEx(exitBtn,2,GREEN);
DrawText("Exit", 45, 481, 22, WHITE);
if (CheckCollisionPointRec(GetMousePosition(), arithmeticBtn) &&
    IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
{
    currentPage = 1;
    firstNumber[0] = '\0';
    secondNumber[0] = '\0';
    thirdNumber[0] = '\0';
    resultText[0] = '\0';
    firstLength = 0;
    secondLength = 0;
    thirdLength = 0;
}

if (CheckCollisionPointRec(GetMousePosition(), scientificBtn) &&
    IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
{
    currentPage = 2;
firstNumber[0]='\0';
secondNumber[0]='\0';
thirdNumber[0]='\0';
resultText[0]='\0';
firstLength=0;
secondLength=0;
thirdLength=0;
}

if (CheckCollisionPointRec(GetMousePosition(), trigonometryBtn) &&
    IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
{
    currentPage = 3;
firstNumber[0]='\0';
secondNumber[0]='\0';
thirdNumber[0]='\0';
resultText[0]='\0';
firstLength=0;
secondLength=0;
thirdLength=0;
}

if (CheckCollisionPointRec(GetMousePosition(), interestBtn) &&
    IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
{
    currentPage = 4;
firstNumber[0]='\0';
secondNumber[0]='\0';
thirdNumber[0]='\0';
resultText[0]='\0';
firstLength=0;
secondLength=0;
thirdLength=0;
}

if (CheckCollisionPointRec(GetMousePosition(), historyBtn) &&
    IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
{
currentPage = 5;
firstNumber[0]='\0';
secondNumber[0]='\0';
thirdNumber[0]='\0';
resultText[0]='\0';
firstLength=0;
secondLength=0;
thirdLength=0;
}
if (CheckCollisionPointRec(GetMousePosition(), exitBtn) &&
    IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
{
    CloseWindow();
}
if (CheckCollisionPointRec(GetMousePosition(), homeBtn) &&
    IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
{
    currentPage = 0;
}
float num1, num2, answer;

if (currentPage == 1 &&CheckCollisionPointRec(GetMousePosition(), addBtn) &&
    IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
{
    if(firstLength == 0 || secondLength == 0)
    {
        sprintf(resultText,"Enter both numbers");
    }
    else
    {
        num1 = atof(firstNumber);
        num2 = atof(secondNumber);
        answer = num1 + num2;
        sprintf(resultText,"%.2f",answer);
        if(historyCount < 20)
        {
            sprintf(history[historyCount],
                    "%.2f + %.2f = %.2f",
                    num1,num2,answer);
            historyCount++;
        }
    }
}
if (currentPage == 1 &&CheckCollisionPointRec(GetMousePosition(), subBtn) &&
    IsMouseButtonPressed(MOUSE_LEFT_BUTTON))// - Subtraction
{
    if(firstLength == 0 || secondLength == 0)
    {
        sprintf(resultText,"Enter both numbers");
    }
    else
    {
        num1 = atof(firstNumber);
        num2 = atof(secondNumber);
        answer = num1 - num2;
        sprintf(resultText,"%.2f",answer);
        if(historyCount < 20)
        {
            sprintf(history[historyCount],
                    "%.2f - %.2f = %.2f",
                    num1,num2,answer);
            historyCount++;
        }
    }
}
if (currentPage == 1 &&CheckCollisionPointRec(GetMousePosition(), mulBtn) &&
    IsMouseButtonPressed(MOUSE_LEFT_BUTTON))// × Multiplication
{
    if(firstLength == 0 || secondLength == 0)
    {
        sprintf(resultText,"Enter both numbers");
    }
    else
    {
        num1 = atof(firstNumber);
        num2 = atof(secondNumber);
        answer = num1 * num2;
        sprintf(resultText,"%.2f",answer);
        if(historyCount < 20)
        {
            sprintf(history[historyCount],
                    "%.2f x %.2f = %.2f",
                    num1,num2,answer);
            historyCount++;
        }
    }
}
if (currentPage == 1 &&CheckCollisionPointRec(GetMousePosition(), divBtn) &&
    IsMouseButtonPressed(MOUSE_LEFT_BUTTON))// ÷ Division
{
    if(firstLength == 0 || secondLength == 0)
    {
        sprintf(resultText,"Enter both numbers");
    }
    else
    {
        num1 = atof(firstNumber);
        num2 = atof(secondNumber);
        if(num2 == 0)
        {
            sprintf(resultText,"Cannot divide by 0");
        }
        else
        {
            answer = num1 / num2;
            sprintf(resultText,"%.2f",answer);
            if(historyCount < 20)
            {
                sprintf(history[historyCount],
                        "%.2f / %.2f = %.2f",
                        num1,num2,answer);
                historyCount++;
            }
        }
    }
}
if (currentPage == 1 &&
    CheckCollisionPointRec(GetMousePosition(), clearBtn) &&
    IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
{
    firstNumber[0] = '\0';
    secondNumber[0] = '\0';
    resultText[0] = '\0';
    firstLength = 0;
    secondLength = 0;
}
if (currentPage == 0)
{
    DrawText("Welcome to Scientific Calculator", 360, 100, 30, WHITE);
}
if (currentPage == 2 &&CheckCollisionPointRec(GetMousePosition(), sqrtBtn) &&
    IsMouseButtonPressed(MOUSE_LEFT_BUTTON))// Scientific - Square Root
{
    if(firstLength == 0)
    {
        sprintf(resultText,"Enter a number");
    }
    else
    {
        num1 = atof(firstNumber);
        if(num1 < 0)
        {
            sprintf(resultText,"Invalid");
        }
        else
        {
            answer = sqrt(num1);
            sprintf(resultText,"%.2f",answer);
            if(historyCount < 20)
            {
                sprintf(history[historyCount],
                        "Sqrt(%.2f) = %.2f",
                        num1, answer);
                historyCount++;
            }
        }
    }
}
if (currentPage == 2 &&CheckCollisionPointRec(GetMousePosition(), powerBtn) &&
    IsMouseButtonPressed(MOUSE_LEFT_BUTTON))// Scientific - Power
{
    if(firstLength == 0 || secondLength == 0)
    {
        sprintf(resultText,"Enter both numbers");
    }
    else
    {
        num1 = atof(firstNumber);
        num2 = atof(secondNumber);
        answer = pow(num1, num2);
        sprintf(resultText,"%.2f",answer);
        if(historyCount < 20)
        {
            sprintf(history[historyCount],
                    "%.2f ^ %.2f = %.2f",
                    num1, num2, answer);
            historyCount++;
        }
    }
}
if (currentPage == 2 &&CheckCollisionPointRec(GetMousePosition(), factorialBtn) &&
    IsMouseButtonPressed(MOUSE_LEFT_BUTTON))// Scientific - Factorial
{
    if(firstLength == 0)
    {
        sprintf(resultText,"Enter a number");
    }
    else
    {
        num1 = atof(firstNumber);
        if(num1 < 0 || num1 != (int)num1)
            sprintf(resultText,"Invalid");
        else
        {
            int fact = 1;
            for(int i = 1; i <= (int)num1; i++)
                fact *= i;
            sprintf(resultText,"%d",fact);
        }
    }
}
if (currentPage == 2 &&CheckCollisionPointRec(GetMousePosition(), gcdBtn) &&
    IsMouseButtonPressed(MOUSE_LEFT_BUTTON))// Scientific - GCD
{
    if(firstLength == 0 || secondLength == 0)
    {
        sprintf(resultText,"Enter both numbers");
    }
    else
    {
        int a = atoi(firstNumber);
        int b = atoi(secondNumber);
        int originalA = a;
        int originalB = b;
        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        sprintf(resultText,"%d",a);
        if(historyCount < 20)
        {
            sprintf(history[historyCount],
                    "GCD(%d,%d) = %d",
                    originalA, originalB, a);
            historyCount++;
        }
    }
}
if (currentPage == 2 &&CheckCollisionPointRec(GetMousePosition(), lcmBtn) &&
    IsMouseButtonPressed(MOUSE_LEFT_BUTTON))// Scientific - LCM
{
    if(firstLength == 0 || secondLength == 0)
    {
        sprintf(resultText,"Enter both numbers");
    }
    else
    {
        int a = atoi(firstNumber);
        int b = atoi(secondNumber);
        int originalA = a;
        int originalB = b;
        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        int gcd = a;
        int lcm = (originalA * originalB) / gcd;
        sprintf(resultText,"%d",lcm);
        if(historyCount < 20)
        {
            sprintf(history[historyCount],
                    "LCM(%d,%d) = %d",
                    originalA, originalB, lcm);
            historyCount++;
        }
    }
}
if (currentPage == 2 &&CheckCollisionPointRec(GetMousePosition(), clearSciBtn) &&
    IsMouseButtonPressed(MOUSE_LEFT_BUTTON))// Scientific - Clear
{
    firstNumber[0] = '\0';
    secondNumber[0] = '\0';
    resultText[0] = '\0';
    firstLength = 0;
    secondLength = 0;
}
if (currentPage == 3 &&CheckCollisionPointRec(GetMousePosition(), sinBtn) &&
    IsMouseButtonPressed(MOUSE_LEFT_BUTTON))// Trigonometry - Sin
{
    if(firstLength == 0)
    {
        sprintf(resultText,"Enter an angle");
    }
    else
    {
        num1 = atof(firstNumber);
        answer = sin(num1 * PI / 180.0);
        sprintf(resultText,"%.4f",answer);
        if(historyCount < 20)
        {
            sprintf(history[historyCount],
                    "Sin(%.2f) = %.4f",
                    num1, answer);
            historyCount++;
        }
    }
}
if (currentPage == 3 &&
    CheckCollisionPointRec(GetMousePosition(), clearTrigBtn) &&
    IsMouseButtonPressed(MOUSE_LEFT_BUTTON))// Trigonometry - Clear
{
    firstNumber[0] = '\0';
    resultText[0] = '\0';
    firstLength = 0;
}
if (currentPage == 3 &&CheckCollisionPointRec(GetMousePosition(), cosBtn) &&
    IsMouseButtonPressed(MOUSE_LEFT_BUTTON))// Trigonometry - Cos
{
   if(firstLength==0)
{
    sprintf(resultText,"Enter an angle");
}
else
{
    num1=atof(firstNumber);
    answer=cos(num1*PI/180.0);
    if(fabs(answer)<0.000001)
        answer=0;
    sprintf(resultText,"%.4f",answer);
    if(historyCount<20)
    {
        sprintf(history[historyCount],
                "Cos(%.2f) = %.4f",
                num1,answer);
        historyCount++;
    }
}
}
if (currentPage == 3 &&CheckCollisionPointRec(GetMousePosition(), tanBtn) &&
    IsMouseButtonPressed(MOUSE_LEFT_BUTTON))// Trigonometry - Tan
{
    if(firstLength == 0)
    {
        sprintf(resultText,"Enter an angle");
    }
    else
    {
        num1 = atof(firstNumber);
        int angle = ((int)num1) % 180;
        if(angle == 90 || angle == -90)
        {
            sprintf(resultText,"Undefined");
        }
        else
        {
            answer = tan(num1 * PI / 180.0);
            sprintf(resultText,"%.4f",answer);
            if(historyCount < 20)
            {
                sprintf(history[historyCount],
                        "Tan(%.2f) = %.4f",
                        num1, answer);
                historyCount++;
            }
        }
    }
}
if (currentPage == 3 &&CheckCollisionPointRec(GetMousePosition(), asinBtn) &&
    IsMouseButtonPressed(MOUSE_LEFT_BUTTON))// Trigonometry - ArcSin
{
    if(firstLength == 0)
    {
        sprintf(resultText,"Enter a value");
    }
    else
    {
        num1 = atof(firstNumber);
        if (num1 < -1 || num1 > 1)
        {
            sprintf(resultText,"Invalid");
        }
        else
        {
            answer = asin(num1) * 180.0 / PI;
            sprintf(resultText,"%.2f",answer);
            if(historyCount < 20)
            {
                sprintf(history[historyCount],
                        "ArcSin(%.2f) = %.2f",
                        num1, answer);
                historyCount++;
            }
        }
    }
}
if (currentPage == 3 &&
    CheckCollisionPointRec(GetMousePosition(), acosBtn) &&
    IsMouseButtonPressed(MOUSE_LEFT_BUTTON))// Trigonometry - ArcCos
{
    if(firstLength == 0)
    {
        sprintf(resultText,"Enter a value");
    }
    else
    {
        num1 = atof(firstNumber);
        if (num1 < -1 || num1 > 1)
        {
            sprintf(resultText,"Invalid");
        }
        else
        {
            answer = acos(num1) * 180.0 / PI;
            sprintf(resultText,"%.2f",answer);
            if(historyCount < 20)
            {
                sprintf(history[historyCount],
                        "ArcCos(%.2f) = %.2f",
                        num1, answer);
                historyCount++;
            }
        }
    }
}
if (currentPage == 3 &&CheckCollisionPointRec(GetMousePosition(), atanBtn) &&
    IsMouseButtonPressed(MOUSE_LEFT_BUTTON))// Trigonometry - ArcTan
{
    if(firstLength == 0)
    {
        sprintf(resultText,"Enter a value");
    }
    else
    {
        num1 = atof(firstNumber);
        answer = atan(num1) * 180.0 / PI;
        sprintf(resultText,"%.2f",answer);
        if(historyCount < 20)
        {
            sprintf(history[historyCount],
                    "ArcTan(%.2f) = %.2f",
                    num1, answer);
            historyCount++;
        }
    }
}
if (currentPage == 4 &&CheckCollisionPointRec(GetMousePosition(), ciBtn) &&
    IsMouseButtonPressed(MOUSE_LEFT_BUTTON))// Interest & Area - Compound Interest
{
    iaMode = 2;
    if(firstLength == 0 || secondLength == 0 || thirdLength == 0)
    {
        sprintf(resultText,"Enter P, R & T");
    }
    else
    {
        float principal = atof(firstNumber);
        float rate = atof(secondNumber);
        float time = atof(thirdNumber);
        answer = principal * pow((1 + rate / 100), time);
        sprintf(resultText, "%.2f", answer);
        if(historyCount < 20)
        {
            sprintf(history[historyCount],
                    "CI(%.2f, %.2f%%, %.2f) = %.2f",
                    principal, rate, time, answer);
            historyCount++;
        }
    }
}
if (currentPage == 4 &&CheckCollisionPointRec(GetMousePosition(), siBtn) &&
    IsMouseButtonPressed(MOUSE_LEFT_BUTTON))//Simple Interest
{
    iaMode = 1;
    if(firstLength == 0 || secondLength == 0 || thirdLength == 0)
    {
        sprintf(resultText,"Enter all values");
    }
    else
    {
        float principal = atof(firstNumber);
        float rate = atof(secondNumber);
        float time = atof(thirdNumber);
        answer = (principal * rate * time) / 100;
        sprintf(resultText,"%.2f",answer);
        if(historyCount < 20)
        {
            sprintf(history[historyCount],
                    "SI(%.2f, %.2f%%, %.2f) = %.2f",
                    principal, rate, time, answer);
            historyCount++;
        }
    }
}
if(currentPage == 4 &&CheckCollisionPointRec(GetMousePosition(), rectangleBtn) &&
    IsMouseButtonPressed(MOUSE_LEFT_BUTTON))// Interest & Area - Rectangle
{
    iaMode = 3;
    if(firstLength == 0 || secondLength == 0)
    {
        sprintf(resultText,"Enter length & breadth");
    }
    else
    {
        float length = atof(firstNumber);
        float breadth = atof(secondNumber);
        answer = length * breadth;
        sprintf(resultText,"%.2f",answer);
        if(historyCount < 20)
        {
            sprintf(history[historyCount],
                    "Rectangle %.2f x %.2f = %.2f",
                    length, breadth, answer);
            historyCount++;
        }
    }
}
if(currentPage == 4 &&CheckCollisionPointRec(GetMousePosition(), squareBtn) &&
   IsMouseButtonPressed(MOUSE_LEFT_BUTTON))// Interest & Area - Square
{
    iaMode = 4;
    if(firstLength == 0)
    {
        sprintf(resultText,"Enter side");
    }
    else
    {
        float side = atof(firstNumber);
        answer = side * side;
        sprintf(resultText,"%.2f",answer);
        if(historyCount < 20)
        {
            sprintf(history[historyCount],
                    "Square %.2f = %.2f",
                    side, answer);
            historyCount++;
        }
    }
}
if(currentPage == 4 &&CheckCollisionPointRec(GetMousePosition(), circleBtn) &&
   IsMouseButtonPressed(MOUSE_LEFT_BUTTON))// Interest & Area - Circle

{
    iaMode = 5;
    if(firstLength == 0)
    {
        sprintf(resultText,"Enter radius");
    }
    else
    {
        float radius = atof(firstNumber);
        answer = PI * radius * radius;
        sprintf(resultText,"%.2f",answer);
        if(historyCount < 20)
        {
            sprintf(history[historyCount],
                    "Circle r=%.2f = %.2f",
                    radius, answer);
            historyCount++;
        }
    }
}
if(currentPage == 4 &&CheckCollisionPointRec(GetMousePosition(), triangleBtn) &&
   IsMouseButtonPressed(MOUSE_LEFT_BUTTON))// Interest & Area - Triangle
{
    iaMode = 6;
    if(firstLength == 0 || secondLength == 0)
    {
        sprintf(resultText,"Enter base & height");
    }
    else
    {
        float base = atof(firstNumber);
        float height = atof(secondNumber);
        answer = 0.5 * base * height;
        sprintf(resultText,"%.2f",answer);
        if(historyCount < 20)
        {
            sprintf(history[historyCount],
                    "Triangle %.2f x %.2f = %.2f",
                    base, height, answer);
            historyCount++;
        }
    }
}
if (currentPage == 4 &&CheckCollisionPointRec(GetMousePosition(), clearIABtn) &&
    IsMouseButtonPressed(MOUSE_LEFT_BUTTON))// Interest & Area - Clear
{
    firstNumber[0] = '\0';
    secondNumber[0] = '\0';
    thirdNumber[0] = '\0';
    resultText[0] = '\0';
    firstLength = 0;
    secondLength = 0;
    thirdLength = 0;
    iaMode = 0;
}
if (currentPage == 0)
{
DrawText("Quick Guide",420,170,26,GREEN);  // Quick Guide
DrawText("1. Arithmetic : Basic Operations",420,210,20,WHITE);
DrawText("2. Scientific : Power, Root, GCD, LCM",420,245,20,WHITE);
DrawText("3. Trigonometry : Sin, Cos, Tan",420,280,20,WHITE);
DrawText("4. Interest & Area : SI, CI, Geometry",420,315,20,WHITE);
DrawText("5. History : View Previous Calculations",420,350,20,WHITE);
DrawText("Keyboard Shortcuts",900,180,26,GREEN);// Keyboard Shortcuts
DrawText("F11 - Fullscreen",900,220,20,WHITE);
DrawText("Backspace - Delete",900,255,20,WHITE);
DrawText("Mouse - Select Buttons",900,290,20,WHITE);
DrawText("Features",700,470,28,GREEN);// Features
DrawText("1. Fast Calculations",660,515,20,WHITE);
DrawText("2. Scientific Functions",660,545,20,WHITE);
DrawText("3. Trigonometric Functions",660,575,20,WHITE);
DrawText("4. Calculation History",660,605,20,WHITE);
DrawText("MATHEMATICAL", 1400, 170, 24, GREEN);//Mathematical Constants
DrawText("CONSTANTS",    1410, 200, 24, GREEN);
DrawText("PI = 3.14159265",      1350, 250, 20, WHITE);
DrawText("e = 2.71828183",           1350, 285, 20, WHITE);
DrawText("sqrt(2) = 1.41421356",     1350, 320, 20, WHITE);
DrawText("Golden Ratio = 1.61803",   1350, 355, 20, WHITE);
DrawLine(1340, 390, 1650, 390, GREEN);
DrawText("Calculator Status", 1400, 420, 24, GREEN);
DrawText("Status : READY", 1350, 465, 20, WHITE);
DrawText("Memory : 0",      1350, 500, 20, WHITE);
DrawText("Mode : HOME",     1350, 535, 20, WHITE);
DrawText("Version : 1.0",   1350, 570, 20, WHITE);
DrawLine(1340, 610, 1650, 610, GREEN);
DrawText("Developed By", 1410, 650, 24, GREEN);
DrawText("Samrat Timalsina", 1350, 690, 20, WHITE);
DrawText("Krishna Chandra Giri", 1350, 720, 20, WHITE);
DrawText("Dipesh Dhunghana", 1350, 745, 20, WHITE);
DrawText("Version 1.0",700,880,20,LIGHTGRAY);// Version
}
if (currentPage == 1)
{
DrawText("First Number", 380, 90, 22, WHITE);  // Input Box 1
DrawText("Second Number", 380, 200, 22, WHITE);
Color firstBoxColor = WHITE;
if(firstActive)firstBoxColor = LIGHTGRAY;
DrawRectangleRec(firstBox, firstBoxColor);
DrawText(firstNumber, 390, 135, 22, BLACK);
DrawText("Second Number", 380, 200, 22, WHITE);// Input Box 2
Color secondBoxColor = WHITE;
if(secondActive)secondBoxColor = LIGHTGRAY;
DrawRectangleRec(secondBox, secondBoxColor);
DrawText(secondNumber, 390, 245, 22, BLACK);
Color addColor = DARKGRAY;// Operation Buttons
Color subColor = DARKGRAY;
Color mulColor = DARKGRAY;
Color divColor = DARKGRAY;
Color clearColor = DARKGRAY;
if (CheckCollisionPointRec(GetMousePosition(), addBtn))addColor = GRAY;
if (CheckCollisionPointRec(GetMousePosition(), subBtn))subColor = GRAY;
if (CheckCollisionPointRec(GetMousePosition(), mulBtn))mulColor = GRAY;
if (CheckCollisionPointRec(GetMousePosition(), divBtn))divColor = GRAY;
if (CheckCollisionPointRec(GetMousePosition(), clearBtn))clearColor = GRAY;
DrawRectangleRec(addBtn, addColor);
DrawRectangleRec(subBtn, subColor);
DrawRectangleRec(mulBtn, mulColor);
DrawRectangleRec(divBtn, divColor);
DrawRectangleRec(clearBtn, clearColor);
DrawText("Arithmetic Calculator",380,30,30,GREEN);
DrawText("+",405,332,30,WHITE);
DrawText("-",495,332,30,WHITE);
DrawText("× ",583,332,30,WHITE);
DrawText("÷",673,332,30,WHITE);
DrawText("C",765,332,30,WHITE);
DrawText("Result",380,410,22,WHITE);// Result
DrawRectangleRec(resultBox, WHITE);
DrawText(resultText,390,455,22,BLACK);
DrawText("ARITHMETIC GUIDE",1020,90,26,GREEN);
DrawText("Operations",1080,140,22,WHITE);
DrawText("+  Addition",1040,190,20,WHITE);
DrawText("-  Subtraction",1040,225,20,WHITE);
DrawText("×  Multiplication",1040,260,20,WHITE);
DrawText("÷  Division",1040,295,20,WHITE);
DrawLine(1030,340,1500,340,GREEN);
DrawText("Example",1120,370,22,GREEN);
DrawText("25 + 15 = 40",1060,420,20,WHITE);
DrawText("50 - 12 = 38",1060,455,20,WHITE);
DrawText("12 × 6 = 72",1060,490,20,WHITE);
DrawText("24 ÷ 8 = 3",1060,525,20,WHITE);
DrawLine(1030,570,1500,570,GREEN);
DrawText("Tip",1160,600,22,GREEN);
DrawText("Enter both numbers first.",1035,645,20,WHITE);
}
if (currentPage == 2)
{
Color powerColor = DARKGRAY;
Color sqrtColor = DARKGRAY;
Color factorialColor = DARKGRAY;
Color gcdColor = DARKGRAY;
Color lcmColor = DARKGRAY;
DrawText("Scientific Calculator", 380, 30, 30, GREEN); // Title
DrawText("Number 1", 380, 70, 22, WHITE);// Number 1
Color firstBoxColor = WHITE;
if (firstActive)firstBoxColor = LIGHTGRAY;
DrawRectangleRec(firstBox, firstBoxColor);
DrawText(firstNumber, 390, 135, 22, BLACK);
DrawText("Number 2/Power", 380, 180, 22, WHITE);// Number 2
Color secondBoxColor = WHITE;
if (secondActive)secondBoxColor = LIGHTGRAY;
DrawRectangleRec(secondBox, secondBoxColor);
DrawText(secondNumber, 390, 245, 22, BLACK);
if (CheckCollisionPointRec(GetMousePosition(), powerBtn))powerColor = GRAY;
if (CheckCollisionPointRec(GetMousePosition(), sqrtBtn))sqrtColor = GRAY;
if (CheckCollisionPointRec(GetMousePosition(), factorialBtn))factorialColor = GRAY;
if (CheckCollisionPointRec(GetMousePosition(), gcdBtn))gcdColor = GRAY;
if (CheckCollisionPointRec(GetMousePosition(), lcmBtn))lcmColor = GRAY;
    Color clearSciColor = DARKGRAY;
if(CheckCollisionPointRec(GetMousePosition(), clearSciBtn))clearSciColor = GRAY;
DrawRectangleRec(clearSciBtn, clearSciColor);
DrawText("C",765,405,20,WHITE);
   DrawRectangleRec(powerBtn, powerColor);  // Buttons
DrawRectangleRec(sqrtBtn, sqrtColor);
DrawRectangleRec(factorialBtn, factorialColor);
DrawRectangleRec(gcdBtn, gcdColor);
DrawRectangleRec(lcmBtn, lcmColor);
  DrawText("Power",395,335,20,WHITE);
DrawText("Sqrt",520,335,20,WHITE);
DrawText("n!",660,335,20,WHITE);
DrawText("GCD",410,405,20,WHITE);
DrawText("LCM",530,405,20,WHITE);
 DrawText("Result", 380, 470, 22, WHITE);  // Result
Rectangle sciResultBox = {380, 500, 420, 50};
DrawRectangleRec(sciResultBox, WHITE);
DrawText(resultText, 390, 515, 22, BLACK);
DrawText("SCIENTIFIC GUIDE",1030,90,26,GREEN);
DrawText("Available Functions",1060,140,22,WHITE);
DrawText("Power",1040,190,20,WHITE);
DrawText("Square Root",1040,225,20,WHITE);
DrawText("Factorial",1040,260,20,WHITE);
DrawText("GCD",1040,295,20,WHITE);
DrawText("LCM",1040,330,20,WHITE);
DrawLine(1030,370,1500,370,GREEN);
DrawText("Example",1120,400,22,GREEN);
DrawText("2^5 = 32",1060,450,20,WHITE);
DrawText("sqrt(25)=5",1060,485,20,WHITE);
DrawText("5! =120",1060,520,20,WHITE);
DrawLine(1030,570,1500,570,GREEN);
DrawText("Tip",1160,600,22,GREEN);
DrawText("Factorial accepts integers only.",1035,645,20,WHITE);
}
if (currentPage == 3)
{
DrawText("Trigonometry Calculator", 380, 30, 30, GREEN); // Title
DrawText("Angle (Degrees)", 380, 70, 22, WHITE);// Angle Input
Color firstBoxColor = WHITE;
if (firstActive)firstBoxColor = LIGHTGRAY;
DrawRectangleRec(firstBox, firstBoxColor);
DrawText(firstNumber, 390, 135, 22, BLACK);
Color sinColor = DARKGRAY;// Button Colors
Color cosColor = DARKGRAY;
Color tanColor = DARKGRAY;
Color asinColor = DARKGRAY;
Color acosColor = DARKGRAY;
Color atanColor = DARKGRAY;
Color clearTrigColor = DARKGRAY;
if(CheckCollisionPointRec(GetMousePosition(), sinBtn))sinColor = GRAY;// Hover
if(CheckCollisionPointRec(GetMousePosition(), cosBtn))cosColor = GRAY;
if(CheckCollisionPointRec(GetMousePosition(), tanBtn))tanColor = GRAY;
if(CheckCollisionPointRec(GetMousePosition(), asinBtn))asinColor = GRAY;
if(CheckCollisionPointRec(GetMousePosition(), acosBtn))acosColor = GRAY;
if(CheckCollisionPointRec(GetMousePosition(), atanBtn))atanColor = GRAY;
if(CheckCollisionPointRec(GetMousePosition(), clearTrigBtn))clearTrigColor = GRAY;
DrawRectangleRec(sinBtn, sinColor);// Draw Buttons
DrawRectangleRec(cosBtn, cosColor);
DrawRectangleRec(tanBtn, tanColor);
DrawRectangleRec(asinBtn, asinColor);
DrawRectangleRec(acosBtn, acosColor);
DrawRectangleRec(atanBtn, atanColor);
DrawRectangleRec(clearTrigBtn, clearTrigColor);
DrawText("Sin",410,275,20,WHITE);// Button Text
DrawText("Cos",530,275,20,WHITE);
DrawText("Tan",650,275,20,WHITE);
DrawText("ArcSin",390,345,20,WHITE);
DrawText("ArcCos",510,345,20,WHITE);
DrawText("ArcTan",630,345,20,WHITE);
DrawText("C",765,345,20,WHITE);
DrawText("Result",380,430,22,WHITE);// Result
Rectangle trigResultBox = {380,460,420,50};
DrawRectangleRec(trigResultBox, WHITE);
DrawText(resultText,390,475,22,BLACK);
DrawText("TRIGONOMETRY",1050,90,26,GREEN);
DrawText("Functions",1110,140,22,WHITE);
DrawText("Sin",1040,190,20,WHITE);
DrawText("Cos",1040,225,20,WHITE);
DrawText("Tan",1040,260,20,WHITE);
DrawText("ArcSin",1040,295,20,WHITE);
DrawText("ArcCos",1040,330,20,WHITE);
DrawText("ArcTan",1040,365,20,WHITE);
DrawLine(1030,405,1500,405,GREEN);
DrawText("Remember",1100,440,22,GREEN);
DrawText("Angles are in Degrees.",1040,485,20,WHITE);
DrawText("ArcSin & ArcCos",1040,520,20,WHITE);
DrawText("accept values -1 to 1.",1040,550,20,WHITE);
DrawLine(1030,600,1500,600,GREEN);
DrawText("Example",1120,630,22,GREEN);
DrawText("Sin(30)=0.5",1060,670,20,WHITE);
}
if (currentPage == 4)
{
    DrawText("Interest & Area Calculator",350,30,30,GREEN);
    if(iaMode == 1 || iaMode == 2)
{
    DrawText("Principal",380,70,22,WHITE);
    DrawText("Rate (%)",380,180,22,WHITE);
    DrawText("Time (Years)",380,290,22,WHITE);
}
else if(iaMode == 3)
{
    DrawText("Length",380,70,22,WHITE);
    DrawText("Breadth",380,180,22,WHITE);
}
else if(iaMode == 4)
{
    DrawText("Side",380,70,22,WHITE);
}
else if(iaMode == 5)
{
    DrawText("Radius",380,70,22,WHITE);
}
else if(iaMode == 6)
{
    DrawText("Base",380,70,22,WHITE);
    DrawText("Height",380,180,22,WHITE);
}
    Color firstBoxColor = WHITE;
    if(firstActive)firstBoxColor = LIGHTGRAY;
    DrawRectangleRec(firstBox, firstBoxColor);
    DrawText(firstNumber,390,135,22,BLACK);
    Color secondBoxColor = WHITE;
    if(secondActive)secondBoxColor = LIGHTGRAY;
    DrawRectangleRec(secondBox, secondBoxColor);
    DrawText(secondNumber,390,245,22,BLACK);
    Color thirdBoxColor = WHITE;
    if(thirdActive)thirdBoxColor = LIGHTGRAY;
    DrawRectangleRec(thirdBox, thirdBoxColor);
    DrawText(thirdNumber,390,355,22,BLACK);
Color siColor = DARKGRAY;  // Button Colors
Color ciColor = DARKGRAY;
Color clearIAColor = DARKGRAY;
Color rectangleColor = DARKGRAY;
Color squareColor = DARKGRAY;
Color circleColor = DARKGRAY;
Color triangleColor = DARKGRAY;
if (CheckCollisionPointRec(GetMousePosition(), siBtn))siColor = GRAY;// Hover
if (CheckCollisionPointRec(GetMousePosition(), ciBtn))ciColor = GRAY;
if (CheckCollisionPointRec(GetMousePosition(), clearIABtn))clearIAColor = GRAY;
if(CheckCollisionPointRec(GetMousePosition(), rectangleBtn))rectangleColor = GRAY;
if(CheckCollisionPointRec(GetMousePosition(), squareBtn))squareColor = GRAY;
if(CheckCollisionPointRec(GetMousePosition(), circleBtn))circleColor = GRAY;
if(CheckCollisionPointRec(GetMousePosition(), triangleBtn))triangleColor = GRAY;
DrawRectangleRec(siBtn, siColor);// Draw Buttons
DrawRectangleRec(ciBtn, ciColor);
DrawRectangleRec(clearIABtn, clearIAColor);
DrawRectangleRec(rectangleBtn, rectangleColor);
DrawRectangleRec(squareBtn, squareColor);
DrawRectangleRec(circleBtn, circleColor);
DrawRectangleRec(triangleBtn, triangleColor);
DrawText("Simple Interest",390,415,18,WHITE);// Button Text
DrawText("Compound Interest",580,415,18,WHITE);
DrawText("C",785,415,20,WHITE);
DrawText("Rectangle",390,485,18,WHITE);
DrawText("Square",540,485,18,WHITE);
DrawText("Circle",665,485,18,WHITE);
DrawText("Triangle",775,485,18,WHITE);
DrawText("Result",380,550,22,WHITE);// Result
Rectangle iaResultBox = {380,580,420,50};
DrawRectangleRec(iaResultBox, WHITE);
DrawText(resultText,390,595,22,BLACK);
DrawText("FORMULAS",1120,90,26,GREEN);
DrawText("Simple Interest",1060,150,20,WHITE);
DrawText("SI=(P×R×T)/100",1040,180,20,WHITE);
DrawText("Compound Interest",1040,240,20,WHITE);
DrawText("A=P(1+R/100)^T",1040,270,20,WHITE);
DrawLine(1030,320,1500,320,GREEN);
DrawText("Geometry",1120,360,22,GREEN);
DrawText("Rectangle = L×B",1040,405,20,WHITE);
DrawText("Square = Side²",1040,440,20,WHITE);
DrawText("Circle = πr²",1040,475,20,WHITE);
DrawText("Triangle = ½bh",1040,510,20,WHITE);
DrawLine(1030,560,1500,560,GREEN);
DrawText("Tip",1160,595,22,GREEN);
DrawText("Select a formula before entering values.",1035,640,20,WHITE);
}
if (currentPage == 5)
{
    if(currentPage == 5)
{
DrawText("Calculation History",350,40,30,GREEN);
DrawText("HISTORY",1130,90,26,GREEN);
DrawText("Recent calculations",1060,140,20,WHITE);
DrawLine(1030,180,1500,180,GREEN);
DrawText("Maximum History",1070,230,20,WHITE);
DrawText("20 Calculations",1090,260,20,WHITE);
DrawText("Automatically",1090,320,20,WHITE);
DrawText("Saved",1160,350,20,WHITE);
DrawLine(1030,410,1500,410,GREEN);
DrawText("Tip",1160,450,22,GREEN);
DrawText("Old calculations remain",1050,500,20,WHITE);
DrawText("until the program closes.",1050,530,20,WHITE);
    for(int i = 0; i < historyCount; i++)
    {
        DrawText(history[i], 350, 100 + i * 30, 20, WHITE);
    }
}
}
    EndDrawing();
    }
    CloseWindow();
    return 0;
}
