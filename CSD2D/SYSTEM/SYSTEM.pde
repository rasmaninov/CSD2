// processing-java --sketch=/Users/rahsaan/Documents/CSD2/CSD2D/SYSTEM  --run
// dit is de command voor mijzelf om af te spelen
// voor iedereen else heb ik voor de makkelijk een processing file die je in de
// processing IDE kan gooien gedaan


//if true, visualizes everything
boolean Testflow = true;

// dividing screen into sections
PVector[] flowField;
int scale = 20;
int cols;
int rows;

PVector positionZero = new PVector(0,0);
PVector positionOne = new PVector(0, 0);
PVector spawnPosOne = new PVector(700, 500);

PVector v1 = new PVector(0,0);
PVector v2 = new PVector(0,0);

PVector positionTwo = new PVector(0, 0);
PVector spawnPosTwo = new PVector(250, 250);

// noise offsets
float xoff = 0;
float yoff = 0;
float zoff = 0;
float increment = 0.005;

Entity  ent1 = new Entity(spawnPosOne);
Entity  ent2 = new Entity(spawnPosTwo);

float color1 = 255;
float color2 = 255;

int state1 = 1;
int state2 = 1;

int filter = 1;

PVector pos = new PVector(0,0);
PVector pos2 = new PVector(0,0);

boolean checked;

float r1 = 30;
float r2 = 50;
float r3 = 25;
PVector displace;
boolean hit = false;
float health1, health2;
PVector foodPosition = new PVector(0,0);
float x1, y1, x2, y2, x3, y3, x4, y4;
Food food = new Food(200, 200);
boolean anger1, anger2;
int window = 800;
PShader blur;

void setup(){

  size(1000, 1000, P2D); //setting size and renderer
  blur = loadShader("blur.glsl");

//initializing system and several values
 surface.setTitle("SYSTEM");
 surface.setResizable(true);
 surface.setLocation(-700,-1100);
 frameRate(60);
 background(0);
 //dividing canvas into blocks for flowfield and prepping flowfield PVector array
 cols = floor(width / scale);
 rows = floor(height / scale);
 flowField = new PVector[cols * rows];

 //initializing health1 and health2
 health1 = ent1.life(0);
 health2 = ent2.life(0);
}



