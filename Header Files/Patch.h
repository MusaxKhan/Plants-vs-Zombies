//#pragma once
//#pragma once
//#include <iostream>
//#include "Screen_class.h"
//using namespace std;
//#ifndef PATCH_H
//#define PATCH_H
//
//class patch {
//private:
//    float x;
//    float y;
//    bool valid;
//    bool plant_valid;
//
//public:
//
//
//    patch(float x_cord = 0, float y_cord = 0, bool plantable = 0) {
//        x = x_cord;
//        y = y_cord;
//        valid = plantable;
//        plant_valid = plantable;
//    }
//
//    // Getter for x coordinate
//    float getX() const {
//        return x;
//    }
//    // Getter for y coordinate
//    float getY() const {
//        return y;
//    }
//
//    // Setter for x n y coordinate
//    void set_coords(float newX, float newY) {
//        x = newX;
//        y = newY;
//    }
//
//    // Getter for valid
//    bool isvalid() const {
//        return valid;
//    }
//    bool is_plantvalid() const {
//        return plant_valid;
//    }
//
//
//    // Setter for valid
//    void setvalid(bool newvalid) {
//        valid = newvalid;
//    }
//
//    void set_plantvalid(bool newvalid) {
//        plant_valid = newvalid;
//    }
//};
//
//void setPatch(patch pat[][9])
//{
//    int start_x = 318;
//    int start_y = 98;
//
//    int diff_x = 102;
//    int diff_y = 124;
//
//    int current_x = 404;
//    int current_y = 99;
//
//    pat[0][0].set_coords(start_x, start_y);
//
//    for (int i = 0; i < 5; i++)
//    {
//        current_x = start_x;
//        for (int j = 0; j < 9; j++) {
//            pat[i][j].set_coords(current_x, current_y);
//            current_x += diff_x;
//            pat[i][j].setvalid(0);
//            pat[i][j].set_plantvalid(0);
//        }
//        current_y += diff_y;
//    }
//
//    for (int i = 0;i < 5;i++)
//    {
//        for (int j = 0;j < 9;j++)
//        {
//            cout << pat[i][j].getX() << " ,  " << pat[i][j].getY() << "   ";
//        }
//        cout << endl;
//    }
//}
//void enable_rows(patch grid[][9], int from, int to)
//{
//    while (from <= to)
//    {
//        for (int j = 0;j < 9;j++) {
//            grid[from][j].setvalid(1);
//            grid[from][j].set_plantvalid(1);
//        }
//        from++;
//    }
//}
//
//int* set_Coordinates(int mouse_pos_x, int mouse_pos_y, patch grid[][9])
//{
//    int* cor = new int[2];
//    for (int i = 0;i < 5;i++)
//    {
//        for (int j = 0;j < 9;j++)
//        {
//            if (mouse_pos_x >= grid[i][j].getX() && mouse_pos_x <= grid[i][j].getX() + 102)
//            {
//               // cout << i << " , ";
//                if (mouse_pos_y >= grid[i][j].getY() && mouse_pos_y <= grid[i][j].getY() + 124)
//                {
//                   // cout << j << endl;
//                    cor[0] = grid[i][j].getX();
//                    cor[1] = grid[i][j].getY();
//                    return cor;
//                }
//            }
//        }
//    }
//    cor[0] = 0;
//    cor[1] = 0;
//    return cor;
//}
//
//int* set_Coordinates(int mouse_pos_x, int mouse_pos_y, patch** grid)
//{
//    int* cor = new int[2];
//    for (int i = 0;i < 5;i++)
//    {
//        for (int j = 0;j < 9;j++)
//        {
//            if (mouse_pos_x >= grid[i][j].getX() && mouse_pos_x <= grid[i][j].getX() + 102)
//            {
//                if (mouse_pos_y >= grid[i][j].getY() && mouse_pos_y <= grid[i][j].getY() + 124)
//                {
//                    cor[0] = grid[i][j].getX();
//                    cor[1] = grid[i][j].getY();
//                    return cor;
//                }
//            }
//        }
//    }
//
//    cor[0] = 0;
//    cor[1] = 0;
//    return cor;
//}
//bool touched_correctly(int* cor)
//{
//    if (cor[0] != 0 && cor[1] != 0)
//        return true;
//    return false;
//}
//bool can_be_placed(patch grid[][9], int* cor, bool alpha = false)
//{
//    int row;
//    int column;
//    if (touched_correctly(cor))
//    {
//        for (int i = 0;i < 5;i++)
//        {
//            for (int j = 0;j < 9;j++)
//            {
//                if (grid[i][j].getX() == cor[0] && grid[i][j].getY() == cor[1])
//                {
//                    row = i;
//                    column = j;
//                    cout << row << " , " << column << endl;
//                    if (!alpha)
//                    {
//                        if (grid[row][column].is_plantvalid())
//                        {
//                            grid[row][column].set_plantvalid(0);
//                            return true;
//                        }
//                        else
//                            return false;
//                    }
//                    else
//                    {
//                        grid[row][column].set_plantvalid(1);
//                        return true;
//                    }
//
//                }
//            }
//        }
//    }
//    else
//        return false;
//}
//
//bool can_be_placed(patch** grid, int* cor, bool alpha = false)
//{
//    int row;
//    int column;
//    if (touched_correctly(cor))
//    {
//        for (int i = 0;i < 5;i++)
//        {
//            for (int j = 0;j < 9;j++)
//            {
//                if (grid[i][j].getX() == cor[0] && grid[i][j].getY() == cor[1])
//                {
//                    row = i;
//                    column = j;
//                    if (!alpha)
//                    {
//                        if (grid[row][column].is_plantvalid())
//                        {
//                            grid[row][column].set_plantvalid(0);
//                            return true;
//                        }
//                        else
//                            return false;
//                    }
//                    else
//                    {
//                        grid[row][column].set_plantvalid(1);
//                        return true;
//                    }
//                }
//            }
//        }
//    }
//    else 
//        return false;
//}
//#endif


