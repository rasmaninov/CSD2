class Food {
  PVector foodPosition = new PVector(0,0);
  float foodAmount = 0;
  float shade;
  float d;
  float r;
  boolean growth = true;

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
      growth = false;
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
        growth = true;

      }

    } else {
      if(growth){
        foodAmount += 0.05;

      } else {
        foodAmount -= 0.05;
        if(foodAmount <= 0){
          foodPosition.set(random(width), random(height));
          foodAmount = -random(200);
          growth = true;
          println("reaspamn food");
        }
      }
    }
    if(foodAmount >= 255){
    growth = false;
    println("grow stop bro");
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
    fill(shade, shade, 0 , shade * 2);

    ellipse(foodPosition.x, foodPosition.y, foodAmount/5, foodAmount/5);
    return foodPosition;
  }


}
