// processing-java --sketch=/Users/rahsaan/Documents/CSD2/CSD2D/SYSTEM  --run
// todo : seeding food
// todo ; body building
// todo ; sound????

// dividing screen into sections
PVector[] flowField;
int scale = 20;
int cols;
int rows;
boolean Testflow = false;

PVector positionZero = new PVector(0,0);
PVector positionOne = new PVector(0, 0);
PVector spawnPosOne = new PVector(700, 500);

PVector positionTwo = new PVector(0, 0);
PVector spawnPosTwo = new PVector(250, 250);

// noise offsets
float xoff = 0;
float yoff = 0;
float zoff = 0;
float increment = 0.01;

Entity  ent1 = new Entity(spawnPosOne);
Entity  ent2 = new Entity(spawnPosTwo);
// float foodstartx = 200;
// float foodstarty = 350;

float color1 = 255;
float color2 = 255;

int state1 = 0;
int state2 = 0;


PVector pos = new PVector(0,0);
PVector pos2 = new PVector(0,0);

boolean checked;

float r1 = 40;
float r2 = 60;
float r3 = 25;
PVector displace;
boolean hit = false;
float health1, health2;
PVector mousePosition = new PVector(0,0);
float x1, y1, x2, y2, x3, y3, x4, y4;
Food food = new Food(200, 200, r3);
boolean anger1, anger2;
int window = 800;


void setup(){

  size(800, 800);
//initializing system and several values
 surface.setTitle("SYSTEM");
 surface.setResizable(true);
 surface.setLocation(1500,400);

 cols = floor(width / scale);
 rows = floor(height / scale);

 flowField = new PVector[cols * rows];

 health1 = ent1.life(0);
 health2 = ent2.life(0);

 frameRate(60);
 background(0);
 println("go");
}



