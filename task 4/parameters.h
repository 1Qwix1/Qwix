#pragma once

const float WINDOW_WIDTH = 800;
const float WINDOW_HEIGHT = 800;
const float FIELD_WIDTH = 800;
const float FIELD_HEIGHT = WINDOW_HEIGHT / 2.5;

const int BLOCKS_IN_WIDE = 5;
const int BLOCKS_IN_HEIGHT = 7;
const float SPACE_BLOCK = 5;
const int CHANCE_ACCELERATE_BLOCK = 10;

const float CARRIAGE_WIDTH = 200.0;
const float CARRIAGE_HEIGHT = 30.0;
const float CARRIAGE_SPEED = 10.0;
const float CARRIAGE_X = WINDOW_WIDTH / 2.0 - CARRIAGE_WIDTH / 2.0;
const float CARRIAGE_Y = WINDOW_HEIGHT * 0.8;

const float BALL_RADIUS = 15.0;
const float BALL_X = CARRIAGE_X + CARRIAGE_WIDTH / 2 - BALL_RADIUS;
const float BALL_Y = CARRIAGE_Y - 2 * BALL_RADIUS;
const float BALL_SPEED = 10.0;

const int FONT_SIZE = 70;
const float TEXT_X = WINDOW_WIDTH * 0.9;
const float TEXT_Y = WINDOW_HEIGHT * 0.9;

const int BONUS_VALUE = 7;
const int BONUS_CHANCE = 50;
const float BONUS_RADIUS = 15.0;
const float BONUS_SPEED = 6.0;

const float DELTA_CARRIAGE_WIDTH = CARRIAGE_WIDTH * 0.2;

const float COEFF_SPEED_CHANGE = 0.1;