#pragma once
#include <iostream>
#include "Screen_class.h"
using namespace std;
#ifndef PATCH_H
#define PATCH_H

class patch {
private:
    float x;
    float y;
    bool valid;
    bool plant_valid;

public:


    patch(float x_cord = 0, float y_cord = 0, bool plantable = 0) {
        x = x_cord;
        y = y_cord;
        valid = plantable;
        plant_valid = plantable;
    }

    // Getter for x coordinate
    float getX() const {
        return x;
    }
    // Getter for y coordinate
    float getY() const {
        return y;
    }

    // Setter for x n y coordinate
    void set_coords(float newX, float newY) {
        x = newX;
        y = newY;
    }

    // Getter for valid
    bool isvalid() const {
        return valid;
    }
    bool is_plantvalid() const {
        return plant_valid;
    }


    // Setter for valid
    void setvalid(bool newvalid) {
        valid = newvalid;
    }

    void set_plantvalid(bool newvalid) {
        plant_valid = newvalid;
    }
};

void setPatch(patch pat[][9])
{
    int start_x = 318;
    int start_y = 98;

    int diff_x = 102;
    int diff_y = 124;

    int current_x = 404;
    int current_y = 99;

    pat[0][0].set_coords(start_x, start_y);

    for (int i = 0; i < 5; i++)
    {
        current_x = start_x;
        for (int j = 0; j < 9; j++) {
            pat[i][j].set_coords(current_x, current_y);
            current_x += diff_x;
            pat[i][j].setvalid(0);
            pat[i][j].set_plantvalid(0);
        }
        current_y += diff_y;
    }

    for (int i = 0;i < 5;i++)
    {
        for (int j = 0;j < 9;j++)
        {
            cout << pat[i][j].getX() << " ,  " << pat[i][j].getY() << "   ";
        }
        cout << endl;
    }
}
void enable_rows(patch grid[][9], int from, int to)
{
    while (from <= to)
    {
        for (int j = 0;j < 9;j++) {
            grid[from][j].setvalid(1);
            grid[from][j].set_plantvalid(1);
        }
        from++;
    }
}

int* set_Coordinates(int mouse_pos_x, int mouse_pos_y, patch grid[][9])
{
    int* cor = new int[2];
    for (int i = 0;i < 5;i++)
    {
        for (int j = 0;j < 9;j++)
        {
            if (mouse_pos_x >= grid[i][j].getX() && mouse_pos_x <= grid[i][j].getX() + 102)
            {
                // cout << i << " , ";
                if (mouse_pos_y >= grid[i][j].getY() && mouse_pos_y <= grid[i][j].getY() + 124)
                {
                    // cout << j << endl;
                    cor[0] = grid[i][j].getX();
                    cor[1] = grid[i][j].getY();
                    return cor;
                }
            }
        }
    }
    cor[0] = 0;
    cor[1] = 0;
    return cor;
}

int* set_Coordinates(int mouse_pos_x, int mouse_pos_y, patch** grid)
{
    int* cor = new int[2];
    for (int i = 0;i < 5;i++)
    {
        for (int j = 0;j < 9;j++)
        {
            if (mouse_pos_x >= grid[i][j].getX() && mouse_pos_x <= grid[i][j].getX() + 102)
            {
                if (mouse_pos_y >= grid[i][j].getY() && mouse_pos_y <= grid[i][j].getY() + 124)
                {
                    cor[0] = grid[i][j].getX();
                    cor[1] = grid[i][j].getY();
                    return cor;
                }
            }
        }
    }

    cor[0] = 0;
    cor[1] = 0;
    return cor;
}
bool touched_correctly(int* cor)
{
    if (cor[0] != 0 && cor[1] != 0)
        return true;
    return false;
}
bool can_be_placed(patch grid[][9], int* cor, bool alpha = false)
{
    int row;
    int column;
    if (touched_correctly(cor))
    {
        for (int i = 0;i < 5;i++)
        {
            for (int j = 0;j < 9;j++)
            {
                if (grid[i][j].getX() == cor[0] && grid[i][j].getY() == cor[1])
                {
                    row = i;
                    column = j;
                    cout << row << " , " << column << endl;
                    if (!alpha)
                    {
                        if (grid[row][column].is_plantvalid())
                        {
                            grid[row][column].set_plantvalid(0);
                            return true;
                        }
                        else
                            return false;
                    }
                    else
                    {
                        grid[row][column].set_plantvalid(1);
                        return true;
                    }

                }
            }
        }
    }
    else
        return false;
}

bool can_be_placed(patch** grid, int* cor, bool alpha = false)
{
    int row;
    int column;
    if (touched_correctly(cor))
    {
        for (int i = 0;i < 5;i++)
        {
            for (int j = 0;j < 9;j++)
            {
                if (grid[i][j].getX() == cor[0] && grid[i][j].getY() == cor[1])
                {
                    row = i;
                    column = j;
                    if (!alpha)
                    {
                        if (grid[row][column].is_plantvalid())
                        {
                            grid[row][column].set_plantvalid(0);
                            return true;
                        }
                        else
                            return false;
                    }
                    else
                    {
                        grid[row][column].set_plantvalid(1);
                        return true;
                    }
                }
            }
        }
    }
    else
        return false;
}
#endif