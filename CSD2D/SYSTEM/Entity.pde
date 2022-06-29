//gridindex


class Entity {
  PVector s;//speed in display?
  PVector spawn;
  PVector position;
  PVector tempPos;
  PVector displace;
  float d;
  PVector v;
  float life = 0;
  float armor = 0;
  boolean angered = false;

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

    if (life <= 50 || ent1.life(0) <= 0 || ent2.life(0) <= 0){
      angered = false;

    } else if(life >= 512){
      life = 512;
      angered = true;

    }
    return checked;

  }

  boolean angered(){
    return angered;
  }
  PVector display(PVector s, float kleur, PVector posNew, float size){
    posNew = new PVector(0,0);
    float r = size/2 + 5; // r = radius + strokeweight = radius
    if(life > 255){
      armor = life - 255;
      if(armor > 255){
        armor = 255;
      }
    }
    fill(kleur+50, 50);
    ellipse(tempPos.x, tempPos.y, size + 15, size + 15);
    fill(kleur, 50);
    stroke(255, 255 - armor, 255 - armor, armor);
    strokeWeight(6);
    tempPos.add(s);

    ellipse(tempPos.x, tempPos.y, size, size);
    fill(200);
    stroke(0);
    strokeWeight(3);

    ellipse(tempPos.x, tempPos.y, size/3, size/3);
    strokeWeight(0);
    fill(0);
    ellipse(tempPos.x, tempPos.y, 15, 15);
    // checking if between bounds, update this function!!!!
    if(tempPos.x >= width - r){
      tempPos.x = (width - r);
    } else if(tempPos.x <= r){
      tempPos.x = r ;
    }
    if(tempPos.y >= height-r){
      tempPos.y = height-r;
    } else if(tempPos.y <= r){
      tempPos.y = r;
    }

    posNew = tempPos;
    return posNew;
  }


  boolean collisionDetection(float xA, float yA, float xB, float yB){
    d = dist(xA, yA, xB, yB);
    if(d <= r1+r2){
      hit = true;
    } else {
      hit = false;
    }
    return hit;
  }


  PVector collide(float r1, float r2, PVector displace){
    displace = new PVector(0,0);
    if(d <= r1+r2){
      float a = random(40) - 20;
      float b = random(40) - 20;
    displace.set(a, b);
  }
  return displace;
  }

  float life(float amount){
    life += amount;
    return life;
  }

  boolean lifeCheck(float life){
    boolean state;
    if(life >= 0){
      state = true;
    } else {
      state = false;
    }
    return state;
  }
}
