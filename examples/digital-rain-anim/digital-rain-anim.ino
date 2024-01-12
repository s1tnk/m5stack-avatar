#include <M5Unified.h>
#include <Avatar.h>
#include <DigitalRainAnimation.hpp>

using namespace m5avatar;
Avatar avatar;

DigitalRainAnimation<M5Canvas> matrix_effect = DigitalRainAnimation<M5Canvas>();
bool first = true;

void background_loop(M5Canvas *canvas);

void setup(void)
{
  M5.begin();

  avatar.init(8, background_loop); // 8ビットデプスを指定、背景描画用コールバックを渡す
  avatar.setBatteryIcon(true);
}

void loop(void) {
  // nop
}

// アバターの背景に描画するためのコールバック
void background_loop(M5Canvas *canvas) {
  if (first) {
    matrix_effect.init(canvas);
    first = false;
  }
  matrix_effect.loop();
}