void draw(){

  filter(blur); //shader for Esthetics
  //overlaying a rectangle to create a trail of entity drawings
  fill(0, 20);
  rect(0,0,width,height);

  //displaying food
  foodPosition = food.display();


  // calculating entity one to food vector
  float dx1 = foodPosition.x - positionOne.x;
  float dy1 = foodPosition.y - positionOne.y;
  float angle1 = atan2(dy1, dx1);
  PVector foodPosition1 = PVector.fromAngle(angle1);
  // calculating entity two to food vector
  float dx2 = foodPosition.x - positionTwo.x ;
  float dy2 = foodPosition.y - positionTwo.y ;
  float angle2 = atan2(dy2, dx2);
  PVector foodPosition2 = PVector.fromAngle(angle2);
  //calculatin ent1 to ent2 vector
  float dx3 = positionOne.x - positionTwo.x;
  float dy3 = positionOne.y - positionTwo.y;
  float angle3= atan2(dy3, dx3);
  PVector ent1ToEnt2 = PVector.fromAngle(angle3);
  x3 = positionOne.x - cos(angle3) * 80;
  y3 = positionOne.y - sin(angle3) * 80;

  //drawing ent1toent2 vector
  if(Testflow == true){
    push();
    translate(x3,y3);
    rotate(angle3);
    strokeWeight(5);
    stroke(255);
    line(0,0,80,0);
    pop();
  }
  //calculatin ent2 to ent1 vector
  float dx4 = positionTwo.x - positionOne.x;
  float dy4 = positionTwo.y - positionOne.y;
  float angle4= atan2(dy4, dx4);
  PVector ent2ToEnt1 = PVector.fromAngle(angle4);
  x4 = positionTwo.x - cos(angle4) * 80;
  y4 = positionTwo.y - sin(angle4) * 80;

  //drawing ent2toent1 vector
  if(Testflow == true){
    push();
    translate(x4, y4);
    rotate(angle4);
    strokeWeight(5);
    stroke(255);
    line(0,0,80,0);
    pop();
  }

  //numbers at the end specify which entity
  // calculating and drawing ent1tofoodvector
  x1 = foodPosition.x - cos(angle1) * 80;
  y1 = foodPosition.y - sin(angle1) * 80;
  if(Testflow == true){
    push();
    translate(x1,y1);
    rotate(angle1);
    strokeWeight(5);
    stroke(255);
    line(0,0,80,0);
    pop();
  }
  //updating the foodamount and state based on collisiondetect
  food.update(food.collisionDetection(foodPosition.x, foodPosition.y, positionOne.x ,positionOne.y,  r1), 1);


  // calculating and drawing ent2tofoodvector
  x2 = foodPosition.x - cos(angle2) * 80;
  y2 = foodPosition.y - sin(angle2) * 80;
  if(Testflow == true){
    push();
    translate(x2,y2);
    rotate(angle2);
    strokeWeight(5);
    stroke(255);
    line(0,0,80,0);
    pop();
  }
  //updating the foodamount and state based on collisiondetect
  food.update(food.collisionDetection(foodPosition.x, foodPosition.y, positionTwo.x ,positionTwo.y,  r2), 2);

  //initializing flowfield drawing
  yoff = 0;
  // updating vector angles by noise offsets and drawing flowfield
  for(int y = 0; y < rows; y++){
    xoff = 0;
    for(int x = 0; x < cols; x++){
      int index = x + y * cols;
      float angle = noise(xoff, yoff, zoff) * TWO_PI * 4;
      PVector v = PVector.fromAngle(angle);
      flowField[index] = v;
      v.setMag(0.7);
      xoff += increment;

      // drawing all vector (angles)
      if(Testflow == true){
        stroke(255,70);
        push();
        translate(x * scale, y * scale);
        rotate(v.heading());
        strokeWeight(1);
        line (0,0,scale,0);
        pop();
      }
      //checking if entities collide
      hit = ent1.collisionDetection(positionOne.x, positionOne.y, positionTwo.x, positionTwo.y);
      //if touching, calculate entity displacement
      displace = ent1.collide(r1, r2, displace);

      //whats happens if the hit each other
      if(hit){
        v.add(displace); //adding displacement to current movement vector
        v.setMag(2);
      }
      //splitting displacent for ent1 and ent2
      v1 = v;
      v2 = v;


      //check if it should draw entity, then draw and update
      //positions
      v1.setMag(1.3);
      //change Vector based on entity state
      if(anger1 == true){
        v1 = ent2ToEnt1;
        v.setMag(2);
      } else if(food.foodAmount >= 250 || health1 > 170 && food.foodAmount() > 100){
        v1.add(foodPosition1);
        v1.add(foodPosition1);
        v.setMag(1.4);
      }
      //adapt ent color based on health
      color1 = health1;
      if(color1 >= 255){
        color1 = 255;
      }

      //if living and within bounds
      if(ent1.lifeCheck(health1 )){
        if(ent1.check(positionOne,x, y, checked)){
          anger1 = ent1.angered(); //updating anger based on anger
          //updating position and displays entity
          positionOne = ent1.display(v1, color1, pos, r1*2); // vector, color, new position(returned), size
        }
      }
      //if touching, calculate entity displacement
      displace = ent2.collide(r1, r2, displace);
      //check if it should draw entity, then draw and update
      //positions
      v2.setMag(0.6);
      //change Vector based on entity state
      if(anger2 == true){
        v2 = ent1ToEnt2;
        v2.setMag(2);

      }else if(food.foodAmount >= 200 || health2 < 150 && food.foodAmount() > 100){
        v2.add(foodPosition2);
        v2.setMag(0.7);
      }


      if(hit){
        v2.add(displace);//adding displacement to current movement vector
        v2.setMag(2);
      }
      //adapt ent color based on health
      color2 = health2;
      if(color2 >= 255){
        color2 = 255;
      }
      //if living and within bounds
      if(ent2.lifeCheck(health2)){
        if(ent2.check(positionTwo, x, y, checked)){
          anger2 = ent2.angered();//updating anger based on anger
          //updating position and displays entity

          positionTwo = ent2.display(v2, color2, pos2, r2*2);// vector, color, new position(returned), size
        }
      }

    }
      //updating perlin noise params
      yoff += increment;
      zoff += 0.000007;

  }

  //if hit, and one of entities is angry, they do more damage than the other, if both or none angry same damage
  if(hit){
      if(anger2){
      health1 = ent1.life(-random(7));
      health2 = ent2.life(-random(5));
    } else if(anger1){
      health2 = ent2.life(-random(7));
      health1 = ent1.life(-random(5));
    } else {
      health2 = ent2.life(-random(5));
      health1 = ent1.life(-random(5));
    }
  }

  //respawn if dead
  if(ent1.lifeCheck(health1) == false && frameCount % 500 == 0){
    health1 = ent1.life(1);
    state1 = 1;
    positionOne.set(0, 0);
    println("p1 respawn");


  //if dead and not respawn time yet, keep out of canvas
  } else if (ent1.lifeCheck(health1) == false){
    positionOne.set(-400, -400);
    //if health is under 510, add health until hp full
  } else if (ent1.life(0) < 510){
    if (state1 == 1){
      if(health1 < 250){
        health1 = ent1.life(3);
      } else {
        println("p1 full hp");
        state1 = 0;
        health1 = ent1.life(2);
      }
      //if hp has been full they slowly die unless they eat
    } else {
      health1 = ent1.life(-random(0.05));
    }

  }

  //respawn if dead
  if(ent2.lifeCheck(health2) == false && frameCount % 500 == 150){
    health2 = ent2.life(1);
    state2 = 1;
    positionTwo.set(400, 400);
    println("p2 respawn");


    //if dead and not respawn time yet, keep out of canvas
  } else if (ent2.lifeCheck(health2) == false){
    positionTwo.set(-200, -200);
    //if health is under 510, add health until hp full
  } else if (ent2.life(0) < 510) {
    if (state2 == 1){
      if(health2 < 250){
        health2 = ent2.life(3);
      } else {
        println("p2 full hp");
        state2 = 0;
        health2 = ent2.life(2);
      }
      //if hp has been full they slowly die unless they eat
    } else {
        health2 = ent2.life(-random(0.05));
    }

  }

}
