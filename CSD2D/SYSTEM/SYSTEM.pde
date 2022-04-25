// processing-java --sketch=/Users/rahsaan/Documents/CSD2/CSD2D/SYSTEM  --run
// todo : flow field(viewable at first), seeding food

// dividing screen into sections
PVector[] flowField;
int scale = 15;
int cols;
int rows;


// noise offsets
float xoff = 0;
float yoff = 0;
float zoff = 0;
float increment = 0.01;

void setup(){
 size(600,600);

 surface.setTitle("SYSTEM");
 surface.setResizable(true);
 surface.setLocation(0, 0);

 cols = floor(width / scale);
 rows = floor(height / scale);

 flowField = new PVector[cols * rows];


 frameRate(30);
 background(0);
}

void draw(){
  background(0);
  yoff = 0;
  for(int y = 0; y < rows; y++){
    xoff = 0;
    for(int x = 0; x < cols; x++){
      int index = x + y * cols;

      float angle = noise(xoff, yoff, zoff) * TWO_PI * 4;
      PVector v = PVector.fromAngle(angle);
      flowField[index] = v;
      v.setMag(0.02);
      xoff += increment;

      stroke(255);
      push();
      translate(x * scale, y * scale);
      rotate(v.heading());
      strokeWeight(0.1);

      line (0,0,scale,0);
      pop();


    }
    yoff += increment;
    zoff += 0.00007;
  }




}
