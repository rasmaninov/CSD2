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



void setup(){
 size(800,800);
//initializing system and several values
 surface.setTitle("SYSTEM");
 surface.setResizable(true);
 surface.setLocation(200,0);

 cols = floor(width / scale);
 rows = floor(height / scale);

 flowField = new PVector[cols * rows];

 frameRate(60);
 background(0);
 println("go");
}



void draw(){

  background(0, 0, 0, 30);
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

      //check if it should draw entity, then draw and update
      //positions
      v.setMag(0.5);
      if(ent1.check(positionOne,x, y, checked)){
        positionOne = ent1.display(v, 70, pos, 40); // vector, color, new position(returned), size
      }

      v.setMag(1);
      if(ent2.check(positionTwo, x, y, checked)){
        positionTwo = ent2.display(v, 20, pos2, 60);
      }

    }

    yoff += increment;
    zoff += 0.00007;
  }

}
