// processing-java --sketch=/Users/rahsaan/Documents/CSD2/CSD2D/shader  --run

//voronoi code found on rosettacode.org/wiki/Voronoi_diagram#Processing and
//adjusted by me for this program

void setup() {
  size(800,800, P3D);
  background(255);
  generateVoronoiDiagram(width, height, 100);

  println("done");
}
void draw(){


// noLoop();
}

void generateVoronoiDiagram(int w, int h, int num_cells) {
  int nx[] = new int[num_cells];
  int ny[] = new int[num_cells];

  int nr[] = new int[num_cells];

  for (int n=0; n < num_cells; n++) {
    nx[n]=int(random(w));
    ny[n]=int(random(h));
    nr[n]=int(random(255));
    for (int y = 0; y < h; y++) {
      for (int x = 0; x < w; x++) {
        float dmin = dist(0, 0, w - 1, h - 1);
        int j = -1;
        for (int i=0; i < num_cells; i++) {
          float d = dist(0, 0, nx[i] - x, ny[i] - y);
          if (d < dmin) {
            dmin = d;
            j = i;

          }
          // else if ( d = dmin){
          //   strokeWeight(5);
          //   fill();
          //   point(x,y);
          // }
        }
        set(x, y, color(nr[j]));


      }
    }
  }
  // for (int y = 0; y < h; y++) {
  //   for (int x = 0; x < w; x++) {
  //     color c = get(x,y);
  //     float kleur = red(c);
      // println(kleur);
      // if(kleur > 30){
      //   set(x, y, color(255));
      // } else {
      //   set(x, y, color(0));
      // }
  //   }
  // }
}

void mouseClicked(){
  generateVoronoiDiagram(width, height, 8);
}
