// processing-java --sketch=/Users/rahsaan/Documents/CSD2/CSD2D/SYSTEM  --run
// todo : seeding food
// todo : wrapping function
// todo ; body building
// todo ; sound????

// dividing screen into sections
PVector[] flowField;
int scale = 20;
int cols;
int rows;

float Xone = 200;
float Yone = 300;
// noise offsets
float xoff = 0;
float yoff = 0;
float zoff = 0;
float increment = 0.01;

boolean status = true;


void setup(){
 size(800,800);

 surface.setTitle("SYSTEM");
 surface.setResizable(true);
 surface.setLocation(1500, 0);

 cols = floor(width / scale);
 rows = floor(height / scale);

 flowField = new PVector[cols * rows];


 frameRate(10);
 background(0);
 println("go");
}

void draw(){

  background(0, 0, 0, 70);
  yoff = 0;
  // updating vector angles by offsets
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
      // stroke(255);
      // push();
      // translate(x * scale, y * scale); //
      // rotate(v.heading());
      // strokeWeight(1);
      // line (0,0,scale,0);
      // pop();


      if(Xone >= (scale * (x-1)) + scale && Xone <= scale * (x+1)){
        if(Yone >= (40 * (y - 1)) + 40 && Yone <= 40 * (y+1)){
          // println("yay");
          ellipse(Xone,Yone,50,50);
          Xone += v.x;
          Yone += v.y;
        }
      }
    }
    yoff += increment;
    zoff += 0.00007;

  }

  if(Xone >= 799){
    Xone = 1;
  }
  if(Xone <= 0){
    Xone = 800;
  }
  if(Yone >= 799){
    Yone = 1;
  }
  if(Yone <= 0){
    Yone = 800;
  }
  println(Xone, Yone);
}
