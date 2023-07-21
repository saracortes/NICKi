import ddf.minim.*;
import ddf.minim.analysis.*;
import ddf.minim.effects.*;
import ddf.minim.signals.*;
import ddf.minim.spi.*;
import ddf.minim.ugens.*;

import processing.serial.*;
Serial myPort;
String val;

Minim minim;
AudioPlayer playerH1;
AudioPlayer playerH2;
AudioPlayer playerH3;
AudioPlayer playerG1;
AudioPlayer playerG2;
AudioPlayer playerG3;
AudioPlayer playerHello;

String h = "h";
String g = "g";
String hello = "hello";


void setup(){
  String portName = Serial.list()[1];
  myPort = new Serial (this, portName, 9600);
  minim = new Minim(this);
  playerH1 = minim.loadFile("Happy1.wav");
  playerH2 = minim.loadFile("Happy2.wav");
  playerH3 = minim.loadFile("Happy3.wav");
  playerG1 = minim.loadFile("Grumpy1.wav");
  playerG2 = minim.loadFile("Grumpy2.wav");
  playerG3 = minim.loadFile("Grumpy3.wav");
  playerHello = minim.loadFile("introNICKi.wav");
  
}
void draw(){
  if (myPort.available()>0)
  {
    val = myPort.readString();
    print(val);
    int num = int( random( 0, 3 ) );
    if(val.equals(hello))
    {
      playerHello.play();
    }
    if(val.equals(h))
    {
      if(num==0)
      {
        playerH1.play();
      } 
      if(num==1)
      {
        playerH2.play();
      }
      if(num==2)
      {
        playerH3.play();
      }
    }
    if(val.equals(g))
    {
      if(num==0)
      {
        playerG1.play();
      } 
      if(num==1)
      {
        playerG2.play();
      }
      if(num==2)
      {
        playerG3.play();
      }
    }

    myPort.clear();
  }
  
}
