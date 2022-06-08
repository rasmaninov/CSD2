// processing-java --sketch=/Users/rahsaan/Documents/CSD2/CSD2D/shaders  --run


// void setup(){
//   size(400,400);
//   surface.setLocation(-700,-1300);
//   background(0);
// }
//
// void draw(){
//   fill(200,223,123);
//   ellipse(70,70,20,20);
// }

// examples below copied from processing reference

PShader blur;

void setup() {
  size(640, 360, P2D);
  // Shaders files must be in the "data" folder to load correctly
  blur = loadShader("blur.glsl");
  stroke(0, 102, 153);
  rectMode(CENTER);
  println("loading complete, start");
}

void draw() {
  filter(blur);
  rect(mouseX-75, mouseY, 150, 150);
  ellipse(mouseX+75, mouseY, 150, 150);
}
