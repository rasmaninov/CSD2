class Entity {
  PVector s;//speed in display?
  PVector spawn; //spawnposition
  PVector position; //currentposition
  PVector tempPos; //temporary position for calculations and use within function
  PVector displace; //displacement position if hit
  float d; //collisioncheck distance
  float life = 0; //HP
  float armor = 0; //armor amount
  boolean angered = false; //state of entity

  //create the entity and give it a place
  Entity(PVector spawn){
    tempPos = spawn;
  }

 //checking if entity is alive and within bounds
  boolean check(PVector position, float x, float y, boolean checked){
    if(position.x >= (scale * (x-1)) + scale && position.x <= scale * (x+1)){
      if(position.y >= (40 * (y - 1)) + 40 && position.y <= 40 * (y+1)){
        checked = true;
      }
    } else {
       checked = false;
    }

    //they are no longer angry if either one dies or health goes below 50
    if (life <= 50 || ent1.life(0) <= 0 || ent2.life(0) <= 0){
      angered = false;
      //if the are at full HP, then the become angry
    } else if(life >= 512){
      life = 512;
      angered = true;

    }
    return checked;

  }

  //return state of entity
  boolean angered(){
    return angered;
  }

  // displaying entity, colors are based on life and armor, armor is also update
  // here unknown reason and also updating position. Kinda teveel functies in een
  // functie sry
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
    // checking if between bounds and keeping them within bounds
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

  //detecting if entity touches other entity
  boolean collisionDetection(float xA, float yA, float xB, float yB){
    d = dist(xA, yA, xB, yB);
    if(d <= r1+r2){
      hit = true;
    } else {
      hit = false;
    }
    return hit;
  }

  //if they collide, add displacement vector so they both move "like theyre fighting" when touching
  PVector collide(float r1, float r2, PVector displace){
    displace = new PVector(0,0);
    if(d <= r1+r2){
      float a = random(40) - 20;
      float b = random(40) - 20;
    displace.set(a, b);
  }
  return displace;
  }

  //return HP
  float life(float amount){
    life += amount;
    return life;
  }

  //checking if entity is alive
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
