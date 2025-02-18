#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "Ray.h"
#include "defs.h"
#include<string.h>
#include <stdio.h>
// Structure for holding variables related to the image plane
typedef struct ImagePlane
{
  float left;     // "u" coordinate of the left edge
  float right;    // "u" coordinate of the right edge
  float bottom;   // "v" coordinate of the bottom edge
  float top;      // "v" coordinate of the top edge
    float distance; // distance to the camera (always positive)
    int nx;         // number of pixel columns
    int ny;         // number of pixel rows
} ImagePlane;

class Camera
{
public:
  char imageName[32];
  int id;
  ImagePlane imgPlane;     // Image plane

  Camera(int id,const char* imageName, const Vector3f& pos,         // Camera position
           const Vector3f& gaze,        // Camera gaze direction
           const Vector3f& up,          // Camera up direction
           const ImagePlane& imgPlane); // Image plane parameters

    // Computes the primary ray through pixel (row, col)
  Ray getPrimaryRay(int row, int col) const;

private:
    //
  // You can add member functions and variables here
    //
  Vector3f pos;         // Camera position
  Vector3f gaze;        // Camera gaze direction
  Vector3f up;          // Camera up direction
  Vector3f u;
};

#endif