void draw(){
  background(0);
  // food.update();
  mousePosition = food.display();


  // entity one to food vector
  float dx1 = mousePosition.x - positionOne.x;
  float dy1 = mousePosition.y - positionOne.y;
  float angle1 = atan2(dy1, dx1);
  PVector foodPosition1 = PVector.fromAngle(angle1);
  // entity two to food vector
  float dx2 = mousePosition.x - positionTwo.x ;
  float dy2 = mousePosition.y - positionTwo.y ;
  float angle2 = atan2(dy2, dx2);
  PVector foodPosition2 = PVector.fromAngle(angle2);
  //ent1 to ent2
  float dx3 = positionOne.x - positionTwo.x;
  float dy3 = positionOne.y - positionTwo.y;
  float angle3= atan2(dy3, dx3);
  PVector ent1ToEnt2 = PVector.fromAngle(angle3);
  x3 = positionOne.x - cos(angle3) * 80;
  y3 = positionOne.y - sin(angle3) * 80;
  if(Testflow == true){
    push();
    translate(x3,y3);
    rotate(angle3);
    strokeWeight(5);
    stroke(255);
    line(0,0,80,0);
    pop();
  }
  //ent2 to ent1
  float dx4 = positionTwo.x - positionOne.x;
  float dy4 = positionTwo.y - positionOne.y;
  float angle4= atan2(dy4, dx4);
  PVector ent2ToEnt1 = PVector.fromAngle(angle4);
  x4 = positionTwo.x - cos(angle4) * 80;
  y4 = positionTwo.y - sin(angle4) * 80;
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

  x1 = mousePosition.x - cos(angle1) * 80;
  y1 = mousePosition.y - sin(angle1) * 80;
  food.update(food.collisionDetection(mousePosition.x, mousePosition.y, positionOne.x ,positionOne.y,  r1), 1);
  if(Testflow == true){
    push();
    translate(x1,y1);
    rotate(angle1);
    strokeWeight(5);
    stroke(255);
    line(0,0,80,0);
    pop();
  }



  x2 = mousePosition.x - cos(angle2) * 80;
  y2 = mousePosition.y - sin(angle2) * 80;
  food.update(food.collisionDetection(mousePosition.x, mousePosition.y, positionTwo.x ,positionTwo.y,  r2), 2);
  if(Testflow == true){
    push();
    translate(x2,y2);
    rotate(angle2);
    strokeWeight(5);
    stroke(255);
    line(0,0,80,0);
    pop();
  }


  yoff = 0;
  // updating vector angles by noise offsets
  for(int y = 0; y < rows; y++){
    xoff = 0;
    for(int x = 0; x < cols; x++){
      int index = x + y * cols;
      float angle = noise(xoff, yoff, zoff) * TWO_PI * 4;
      PVector v = PVector.fromAngle(angle);
      flowField[index] = v;
      v.setMag(1);
      xoff += increment;

      // drawing all vector angles
      if(Testflow == true){
        stroke(255,70);
        push();
        translate(x * scale, y * scale);
        rotate(v.heading());
        strokeWeight(1);
        line (0,0,scale,0);
        pop();
      }




      hit = ent1.collisionDetection(positionOne.x, positionOne.y, positionTwo.x, positionTwo.y);
      displace = ent1.collide(r1, r2, displace);

      //check if it should draw entity, then draw and update
      //positions
      v.setMag(1.3);
      if(anger1 == true){
        // println("enraged p1");
        v = ent2ToEnt1;
        v.setMag(2);
        // if(ent1.life(0) <= 50 || ent2.life(0) <= 0){
        //   anger1 = false;
        //   anger2 = false;
        //   println("rage over");
        //
        //
        // }
      } else if(food.foodAmount >= 150){
        v.add(foodPosition1);
        v.setMag(1.4);
      }
      if(hit){
        v.add(displace);
        v.setMag(2);
      }
      color1 = health1;
      if(color1 >= 255){
        color1 = 255;
      }
      if(ent1.lifeCheck(health1 )){
        if(ent1.check(positionOne,x, y, checked)){
          anger1 = ent1.angered();
            positionOne = ent1.display(v, color1, pos, r1*2); // vector, color, new position(returned), size
        }
      }
         // vector, color, new position(returned), size

      displace = ent2.collide(r1, r2, displace);

      v.setMag(0.6);
      if(anger2 == true){
        // println("enraged p2");
        v = ent1ToEnt2;
        v.setMag(2);
        // if(ent2.life(0) <= 50 || ent1.life(0) <= 0){
        //   anger2 = false;
        //   anger1 = false;
        //   println("rage over");
        //
        //
        // }
      } else if(food.foodAmount >= 150){
        v.add(foodPosition2);
        v.setMag(0.7);
      }
      if(hit){
        v.add(displace);
        v.setMag(2);
      }
      color2 = health2;
      if(color2 >= 255){
        color2 = 255;
      }
      if(ent2.lifeCheck(health2)){
        if(ent2.check(positionTwo, x, y, checked)){
          anger2 = ent2.angered();
          positionTwo = ent2.display(v, color2, pos2, r2*2);
        }
      }
       // vector, color, new position(returned), size

    }

      yoff += increment;
      zoff += 0.00007;

  }


  if(hit){
    health2 = ent2.life(-random(5));
    health1 = ent1.life(-random(5));
  }


  if(ent1.lifeCheck(health1) == false && frameCount % 500 == 0){
    health1 = ent1.life(1);
    state1 = 1;
    positionOne.set(0, 0);
    println("p1 respawn");



  } else if (ent1.lifeCheck(health1) == false){
    positionOne.set(-400, -400);
  } else if (ent1.life(0) < 255){
    if (state1 == 1){
      if(health1 < 250){
        health1 = ent1.life(3);
      } else {
        println("p1 full hp");
        state1 = 0;
        health1 = ent1.life(2);
      }
    } else {
      health1 = ent1.life(2);
    }

  }


  if(ent2.lifeCheck(health2) == false && frameCount % 500 == 150){
    health2 = ent2.life(1);
    state2 = 1;
    positionTwo.set(400, 400);
    println("p2 respawn");



  } else if (ent2.lifeCheck(health2) == false){
    positionTwo.set(-200, -200);
  } else if (ent2.life(0) < 255) {
    if (state2 == 1){
      if(health2 < 250){
        health2 = ent2.life(3);
      } else {
        println("p2 full hp");
        state2 = 0;
        health2 = ent2.life(2);
      }
    } else {
        health2 = ent2.life(2);
    }

  }

  //
  println(health1, "p1 hp");
  println(health2, "p2 hp");
}
