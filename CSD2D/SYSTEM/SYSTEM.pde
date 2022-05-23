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
// boolean Testflow = true;

float Xone = 500;
float Yone = 500;
float Xtwo = 100;
float Ytwo = 100;

// noise offsets
float xoff = 0;
float yoff = 0;
float zoff = 0;
float increment = 0.01;

Entity  ent1 = new Entity(Xone, Yone, 100);

Entity  ent2 = new Entity(Xtwo, Ytwo, 20);

PVector pos = new PVector(0,0);
PVector pos2 = new PVector(0,0);


boolean checked1;
boolean checked2;




void setup(){
 size(800,800);

 surface.setTitle("SYSTEM");
 surface.setResizable(true);
 surface.setLocation(1500, 0);

 cols = floor(width / scale);
 rows = floor(height / scale);

 flowField = new PVector[cols * rows];

 frameRate(30);
 background(0);
 println("go");
}



void draw(){

  background(0, 0, 0, 30);
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
      // if(Testflow == true){
        stroke(255,70);
        push();
        translate(x * scale, y * scale);
        rotate(v.heading());
        strokeWeight(1);
        line (0,0,scale,0);
        pop();
      // }

      //check if it should draw entity, then draw and update
      //positions
      if(ent1.check(Xone, Yone, x, y, checked1)){
        pos = ent1.display(v.x, v.y, 50, pos);
        Xone = pos.x;
        Yone = pos.y;

      }
  checked1 = false;
      if(ent2.check(Xtwo, Ytwo, x, y, checked2)){
        ent2.display(v.x, v.y, 50, pos2);
        Xtwo = pos2.x;
        Ytwo = pos2.y;
      }
      checked2 = false;

    }

    yoff += increment;
    zoff += 0.00007;
  }


}



class Entity {

  float xpos, ypos;
  float col;
  float Xone, Yone;


  Entity(float x, float y, float colr){
    xpos = x;
    ypos = y;
    col = colr;
    // fill(colr);

  }

  boolean check(float Xone, float Yone, float x, float y, boolean checked){
    if(Xone >= (scale * (x-1)) + scale && Xone <= scale * (x+1)){
      if(Yone >= (40 * (y - 1)) + 40 && Yone <= 40 * (y+1)){
        checked = true;
      }
    } else {
       checked = false;
    }
    return checked;
  }

  PVector display(float vx, float vy, float kleur, PVector pos){
      pos = new PVector(0,0);

      fill(kleur);
      strokeWeight(5);
      xpos += vx;
      ypos += vy;
      ellipse(xpos,ypos,50,50);

      if(xpos >= 775){
        xpos = 25;
      } else if(xpos <= 25){
        xpos = 775;
      }
      if(ypos >= 775){
        ypos = 25;
      } else if(ypos <= 25){
        ypos = 775;
      }

      pos.set(xpos,ypos);
      return pos;
  }



}
