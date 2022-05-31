class Food {
  PVector foodPosition = new PVector(0,0);
  float foodAmount = 0;
  float shade;
  float d;
  float r;

  Food(float x, float y, float r){
    foodPosition.set(x, y);
    this.r = r;
  }

  boolean collisionDetection(float xA, float yA, float xB, float yB, float r2){
    d = dist(xA, yA, xB, yB);
    if(d <= foodAmount/5+r2){
      hit = true;
    } else {
      hit = false;
    }
    return hit;


  }

  float foodAmount(){
    return foodAmount;
  }


  void update(boolean hit, float player){
    if(hit){

      if(foodAmount > 0){
        foodAmount -= 1;
        if(player == 1){
          health1 = ent1.life(1);
        } else {
          health2 = ent2.life(1);
        }
      } else if(foodAmount <= 0){
        foodPosition.set(random(width), random(height));
        foodAmount = -random(200);

      }

    } else {
      foodAmount += 0.1;
    }
    if(foodAmount >= 255){
      foodAmount = 255;
    }
    // println(foodAmount + "foodAmount");
  }

  PVector display(){
    if(foodAmount >= 255){
      shade = 255;
    } else {
      shade = foodAmount;
    }
    strokeWeight(0);
    stroke(20);
    fill(shade, shade, 0 , 100);

    ellipse(foodPosition.x, foodPosition.y, foodAmount/5, foodAmount/5);
    return foodPosition;
  }


}
