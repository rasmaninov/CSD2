//gridindex


class Entity {
  PVector s;//speed in display?
  PVector spawn;
  PVector position;
  PVector tempPos;

  Entity(PVector spawn){
    tempPos = spawn;
  }

  boolean check(PVector position, float x, float y, boolean checked){
    if(position.x >= (scale * (x-1)) + scale && position.x <= scale * (x+1)){
      if(position.y >= (40 * (y - 1)) + 40 && position.y <= 40 * (y+1)){
        checked = true;
      }
    } else {
       checked = false;
    }
    return checked;
  }

  PVector display(PVector s, float kleur, PVector posNew, float size){
    posNew = new PVector(0,0);

    float r = size/2 + 5; // r = radius + strokeweight = radius
    fill(kleur);
    strokeWeight(5);
    tempPos.add(s);

    ellipse(tempPos.x, tempPos.y, size, size);
    // checking if between bounds, update this function!!!!
    if(tempPos.x >= width - r){
      tempPos.x = (width - r);
    } else if(tempPos.x <= r){
      tempPos.x = r ;
    }
    if(tempPos.y >= width-r){
      tempPos.y = width-r;
    } else if(tempPos.y <= r){
      tempPos.y = r;
    }

    posNew = tempPos;
    return posNew;
  }

  void collide() {

  }


}
