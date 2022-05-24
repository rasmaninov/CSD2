//gridindex


class Entity {
  PVector s;//speed in display?
  float xpos, ypos;
  float Xone, Yone;
  PVector position;

  Entity(float x, float y){
    xpos = x;
    ypos = y;
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

  PVector display(PVector s, float kleur, PVector pos, float size){
      pos = new PVector(0,0);
      float r = size/2 + 5; // r = radius + strokeweight
      fill(kleur);
      strokeWeight(5);
      xpos += s.x;
      ypos += s.y;
      ellipse(xpos, ypos, size, size);

      if(xpos >= width - r){
        xpos = (width - r);
      } else if(xpos <= r){
        xpos = r ;
      }
      if(ypos >= width-r){
        ypos = width-r;
      } else if(ypos <= r){
        ypos = r;
      } // magic numbers weghalen
      //wrapping secuur??>?
      // pos = position;
      pos.set(xpos,ypos);
      return pos;
  }

  void collide() {

  }


}
