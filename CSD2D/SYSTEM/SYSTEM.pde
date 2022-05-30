// processing-java --sketch=/Users/rahsaan/Documents/CSD2/CSD2D/SYSTEM  --run
// todo : seeding food
// todo ; body building
// todo ; sound????

// dividing screen into sections
PVector[] flowField;
int scale = 20;
int cols;
int rows;
boolean Testflow = true;

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

PVector pos = new PVector(0,0);
PVector pos2 = new PVector(0,0);

boolean checked;

float r1 = 40;
float r2 = 60;
PVector displace;
boolean hit = false;
float health1, health2;


void setup(){
 size(400,400);
//initializing system and several values
 surface.setTitle("SYSTEM");
 surface.setResizable(true);
 surface.setLocation(1500,400);

 cols = floor(width / scale);
 rows = floor(height / scale);

 flowField = new PVector[cols * rows];

 frameRate(60);
 background(0);
 println("go");
}



void draw(){

  background(0);
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
      v.setMag(1);
      if(hit){
        v.add(displace);
        v.setMag(2);
      }

      if(ent1.lifeCheck(health1 )){
        if(ent1.check(positionOne,x, y, checked)){
            positionOne = ent1.display(v, health1, pos, r1*2); // vector, color, new position(returned), size
        }
      }
         // vector, color, new position(returned), size

      displace = ent2.collide(r1, r2, displace);

      v.setMag(1);
      if(hit){
        v.add(displace);
        v.setMag(2);
      }

      if(ent2.lifeCheck(health2)){
        if(ent2.check(positionTwo, x, y, checked)){
          positionTwo = ent2.display(v, health2, pos2, r2*2);
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
    health1 = ent1.life(250);
    println("p1 respawn");
    positionOne.set(0, 0);
  } else if (ent1.lifeCheck(health1) == false){
    positionOne.set(-400, -400);
  } else if (ent1.life(0) < 255){
    health1 = ent1.life(1);
  }

  if(ent2.lifeCheck(health2) == false && frameCount % 500 == 150){
    health2 = ent2.life(250);
    positionTwo.set(400, 400);
    println("p2 respawn");

  } else if (ent2.lifeCheck(health2) == false){
    positionTwo.set(-200, -200);
  } else if (ent2.life(0) < 255) {
    health2 = ent2.life(1);
  }


  println(health1, "p1 hp");
  println(health2, "p2 hp");
}
