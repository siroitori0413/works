#include <M5Stack.h>
#include "AudioFileSourceSD.h"
#include "AudioFileSourceID3.h"
#include "AudioGeneratorMP3.h"
#include "AudioOutputI2S.h"

AudioGeneratorMP3 *mp3;
AudioFileSourceSD *file;
AudioOutputI2S *out;
AudioFileSourceID3 *id3;

const  int  TouchPin = 22 ; 

boolean isEating = false;
boolean isDrawing = false;
boolean isStartSleep = false;

uint16_t analogRead_value = 0;

void playMP3(char *filename){
  file = new AudioFileSourceSD(filename);
  id3 = new AudioFileSourceID3(file);
  out = new AudioOutputI2S(0, 1); // Output to builtInDAC
  out->SetOutputModeMono(true);
  out->SetGain(2.0);
  mp3 = new AudioGeneratorMP3();
  mp3->begin(id3, out);
  while(mp3->isRunning()) {
    if (!mp3->loop()) mp3->stop();
  }
}

// pushテストのためコメント

// void monitorButtonTask(void* arg) {
//   //int cnt = 0;
//   while (1) {
//     M5.update();
//     if (M5.BtnB.wasPressed()){
//       // 食べる！
//       while(isDrawing || isStartSleep){
//         // 描画中は待つ
//         delay(100);
//       }
//       isEating = true;
//       M5.Lcd.drawJpgFile(SD, "/Fabies_Eye3.jpg");
//       playMP3("/_sound_anime_mp3_eat-meat1.mp3");
      
//       M5.Lcd.drawJpgFile(SD, "/Fabies_Eye1.jpg");
//       isEating = false;
      
//     }
    
//     //printf("task2 thread_cnt=%ld\n", cnt++);
//     delay(100);
//   }
// }

void setup() {
  M5.begin();
  // pinMode(26, INPUT);
  // pinMode(TouchPin, INPUT); 
  // // ボタン監視用スレッド
  // xTaskCreatePinnedToCore(monitorButtonTask, "MonitorButtonTask", 4096, NULL, 1, NULL, 0);
}

void loop() {

    M5.update();
    if (M5.BtnA.wasPressed()){
      // なんか食べる
      playMP3("/_sound_anime_mp3_eat-meat1.mp3");
    }  
    if (M5.BtnB.wasPressed()){
      //　なんか飲む
      playMP3("/_sound_anime_mp3_eat-meat1.mp3");
    }
    if (M5.BtnC.wasPressed()){
      // 散歩に行く
      playMP3("/_sound_anime_mp3_eat-meat1.mp3");


      // 食べる！
      // while(isDrawing || isStartSleep){
      //   // 描画中は待つ
      //   delay(100);
      // }
      // isEating = true;
      // M5.Lcd.drawJpgFile(SD, "/Fabies_Eye3.jpg");
      // playMP3("/_sound_anime_mp3_eat-meat1.mp3");
      
      // M5.Lcd.drawJpgFile(SD, "/Fabies_Eye1.jpg");
      // isEating = false;
      
    }
    
    //printf("task2 thread_cnt=%ld\n", cnt++);
    delay(100);



  // while(isEating || isStartSleep){
  //   // 食べてる間は待つ
  //   delay(100);
  // }
  // // 最初の顔
  // isDrawing = true;
  // M5.Lcd.drawJpgFile(SD, "/Fabies_Eye1.jpg");
  // isDrawing = false;
  // delay(2000);

  // while(isEating || isStartSleep){
  //   // 食べてる間は待つ
  //   delay(100);
  // }
  // // 瞬き
  // isDrawing = true;
  // M5.Lcd.drawJpgFile(SD, "/Fabies_Eye2.jpg");
  // isDrawing = false;
  // delay(200);
}
