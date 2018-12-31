#pragma once
// trying to create singleton class that in the future will parse txt file
class Config {
  public:
    static int WINDOW_WIDTH;
    static int WINDOW_HEIGHT;
    static float CAMERA_SPEED;
    static float CAMERA_SENSITIVITY;
    Config();
    ~Config();
};