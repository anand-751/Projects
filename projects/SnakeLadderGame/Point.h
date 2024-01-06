#pragma once

class Point {
    private:
        int mX; 
        int mY; 

    public:
        Point(int x, int y);

        int getX() const;
        int getY() const;

        void setX(int x);
        void setY(int y);

};

